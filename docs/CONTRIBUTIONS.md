# 담당 범위와 공동 작업

원본 경로·전체 파일을 유지하면서, 담당 부분과 코드 흐름을 이해하는 데 필요한 주변 코드를 함께 담았습니다. 함수마다 Git 작성자가 같아야 한다는 이전 발췌 규칙은 적용하지 않았습니다. 대신 현재 파일의 작성 이력과 본인 변경 커밋을 manifest에 남겼습니다. 코드가 복사·이동되거나 여러 사람에게 수정될 수 있으므로 이력만으로 소유권이나 설계 기여를 단정하지 않습니다.

## 모델 변환·툴

변환·추출, ModelEditor 확인 도구. 리타겟 계산·애니메이션 제작에는 UE5를 오프라인 도구로 사용했으며 UE5 리타겟 도구 자체를 구현한 것은 아닙니다.

| 파일 | 포함 이유 | 현재 작성 이력 |
| --- | --- | --- |
| [Engine/Public/Engine_Model_Struct.h](../Engine/Public/Engine_Model_Struct.h) | 공유 형식·공동 코드 | 본인·팀원 공동 기록 |
| [ModelEditor/Private/Camera_Editor.cpp](../ModelEditor/Private/Camera_Editor.cpp) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Private/EditorBlock.cpp](../ModelEditor/Private/EditorBlock.cpp) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Private/Level_ModelEditor.cpp](../ModelEditor/Private/Level_ModelEditor.cpp) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Private/LogWindow.cpp](../ModelEditor/Private/LogWindow.cpp) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Private/ModelConverter.cpp](../ModelEditor/Private/ModelConverter.cpp) | 담당 구현 | 본인·팀원 공동 기록 |
| [ModelEditor/Private/ModelEditorApp.cpp](../ModelEditor/Private/ModelEditorApp.cpp) | 툴 구동·주변 코드 | 본인·팀원 공동 기록 |
| [ModelEditor/Private/ModelEditorCamera.cpp](../ModelEditor/Private/ModelEditorCamera.cpp) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Private/ModelImGui_Manager.cpp](../ModelEditor/Private/ModelImGui_Manager.cpp) | 툴 구동·주변 코드 | 본인·팀원 공동 기록 |
| [ModelEditor/Private/ModelInspector.cpp](../ModelEditor/Private/ModelInspector.cpp) | 담당 구현 | 본인·팀원 공동 기록 |
| [ModelEditor/Private/ModelSceneWindow.cpp](../ModelEditor/Private/ModelSceneWindow.cpp) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Private/ModelTestPanel.cpp](../ModelEditor/Private/ModelTestPanel.cpp) | 담당 구현 | 본인으로 기록 |
| [ModelEditor/Private/ModelViewerObject.cpp](../ModelEditor/Private/ModelViewerObject.cpp) | 담당 구현 | 본인·팀원 공동 기록 |
| [ModelEditor/Public/Camera_Editor.h](../ModelEditor/Public/Camera_Editor.h) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Public/EditorBlock.h](../ModelEditor/Public/EditorBlock.h) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Public/Level_ModelEditor.h](../ModelEditor/Public/Level_ModelEditor.h) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Public/LogWindow.h](../ModelEditor/Public/LogWindow.h) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Public/ModelConverter.h](../ModelEditor/Public/ModelConverter.h) | 담당 구현 | 본인으로 기록 |
| [ModelEditor/Public/ModelEditorApp.h](../ModelEditor/Public/ModelEditorApp.h) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Public/ModelEditorCamera.h](../ModelEditor/Public/ModelEditorCamera.h) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Public/ModelImGui_Manager.h](../ModelEditor/Public/ModelImGui_Manager.h) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Public/ModelInspector.h](../ModelEditor/Public/ModelInspector.h) | 담당 구현 | 본인·팀원 공동 기록 |
| [ModelEditor/Public/ModelSceneWindow.h](../ModelEditor/Public/ModelSceneWindow.h) | 툴 구동·주변 코드 | 본인으로 기록 |
| [ModelEditor/Public/ModelTestPanel.h](../ModelEditor/Public/ModelTestPanel.h) | 담당 구현 | 본인으로 기록 |
| [ModelEditor/Public/ModelViewerObject.h](../ModelEditor/Public/ModelViewerObject.h) | 담당 구현 | 본인으로 기록 |

## 애니메이션·편집

상태/애니메이션 매핑, Root Motion과 Modifier 연동. ModelCom·Animation·Channel과 MainEditor의 편집 뷰는 팀 코드이며, Notify·프리뷰·효과 편집 등 파일 전체를 개인 기여로 제시하지 않습니다.

| 파일 | 포함 이유 | 현재 작성 이력 |
| --- | --- | --- |
| [Engine/Private/Animation.cpp](../Engine/Private/Animation.cpp) | 공동 런타임 | 본인·팀원 공동 기록 |
| [Engine/Private/AnimState_Parser.cpp](../Engine/Private/AnimState_Parser.cpp) | 공동 런타임 | 본인·팀원 공동 기록 |
| [Engine/Private/Bone.cpp](../Engine/Private/Bone.cpp) | 공동 런타임 | 본인·팀원 공동 기록 |
| [Engine/Private/Channel.cpp](../Engine/Private/Channel.cpp) | 공동 런타임 | 본인·팀원 공동 기록 |
| [Engine/Private/ModelCom.cpp](../Engine/Private/ModelCom.cpp) | 공동 런타임 | 본인·팀원 공동 기록 |
| [Engine/Public/Animation.h](../Engine/Public/Animation.h) | 공동 런타임 | 본인·팀원 공동 기록 |
| [Engine/Public/AnimState_Parser.h](../Engine/Public/AnimState_Parser.h) | 공동 런타임 | 본인·팀원 공동 기록 |
| [Engine/Public/Bone.h](../Engine/Public/Bone.h) | 공동 런타임 | 본인·팀원 공동 기록 |
| [Engine/Public/Channel.h](../Engine/Public/Channel.h) | 공동 런타임 | 본인·팀원 공동 기록 |
| [Engine/Public/ModelCom.h](../Engine/Public/ModelCom.h) | 공동 런타임 | 본인·팀원 공동 기록 |
| [MainEditor/Private/Animation_View.cpp](../MainEditor/Private/Animation_View.cpp) | 공동 편집기 | 본인·팀원 공동 기록 |
| [MainEditor/Private/AnimState_View.cpp](../MainEditor/Private/AnimState_View.cpp) | 공동 편집기 | 본인·팀원 공동 기록 |
| [MainEditor/Private/Model_Inspector.cpp](../MainEditor/Private/Model_Inspector.cpp) | 공동 편집기 | 팀원 코드·호출 맥락 |
| [MainEditor/Public/Animation_View.h](../MainEditor/Public/Animation_View.h) | 공동 편집기 | 본인·팀원 공동 기록 |
| [MainEditor/Public/AnimState_View.h](../MainEditor/Public/AnimState_View.h) | 공동 편집기 | 본인·팀원 공동 기록 |
| [MainEditor/Public/Model_Inspector.h](../MainEditor/Public/Model_Inspector.h) | 공동 편집기 | 팀원 코드·호출 맥락 |

## Modifier

AnimationModifier, ChainModifier, PhysicsModifier, OffsetAnimationModifier와 충돌 형태 데이터 파싱. 캐릭터별 원본 프리셋·리소스는 제외했습니다. PoseFollow 계열의 과거 실험 코드를 대표 기능으로 추가하지 않았습니다.

| 파일 | 포함 이유 | 현재 작성 이력 |
| --- | --- | --- |
| [Engine/Private/AnimationModifier.cpp](../Engine/Private/AnimationModifier.cpp) | 담당 구현 | 본인으로 기록 |
| [Engine/Private/ChainModifier.cpp](../Engine/Private/ChainModifier.cpp) | 담당 구현 | 본인으로 기록 |
| [Engine/Private/ModelPhysicsParser.cpp](../Engine/Private/ModelPhysicsParser.cpp) | 담당 구현 | 본인으로 기록 |
| [Engine/Private/OffsetAnimationModifier.cpp](../Engine/Private/OffsetAnimationModifier.cpp) | 담당 구현 | 본인·팀원 공동 기록 |
| [Engine/Private/PhysicsModifier.cpp](../Engine/Private/PhysicsModifier.cpp) | 담당 구현 | 본인·팀원 공동 기록 |
| [Engine/Public/AnimationModifier.h](../Engine/Public/AnimationModifier.h) | 담당 구현 | 본인으로 기록 |
| [Engine/Public/ChainModifier.h](../Engine/Public/ChainModifier.h) | 담당 구현 | 본인으로 기록 |
| [Engine/Public/ModelPhysicsParser.h](../Engine/Public/ModelPhysicsParser.h) | 담당 구현 | 본인으로 기록 |
| [Engine/Public/OffsetAnimationModifier.h](../Engine/Public/OffsetAnimationModifier.h) | 담당 구현 | 본인으로 기록 |
| [Engine/Public/PhysicsModifier.h](../Engine/Public/PhysicsModifier.h) | 담당 구현 | 본인으로 기록 |

## 월드 액션

파쿠르·상하 로프·그래플링 요청과 실행, FreeAim의 애니메이션 보정. 공유 플레이어 베이스·점프·상호작용 오브젝트는 연결을 읽기 위해 포함했습니다. 공격·전투·플레이어 전체의 단독 구현을 뜻하지 않습니다.

| 파일 | 포함 이유 | 현재 작성 이력 |
| --- | --- | --- |
| [Client/Private/Player_FreeAim.cpp](../Client/Private/Player_FreeAim.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Private/Player_GrappleAction.cpp](../Client/Private/Player_GrappleAction.cpp) | 담당 기능과 공동 편집 | 본인으로 기록 |
| [Client/Private/Player_Jump.cpp](../Client/Private/Player_Jump.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Private/Player_ParkourAction.cpp](../Client/Private/Player_ParkourAction.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Private/Player_RopeAction.cpp](../Client/Private/Player_RopeAction.cpp) | 담당 기능과 공동 편집 | 본인으로 기록 |
| [Client/Private/Player_State.cpp](../Client/Private/Player_State.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Private/Player_WorldAction.cpp](../Client/Private/Player_WorldAction.cpp) | 담당 기능과 공동 편집 | 팀원 코드·호출 맥락 |
| [Client/Private/Player_WorldBase.cpp](../Client/Private/Player_WorldBase.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Private/WorldGrapplingRopeSpot.cpp](../Client/Private/WorldGrapplingRopeSpot.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Private/WorldInteractionSpot.cpp](../Client/Private/WorldInteractionSpot.cpp) | 담당 기능과 공동 편집 | 본인으로 기록 |
| [Client/Private/WorldLedgeSpot.cpp](../Client/Private/WorldLedgeSpot.cpp) | 담당 기능과 공동 편집 | 본인으로 기록 |
| [Client/Private/WorldUpDownRopeSpot.cpp](../Client/Private/WorldUpDownRopeSpot.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Public/Player_FreeAim.h](../Client/Public/Player_FreeAim.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Public/Player_GrappleAction.h](../Client/Public/Player_GrappleAction.h) | 담당 기능과 공동 편집 | 본인으로 기록 |
| [Client/Public/Player_Jump.h](../Client/Public/Player_Jump.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Public/Player_ParkourAction.h](../Client/Public/Player_ParkourAction.h) | 담당 기능과 공동 편집 | 본인으로 기록 |
| [Client/Public/Player_RopeAction.h](../Client/Public/Player_RopeAction.h) | 담당 기능과 공동 편집 | 본인으로 기록 |
| [Client/Public/Player_State.h](../Client/Public/Player_State.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Public/Player_WorldAction.h](../Client/Public/Player_WorldAction.h) | 담당 기능과 공동 편집 | 팀원 코드·호출 맥락 |
| [Client/Public/Player_WorldBase.h](../Client/Public/Player_WorldBase.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Public/WorldGrapplingRopeSpot.h](../Client/Public/WorldGrapplingRopeSpot.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Public/WorldInteractionSpot.h](../Client/Public/WorldInteractionSpot.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Public/WorldLedgeSpot.h](../Client/Public/WorldLedgeSpot.h) | 담당 기능과 공동 편집 | 본인으로 기록 |
| [Client/Public/WorldUpDownRopeSpot.h](../Client/Public/WorldUpDownRopeSpot.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |

## 맵 통합

모델별 머티리얼 편집, Static/Instanced 데이터 분할 입출력과 Client 어댑터·로더 연결. SceneContext·PanelModelOverride·MapLoader는 공동 작성입니다. 맵 에디터·셰이더 전체를 제작했다는 의미는 아닙니다.

| 파일 | 포함 이유 | 현재 작성 이력 |
| --- | --- | --- |
| [Client/Private/MapAdapter.cpp](../Client/Private/MapAdapter.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Private/MapCollisionAdapter.cpp](../Client/Private/MapCollisionAdapter.cpp) | 담당 기능과 공동 편집 | 본인으로 기록 |
| [Client/Private/MapInstancedMesh.cpp](../Client/Private/MapInstancedMesh.cpp) | 적용 경로·주변 코드 | 본인·팀원 공동 기록 |
| [Client/Private/MapLoader.cpp](../Client/Private/MapLoader.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Private/MapStaticMesh.cpp](../Client/Private/MapStaticMesh.cpp) | 적용 경로·주변 코드 | 본인·팀원 공동 기록 |
| [Client/Public/MapAdapter.h](../Client/Public/MapAdapter.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Public/MapCollisionAdapter.h](../Client/Public/MapCollisionAdapter.h) | 담당 기능과 공동 편집 | 본인으로 기록 |
| [Client/Public/MapInstancedMesh.h](../Client/Public/MapInstancedMesh.h) | 적용 경로·주변 코드 | 팀원 코드·호출 맥락 |
| [Client/Public/MapLoader.h](../Client/Public/MapLoader.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Public/MapStaticMesh.h](../Client/Public/MapStaticMesh.h) | 적용 경로·주변 코드 | 팀원 코드·호출 맥락 |
| [MapEditor/Private/MEMaterialApplicator.cpp](../MapEditor/Private/MEMaterialApplicator.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [MapEditor/Private/MEModelManager.cpp](../MapEditor/Private/MEModelManager.cpp) | 적용 경로·주변 코드 | 팀원 코드·호출 맥락 |
| [MapEditor/Private/PanelModelOverride.cpp](../MapEditor/Private/PanelModelOverride.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [MapEditor/Private/SceneContext.cpp](../MapEditor/Private/SceneContext.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [MapEditor/Public/MapEditorDefines.h](../MapEditor/Public/MapEditorDefines.h) | 공유 형식·공동 코드 | 본인·팀원 공동 기록 |
| [MapEditor/Public/MEMaterialApplicator.h](../MapEditor/Public/MEMaterialApplicator.h) | 담당 기능과 공동 편집 | 팀원 코드·호출 맥락 |
| [MapEditor/Public/MEModelManager.h](../MapEditor/Public/MEModelManager.h) | 적용 경로·주변 코드 | 팀원 코드·호출 맥락 |
| [MapEditor/Public/PanelModelOverride.h](../MapEditor/Public/PanelModelOverride.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [MapEditor/Public/SceneContext.h](../MapEditor/Public/SceneContext.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |

## ScreenFx

ScreenFx 인스턴스·관리·편집과 RT 복사·UI 순서 보정. 효과 클래스·셰이더는 공동 변경 이력을 포함합니다. 렌더러·셰이더 시스템 전체는 담당 범위가 아닙니다.

| 파일 | 포함 이유 | 현재 작성 이력 |
| --- | --- | --- |
| [Client/Bin/ShaderFiles/Shader_ScreenFx.hlsl](../Client/Bin/ShaderFiles/Shader_ScreenFx.hlsl) | 공유 형식·공동 코드 | 본인·팀원 공동 기록 |
| [Client/Private/CA_ScreenFx.cpp](../Client/Private/CA_ScreenFx.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Private/ClientScreenFxManager.cpp](../Client/Private/ClientScreenFxManager.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Private/Distortion_ScreenFx.cpp](../Client/Private/Distortion_ScreenFx.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Private/Flash_ScreenFx.cpp](../Client/Private/Flash_ScreenFx.cpp) | 담당 기능과 공동 편집 | 팀원 코드·호출 맥락 |
| [Client/Private/RadialBlur_ScreenFx.cpp](../Client/Private/RadialBlur_ScreenFx.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Private/WorldDesaturate_ScreenFx.cpp](../Client/Private/WorldDesaturate_ScreenFx.cpp) | 담당 기능과 공동 편집 | 팀원 코드·호출 맥락 |
| [Client/Public/CA_ScreenFx.h](../Client/Public/CA_ScreenFx.h) | 담당 기능과 공동 편집 | 본인으로 기록 |
| [Client/Public/ClientScreenFxManager.h](../Client/Public/ClientScreenFxManager.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Public/Distortion_ScreenFx.h](../Client/Public/Distortion_ScreenFx.h) | 담당 기능과 공동 편집 | 본인으로 기록 |
| [Client/Public/Flash_ScreenFx.h](../Client/Public/Flash_ScreenFx.h) | 담당 기능과 공동 편집 | 팀원 코드·호출 맥락 |
| [Client/Public/RadialBlur_ScreenFx.h](../Client/Public/RadialBlur_ScreenFx.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Client/Public/WorldDesaturate_ScreenFx.h](../Client/Public/WorldDesaturate_ScreenFx.h) | 담당 기능과 공동 편집 | 팀원 코드·호출 맥락 |
| [Engine/Private/ScreenFx_Instance.cpp](../Engine/Private/ScreenFx_Instance.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Engine/Private/ScreenFx_Manager.cpp](../Engine/Private/ScreenFx_Manager.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [Engine/Public/ScreenFx_Instance.h](../Engine/Public/ScreenFx_Instance.h) | 담당 기능과 공동 편집 | 본인으로 기록 |
| [Engine/Public/ScreenFx_Manager.h](../Engine/Public/ScreenFx_Manager.h) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [MainEditor/Private/ScreenFx_View.cpp](../MainEditor/Private/ScreenFx_View.cpp) | 담당 기능과 공동 편집 | 본인·팀원 공동 기록 |
| [MainEditor/Public/ScreenFx_View.h](../MainEditor/Public/ScreenFx_View.h) | 담당 기능과 공동 편집 | 본인으로 기록 |

## Morph 실험

Morph 변환·데이터 처리의 실험과 연결. FacialAnimationModifier·AnimComputeRuntime은 공동 코드이며 최종 Facial 전체의 단독 구현·실행 검증을 주장하지 않습니다.

| 파일 | 포함 이유 | 현재 작성 이력 |
| --- | --- | --- |
| [Engine/Bin/ShaderFiles/Compute/Shader_Compute_MorphDeform.hlsl](../Engine/Bin/ShaderFiles/Compute/Shader_Compute_MorphDeform.hlsl) | 실험용 형식·셰이더 | 본인으로 기록 |
| [Engine/Private/AnimComputeRuntime.cpp](../Engine/Private/AnimComputeRuntime.cpp) | 실험·공동 런타임 | 본인·팀원 공동 기록 |
| [Engine/Private/FacialAnimationModifier.cpp](../Engine/Private/FacialAnimationModifier.cpp) | 실험·공동 런타임 | 본인·팀원 공동 기록 |
| [Engine/Private/ModelDeform.cpp](../Engine/Private/ModelDeform.cpp) | 실험·공동 런타임 | 본인으로 기록 |
| [Engine/Public/AnimCompute_Types.h](../Engine/Public/AnimCompute_Types.h) | 실험용 형식·셰이더 | 본인·팀원 공동 기록 |
| [Engine/Public/AnimComputeRuntime.h](../Engine/Public/AnimComputeRuntime.h) | 실험·공동 런타임 | 본인·팀원 공동 기록 |
| [Engine/Public/FacialAnimationModifier.h](../Engine/Public/FacialAnimationModifier.h) | 실험·공동 런타임 | 본인·팀원 공동 기록 |
| [Engine/Public/ModelDeform.h](../Engine/Public/ModelDeform.h) | 실험·공동 런타임 | 본인으로 기록 |
| [ModelEditor/Private/GltfMorphBuilder.cpp](../ModelEditor/Private/GltfMorphBuilder.cpp) | 실험 코드 | 본인으로 기록 |
| [ModelEditor/Public/GltfMorphBuilder.h](../ModelEditor/Public/GltfMorphBuilder.h) | 실험 코드 | 본인으로 기록 |

## 포함하지 않은 코드

공통 렌더러·디바이스·GameInstance 전체, 외부 라이브러리 구현, 게임 리소스와 원본 이력은 제외했습니다. IK 초기 코드, 전투 시스템 전체와 초기 설계에서 확장된 팀원 구현도 대표 기여에 넣지 않았습니다. 코드에 참조되는 헤더가 모두 제공되지는 않습니다.

[source-manifest.json](../source-manifest.json)은 파일별 주제·포함 이유, 작성자별 잔존 라인 수, 본인 변경 커밋, 원본 blob 및 SHA-256을 기록합니다. 잔존 라인 수와 변경량은 기여도·완성도 점수가 아닙니다.
