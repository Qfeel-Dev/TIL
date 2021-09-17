# C++📜

## Basic I/O💻

- C언어에서 <stdioo.h>에 `printf`,`scnaf`를 대신해<br>
  C++에서는 <iostream> `std::cout`,`std::cin`을 사용한다.  
   --- _c언어 함수를 사용하지 못하는 것은 아님!! c++은 c언어를 포함함!!_

## Function Overloading🧱

- *매개변수 선언의 차이*를 두어 동일한 이름의 함수정의를 허용하는 형태
  - 매개변수 선언의 차이: 매개변수의 자료형 혹은 개수를 달리하는 것
- 함수의 이름만을 이용해서 호출대상을 찾는 C와 달리,<br>
  C++은 이름과 매개변수의 선언을 이용해 호출대상을 찾기에 오버로딩이 가능

  ```c++
  //overloading example
  void MyfuncOne(void);

  void MyfuncOne(int num);

  void MyfuncOne(char name);

  void MyfuncOne(int num1,int num2);
  ```

## Defalut Value🔢

- 함수호출 시 인자를 전달하지 않으면 기본으로 설정을 해주는 값을 지정하는 방식

  ```c++
  int MyfuncOne(int num =7){
    return num+1; //매개변수가 전달되지 않을 경우 return 8;
  }

  int MyfuncOne(int num1 =7, int num2 =5){
    return num1+num2; //매개변수가 전달되지 않을 경우 return 12;
  }
  ```

- 부분적 디폴트 값 설정 시 오른쪽 매개변수의 디폴트 값부터 채우는 형식이어야함
  - 함수에 전달되는 인자가 왼쪽에서붐터 오른쪽으로 채워지기 때문입니다.

## Namespace!🙋‍♂️
