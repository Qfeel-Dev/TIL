# C++📜

## 복사 생성자(Copy Constructor) 🦋

- 객체간의 대입연산(= , ( ))을 통해 멤버 대 멤버 복사가 일어나면서 객체를 초기화 하는 생성자

- 복사 생성자를 정의하지 않을 경우 **디폴트 복사 생성자**가 자동으로 삽입됨

```cpp
  class SimpleClass{
    int num1;
    int num2;

    public :
    SimpleClass(int n1, int n2) :num1(n1),num2(n2){}
    //SimpleClass(SimpleClass &copy) : num1(copy.num1),num2(copy.num2) 따로 정의하지 않아도 생기는 디폴트 복사 생성자 + 이 코드의 경우 있으나 없으나 동일
  };

  int main(){
    SimpleClass s1(1,2);
    SimpleClass s2=s1;//대입 연산자를 활용한 복사생성자 호출 -> 이문장은 결국 아래 줄과 같이 묵시적 변환 -> 변환을 원치 않을 경우 explicit 키워드 사용
    SimpleClass s3(s1);//괄호를 이용한 복사생성자 호출
    return 0;
  }
```

## 깊은 복사(Deep Copy)🏊‍♂️ 와 얕은 복사(Shallow copy)🏄‍♂️

- 얕은 복사(Shallow copy) : 단순 값인 멤버들만 복사하는 경우 (정의 필요 X -> 디폴트 복사 생성자)
- 깊은 복사(Shallow copy) : 단순 값인 멤버들뿐 아니라 포인터로 참조하는 대상까지 복사하는 경우 (정의 필요 O)

  ```cpp
  class SimpleClass{
    int num1;
    int num2;
    char * str;

    public :
      SimpleClass(SimpleClass &copy) : num1(copy.num1),num2(copy.num2){//깊은 복사 구현 방식
        str = new char[strlen(copy.str)+1];
        strcpy(str,copy.str)
      }
  };
  ```
