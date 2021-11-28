# C++

## 함수 템플릿(Function Template)📐

- 함수를 만드는 도구 -> 다양한 자료형의 함수(템플릿 함수)를 만들어내는 도구

```cpp
template <typename T>
//template <class T> 대신 사용
T Add(T num1, T num2)
{
  return num1+num2;
}

int main(void)
{
  Add<int>(15,20);//자료형 int로 템플릿 사용
  Add<double>(2.9,3.7);//자료형 double로 템플릿 사용
}
```

- 상황에따라 함수의 구성방법에 예외 둘 필요가 있는 경우 **함수 템플릿의 특수화(Specialization)**를 사용한다

```cpp
template <>//char* 형 함수의 특수화 예시
char* Add(char* a, char* b)
{
  char* summary = new char[strlen(a) + strlen(b) +1];
  strcpy(summary,a);
  strcat(txt,s.txt);

  return summary;
}
```
