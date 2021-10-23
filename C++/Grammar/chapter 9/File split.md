# C++📜

## 파일 분할 📚

- 각각의 클래스마다 **선언은 `.h`**, **정의는 `.cpp`** 파일에 저장하여 소스코드의 유지보수성을 높이기 위한 수단
- .h파일 예제
  ```
  #ifndef Calculator_h
  #define Calculator_h
  
  class Basic(){
    private:
      int a;
      int b;
      
    public:
      Basic();
      ~Basic();
      void Add(int n1,int n2);
  };
  
  #endif  
  ```
