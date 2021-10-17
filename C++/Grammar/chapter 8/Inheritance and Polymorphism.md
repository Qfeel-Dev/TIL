# C++📜

## 객체 포인터의 참조 관계 🔁

- AAA형 포인터 변수는 AAA객체 또는 AAA를 직,간접적으로 상속받는 모든 객체의 주소값을 저장할 수 있다.

  - 이는 IS-A 관계에 삼단논법으로 설명이 가능하다 _EX|학생은 사람이다, 근로학생은 학생이다, 고로 근로학생은 사람이다_<br> 이렇기 때문에 직,간접적인 경우에도 객체의 주소값을 지정할 수 있다.

- 오버라이딩(overriding) : 기초클래스의 매개변수의 자료형 및 개수 등과 같은 동일한 형태의 함수를 유도클래스에서 재 정의하여 사용하는 개념

## 가상함수(Virtual Function)🐧

- C++ 컴파일러는 포인터 연산의 가능성 여부를 포인터의 자료형을 기준으로 판단한다.

```cpp
  class First{
    public:
      void FirstFunc(){cout<<"FirstFunc"<<endl;}
  };

  class Second: public First{
    public:
      void SecondFunc(){cout<<"SecondFunc"<<endl;}
  };

  int main(void){
    Second * sptr=new Second();
    First * fptr=sptr;

    //fptr->SecondFunc(); 따라서 이 부분의 주석을 해제할 경우에러가 나게된다. -> SecondFunc은 Second의 연산에 반해 fptr의 자료형은 First이기 때문이다.

    delete tptr;
    return 0;
  }
```

- 하지만 해당 객체에서 호출되어야 하는 함수가 필요한 경우가 있기 때문에, **가상함수**라는 것을 사용한다.

- 가상 함수는 가상함수 키워드를 작성한 함수에 한하여, 해당 함수가 오버라이딩 될 경우, 포인터 변수의 자료형을 기반으로 호출대상을 정하지 않고, 가르키고 있는 객체를 참조하여 호출 대상을 결정하는 개념이다.

```cpp
  class First{
    public:
      virtual void FirstFunc(){cout<<"FirstFunc"<<endl;}//virtual이 가상함수 키워드!
  };
```

## 순수 가상함수와 추상 클래스👼

- 클래스 중에서는 다른 클래스들과의 연관을 위한 역할만 하고, 객체생성을 목적으로 정의 되지 않는 클래스들이 존재한다. C++에서는 이러한 클래스들 객체를 생성을 막는 순수 가상함수로 구성된 추상 클래스가 있다.

```cpp
class Employee{
private:
	char name[100];
public:
	Employee(char * name){strcpy(this->name, name);}
	void ShowYourName() const {cout<<"name: "<<name<<endl;}
	virtual int GetPay() const = 0; //순수 가상함수 정의 방법 const = 0;을 추가
	virtual void ShowSalaryInfo() const = 0;
};
```

## 다형성(Polymorphism)🎭

- **다형성**이란 **동질이상**을 의미하며 이는 즉, **모습은 같은데 형태는 다르다** 이것이 c++에선 **문장은 같은데 결과는 다르다**라는 것을 의미한다.

- 앞서 언급한 내용들을 가지고 객체지향의 특징인 다형성을 구현할 수 있다
