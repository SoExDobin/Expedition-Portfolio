// Portfolio excerpt: selected functions only; not a complete translation unit.
// Original file: Engine/Private/ScreenFx_Instance.cpp
// Snapshot: 6af96f1b15b987af897bc12c479ee0544b3d425d
// Team-owned or mixed-author functions are omitted.

// Original lines 45-50 | ScreenFx_Instance::Update_ScreenFx
void ScreenFx_Instance::Update_ScreenFx(float timeDelta)
{
    _elapsedTime += timeDelta;
    
    Evaluate_At(_elapsedTime);
}