# Morph 변환과 Facial 연결 시도

[GltfMorphBuilder](../ModelEditor/Private/GltfMorphBuilder.cpp)에서 glTF/GLB 입력을 읽고 Morph 데이터를 매칭·출력하는 흐름을 구현했습니다. [ModelDeform](../Engine/Private/ModelDeform.cpp)은 Morph 데이터와 weight를 관리합니다. 런타임 연결을 읽기 위해 공동 작성된 [AnimComputeRuntime](../Engine/Private/AnimComputeRuntime.cpp), [FacialAnimationModifier](../Engine/Private/FacialAnimationModifier.cpp)도 포함했습니다.

2026-06-10 커밋 `ce928a3ee`에는 정점 기반 접근의 실패와 본 기반 접근 추가가 함께 기록돼 있습니다. 변환 코드가 있다는 사실과 최종 표정 런타임의 완성은 구분해야 합니다. 최종 FacialAnimationModifier와 compute 런타임 전체를 개인 제작으로 제시하지 않습니다. 원본 표정 데이터·모델·애니메이션은 제외했고, 이번에 새 실행 검증을 하지 않았습니다.

이 문서는 실패 경로와 구현 범위를 설명하는 보조 자료입니다. 대표 완성 기능·성능 개선 사례로 제시하지 않습니다.
