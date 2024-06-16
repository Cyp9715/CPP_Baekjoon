# CPP_Baekjoon

현재까지 직접 풀어본 Baekjoon 문제들의 저장소입니다.

### > CMake
실행환경에 차별을 두고싶지 않아 CMake를 기준으로 작성되어 있습니다. 대부분의 OS에서 빌드가 가능하며, gdb 와 같은 디버거를 연동시에 디버깅 역시 가능합니다. 편의를 위해서 Visual Studio, CLion, Visual Studio Code 같이 CMake를 지원하는 환경에서 빌드-디버깅을 권장드립니다. 

```CMakeLists.txt``` 파일 내에 ```main.cpp``` 파일만 ```add_executable``` 로 지정되어 있습니다. 때문에 ```main.cpp``` 파일 생성후, 해당 파일에서 다른 파일들을 참조하여 사용하면 됩니다.

### > 주의사항
알고리즘 코드인만큼 MSVC로 작업해도 문제가 생기지 않을 가능성이 높다고 생각되나, 기본적으로 소스코드는 GCC의 C++로 작성되어 있습니다. 때문에 Windows + Visual Studio 환경에서 사용시 WSL2 와 연계하여 Linux 환경에서 실행을 권장 드립니다. Visual Studio 2022 기준 WSL2 를 완벽히 지원하기에 실행에 큰 어려움이 없으리라 생각됩니다.

### > 참고사항
각 파일은 헤더를 배제한 ```.cpp``` 파일로 정리되어 있습니다. 이는 Baekjoon 테스트 간 편의를 위함입니다.
