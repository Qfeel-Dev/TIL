# C++π

## κ°μ²΄ ν¬μΈν°μ μ°Έμ‘° κ΄κ³ π

- AAAν ν¬μΈν° λ³μλ AAAκ°μ²΄ λλ AAAλ₯Ό μ§,κ°μ μ μΌλ‘ μμλ°λ λͺ¨λ  κ°μ²΄μ μ£Όμκ°μ μ μ₯ν  μ μλ€.

  - μ΄λ IS-A κ΄κ³μ μΌλ¨λΌλ²μΌλ‘ μ€λͺμ΄ κ°λ₯νλ€ _EX|νμμ μ¬λμ΄λ€, κ·Όλ‘νμμ νμμ΄λ€, κ³ λ‘ κ·Όλ‘νμμ μ¬λμ΄λ€_<br> μ΄λ κΈ° λλ¬Έμ μ§,κ°μ μ μΈ κ²½μ°μλ κ°μ²΄μ μ£Όμκ°μ μ§μ ν  μ μλ€.

- μ€λ²λΌμ΄λ©(overriding) : κΈ°μ΄ν΄λμ€μ λ§€κ°λ³μμ μλ£ν λ° κ°μ λ±κ³Ό κ°μ λμΌν ννμ ν¨μλ₯Ό μ λν΄λμ€μμ μ¬ μ μνμ¬ μ¬μ©νλ κ°λ

- κ°μ²΄ ν¬μΈν° : κ°μ²΄λ₯Ό κ°λ¦¬ν¬ μ μλ ν¬μΈν°λ₯Ό μλ―Ένλ€ (μμ ν΄λμ€λ νμ ν΄λμ€μ κ°μ²΄ μ£Όμ μ μ₯μ΄ )

## κ°μν¨μ(Virtual Function)π§

- C++ μ»΄νμΌλ¬λ ν¬μΈν° μ°μ°μ κ°λ₯μ± μ¬λΆλ₯Ό ν¬μΈν°μ μλ£νμ κΈ°μ€μΌλ‘ νλ¨νλ€.

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

    //fptr->SecondFunc(); λ°λΌμ μ΄ λΆλΆμ μ£Όμμ ν΄μ ν  κ²½μ°μλ¬κ° λκ²λλ€. -> SecondFuncμ Secondμ μ°μ°μ λ°ν΄ fptrμ μλ£νμ Firstμ΄κΈ° λλ¬Έμ΄λ€.

    delete tptr;
    return 0;
  }
```

- νμ§λ§ ν΄λΉ κ°μ²΄μμ νΈμΆλμ΄μΌ νλ ν¨μκ° νμν κ²½μ°κ° μκΈ° λλ¬Έμ, **κ°μν¨μ**λΌλ κ²μ μ¬μ©νλ€.

- κ°μ ν¨μλ κ°μν¨μ ν€μλλ₯Ό μμ±ν ν¨μμ ννμ¬, ν΄λΉ ν¨μκ° μ€λ²λΌμ΄λ© λ  κ²½μ°, ν¬μΈν° λ³μμ μλ£νμ κΈ°λ°μΌλ‘ νΈμΆλμμ μ νμ§ μκ³ , κ°λ₯΄ν€κ³  μλ κ°μ²΄λ₯Ό μ°Έμ‘°νμ¬ νΈμΆ λμμ κ²°μ νλ κ°λμ΄λ€.

```cpp
  class First{
    public:
      virtual void FirstFunc(){cout<<"FirstFunc"<<endl;}//virtualμ΄ κ°μν¨μ ν€μλ!
  };
```

## μμ κ°μν¨μμ μΆμ ν΄λμ€πΌ

- ν΄λμ€ μ€μμλ λ€λ₯Έ ν΄λμ€λ€κ³Όμ μ°κ΄μ μν μ­ν λ§ νκ³ , κ°μ²΄μμ±μ λͺ©μ μΌλ‘ μ μ λμ§ μλ ν΄λμ€λ€μ΄ μ‘΄μ¬νλ€. C++μμλ μ΄λ¬ν ν΄λμ€λ€ κ°μ²΄λ₯Ό μμ±μ λ§λ μμ κ°μν¨μλ‘ κ΅¬μ±λ μΆμ ν΄λμ€κ° μλ€.

```cpp
class Employee{
private:
	char name[100];
public:
	Employee(char * name){strcpy(this->name, name);}
	void ShowYourName() const {cout<<"name: "<<name<<endl;}
	virtual int GetPay() const = 0; //μμ κ°μν¨μ μ μ λ°©λ² const = 0;μ μΆκ°
	virtual void ShowSalaryInfo() const = 0;
};
```

## λ€νμ±(Polymorphism)π­

- **λ€νμ±**μ΄λ **λμ§μ΄μ**μ μλ―Ένλ©° μ΄λ μ¦, **λͺ¨μ΅μ κ°μλ° ννλ λ€λ₯΄λ€** μ΄κ²μ΄ c++μμ  **λ¬Έμ₯μ κ°μλ° κ²°κ³Όλ λ€λ₯΄λ€**λΌλ κ²μ μλ―Ένλ€.

- μμ μΈκΈν λ΄μ©λ€μ κ°μ§κ³  κ°μ²΄μ§ν₯μ νΉμ§μΈ λ€νμ±μ κ΅¬νν  μ μλ€
