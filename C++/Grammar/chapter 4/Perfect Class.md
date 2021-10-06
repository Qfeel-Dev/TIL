# C++📜

## 정보은닉( Information Hiding)🔒

- 접근제어자+엑세스 함수를 이용하여 클래스의 멤버 변수의 안전한 접근을 독려하는 개념

  ```c++
  class Point
  {
    private://접근제어자를 사용한 멤버변수 은닉
      int x;
      int y;

    public://엑세스 함수를 이용한 안전한 접근
      int GetX() const;
      int GetY() const;
      bool SetX(int xpos);
      bool SetY(int ypos);
  };
  ```

- const함수 : 함수 내에서는 멤버변수에 저장된 값을 변경하지 않겠다.

  ```cpp
  Point::GetX() const{
    return return x;
  }
  ```

- 작성 중 발견한 컴파일 오류
  ```cpp
  ld returned 1 exit status
  /*링커가 정상 종료되지않았을 때 나타나는 오류*/
  ```

## 캡슐화(Encapsulation)💊

- 프로그램 복잡도 감소를 위해 관련있는 함수와 변수들을 하나의 클래스에 묶어버리는 작업

- 캡슐화의 범위를 결정하기 위해선 구체적인 정보와 가정이 필요- 캡슐화가 어려운 개념인 이유

  ```cpp
  class SinivelCap{//캡슐화 대상 클래스
    public:
      void Take() const {cout<<"콧물이 싹~ 납니다."<<endl;}
  };

  class SneezeCap{//캡슐화 대상 클래스
    public:
      void Take() const {cout<<"재채기가 멎습니다."<<endl;}
  };

  class SnuffleCap{//캡슐화 대상 클래스
    public:
      void Take() const {cout<<"코가 뻥 뚫립니다."<<endl;}
  };

  class CONTAC600 {//캡슐화를 진행한 클래스
    private:
      SinivelCap sin;
      SneezeCap sne;
      SnuffleCap snu;

    public:
      void Take() const{
        sin.Take();
        sne.Take();
        snu.Take();
      }
  };
  ```

## 생성자🗻 & 소멸자🌋

- 생성자(Constructor)

  - 클래스의 이름과 함수이름이 동일하며, 반환형이 선언되지 않고 반환하지 않는 함수

  - 객체 생성시 딱 한번만 호출됨

    ```cpp
    class SimpleClass{
      private:
        int num1;
        int num2;

      public:
        SimpleClass(){//생성자
          num1=1;//주로 변수 초기화의 용도
          num2=2;
        }
    }
    ```

- 멤버 이니셜라이져(Member Initializer)

  - 객체 생성과정 중에 멤버 변수 클래스에 해당하는 생성자를 호출하여 해당 객체또한 연쇄적으로 초기화하는 방식

    ```cpp
    class Point{
      int x;
      int y;
      public:
        Point(const int &xpos, const int &ypos);
    };

    Point::Point(const int &xpos, const int &ypos){
      x=xpos;
      y=ypos;
    }


    class Rectangle{
      Point upLeft;
      Point lowRight;

      public:
        Rectangle(const int &x1, const int &y1, const int &x2, const int &y2);
    };

    Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
    :upLeft(x1, y1), lowRight(x2, y2)//멤버 이니셜라이져
    {
      /*객체 upleft의 생성과정에서 x1과 y1을 인자로 받는 생성자 호출*/
      /*객체 lowRight의 생성과정에서 x2과 y2을 인자로 받는 생성자 호출*/
    }
    ```
