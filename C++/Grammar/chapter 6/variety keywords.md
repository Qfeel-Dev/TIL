# C++

## const 키워드 🌳

- `const`의 가장 큰 특징은 **"변경을 허용하지 않겠다!"** 이다.

- const 키워드가 객체에 적용될 경우 **"객체의 데이터 변경을 허용하지 않겠다!"** 라는 뜻으로 간주되며, const 멤버함수만 호출이 가능해진다

- const 키워드가 함수에 적용될 경우 오버로딩 키워드로써의 역할도 수행한다.

## friend 키워드 👬

- `friend`키워드는 다른 클래스에게 자신의 클래스에 private에 해당하는 부분을 공개해주는 키워드이다.

- friend 선언은 private,public 관계없이 선언이 가능하다.

```cpp
class SimpleClass1{
  int age;
  int tel;

  public :
  SimpleClass1(int n1, int n2) :num1(n1),num2(n2){}
};

class SimpleClass2{
  int num1;
  int num2;
  friend class SimpleClass1;//SimpleClass1 friend 선언

  public :
  SimpleClass1(int n1, int n2) :num1(n1),num2(n2){}
  void ShowInfo(SimpleClass1 &s1){
    cout << s1.age << s1.tel << endl;//private 접근
  }
};
```

- 개인적으로 goto가 c의 절차지향적 특징을 흐리게 할 수 있다하면, friend 키워드는 객체지향의 특징을 흐리게할 수 있는 키워드인 것 같아서 가급적 사용을 자제해야 할 것 같다.

## static 키워드 ⚡️

- static 키워드는 어떤 곳에 활용하는지에 따라 역할이 조금 다르다

- 함수에서의 static은 **한번만 초기화되고 함수를 빠져나가도 소멸되지 않는 특성**

- 전역 변수에서의 static은 **선언된 파일 내에서만 참조를 하겠다는 특성**

- 클래스에서의 static

  - 선언된 클래스의 모든 객체가 static 함수,변수를 공유
  - public으로 선언이 되면, 클래스의 이름을 이용한 호출이 가능
  - 객체의 멤버로 존재하는 것이 아닌 별도의 메모리 공간에 적재

    ```cpp
    class SimpleClass1{
      private:
      int age;
      int tel;
      static int a;//private static 변수 선언
      public :

      static void adder(){//static 함수 선언
        a++;
      }
      SimpleClass1(int n1, int n2) :num1(n1),num2(n2){}
    };
    int SimpleClass1::a = 0;//static 변수 초기화
    ```
