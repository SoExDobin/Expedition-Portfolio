# 코드 읽는 순서

1. ModelConverter와 ModelViewerObject에서 변환한 데이터를 확인하는 흐름을 읽습니다. 메시·본·애니메이션 변환과 자체 엔진 적용이 담당 범위이며 UE5 리타게팅 도구 자체를 구현했다는 의미는 아닙니다.
2. AnimState_Parser와 Player_RopeAction, Player_ParkourAction에서 상태 데이터와 월드 동작을 살펴봅니다.
3. AnimationModifier 인터페이스를 먼저 읽고 ChainModifier의 평가, PhysicsModifier 발췌 함수로 내려갑니다. 발표에서는 기본 포즈에 보조 움직임을 적용하는 구조를 설명합니다. OFF/ON 비교나 성능 수치는 아직 제시하지 않습니다.
4. MapCollisionAdapter와 MapAdapter·MapLoader의 발췌 함수를 읽습니다. 공동 편집된 SceneContext에서는 이번 선택 규칙에 맞는 독립 함수를 확보하지 못해 제외했습니다. 원본 로더·에디터 전체가 개인 작업인 것은 아닙니다.
5. ScreenFx 코드는 보조 사례입니다. 전체 렌더러·셰이더의 개인 제작으로 해석하지 않도록 범위를 제한했습니다.

## 파일 목록

| 원본 경로 → 공개 코드 | 포함 범위 |
| --- | --- |
| [Client/Private/MapAdapter.cpp](../code/04-map-integration/Client/Private/MapAdapter.excerpt.cpp) | 본인 함수 7개 |
| [Client/Private/MapCollisionAdapter.cpp](../code/04-map-integration/Client/Private/MapCollisionAdapter.cpp) | 전체 파일 |
| [Client/Private/MapLoader.cpp](../code/04-map-integration/Client/Private/MapLoader.excerpt.cpp) | 본인 함수 1개 |
| [Client/Private/Player_ParkourAction.cpp](../code/02-character-world/Client/Private/Player_ParkourAction.excerpt.cpp) | 본인 함수 4개 |
| [Client/Private/Player_RopeAction.cpp](../code/02-character-world/Client/Private/Player_RopeAction.cpp) | 전체 파일 |
| [Client/Public/MapCollisionAdapter.h](../code/04-map-integration/Client/Public/MapCollisionAdapter.h) | 전체 파일 |
| [Client/Public/Player_ParkourAction.h](../code/02-character-world/Client/Public/Player_ParkourAction.h) | 전체 파일 |
| [Client/Public/Player_RopeAction.h](../code/02-character-world/Client/Public/Player_RopeAction.h) | 전체 파일 |
| [Engine/Private/AnimState_Parser.cpp](../code/02-character-world/Engine/Private/AnimState_Parser.excerpt.cpp) | 본인 함수 1개 |
| [Engine/Private/AnimationModifier.cpp](../code/03-animation-modifier/Engine/Private/AnimationModifier.cpp) | 전체 파일 |
| [Engine/Private/ChainModifier.cpp](../code/03-animation-modifier/Engine/Private/ChainModifier.cpp) | 전체 파일 |
| [Engine/Private/PhysicsModifier.cpp](../code/03-animation-modifier/Engine/Private/PhysicsModifier.excerpt.cpp) | 본인 함수 31개 |
| [Engine/Private/ScreenFx_Instance.cpp](../code/05-screen-fx/Engine/Private/ScreenFx_Instance.excerpt.cpp) | 본인 함수 1개 |
| [Engine/Private/ScreenFx_Manager.cpp](../code/05-screen-fx/Engine/Private/ScreenFx_Manager.excerpt.cpp) | 본인 함수 1개 |
| [Engine/Public/AnimationModifier.h](../code/03-animation-modifier/Engine/Public/AnimationModifier.h) | 전체 파일 |
| [Engine/Public/ChainModifier.h](../code/03-animation-modifier/Engine/Public/ChainModifier.h) | 전체 파일 |
| [Engine/Public/PhysicsModifier.h](../code/03-animation-modifier/Engine/Public/PhysicsModifier.h) | 전체 파일 |
| [Engine/Public/ScreenFx_Instance.h](../code/05-screen-fx/Engine/Public/ScreenFx_Instance.h) | 전체 파일 |
| [MainEditor/Private/ScreenFx_View.cpp](../code/05-screen-fx/MainEditor/Private/ScreenFx_View.excerpt.cpp) | 본인 함수 1개 |
| [MainEditor/Public/ScreenFx_View.h](../code/05-screen-fx/MainEditor/Public/ScreenFx_View.h) | 전체 파일 |
| [ModelEditor/Private/ModelConverter.cpp](../code/01-model-pipeline/ModelEditor/Private/ModelConverter.excerpt.cpp) | 본인 함수 18개 |
| [ModelEditor/Private/ModelViewerObject.cpp](../code/01-model-pipeline/ModelEditor/Private/ModelViewerObject.excerpt.cpp) | 본인 함수 11개 |
| [ModelEditor/Public/ModelConverter.h](../code/01-model-pipeline/ModelEditor/Public/ModelConverter.h) | 전체 파일 |
| [ModelEditor/Public/ModelViewerObject.h](../code/01-model-pipeline/ModelEditor/Public/ModelViewerObject.h) | 전체 파일 |

## 생략된 의존성

Base, ModelCom, GameInstance, EditorBlock 같은 엔진 공통 타입, PCH·리플렉션 매크로, DirectX·PhysX·Assimp·ImGui 등의 의존성은 제공하지 않습니다. 함수의 상호 관계를 읽기 위한 코드이며 누락된 헤더를 대신하는 가짜 구현은 추가하지 않았습니다.

선택 규칙 때문에 일부 초기화 함수나 팀원이 수정한 함수가 생략됩니다. 발췌 파일을 완전한 클래스 구현으로 읽지 않도록 각 범위를 manifest에 기록했습니다. 원본을 복사한 파일의 BOM·한글을 보존했습니다.
