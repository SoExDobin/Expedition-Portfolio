// Portfolio excerpt: selected functions only; not a complete translation unit.
// Original file: MainEditor/Private/ScreenFx_View.cpp
// Snapshot: 6af96f1b15b987af897bc12c479ee0544b3d425d
// Team-owned or mixed-author functions are omitted.

// Original lines 18-37 | ScreenFx_View::Update
void ScreenFx_View::Update(float timeDelta)
{
    if (_previewInstance && _isPlaying)
    {
        auto delta = ImGui::GetIO().DeltaTime * _playbackSpeed;
        _previewInstance->Set_ElapsedTime(_previewInstance->Get_ElapsedTime() + delta);
        
        if (_previewInstance->Get_ElapsedTime() >= _previewInstance->Get_Duration())
        {
            if (_autoLoop)
                _previewInstance->Set_ElapsedTime(0.f);
            else
            {
                _previewInstance->Set_ElapsedTime(_previewInstance->Get_Duration());
                _isPlaying = false;
            }
        }
        _previewInstance->Evaluate_At(_previewInstance->Get_ElapsedTime());
    }
}