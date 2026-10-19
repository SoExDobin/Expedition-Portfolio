// Portfolio excerpt: selected functions only; not a complete translation unit.
// Original file: Client/Private/Player_ParkourAction.cpp
// Snapshot: 6af96f1b15b987af897bc12c479ee0544b3d425d
// Team-owned or mixed-author functions are omitted.

// Original lines 252-258 | Player_ParkourAction::Build_ParkourRequest
bool Player_ParkourAction::Build_ParkourRequest(ParkourActionType actionType, ParkourMoveRequest& outRequest) const
{
    if (actionType == ParkourActionType::LowMantle)
        return Build_LowParkourRequest(outRequest);

    return Build_HighParkourRequest(outRequest);
}

// Original lines 383-392 | Player_ParkourAction::Is_EnvironmentHit
bool Player_ParkourAction::Is_EnvironmentHit(const PhysXQueryHit& hit) const
{
    if (!hit.hit)
        return false;

    if (hit.collider != nullptr)
        return hit.collider->Get_Channel() == Collision_Channel::Environment;

    return hit.staticHandle.Is_Valid();
}

// Original lines 394-407 | Player_ParkourAction::Try_PrepareAction
bool Player_ParkourAction::Try_PrepareAction(ParkourActionType actionType)
{
    _hasPreparedRequest = false;

    ParkourMoveRequest request{};
    if (!Build_ParkourRequest(actionType, request))
    {
        return false;
    }

    _request = request;
    _hasPreparedRequest = true;
    return true;
}

// Original lines 414-425 | Player_ParkourAction::Create
Shared<Player_ParkourAction> Player_ParkourAction::Create(const Shared<Player_WorldBase>& owner)
{
    auto instance = make_shared<Player_ParkourAction>(owner);

    if (FAILED(instance->Initialize()))
    {
        LOG_ERROR("[PLAYER PARKOUR ACTION] : Failed to Create State");
        return nullptr;
    }

    return instance;
}