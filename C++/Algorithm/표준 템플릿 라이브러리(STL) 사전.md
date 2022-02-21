# 라이브러리(Library)📚

## 라이브러리란❓

- 입출력, 문자열, 알고리즘, 자료구조 등을 미리 구현해놓은 클래스 및 함수를 일컫는 말
- C++ 라이브러리의 대부분은 템플릿으로 제공되며, `표준 템플릿 라이브러리(Standard Template Library, STL)`이라 칭한다 - 윤성우 열혈 C++ 참고

## 표준 템플릿 라이브러리 - STL

- STL은 컨테이너라고 부르는 자료 집합을 관리하는 동적 배열, 리스트, 스택, 큐 등의 클래스와 이와 관련된 함수를 제공한다.

  ### `stack`

  ```c++
  #include <iostream>
  #include <stack>

  using namespace std;

  int main(){
    stack<int> S;//S라는 이름의 int 자료형 요소를 관리하는 스택 생성

    S.push(3);//스택에 값 추가
    S.push(7);
    S.push(1);

    cout << S.size() << " ";//3 사이즈 리턴함수

    cout << S.top() << " ";//1 가장 위에 있는 요소 리턴
    S.pop();// 가장 위에 있는 요소 제거

    cout << S.top() << " ";//7
    S.pop();

    cout << S.top() << " ";//3

    S.push(5);
    cout << S.top() << " ";//5
    S.pop();

    cout << S.top() << " ";//3
    //S.empty() //스택이 비었을 경우 true 리턴
    return 0;
  }
  ```

  ### `queue`

  ```c++
  #include <iostream>
  #include <queue>
  #include <string>

  using namespace std;

  int main(){
    queue <string> Q;//Q라는 이름의 string 자료형 요소를 관리하는 큐 생성

    Q.push("red");//큐에 값 추가
    Q.push("yellow");
    Q.push("yellow");
    Q.push("blue");

    cout << Q.front() << " ";//red 큐에 가장 앞쪽 요소 출력
    Q.pop();//큐에 가장 앞쪽 요소 제거

    cout << Q.front() << " ";//yellow
    Q.pop();

    cout << Q.front() << " ";//yellow
    Q.pop();

    Q.push("green");

    cout << Q.front() << " ";//blue
    Q.pop();

    cout << Q.front() << " ";//green

    return 0;
  }

  ```

  ### `vector` - 동적 배열

  ```c++
  #include <iostream>
  #include <vector>

  using namespace std;

  void print(vector<double> V){
    for(int i = 0; i<V.size(); i++){//V의 사이즈 만큼 배열 순회
      cout << V[i] << " ";
    }
    cout << endl;
  }

  int main(){
    vector <double> V;

    V.push_back(0.1);//배열의 가장 뒷 자리에 매개 변수 값 추가
    V.push_back(0.2);
    V.push_back(0.3);
    V[2] = 0.4;//일반 배열처럼  [] 연산자 사용 가능

    print(V);//0.1  0.2  0.3

    V.insert(V.begin()+2,0.8);
    //첫번째 매개변수(시작점에서 + 2 위치) 위치에서  두번째 매개변수 값 삽입  뒤에 값들은 밀어넣기
    print(V);//0.1  0.2  0.8  0.4

    V.erase(V.begin() + 1);//매개변수 위치 값 삭제(사이 값일 경우 뒤에 값들 당겨옴)
    print(V);//0.1  0.8  0.4

    return 0;
  }
  ```
