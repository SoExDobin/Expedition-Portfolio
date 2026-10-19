# 코드 읽는 순서

## 1. 변환기에서 런타임까지

1. [ModelConverter.h](../ModelEditor/Public/ModelConverter.h) → [구현](../ModelEditor/Private/ModelConverter.cpp): `Convert_Model`, `BuildBoneHierarchy`, `ReadMeshes`, `ReadAnimations`과 Export 함수에서 입력을 엔진 데이터로 내보내는 흐름을 봅니다.
2. [ModelViewerObject](../ModelEditor/Private/ModelViewerObject.cpp)와 [ModelTestPanel](../ModelEditor/Private/ModelTestPanel.cpp): 변환 결과를 도구에서 확인하는 경로입니다.
3. [Animation](../Engine/Private/Animation.cpp), [Channel](../Engine/Private/Channel.cpp), [ModelCom](../Engine/Private/ModelCom.cpp): 애니메이션 채널 평가, Root Translation 조회와 모델의 재생·Modifier 적용을 연결해 봅니다. 공동 런타임입니다.

## 2. 상태 매핑과 월드 액션

1. [AnimState_Parser](../Engine/Private/AnimState_Parser.cpp)의 `Load_StateAnimations`/`Save_StateAnimations_ToFile`과 [AnimState_View](../MainEditor/Private/AnimState_View.cpp): 프리팹 GUID·클래스와 애니메이션 상태의 매핑을 읽습니다.
2. [Player_State](../Client/Private/Player_State.cpp) → [Player_ParkourAction](../Client/Private/Player_ParkourAction.cpp): 상태와 Root Motion을 연결하는 곳을 봅니다.
3. [WorldUpDownRopeSpot](../Client/Private/WorldUpDownRopeSpot.cpp) → [Player_RopeAction](../Client/Private/Player_RopeAction.cpp): 상호작용 요청과 실제 로프 액션을 함께 봅니다.
4. [WorldGrapplingRopeSpot](../Client/Private/WorldGrapplingRopeSpot.cpp) → [Player_GrappleAction](../Client/Private/Player_GrappleAction.cpp): 타깃 요청, 방향 보간과 이동 액션을 읽습니다.
5. [Player_FreeAim](../Client/Private/Player_FreeAim.cpp)의 `Bind_AnimationModifiers` → [OffsetAnimationModifier](../Engine/Private/OffsetAnimationModifier.cpp): `AimOffset` 및 방향별 걷기 태그와 보정 애니메이션의 연결입니다. IK 적용 경로로 설명하지 않습니다.

## 3. Modifier의 평가와 적용

[AnimationModifier](../Engine/Public/AnimationModifier.h) → [ChainModifier](../Engine/Private/ChainModifier.cpp) / [PhysicsModifier](../Engine/Private/PhysicsModifier.cpp) → [ModelCom](../Engine/Private/ModelCom.cpp)의 `Evaluate_AnimationModifiers` 순서로 읽습니다. 파생 클래스가 모델 포즈를 보정하고 공통 평가 루프에서 실행되는 구조입니다. [ModelPhysicsParser](../Engine/Private/ModelPhysicsParser.cpp)는 JSON의 캡슐 정보를 읽는 부분입니다. 공개본에 실제 캐릭터 프리셋·충돌 리소스는 없습니다.

## 4. 에디터 저장 형식과 Client의 소비 경로

[PanelModelOverride](../MapEditor/Private/PanelModelOverride.cpp) → [SceneContext](../MapEditor/Private/SceneContext.cpp)의 `SaveToFile`/`LoadFromFile` → [MapAdapter](../Client/Private/MapAdapter.cpp) → [MapLoader](../Client/Private/MapLoader.cpp) 및 [MapCollisionAdapter](../Client/Private/MapCollisionAdapter.cpp)를 따라갑니다. 상세 문제와 AI 활용 범위는 [맵 통합 기록](MAP_INTEGRATION.md)에 있습니다.

## 5. ScreenFx 편집과 Client 적용

[ScreenFx_View](../MainEditor/Private/ScreenFx_View.cpp) → [ScreenFx_Instance](../Engine/Private/ScreenFx_Instance.cpp) / [ScreenFx_Manager](../Engine/Private/ScreenFx_Manager.cpp) → [ClientScreenFxManager](../Client/Private/ClientScreenFxManager.cpp)와 [효과 셰이더](../Client/Bin/ShaderFiles/Shader_ScreenFx.hlsl)를 봅니다. [통합 시 수정한 문제](SCREENFX_NOTES.md)를 함께 적었습니다. 팀 렌더러의 전체 RT/MRT 구성은 포함하지 않았습니다.

## 검증 범위

정리 시점에 원본 스냅샷과 파일 해시·UTF-8, 공개 파일 목록과 문서 링크를 확인했습니다. 게임의 새 빌드·실행, 물리 시뮬레이션의 안정성, 영상 전체 재생·자막 싱크 검증은 수행하지 않았습니다. 발표 영상과 현재 코드가 모든 프레임에서 일치한다고 주장하지 않습니다.
