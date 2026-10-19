# Expedition 33 — 담당 코드 포트폴리오

C++20 / DirectX 11 팀 프로젝트에서 맡은 모델·애니메이션, 월드 상호작용과 맵 데이터 통합 코드를 골라 정리했습니다. 《Clair Obscur: Expedition 33》을 학습 목적으로 재현한 프로젝트이며 원작 제작 참여 이력이 아닙니다.

- [상세 포트폴리오](https://app.notion.com/p/Expedition158-3d1f59d27d7180fe9e23f887cd6aeb10)
- [YouTube 발표 영상](https://www.youtube.com/watch?v=iG57KTDhf0o&list=PLB_KDWv0W5Qo&index=5)
- [코드 읽는 순서](docs/CODE_GUIDE.md)
- [AI를 활용한 맵·셰이더 통합](docs/MAP_INTEGRATION.md)

## 무엇을 볼 수 있나요?

| 분야 | 확인할 내용 | 코드 |
| --- | --- | --- |
| 리소스 파이프라인 | 모델·애니메이션 변환과 모델 확인 도구 | [Model Editor](code/01-model-pipeline) |
| 캐릭터 동작 | 애니메이션 상태 데이터, 파쿠르·로프 액션 | [Character / World](code/02-character-world) |
| 보조 애니메이션 | 공통 Modifier, ChainModifier·PhysicsModifier | [Animation Modifier](code/03-animation-modifier) |
| 맵 통합 | 에디터 저장과 Client 어댑터·로더의 연결 | [Map integration](code/04-map-integration) |
| 화면 효과 | ScreenFx 인스턴스·뷰어·관리 코드 일부 | [Screen FX](code/05-screen-fx) |

## 공개 범위

원본 작업 브랜치의 커밋 `6af96f1b15b987af897bc12c479ee0544b3d425d`를 기준으로 추렸습니다. Git blame에서 SoExDobin으로 기록된 전체 파일 또는 함수만 담았습니다. 여러 작성자의 코드가 섞인 함수와 팀 공통 엔진·셰이더는 제외했습니다. Git 기록은 작성 이력을 확인하는 근거이며 모든 코드의 독자적 창작 여부를 증명하지는 않습니다.

`*.excerpt.cpp`는 원본 파일의 선택된 함수이며 독립된 번역 단위가 아닙니다. 각 함수 앞에 원본 경로·라인을 표시했고, [manifest](source-manifest.json)에 범위와 원본 blob 식별자를 기록했습니다. 원본 Git 이력은 가져오지 않았습니다.

리소스, 텍스처, 모델, 애니메이션 파일, 사운드, 게임 데이터, 바이너리, SDK와 외부 라이브러리 구현은 포함하지 않았습니다. 일부 원본 코드의 게임 객체명이나 리소스 경로 문자열은 코드 맥락으로 남아 있으나 해당 자산은 제공하지 않습니다. 의존하는 팀 엔진과 리소스가 없으므로 이 저장소만으로 빌드·실행할 수 없습니다. 함수와 데이터 흐름을 읽는 포트폴리오입니다.

빌드나 최신 실행 검증을 완료했다는 의미는 아닙니다. 발표 영상은 팀 결과를 포함하며, 이 저장소의 파일 범위가 개인 기여의 근거입니다. 원작 자산과 타인의 권리를 포괄하는 오픈소스 라이선스는 부여하지 않습니다.
