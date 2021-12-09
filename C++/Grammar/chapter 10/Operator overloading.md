# C++📜

## 연산자 오버로딩 🧗‍♀️

- 함수의 오버로딩과 동일하게 기존의 존재하던 **연산자의 기본 기능 이외에 다른 기능을 추가할 수 있다.**

- 객체도 기본 자료형 처럼 연산이 가능하게끔 할 수 있는 방법이다. -> 피연산자의 종류에 따른 연산 방식의 변화가 가능

- `operator` 키워드와 연산자를 묶어서 함수를 정의하면 **함수의 이름을 통한 함수 호출** , **연산자를 통한 함수 호출**을 허용하게 된다.

- 연산자 오버로딩 예제

  ```cpp
   class Point
   {
   private:
     int xpos, ypos;
   public:
     Point(int x=0, int y=0) : xpos(x), ypos(y)
     {  }

     Point operator+(const Point &ref)    //+ 얀산자 오버로딩 //+ 연산은 피연산자에게 영향을 주지 않기 때문에, const 선언 진행
     {
       Point pos(xpos+ref.xpos, ypos+ref.ypos);
       return pos;
     }
   };

   int main(void){
     Point p1(5,3);
     Point p2(10,7);

     cout<< p1.operator+(p2)<<endl//함수 이름을 통한 호출
     cout<< p1+p2<<endl//연산자를 통한 호출 => p1.operator+(p2)로 치환
     //둘다 동일한 Point operator+(const Point &ref) 함수 호출
     //"p1이 operator+ 함수에다가 p2라는 매개변수를 집어넣고 호출한다" 로 해석됨
   }
  ```

- 연산자의 오버로딩에는 **전역함수를 통한 오버로딩 `operator+(p1,p2)`** 과 **멤버 함수를 통한 오버로딩 `p1.operator+(p2)`** 이 있다.

  - 두 종류의 오버로딩이 동시에 일어날 경우 멤버함수를 통한 오버로딩이 우선시된다
  - 전역함수를 통한 오버로딩 예제

    ```cpp
    class Point
    {
    private:
      int xpos, ypos;
    public:
      Point(int x=0, int y=0) : xpos(x), ypos(y)
      {  }
      friend Point operator+(const Point &p1, const Point &p2);//private 영역 접근을 위한 friend 선언

    };

    Point operator+(const Point &p1, const Point &p2)    //+ 얀산자 오버로딩 //+ 연산은 피연산자에게 영향을 주지 않기 때문에, const 선언 진행
    {
      Point pos(p1.xpos+p2.xpos, p1.ypos+p2.ypos);*
      return pos;
    }
    ```

  - 객체지향에는 전역에 대한 개념이 존재하지 않아, 전역변수를 통한 호출은 사용하지 않는 것이 좋지만, **교환법칙** 등 과 같은 문제에선 어쩔 수 없이 사용해야 하는 경우도 존재한다.

- 연산자 오버로딩 시 주의사항

  - 본래의 의도를 벗어난 형태의 연산자 오버로딩은 좋지않다.
  - 연산자의 우선순위와 결합성은 바뀌지 않는다.
  - 연산자의 순수 기능까지 빼앗을 수 없다.
  - 상황에 따라 오버로딩이 불가능한 연산자와 멤버함수 기반으로만 오버로딩이 가능한 연산자가 있다.

- 단항 연산자의 오버로딩

  - 피연산자의 개수가 한 개인 단항 연산자의 오버로딩은 동일한 방식으로 이뤄지지만 **증감연산자와 같이 전,후 위치에 따라 결과가 다른 특수한 케이스를**다루기 위해 따로 나누었다.

  - 증감연산자와 같은 단항연산자를 오버로딩할 경우 멤버함수를 통한 정의일 경우 매개변수가 필요없는 `Point operator++() `형태로 정의 하며<br> 전역변수를 통한 정의일 경우 `객체 이름 operator++(const Point &ref)`로 정의 되어지며, 멤버함수를 통한 정의일 경우 `pos.operator(객체 이름)`으로 정의되어진다.

  - 증감연산자의 오버로딩의 경우 전위 연산의 경우 위의 예제와 동일하게 선언하고, 후위 연산의 경우 매개변수의 `int`를 이용하여 구분한다. (순수한 구분 목적)

## 입/출력 의 정체 👽

- C++의 대표적인 입/출력 헤더인 `iostream`을 살펴보면, `cin, cout`은 `istream`과 `ostream`라는 클래스의 객체이며, `<<` 와 `>>`의 연산자 오버로딩을 통해서 입출력 기능을 수행하고 있다는 것을 알 수 있다.

- 추가적으로 `endl`은 `ostream`클래스 멤버함수이다.

- 따라서 이들을 흉내내어 오버로딩을 원하는 경우 `ostream`,`istream`을 수정 할 순 없으니 전역함수 형태로 오버로딩하여 사용한다
  - 전역함수 예제
    ```cpp
    ostream& operator<<(ostream& os, const /*오버로딩 매개변수*/){
      //오버로딩 내용
      return os;
    }
    ```
