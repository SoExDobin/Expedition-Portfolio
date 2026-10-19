// Portfolio excerpt: selected functions only; not a complete translation unit.
// Original file: Engine/Private/AnimState_Parser.cpp
// Snapshot: 6af96f1b15b987af897bc12c479ee0544b3d425d
// Team-owned or mixed-author functions are omitted.

// Original lines 253-291 | AnimState_Parser::Save_StateAnimations_ToFile
bool AnimState_Parser::Save_StateAnimations_ToFile(
    const wstring& savePath,
    const string& enumTypeName,
    const string& prefabName,
    const vector<string>& stateNames,
    const vector<int32>& stateIndices,
    const unordered_map<string, string>& animationMapping)
{
    if (savePath.empty())
        return false;
    json root;
    root["EnumType"] = enumTypeName;
    // 최상위 Prefab 기준 저장 (ModelGuid 미저장)
    if (!prefabName.empty())
    {
        root["PrefabName"] = prefabName;
        string guid = Get_PrefabGuid(prefabName);
        if (!guid.empty())
            root["PrefabGuid"] = guid;
    }
    json mappings = json::array();
    for (size_t i = 0; i < stateNames.size(); ++i)
    {
        const auto it = animationMapping.find(stateNames[i]);
        if (it == animationMapping.end() || it->second.empty())
            continue;
        json entry;
        entry["Index"] = stateIndices[i];
        entry["State"] = stateNames[i];
        entry["Anim"] = it->second;
        mappings.push_back(entry);
    }
    root["Mappings"] = mappings;
    std::ofstream file(savePath);
    if (!file.is_open())
        return false;
    file << std::setw(4) << root << std::endl;
    return true;
}