# C++📜

## 파일 분할 📚

- 각각의 클래스마다 **선언은 `.h`**, **정의는 `.cpp`** 파일에 저장하여 소스코드의 유지보수성을 높이기 위한 수단

- 프로젝트를 시작시에 파일 분할원칙과 구조에 따라 이를 따라, 파일을 분할해야한다.

- .h파일 예제

  ```
  #ifndef Calculator_h
  #define Calculator_h

  class Basic(){
    private:
      int a;
      int b;

    public:
      Basic();
      ~Basic();
      void Add(int n1,int n2);
  };

  #endif
  ```

- .cpp파일 예제

  ```cpp
  #include <iostream>
  #include "Calculator.h"

  Basic::Basic(){
    //정의
  }

  Basic::~Basic(){
    //정의
  }

  void Basic::Add(int n1, int n2){
    return n1+n2;
  }
  ```

## Build Process(Compiler)

- preprocesser -> trnaslation unit

- compiler -> obj

- linker -> exe
