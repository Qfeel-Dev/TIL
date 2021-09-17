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
  /*텍스트의 간격을 설정 하는 속성 (value ex|20px, 2.0, 200%)
  세로 정렬일 경우에도 사용*/

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
  /*셀과 셀사이의 두 줄의 결합 여부를 설정하는 속성
  table 태그에만 적용시키면 됨*/
  ```

- 배경 관련 스타일 속성

  ```css
  background-color: 색상;
  /*배경색을 지정하는 속성 (value ex| red, #ff0000, rgb(255,0,0))*/

  background-clip: 범위;
  /*배경색을 지정할 범위를 정하는 속성 (value ex| border-box, padding-box, content-box)*/

  background-image: url("이미지경로");
  /*배경 이미지를 넣는 속성*/

  background-repeat: 반복여부;
  /*배경 이미지의 반복 방법을 지정하는 속성 (value ex| repeat,repeat-x,repeat-y,no-repeat)*/

  background-position: <수평위치> <수직위치>;
  /*배경 이미지의 위치를 조절하는 속성
  백분율, 크기 값으로도 올 수 있지만 left,top과 같은 키워드로도 이용 가능*/

  background-origin: 범위;
  /*배경 이미지를 지정할 범위를 정하는 속성 (value ex| border-box, padding-box, content-box)*/

  background-attachment: 고정여부
  /*화면 스크롤시 이미지 고정여부를 설정하는 속성 (value ex| scroll,fixed)*/

  background: url("주소") 반복여부 위치 고정여부
  /*배경 이미지 관련 속성을 하나의 속성으로 사용하게끔 하는 속성*/

  background-size: 크기
  /*배경 이미지 크기를 조율하는 속성 (value ex| auto, cover, contain)*/
  ```

## Layout with CSS✏️

- 웹 문서에서 각 요소를 배치하는 방법으로 **CSS 박스모델**을 사용한다.
  - 박스모델 : 박스형태의 요소로, Contents, padding, margin, border등으로 구성
- 웹 문서의 요소들은 또, 인라인 레벨 과 블록 레벨로 나눠진다

- 박스모델 구성요소(그림)<br>
  <!--![구성요소](.\img\boxmodel_component.png) -->

  ![boxmodel_component](https://user-images.githubusercontent.com/71952165/133574962-1a270806-dbb3-4e0a-ab28-dd873fbd043c.PNG)

- 박스모델 관련 속성

  ```css
  width: 너비;
  height: 높이;
  /*박스모델의 콘텐츠 영역의 너비와 높이를 지정하는 속성*/

  box-shadow: <가로거리> <세로거리> <흐림정도> <번짐정도> <색상>;
  /*박스모델의 그림자 효과를 주는 속성*/

  border-style: 테두리 모양;
  /*박스모델의 테두리 스타일을 정하는 속성*/

  border-width: 크기;
  /*박스모델의 테두리 두께를 정하는 속성*/

  border-color: 색상;
  /*박스모델의 테두리 색상을 정하는 속성*/

  border : 모양 크기 색상;
  /*테두리 모양,크기,색상을 한꺼번에 지정할 수 있는 속성*/

  border-radius: 반지름 크기,배율
  /*테두리를 둥글게 만드는 속성*/

  margin : 크기
  /*요소 주변의 여백(이하 마진)을 조절하는 속성
  속성값의 개수를 다르게 지정할 경우 적용되는게 다 다름
  1개: 상하좌우 2개:상하-좌우 3개:상-좌우-하 4개:상-하-좌-우*/

  padding : 크기
  /*콘텐츠 영역과 테두리 사이의 여백(이하 마진)을 조절하는 속성  속성값의 개수를 다르게 지정할 경우 적용되는게 다 다름
  1개: 상하좌우 2개:상하-좌우 3개:상-좌우-하 4개:상-하-좌-우*/
  ```

- 박스모델 배치 관련 속성

  ```css
  display : 레벨
  /*배치 방법을 결정하는 속성 (value ex| block, inline, inline-block)*/

  float : 위치
  /*왼쪽이나 오른쪽으로 배치하는 속성*/

  clear : 위치
  /*float 속성을 해제하는 속성*/

  position : 포지셔닝
  /*요소를 원하는 위치로 배치하게끔 하는 속성*/
  /*포지셔닝 종류
  static: 문서의 흐름에 맞춰 배치, 기본값
  relative: 위칫값을 지정하는 static
  absolute: relative값을 기준으로 요소의 위치를 지정
  fixed: 브라우저 창을 기준으로 위치를 지정
  */
  ```
