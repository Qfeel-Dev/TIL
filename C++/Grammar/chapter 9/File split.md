# C++π

## νμΌ λΆν  π

- κ°κ°μ ν΄λμ€λ§λ€ **μ μΈμ `.h`**, **μ μλ `.cpp`** νμΌμ μ μ₯νμ¬ μμ€μ½λμ μ μ§λ³΄μμ±μ λμ΄κΈ° μν μλ¨

- νλ‘μ νΈλ₯Ό μμμμ νμΌ λΆν μμΉκ³Ό κ΅¬μ‘°μ λ°λΌ μ΄λ₯Ό λ°λΌ, νμΌμ λΆν ν΄μΌνλ€.

- .hνμΌ μμ 

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

- .cppνμΌ μμ 

  ```cpp
  #include <iostream>
  #include "Calculator.h"

  Basic::Basic(){
    //μ μ
  }

  Basic::~Basic(){
    //μ μ
  }

  void Basic::Add(int n1, int n2){
    return n1+n2;
  }
  ```

## Build Process(Compiler)

- preprocesser -> trnaslation unit

- compiler -> obj

- linker -> exe
