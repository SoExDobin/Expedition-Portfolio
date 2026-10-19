# Expedition 158 — 모델·애니메이션 및 에디터 통합

C++20 / DirectX 11 팀 프로젝트에서 담당한 모델 변환, 보조 애니메이션과 맵 데이터 통합 코드를 정리했습니다. 《Clair Obscur: Expedition 33》을 학습 목적으로 재현한 팀 프로젝트입니다.

- **[발표 영상 — YouTube](https://www.youtube.com/watch?v=iG57KTDhf0o&list=PLB_KDWv0W5Qo&index=5)**
- **[상세 포트폴리오](https://app.notion.com/p/Expedition158-3d1f59d27d7180fe9e23f887cd6aeb10)**
- [담당 범위와 공동 작업](docs/CONTRIBUTIONS.md) · [코드 읽는 순서](docs/CODE_GUIDE.md) · [맵 통합과 AI 활용](docs/MAP_INTEGRATION.md)

함수만 떼어 놓으면 에디터와 런타임의 연결을 읽기 어려워, 원본 폴더 구조와 클래스의 헤더·구현을 유지했습니다. 담당 코드와 흐름을 설명하는 데 필요한 공동 작성·주변 코드를 포함했습니다. 파일 전체를 개인이 작성했다는 의미는 아니며, 구분과 근거는 [기여 범위](docs/CONTRIBUTIONS.md)에 적었습니다.

## 담당한 작업

| 분야 | 구현·연결한 내용 | 시작할 코드 |
| --- | --- | --- |
| 모델 변환·확인 도구 | 메시·본·애니메이션을 엔진용 데이터로 변환하고, 뷰어에서 확인하는 ModelEditor 흐름 | [ModelConverter](ModelEditor/Private/ModelConverter.cpp), [ModelViewerObject](ModelEditor/Private/ModelViewerObject.cpp) |
| 애니메이션·월드 액션 연결 | 상태 매핑과 파쿠르 관련 코드. Root Motion·로프·그래플링·FreeAim 연결은 호출 흐름을 읽는 보조 자료 | [AnimState_Parser](Engine/Private/AnimState_Parser.cpp), [Player_State](Client/Private/Player_State.cpp), [Player_GrappleAction](Client/Private/Player_GrappleAction.cpp) |
| 보조 애니메이션 | 공통 Modifier 평가, Chain·Physics 보정, Offset 애니메이션 적용 | [AnimationModifier](Engine/Public/AnimationModifier.h), [PhysicsModifier](Engine/Private/PhysicsModifier.cpp), [OffsetAnimationModifier](Engine/Private/OffsetAnimationModifier.cpp) |
| 맵 에디터–Client 통합 | 모델별 머티리얼 편집, 분할 JSON 저장·로드, 맵·충돌 어댑터 연결 | [PanelModelOverride](MapEditor/Private/PanelModelOverride.cpp), [SceneContext](MapEditor/Private/SceneContext.cpp), [MapAdapter](Client/Private/MapAdapter.cpp) |
| ScreenFx | 인스턴스·관리자·편집 뷰, 화면 효과 셰이더와 Client 적용 | [ScreenFx_Manager](Engine/Private/ScreenFx_Manager.cpp), [ClientScreenFxManager](Client/Private/ClientScreenFxManager.cpp), [Shader_ScreenFx](Client/Bin/ShaderFiles/Shader_ScreenFx.hlsl) |

## 시스템 연결

```text
모델·애니메이션 입력
  → ModelEditor / ModelConverter
  → 엔진용 모델·애니메이션 데이터
  → ModelCom · Animation · Channel
      ├─ AnimState_Parser ↔ MainEditor / AnimState_View
      ├─ AnimationModifier → Chain / Physics / Offset
      └─ Player_State → Parkour / Rope / Grapple / FreeAim

MapEditor / PanelModelOverride · SceneContext
  → 분할 맵 JSON · 모델별 머티리얼 설정
  → Client / MapAdapter · MapLoader · MapCollisionAdapter
  → Static / Instanced Mesh와 충돌 데이터 적용

MainEditor / ScreenFx_View
  → ScreenFx_Instance · ScreenFx_Manager
  → ClientScreenFxManager · 효과별 구현 · Shader_ScreenFx
```

역할을 따라 읽기 위한 요약입니다. 런타임과 도구는 팀 엔진의 타입·리소스·렌더러에 의존합니다. 추가로 확인한 FreeAim·로프·그래플링·Root Motion 연결을 별도의 핵심 구현 사례로 내세우지는 않습니다. 전체 엔진 설계나 플레이어 시스템 전체를 개인 제작으로 제시하지 않습니다.

## 폴더 구성

| 경로 | 포함한 내용 |
| --- | --- |
| [ModelEditor](ModelEditor) | 변환기·뷰어·검수 패널과 이를 띄우는 툴 코드 |
| [Engine/Public](Engine/Public), [Engine/Private](Engine/Private) | 모델·애니메이션 런타임, 상태 파서, Modifier, ScreenFx |
| [MainEditor](MainEditor) | 애니메이션·상태 매핑·모델 검사·ScreenFx 편집 화면. 공동 작성 파일의 주변 기능도 원본 그대로 포함 |
| [MapEditor](MapEditor) | 머티리얼 오버라이드 편집, SceneContext 입출력과 관련 적용 코드 |
| [Client](Client) | 월드 액션, 맵 로더·어댑터, ScreenFx 적용 및 관련 셰이더 |
| [docs](docs) | 읽는 순서, 개인·공동 기여 구분, 통합 과정과 문제 해결 근거 |

## 맵 통합에서 AI를 사용한 부분

셰이더 기능이 바뀌면 에디터도 맞춰야 했고, 맵에 새 기능이나 텍스처가 필요할 때도 양쪽 수정이 필요했습니다. 담당자들의 문제 설명과 인수인계 내용을 바탕으로 AI를 활용해 맵 에디터와 셰이더 코드를 분석했습니다. 머티리얼 기능을 에디터에서 설정·확인하고, 커스텀 설정을 JSON으로 분리해 Client가 같은 데이터를 적용하도록 연결했습니다.

[맵 통합 기록](docs/MAP_INTEGRATION.md)에서는 이 작업의 문제 상황과 코드 경로를 설명합니다. 도구명·요청 원문·답변별 채택/수정 기록은 확보되지 않았으므로 재구성하지 않았습니다. 이 저장소를 정리하며 만든 문서는 당시의 AI 대화 기록이 아닙니다.

## 실험 및 보조 작업

[Morph 변환·런타임 연결](docs/EXPERIMENTS.md)은 시도와 한계를 함께 정리했습니다. 최종 Facial 런타임 전체를 개인 구현으로 제시하지 않습니다.

## 공개 범위와 기준 버전

- 기준: 원본 기본 브랜치 `dev`의 2차 녹화 버전, `743f2a13ba350eadd2858541ff264eeeee095597` (2026-08-02).
- 전체 파일을 원본 경로에 두었습니다. 공동 작성 파일은 [기여 범위](docs/CONTRIBUTIONS.md)와 [manifest](source-manifest.json)에 표시했습니다. Git 작성 이력은 담당 범위를 확인하는 근거이며, 단독 창작이나 권리 보유를 증명하지는 않습니다.
- 모델·텍스처·음원·애니메이션·게임 데이터 등의 리소스, SDK·외부 라이브러리 구현, 빌드 파일·바이너리, 원본 Git 이력은 제외했습니다. 셰이더는 구현 소스만 포함했습니다.
- 코드에 남은 자산명·경로 문자열에 해당하는 파일은 제공하지 않습니다. 영상은 팀 결과를 포함하므로 개인 담당 범위는 본문과 코드 설명을 함께 봐 주세요.
- **이 저장소만으로 빌드·실행할 수 없습니다.** 목적은 담당 시스템과 툴·런타임 연결을 읽는 것입니다. 이번 정리에서 게임을 새로 빌드하거나 실행 검증하지 않았습니다.

원작 자산·팀 공통 코드·타인의 기여를 포괄하는 오픈소스 라이선스는 부여하지 않습니다.
