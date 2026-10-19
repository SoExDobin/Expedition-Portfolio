// Portfolio excerpt: selected functions only; not a complete translation unit.
// Original file: Engine/Private/ScreenFx_Manager.cpp
// Snapshot: 6af96f1b15b987af897bc12c479ee0544b3d425d
// Team-owned or mixed-author functions are omitted.

// Original lines 111-117 | ScreenFx_Manager::Is_ScreenEffectFinished
bool ScreenFx_Manager::Is_ScreenEffectFinished(const wstring& tag) const
{
    if (tag.empty())
        return false;

    return _finishedEffectTags.contains(tag);
}