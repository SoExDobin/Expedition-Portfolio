// Portfolio excerpt: selected functions only; not a complete translation unit.
// Original file: Client/Private/MapAdapter.cpp
// Snapshot: 6af96f1b15b987af897bc12c479ee0544b3d425d
// Team-owned or mixed-author functions are omitted.

// Original lines 709-721 | MapAdapter::ResolveMapModelPath
string MapAdapter::ResolveMapModelPath(const string& modelFolder, const string& modelPathStr)
{
    const fs::path modelPath(modelPathStr);
    const string directPathA = MakeMapResourcePathString(modelPath);
    if (fs::exists(fs::path(directPathA)))
        return directPathA;

    const string folderPathA = MakeMapResourcePathString(fs::path(modelFolder) / modelPath);
    if (fs::exists(fs::path(folderPathA)))
        return folderPathA;

    return modelPath.has_parent_path() ? directPathA : folderPathA;
}

// Original lines 759-792 | MapAdapter::AppendModelOverrides
void MapAdapter::AppendModelOverrides(const json& mapData, unordered_map<string, ModelOverrideEntry>& outOverrides)
{
    if (!mapData.contains("ModelOverrides") || !mapData["ModelOverrides"].is_object())
        return;

    for (auto& [filename, entry] : mapData["ModelOverrides"].items())
    {
        if (!entry.is_object())
            continue;

        ModelOverrideEntry overrideEntry;
        AppendMaterialBindingsFromSavedOverride(entry, overrideEntry);
        AppendLegacyPassToMaterialBindings(entry, overrideEntry);

        if (entry.contains("TextureSlots") && entry["TextureSlots"].is_object())
        {
            for (auto& [slotStr, texPath] : entry["TextureSlots"].items())
            {
                if (!texPath.is_string())
                    continue;

                try
                {
                    overrideEntry.textureSlots[stoi(slotStr)] = texPath.get<string>();
                }
                catch (...)
                {
                }
            }
        }

        outOverrides[filename] = overrideEntry;
    }
}

// Original lines 794-812 | MapAdapter::TryAppendModelOverridesFromJsonFile
void MapAdapter::TryAppendModelOverridesFromJsonFile(const fs::path& jsonPath, unordered_map<string, ModelOverrideEntry>& outOverrides)
{
    if (jsonPath.empty() || !fs::exists(jsonPath) || !fs::is_regular_file(jsonPath))
        return;

    ifstream ifs(jsonPath);
    if (!ifs.is_open())
        return;

    try
    {
        json root = json::parse(ifs);
        if (root.contains("MapData") && root["MapData"].is_object())
            AppendModelOverrides(root["MapData"], outOverrides);
    }
    catch (...)
    {
    }
}

// Original lines 814-820 | MapAdapter::AppendModelOverridesFromMaterialMapName
void MapAdapter::AppendModelOverridesFromMaterialMapName(const string& mapName, unordered_map<string, ModelOverrideEntry>& outOverrides)
{
    if (mapName.empty())
        return;

    AppendModelOverridesFromMaterialDirectory(MaterialResourceRootPath() / mapName, outOverrides);
}

// Original lines 822-848 | MapAdapter::AppendModelOverridesFromMaterialDirectory
void MapAdapter::AppendModelOverridesFromMaterialDirectory(const fs::path& materialDir, unordered_map<string, ModelOverrideEntry>& outOverrides)
{
    if (materialDir.empty() || !fs::exists(materialDir) || !fs::is_directory(materialDir))
        return;

    for (const fs::directory_entry& entry : fs::directory_iterator(materialDir))
    {
        if (!entry.is_regular_file() || entry.path().extension() != ".json")
            continue;

        ifstream ifs(entry.path());
        if (!ifs.is_open())
            continue;

        try
        {
            json root = json::parse(ifs);
            if (TryAppendModelOverrideFromV2MaterialJson(root, entry.path(), outOverrides))
                continue;

            (void)TryAppendModelOverrideFromLegacyMaterialJson(root, entry.path(), outOverrides);
        }
        catch (...)
        {
        }
    }
}

// Original lines 850-867 | MapAdapter::BuildMaterialApplyDesc
MapAdapter::MaterialApplyDesc MapAdapter::BuildMaterialApplyDesc(
    const string& modelFolder,
    const string& modelFullPath,
    const ModelOverrideEntry* overrideEntry)
{
    MaterialApplyDesc desc{};
    desc.modelFolder = modelFolder;
    desc.modelFullPath = modelFullPath;
    desc.mapResourceRoot = kMapResourceRoot;

    if (overrideEntry == nullptr)
        return desc;

    desc.overrideView.hasOverride = true;
    desc.overrideView.textureSlots = &overrideEntry->textureSlots;
    desc.overrideView.modelJson = &overrideEntry->modelJson;
    return desc;
}

// Original lines 869-882 | MapAdapter::ApplyMaterial
void MapAdapter::ApplyMaterial(ModelCom& model, const MaterialApplyDesc& desc)
{
    if (desc.modelFolder.empty())
        return;

    const string modelStem = fs::path(desc.modelFullPath).stem().string();
    const string bundleKey = ResolveBundleKey(desc);
    const vector<MaterialSlotBinding> bindings = LoadSidecarStaticMaterials(desc.modelFullPath);

    ApplyBaseBindings(model, bundleKey, bindings);
    LogBaseMaterialMatch(modelStem, bundleKey, bindings.size(), desc.overrideView);
    ApplyLegacyTextureOverrides(model, desc);
    ApplyRuntimeMaterialBindings(model, modelStem, bundleKey, desc.overrideView);
}