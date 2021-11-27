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
