# ScreenFx 통합에서 다룬 문제

RT 복사 크기와 렌더링 순서는 효과 클래스 하나만 읽어서는 드러나지 않는 문제였습니다. 관련 수정 이력과 공개 코드 경로를 함께 적었습니다. 당시 기록을 바탕으로 정리한 문서이며, 이번에 같은 오류를 재현하거나 새 빌드를 검증한 기록은 아닙니다.

| 문제 | 수정 이력 | 공개본에서 읽을 곳 |
| --- | --- | --- |
| 렌더 타깃 복사 시 크기 불일치 | `9c03bec87`: 크기 매칭·회피 로직 | [ScreenFx_Manager](../Engine/Private/ScreenFx_Manager.cpp)의 RT 처리. 공통 Target_Manager 구현은 제외 |
| UI와 ScreenFx의 실행 순서 | `e1792bcb3`: UI 이전 렌더링 시점으로 변경 | [ClientScreenFxManager](../Client/Private/ClientScreenFxManager.cpp), [ScreenFx_Instance](../Engine/Private/ScreenFx_Instance.cpp). 팀 Renderer의 전체 호출부는 제외 |
| 효과 상태 확인 | `555a7446b`: 상태 체크 추가 | [ScreenFx_Manager](../Engine/Private/ScreenFx_Manager.cpp)와 [ClientScreenFxManager](../Client/Private/ClientScreenFxManager.cpp) |

효과 코드와 셰이더에는 팀원의 추가 구현도 포함됩니다. 전체 렌더링 파이프라인을 단독 설계했다는 의미로 읽지 않도록 [기여 범위](CONTRIBUTIONS.md)를 함께 확인해 주세요.
