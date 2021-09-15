# CSS📜

## Hello CSS👋

- "Cascading style sheets"의 줄임말로, HTML로 만든 문서에 스타일을 입히는 언어

- 웹 문서의 내용과 상관 없이 스타일 변경이 가능하므로 **반응형 웹 디자인**이 가능함

  - 반응형 웹 디자인 : 어떤 기기던지간에 웹 페이지가 호환되게 디자인 하는 것<br>

## CSS Basic Structure🧱

- CSS의 스타일 형식은 `선택자 {속성: 속성값;}`으로 구성한다 (하단 예제 참고)

  ```CSS
  p{
    text-align : center;
    color : blue;
  }
  /*여러 줄 표현*/

  p{text-align : center; color : blue;}
  /*한 줄 표현*/
  ```

- 선택자의 종류

  - 전체 선택자 <br>
    |개념 | 문서의 모든 요소를 선택하는 방법|
    |:---:|---|
    |**표현 방법**| `* {속성: 값; ....}`|

  - 타입 선택자<br>
    |개념 | 특정 태그의 요소를 선택하는 방법|
    |:---:|---|
    |**표현 방법**| `특정 태그명 {속성: 값; ....}`|

  - 클래스 선택자<br>
    |개념 | 특정 부분의 요소를 선택하는 방법|
    |:---:|---|
    |**표현 방법**| `.클래스명 {속성: 값; ....}`|
    |**\*주의 사항**| 적용하고자하는 태그의 class 속성값을 할당해줘야함|

  - id 선택자<br>
    |개념 | 특정 부분의 요소를 한 번만 선택하는 방법 (중복사용 x)|
    |:---:|---|
    |**표현 방법**| `#id명 {속성: 값; ....}`|
    |**\*주의 사항**| 적용하고자하는 태그의 id 속성값을 할당해줘야함|

## How to define CSS📝

- 인라인 스타일<br>
  스타일을 적용할 대상에 직접 표시하는 방식, 해당 HTML 태그에 style속성을 적용하는 방식<br>

  ```html
  <p style="color : blue">인라인 스톼일</p>
  ```

- 내부 스타일<br>
  스타일을 같은 HTML `<head>`에 `<style>`태그를 이용해 적용하는 방식

  ```html
  <head>
    <style>
      p {
        text-align: center;
        color: blue;
      }
    </style>
  </head>
  ```

- 외부 스타일<br>
  스타일을 따로 `.css`파일로 작성하고 Html `<head>`에 `<link>` 태그로 연결 시켜 적용하는 방식

  ```html
  <head>
    <link rel="stylesheet" href="addr/style.css" />
  </head>
  ```

## Rule about CSS👨‍💻

- CSS는 스타일 끼리 출동하지 않게끔 하는 Cascading 개념을 적용하였는데,<br>그 방법으로는 **스타일 우선순위**와 **스타일 상속**이 있다.

- 스타일 우선순위 (내림차순)

  - 주체에 따른 순위 : 사용자 > 제작자 > 브라우저
  - 적용 범위에 따른 순위 : !important > 인라인 > id > 클래스 > 타입
  - 소스코드 작성에 따른 순위 : 아래 > 위

- 스타일 상속
  - HTML에서 부모 요소와 자식 요소에서 자식 요소에 스타일을 지정하지 않을 경우 부모 요소의 스타일 속성이 그대로 전달되는 방식.

## How to use CSS📕

- 글꼴 관련 스타일 속성

  ```css
  font-family: 글꼴 이름;
  /*사용할 글꼴를 설정하는 속성*/

  font-size: 크기;
  /*글자의 크기를 설정 하는 속성 (value ex|20px, 5pt, 100%)*/

  font-weight: 굵기;
  /*글자의 굵기를 설정하는 속성 (value ex| bold, lighter, 100~900)*/
  ```

- 텍스트 관련 스타일 속성

  ```css
  color: 색상;
  /*글자색을 지정하는 속성 (value ex| red, #ff0000, rgb(255,0,0))*/

  text-align: 위치;
  /*텍스트의 좌우 정렬 위치를 지정하는 속성 (value ex| center, right, left)*/

  line-height: 간격;
  /*텍스트의 간격을 설정 하는 속성 (value ex|20px, 2.0, 200%)*/
  /*세로 정렬일 경우에도 사용*/

  text-decoration: 줄 표시 위치;
  /*텍스트의 줄을 긋기 위한 속성 (value ex| underline, overline)*/

  text-shadow: <가로거리> <세로거리> <번짐정도> <색상>;
  /*텍스트의 그림자 효과 생성을 위한 속성 (value ex| 5 5 2 black)*/

  letter-spacing: 간격;
  /*자간 조율을 위한 속성 (value ex| 0.2em)*/
  ```

- 목록 관련 스타일 속성

  ```css
  list-style-type: 불릿의 모양, 번호의 스타일;
  /*리스트 문자의 타입을 지정해주는 속성 (value ex| disc, lower-roman)*/

  list-style-img: url(이미지 경로);
  /*리스트 문자의 타입 대신 이미지를 지정해주는 속성*/

  list-style-position: inside, outside;
  /*리스트를 들여쓰기 여부에 대한 속성*/

  list-style: type img position;
  /*목록 관련 스타일 속성을 한꺼번에 이용할 수 있는 속성*/
  ```

- 표 관련 스타일 속성

  ```css
  caption-side: top, bottoml;
  /*표의 제목인 caption의 위치를 조정하는 속성*/

  border: 굵기 선종류 색상;
  /*표의 테두리를 설정하는 속성 (value ex|1px solid black)*/

  border-collapse: collapse;
  /*셀과 셀사이의 두 줄의 결합 여부를 설정하는 속성*/
  /*table 태그에만 적용시키면 됨*/
  ```
