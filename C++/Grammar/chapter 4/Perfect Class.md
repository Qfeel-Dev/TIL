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

## 캡슐화(Encapsulation)

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
