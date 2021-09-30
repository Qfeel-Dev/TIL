# C++📜

## 파일분할📁

- C++에서는 클래스 별로 **헤더파일(.h)**과 **소스파일(.cpp)**을 생성해서 클래스의 선언과 정의를 분리하는 경우가 많다
- 헤더파일(.h) : 클래스의 선언

  ```cpp
  #ifndef __CAR_H__//헤더파일 중복포함 문제 해결
  #define __CAR_H__

  class Car
  {
    private:
      char gamerID[20];
      int fuelGauge;
      int curSpeed;

    public:
      void InitMembers(int fuel);
  };

  #endif
  ```

- 소스파일(.cpp) : 클래스의 정의

  ```cpp
    void Car::InitMembers(int fuel){
      fuelGauge=fuel;
      curSpeed=0;
    }
  ```

- 인라인 함수의 경우 헤더파일에 정의 -> 컴파일 과정에서 함수의 호출 문이 있는 곳에 함수의 몸체 부분이 삽입되어야 하므로!

  - 인라인 함수: 컴파일러가 함수의 내용을 함수가 사용한 곳에다가 삽입하는 함수 -> inline 키워드 사용

- 작성 중 발견한 컴파일 오류
  ```
  deprecated conversion from string constant to 'char*'//추후에 알아봅시다...
  ```

## 객체지향 프로그래밍(Oriented Object Programming)🧚‍♀️

- 현실에 존재하는 사물과 대상(데이터), 그리고 그에 따른 행동(기능)을 있는 그대로 실체화 시키는 형태의 프로그래밍
- 객체는 하나 이상의 상태 정보(데이터)와 하나 이상의 행동(기능)으로 구성됨
- 객체를 생성하기에 앞서 틀을 먼저 만들어야 하는데, 이 틀이 `Class` 이다.

  ```cpp
  class Car
  {
    private://데이터 -> 멤버 변수
      char gamerID[20];
      int fuelGauge;
      int curSpeed;

    public://기능 -> 멤버 함수
      void InitMembers(int fuel);
  };
  ```

- 객체간의 대화 방법(Message Passing) : 둘 이상의 클래스를 정의하여 서로를 호출하며 데이터를 주고 받는 관계
