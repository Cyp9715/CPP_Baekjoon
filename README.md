# CPP_BaekJoon

현재까지 직접 풀어본 BeakJoon 문제들의 저장소입니다.  
문제별 ```.cpp``` 파일로 정리되어 있기에, ```main.cpp``` 를 통해 ```include alpha.cpp``` 형태로 참조 시, rebuild, clean 후에 다시 진행해야 하는 불편함이 있습니다. 만약 rebuild, clean 하지 않는다면 visual studio 특성상 소스코드 변경이 올바르게 적용되지 않습니다.

이는 header 파일을 통해 선언하고, cpp 파일을 통해 구현한다면 해결되는 문제이지만, hpp, cpp 를 동시에 운용하면 BeakJoon 에 소스코드를 제출하는데에 불편함이 있기에 현행 방식으로 운용합니다. 대신, 계속 수정해 가며 디버깅 해야 하는 코드가 있다면 ```main.cpp``` 에 그대로 코딩한 후, 완성본을 ```beta.cpp``` 파일로 만들어 저장하는 형태로 사용하는 것을 권장 드립니다.
