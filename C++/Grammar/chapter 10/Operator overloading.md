# C++📜

## 연산자 오버로딩 🧗‍♀️

- 함수의 오버로딩과 동일하게 기존의 존재하던 **연산자의 기본 기능 이외에 다른 기능을 추가할 수 있다.**

- 객체도 기본 자료형 처럼 연산이 가능하게끔 할 수 있는 방법이다.

- `operator` 키워드와 연산자를 묶어서 함수를 정의하면 함수와 연산자의 호출을 둘 다 허용하는 형태

- 연산자의 오버로딩에는 전역함수를 통한 오버로딩과 멤버 함수를 통한 오버로딩이 있다

  - 멤버함수 오버로딩

    ```cpp
    class Point
    {
    private:
      int xpos, ypos;
    public:
      Point(int x=0, int y=0) : xpos(x), ypos(y)
      {  }

      Point operator+(const Point &ref)    //+ 얀산자 오버로딩
      {
        Point pos(xpos+ref.xpos, ypos+ref.ypos);
        return pos;
      }
    };

    int main(void){
      Point p1(5,3);
      Point p2(10,7);

      cout<< p1.operator+(p2)<<endl//15,10 출력
      cout<< p1+p2<<endl////15,10 출력
    }
    ```

  - 전역함수 오버로딩

    ```cpp
    class Point
    {
    private:
      int xpos, ypos;
    public:
      Point(int x=0, int y=0) : xpos(x), ypos(y)
      {  }

      friend Point operator+(const Point &ref)    //operator+ 함수가 xpos,ypos를 사용할 수 있게끔 friend 선언
    };

    Point operator+(const Point &pos1, const Point &pos2) //+연산자 오버로딩
    {
      Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
      return pos;
    }

    int main(void){
      Point p1(5,3);
      Point p2(10,7);

      cout<< p1.operator+(p2)<<endl//15,10 출력
      cout<< p1+p2<<endl////15,10 출력
    }
    ```

- 연산자 오버로딩 시 주의사항

  - 본래의 의도를 벗어난 형태의 연산자 오버로딩은 좋지않다.
  - 연산자의 우선순위와 결합성은 바뀌지 않는다.
  - 연산자의 순수 기능까지 빼앗을 수 없다.

- 단항 연산자의 오버로딩
  - `++` , `-- `, `!` 등과 같은 단항연산자는 매개변수가 없는 멤버변수로 선언하며 오버로딩 되어진다.
