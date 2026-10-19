// Portfolio excerpt: selected functions only; not a complete translation unit.
// Original file: ModelEditor/Private/ModelViewerObject.cpp
// Snapshot: 6af96f1b15b987af897bc12c479ee0544b3d425d
// Team-owned or mixed-author functions are omitted.

// Original lines 39-51 | ModelViewerObject::Update
void ModelViewerObject::Update(float timeDelta)
{
	GameObject::Update(timeDelta);

	if (_modelCom && _modelCom->Is_Skeletal() && _animComputeRuntime != nullptr)
	{
		CHECK_FAILED(_animComputeRuntime->Update_Frame(timeDelta), );
	}
	else if (_modelCom && _modelCom->Is_Skeletal())
	{
		_modelCom->Play_Animation(timeDelta);
	}
}

// Original lines 53-58 | ModelViewerObject::Late_Update
void ModelViewerObject::Late_Update(float timeDelta)
{
	GameObject::Late_Update(timeDelta);

	GAME->Add_RenderGroup(RenderGroup::NonBlend, GetSharedPtr<GameObject>());
}

// Original lines 60-71 | ModelViewerObject::Render
HRESULT ModelViewerObject::Render()
{
    _lastRenderComputeSkinned = false;

	if (nullptr == _modelCom || nullptr == _staticShaderCom || nullptr == _animShaderCom)
		return S_OK;

    if (_modelCom->Is_Skeletal() && _animComputeRuntime != nullptr)
        return Render_ComputeSkinned();

    return Render_Default();
}

// Original lines 73-119 | ModelViewerObject::Render_Default
HRESULT ModelViewerObject::Render_Default()
{
    const Shared<ShaderCom> shader = _modelCom->Is_Skeletal() ? _animShaderCom : _staticShaderCom;
    CHECK_NULL(shader, E_FAIL);
    
    CHECK_FAILED(Bind_ShaderResources(shader), E_FAIL);
    CHECK_FAILED(shader->Reset_DrawFeatures(), E_FAIL);

	const uint32 numMeshes = static_cast<uint32>(_modelCom->Get_NumMeshes());
    for (uint32 i = 0; i < numMeshes; ++i)
    {
        const uint32 materialIndex = _modelCom->Get_MeshMaterialIndex(i);
        const Shared<Material> material = _modelCom->Get_Material(materialIndex);
        if (material == nullptr)
        {
            continue;
        }

        if (FAILED(shader->Bind_MaterialTextures(*material)))
        {
            continue;
        }

        if (FAILED(shader->Bind_CBufferData(material->Get_CB())))
        {
            return E_FAIL;
        }

        if (_modelCom->Is_Skeletal())
        {
            if (FAILED(_modelCom->Bind_BoneMatrices(shader.get(), "g_BoneMatricesBuffer", i)))
            {
                return E_FAIL;
            }
        }

        const uint32 passIndex = material->Get_PassIndex();
        if (FAILED(shader->Begin(passIndex)))
        {
            return E_FAIL;
        }

        _modelCom->Render(i);
    }

	return S_OK;
}

// Original lines 121-155 | ModelViewerObject::Render_ComputeSkinned
HRESULT ModelViewerObject::Render_ComputeSkinned()
{
    CHECK_NULL(_animComputeRuntime, E_FAIL);
    CHECK_NULL(_staticShaderCom, E_FAIL);

    _lastRenderComputeSkinned = true;

    CHECK_FAILED(_animComputeRuntime->Prepare_ComputeSkinning(), E_FAIL);
    CHECK_FAILED(Bind_ShaderResources(_staticShaderCom), E_FAIL);
    CHECK_FAILED(_staticShaderCom->Reset_DrawFeatures(), E_FAIL);

    const uint32 numMeshes = static_cast<uint32>(_modelCom->Get_NumMeshes());
    for (uint32 i = 0; i < numMeshes; ++i)
    {
        const uint32 materialIndex = _modelCom->Get_MeshMaterialIndex(i);
        const Shared<Material> material = _modelCom->Get_Material(materialIndex);
        if (material == nullptr)
            continue;

        if (FAILED(_staticShaderCom->Bind_MaterialTextures(*material)))
            continue;

        if (FAILED(_staticShaderCom->Bind_CBufferData(material->Get_CB())))
            return E_FAIL;

        const uint32 passIndex =
            ShaderPassFinder::Find_PassIndex(ShaderType::VtxMesh, material->Get_RenderState());
        if (FAILED(_staticShaderCom->Begin(passIndex)))
            return E_FAIL;

        CHECK_FAILED(_animComputeRuntime->Render_ComputeSkinned(i), E_FAIL);
    }

    return S_OK;
}

// Original lines 193-201 | ModelViewerObject::Play_Animation
void ModelViewerObject::Play_Animation(uint32 animIndex, float blendDuration, bool isLoop, bool isRoot)
{
    _modelCom->Set_RootMotionEnabled(isRoot);

	if (_modelCom && _modelCom->Is_Skeletal())
	{
		_modelCom->Set_Animation(animIndex, blendDuration, isLoop);
	}
}

// Original lines 228-246 | ModelViewerObject::Ready_Components
HRESULT ModelViewerObject::Ready_Components()
{
    if (FAILED(GameObject::Add_Component(0, TEXT("Shader_VtxMesh"), _staticShaderCom)))
        return E_FAIL;

    if (FAILED(GameObject::Add_Component(0, TEXT("Shader_VtxAnimMesh"), _animShaderCom)))
        return E_FAIL;

    if (FAILED(GameObject::Add_Component(0, TEXT("ComputeShader_BoneRemap"), _boneRemapShaderCom)))
        return E_FAIL;

    if (FAILED(GameObject::Add_Component(0, TEXT("ComputeShader_AnimMeshSkinning"), _skinningShaderCom)))
        return E_FAIL;

    if (FAILED(GameObject::Add_Component(0, TEXT("ComputeShader_MorphDeform"), _morphShaderCom)))
        return E_FAIL;

    return S_OK;
}

// Original lines 248-263 | ModelViewerObject::Ready_AnimComputeRuntime
HRESULT ModelViewerObject::Ready_AnimComputeRuntime()
{
    if (_modelCom == nullptr || !_modelCom->Is_Skeletal())
        return S_OK;

    AnimComputeRuntime::CreateDesc runtimeDesc{};
    runtimeDesc.model = _modelCom.get();
    runtimeDesc.boneRemapShader = _boneRemapShaderCom;
    runtimeDesc.skinningShader = _skinningShaderCom;
    runtimeDesc.morphShader = _morphShaderCom;

    _animComputeRuntime = AnimComputeRuntime::Create(_device, _context, runtimeDesc);
    CHECK_NULL(_animComputeRuntime, E_FAIL);

    return S_OK;
}

// Original lines 265-276 | ModelViewerObject::Bind_ShaderResources
HRESULT ModelViewerObject::Bind_ShaderResources(const Shared<ShaderCom>& shader)
{
    if (nullptr == _modelCom || nullptr == shader) return E_FAIL;

	if (FAILED(shader->Bind_ObjectCB(_transformCom->Get_WorldMatrix())))
		return E_FAIL;

    if (FAILED(GAME->Bind_CameraCB(shader)))
        return E_FAIL;

	return S_OK;
}

// Original lines 278-289 | ModelViewerObject::Create
Shared<ModelViewerObject> ModelViewerObject::Create(const ComPtr<Device>& device, const ComPtr<Context>& context)
{
	auto instance = make_shared<ModelViewerObject>(device, context);

	if (FAILED(instance->Initialize_Prototype()))
	{
		MSG_BOX("Failed to Created : ModelViewerObject");
		return nullptr;
	}

	return instance;
}

// Original lines 291-302 | ModelViewerObject::Clone
Shared<GameObject> ModelViewerObject::Clone(void* arg)
{
	auto instance = make_shared<ModelViewerObject>(*this);

	if (FAILED(instance->Initialize(arg)))
	{
		MSG_BOX("Failed to Clone : ModelViewerObject");
		return nullptr;
	}

	return instance;
}