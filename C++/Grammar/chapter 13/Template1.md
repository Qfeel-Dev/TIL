# C++

## ννλ¦Ώ(Template) π

### ν¨μ ννλ¦Ώ(Function Template)

- ν¨μλ₯Ό λ§λλ λκ΅¬(ν¨μ ννλ¦Ώ)λ‘ λ€μν μλ£νμ ν¨μ(ννλ¦Ώ ν¨μ)λ₯Ό λ§λ€μ΄λ΄λ λκ΅¬

  ```cpp
  template <typename T>
  //template <class T> λμ  μ¬μ©
  T Add(T num1, T num2)
  {
    return num1+num2;
  }

  int main(void)
  {
    Add<int>(15,20);//μλ£ν intλ‘ ννλ¦Ώ μ¬μ©
    Add<double>(2.9,3.7);//μλ£ν doubleλ‘ ννλ¦Ώ μ¬μ©
  }
  ```

- μν©μλ°λΌ ν¨μμ κ΅¬μ±λ°©λ²μ μμΈ λ νμκ° μλ κ²½μ° **ν¨μ ννλ¦Ώμ νΉμν(Specialization)**λ₯Ό μ¬μ©νλ€

  ```cpp
  template <>//char* ν ν¨μμ νΉμν μμ
  char* Add(char* a, char* b)
  {
    char* summary = new char[strlen(a) + strlen(b) +1];
    strcpy(summary,a);
    strcat(txt,s.txt);

    return summary;
  }
  ```

### ν΄λμ€ ννλ¦Ώ(Class Template)

- ν΄λμ€λ₯Ό λ§λλ λκ΅¬(ν¨μ ννλ¦Ώ)λ‘ λ€μν μλ£νμ ν¨μ(ννλ¦Ώ ν¨μ)λ₯Ό λ§λ€μ΄λ΄λ λκ΅¬

  ```cpp
  template <typename T>
  class Point
  {
    private:
      T xpos, ypos;
    public:
      Point(T x=0, T y=0) : xpos(x),ypos(y)
      {}
      void ShowPosition() const
      {
        std::cout<<xpos<<"  "<<ypos<<endl;
      }
  };
  /*μΈλΆ μ μ λ°©μ
  template <typename T>
  Point<T>::Point(T x,T y) : xpos(x), ypos(y)
  {}

  template <typename T>
  void ShowPosition() const
  {
    std::cout<<xpos<<"  "<<ypos<<endl;
  }
  */
  int main()
  {
    Point<int> pos1(3,4);
  }
  ```

- μΈλΆ μ μ λ°©μμ μ¬μ©νμ¬ νμΌμ λλ λμλ μ»΄νμΌλ¬μ **νμΌλ¨μ μ»΄νμΌ** μ­ν μ μκ°ν΄μΌνλ©°, κ·Έλ κΈ° λλ¬Έμ headerνμΌμ μ μλ₯Ό μΆκ°ν΄μΌνλ€.
