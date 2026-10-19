// Portfolio excerpt: selected functions only; not a complete translation unit.
// Original file: Client/Private/MapLoader.cpp
// Snapshot: 6af96f1b15b987af897bc12c479ee0544b3d425d
// Team-owned or mixed-author functions are omitted.

// Original lines 27-38 | MapLoader::MakeCollisionRuntimeContext
MapCollisionAdapter::RuntimeContext MapLoader::MakeCollisionRuntimeContext(LoadSession& session)
{
    MapCollisionAdapter::RuntimeContext context{};
    context.globalCacheMutex = &g_globalCacheMutex;
    context.globalCollisionCache = &g_globalCollisionCache;
    context.preloadedCollisionCache = &session.preloadedCollisionCache;
    context.cookedCollisionCache = &session.cookedCollisionCache;
    context.primitiveCollisionCache = &session.primitiveCollisionCache;
    context.outBuildDuration = &session.collisionBuildDuration;
    context.outBuildCount = &session.collisionBuildCount;
    return context;
}