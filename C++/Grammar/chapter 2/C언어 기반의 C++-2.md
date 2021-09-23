# C++📜

## Reference📋

- 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름
- "변수에 별칭을 붙여주는 것입니다"

  ```c++
  int num1 =10;
  int &num2 = num1;//참조자 선언

  num2 = 20;//참조자를 이용한 변수 값 변경

  std::cout<<num2;//변경한 20값 출력
  ```

- 선언 규칙
  - 참조자의 수에는 제한이 없으며,<br>
    참조자를 대상으로도 참조자 선언이 가능

## Call-by-value & Call-by-reference👬

- Call-by-value
  - 값을 인자로 전달받는 방식
    ```c++
      int Adder(int num1, int num2) {
        return num1 + num2;
      }
    ```
- Call-by-reference

  - 주소값을 인자로 전달받는 방식
  - 함수 외부에 선언된 변수에 접근하는 형태의 함수 호출
  - C++에서는 **주소 값 Call-by-reference**, **참조자 Call-by-reference**

    ```c++
      int Swap(int *num1, int *num2) {
        int tmp = *num1;
        *num1 = *num2;
        *num2 = tmp;
      }//주소 값 Call-by-reference

      int Swap(int &num1, int &num2) {
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
      }//참조자 값 Call-by-reference
    ```
