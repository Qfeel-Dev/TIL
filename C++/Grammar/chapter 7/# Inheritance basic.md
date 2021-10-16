# C++

## Control Class🎮

- 기능 처리를 실제로 담당하고 있는 클래스\

- 프로그램이 어떠한 기능을 제공하는지 구체적으로 알 수 있는 클래스

## 상속👨‍👦의 문법📚

- 상속은 다룰 내용이 많기 때문에 여러번 거쳐서 정리를 하겠다!

- 클래스가 가지고 있는 고유의 특성(객체 자신의 멤버함수, 변수) 이외에 상위 클래스의 특성을 물려받는 특성

- 상속을 해주는 클래스 : 기초 클래스, 상위 클래스,부모 클래스

- 상속을 받는 클래스 : 유도 클래스, 하위 클래스,자식 클래스

```cpp
  class Person{//기초 클래스, 상위 클래스,부모 클래스
  private:
    char name[50];
  public:
    Person(char * myname){
      strcpy(name, myname);
    }
    void WhatYourName() const {
      cout<<"My name is "<<name<<endl;
    }
  };

  class UnivStudent : public Person{//유도 클래스, 하위 클래스,자식 클래스
  private:
    char major[50];
  public:
    UnivStudent(char * myname, char * mymajor): Person(myname)
    {
      strcpy(major, mymajor);
    }
    void WhoAreYou() const {
      WhatYourName();
      cout<<"My major is "<<major<<endl<<endl;
    }
  };
```

- 유도 클래스의 객체를 생성하게되면 **기초 클래스 생성자 -> 유도 클래스 생성자** 과정을 통해서 초기화 되며,<br> 삭제는 **유도 클래스 생성자 -> 기초 클래스 생성자**순으로, 스택의 구조 형태인 LIFO을 따른다.

## 상속과 관련된 접근제어자 키워드🧚‍♀️

- `protected`는 `private,public` 와 달리 상속 했을 경우 그 특징이 들어나는 접근제어자이다.

- protected로 선언된 멤버 변수,함수는 private와 같이 외부에서 사용은 되지 않지만 상속받는 유도클래스에선 사용이 가능한 키워드이다,

- 접근제어자를 통한 상속의 세가지 형태
  - public 상속
  - protected 상속
  - private 상속

## 상속의 조건🔑

- 상속으로 묶인 두개의 클래스는 강한 연광성을 띤다. 그러므로 상속이 필요할때를 잘 판단하여 사용해야 한다.

- 대부분 Is-A(일종의 ~이다) 관계가 형성되면 상속을 해도 무관하다.
