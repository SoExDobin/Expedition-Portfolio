# 맵 에디터의 설정을 Client까지 가져오기

## 문제

셰이더 수정 때마다 에디터 기능도 맞춰야 했습니다. 반대로 맵에 새 기능이나 텍스처가 필요하면 셰이더와 에디터 양쪽을 수정해야 했습니다. 전체 셰이더 구성을 파악하면서 머티리얼을 설정하기 어려웠고, 에디터 작업물을 그대로 게임에 가져올 수 있는 공통 경로가 필요했습니다.

## 작업 과정과 AI 활용

맵·셰이더 담당자가 전달한 문제점과 인수인계 내용을 바탕으로 AI를 활용해 두 코드의 구성을 분석했습니다. 셰이더의 머티리얼 기능을 에디터에서도 설정하고 확인하도록 연결했습니다. 커스텀 데이터는 JSON으로 분리하고 Client의 맵 적용 파이프라인에서 읽도록 구성했습니다.

이 과정은 2026-10-19 본인 회고와 코드·커밋 기록을 근거로 정리했습니다. 당시 사용한 AI 도구명, 실제 요청 원문, 답변별 채택·수정 내역은 확보하지 못했습니다. 구체적인 검수 장면이나 시간 절감 수치를 새로 만들어 넣지 않았습니다.

## 코드를 따라가는 순서

| 단계 | 확인할 코드 | 읽을 내용 |
| --- | --- | --- |
| 머티리얼 편집 | [PanelModelOverride](../MapEditor/Private/PanelModelOverride.cpp) | 모델별 머티리얼 바인딩·오버라이드 편집 |
| 에디터 저장·로드 | [SceneContext](../MapEditor/Private/SceneContext.cpp) | Static/Instanced 분할 맵 데이터와 모델별 설정의 입출력 |
| 에디터 적용 경로 | [MEMaterialApplicator](../MapEditor/Private/MEMaterialApplicator.cpp) | 오브젝트에 머티리얼 설정을 반영하는 공동 코드 |
| Client 형식 해석 | [MapAdapter](../Client/Private/MapAdapter.cpp) | 분할 맵 데이터와 머티리얼 오버라이드를 Client 형식으로 연결 |
| 게임 측 로드 | [MapLoader](../Client/Private/MapLoader.cpp) | SplitMapInstanceData 소비, Static/Instanced와 모델별 설정 적용 |
| 충돌 분리 | [MapCollisionAdapter](../Client/Private/MapCollisionAdapter.cpp) | 충돌 정보·캐시와 런타임 컨텍스트 연결 |

## 개인 구현과 공동 코드

관련 본인 커밋으로 `8a68c6139`(분할 모델 JSON), `d7033427c`(커스텀 모델 파이프라인), `ddc5f153e`(충돌 데이터 분리·Legacy pass 제거), `e105fcddc`(저장 방식 보정)가 있습니다. 파일별 전체 커밋 식별자는 [manifest](../source-manifest.json)에 남겼습니다.

맵 에디터와 셰이더 전체를 개인이 제작한 것은 아닙니다. SceneContext·PanelModelOverride·MapLoader 등은 팀원이 수정한 내용도 포함합니다. 이 파일들은 연결을 읽을 수 있도록 온전한 형태로 두고 [기여 범위](CONTRIBUTIONS.md)에서 공동 작업임을 표시했습니다. 팀 셰이더 전체나 원본 게임 리소스는 포함하지 않았습니다.

## 결과와 한계

에디터의 커스텀 설정을 저장하고 Client가 소비하는 구현 경로를 확인할 수 있습니다. 이후 추가되는 모든 셰이더 기능이 자동 지원되는 구조라는 뜻은 아닙니다. 같은 오브젝트의 Editor 설정·JSON 필드·Client 결과를 나란히 보여주는 비교 자료와 실제 작업 당시 AI 대화는 추가로 확보할 자료입니다. 이번 정리에서 게임을 새로 실행해 결과를 재검증하지는 않았습니다.
