# CSS📜

## Hello CSS👋

- "Cascading style sheets"의 줄임말로, HTML로 만든 문서에 스타일을 입히는 언어

- 웹 문서의 내용과 상관 없이 스타일 변경이 가능하므로 **반응형 웹 디자인**이 가능함

  - 반응형 웹 디자인 : 어떤 기기던지간에 웹 페이지가 호환되게 디자인 하는 것<br>

## CSS Structure🧱

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

- 변형 관련 스타일 속성 + 함수

  - 변형 관련 스타일 정의 내용

  ```css
  /*변형은 기존에 다른 속성과 달리 함수를 이용하여 스타일을 적용하는데 내가 느끼기엔 기존에 JS로 처리하던걸 CSS가 처리하려고해서 그런 것 같다!*/

  transform: 함수;
  /*변형을 적용하기 위한 기본 구조*/

  transform: translate(x좌표, y좌표, z좌표);
  /*요소를 이동시키는 함수*/

  transform: scale(x 배율, y 배율);
  /*요소를 설정한 배율만큼 조정하는 함수 + 인자로 하나만 입력할 경우 xy를 동일한 배율 조정*/

  transform: rotate(각도);
  /*요소를 설정한 각도만큼 회전 시키는 함수*/

  /*트랜지션 : 스타일을 변경시키는 스타일 방법 +
  책엔 hover,active와 같이 사용자의 행위에 따른 변경만 나오는데
  웹을 키자마자 동작되는 건 없나 찾아봐야겠다...*/

  transition-property: 속성;
  /*트랜지션을 적용할 요소를 지정해주는 속성 */

  transition-duration: 시간;
  /*스타일 변경이 진행되는 시간을 지정하는 속성 (value ex| 1s, 2s)*/

  transition-delay: 시간;
  /*트랜지션의 시작 시간을 지정하는 속성*/

  transition-timing-function: 템포;
  /*트랜지션의 진행 흐름을 설정하는 속성+ 음악에서의 템포라 생각하면 쉬움 (value ex| ease, linear)*/

  /*애니메이션: 트랜지션보다 더 쉽게 스타일 속성을 변경하여 애니메이션 효과를 내는 방법*/

  @keyframes <이름>{
    from {속성: 속성값;}/*이곳에 해당하는 속성에서*/
    50%{속성: 속성값;}/*이곳에 해당하는 속성으로 변경되었다가*/
    to {속성: 속성값;}
    /*여기서 마무리하는 구조 중간 지점을 추가로 넣을시 수치%{속성:속성값}}을 넣어주면 끝*/
  }
  /*키프레임은 스타일이 바뀌는 지점과 바뀔 스타일에 관해 작성하는 속성*/

  animation-name: 키프레임 이름;
  /*어떤 키프레임을 애니메이션으로 사용할지 정하는 속성*/

  animation-duration: 시간;
  /*애니메이션 진행시간을 정하는 속성*/

  animation-iteration-count: 횟수
  /*애니메이션의 반복 횟수를 정하는 속성*/

  animation-timing-function : 템포;
  /*애니메이션의 진행 흐름을 설정하는 속성+ 음악에서의 템포라 생각하면 쉬움 (value ex| ease, linear)*/

  animation-direction: 방향;
  /*기본값은 키프레임에 from -> to로 속성값이 변경되지만 해당 속성을 이용하면 to -> from과 같이 방향 변경이 가능  (value ex| normal, reverse| alternate)*/
  ```

  - 변형 관련 스타일 예제

  ```

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

## CSS Selecter✔️

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

- 하위 선택자<br>
  |개념 |부모요소에 포함된 모든 하위 요소를 선택하는 방법|
  |:---:|---|
  |**표현 방법**| `상위요소 하위요소{속성: 값; ....}`|

- 자식 선택자<br>
  |개념 |부모요소에서 바로 한 단계 아래의 요소를 선택하는 방법|
  |:---:|---|
  |**표현 방법**| `부모요소 > 자식요소{속성: 값; ....}`|

- 형제 선택자<br>
  |개념 |같은 부모요소에서 나온 요소를 선택하는 방법|
  |:---:|---|
  |**표현 방법**| `요소1 ~ 요소2{속성: 값; ....}`|

- 인접 형제 선택자<br>
  |개념 |같은 부모요소에서 나온 요소 중 가장 가까운 요소를 선택하는 방법|
  |:---:|---|
  |**표현 방법**| `요소1 + 요소2{속성: 값; ....}`|

- 속성 선택자
  |개념 |태그 안에서 사용하는 속성,속성값에 따라 요소를 선택하는 방법|
  |:---:|---|
  |**종류별 방법**| `tag[속성]{속성: 값; ....}` -해당 속성이 있는 요소 선택|
  || `tag[속성*= 값]{속성: 값; ....}` -지정한 속성값이 있는 요소 선택|
  || `tag[속성^= 값]{속성: 값; ....}` -지정한 속성값으로 시작하는 요소 선택|
  || `tag[속성$= 값]{속성: 값; ....}` -지정한 속성값으로 끝나는 요소 선택|
  || `tag[속성*= 값]{속성: 값; ....}` -지정한 속성값의 일부가 일치하는 요소 선택|

- 가상 클래스
  |개념 |사용자의 동작에 반응하도록 스타일을 구성할때 필요한 클래스 선택자|
  |:---:|---|
  |**종류별 방법**| `tag:link{속성: 값; ....}` -링크들 중에서 방문하지 않은 링크를 선택|
  || `tag:visited{속성: 값; ....}` -링크들 중에서 방문했던 링크를 선택|
  || `tag:hover{속성: 값; ....}` -마우스 포인터를 올려놓은 항목을 선택|
  || `tag:active{속성: 값; ....}` -클릭한 항목을 선택|
  || `tag:checked{속성: 값; ....}` -박스요소 중 체크한 항목을 선택|
  || `tag:not([속성=값]){속성: 값; ....}` -속성=값인 요소를 제외하고 모두 선택|

## Reponsive Web🙌

- 뷰포트(Viewport)
  - PC뿐만 아니라 다양한 모바일 기기로도 웹 사이트 접근이 가능해지면서 화면에 크기에 **반응**하는 화면 요소를 바꾸어 사이트를 구현하는 방식
  - 각 기기별 크기를 맞추기 위해 **뷰포트**를 설정하여 크기를 제어
    - 뷰포트: 현재 화면에 보여지고 있는 영역을 의미
  - 뷰포트 지정방식
    ```html
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <!--너비를 기기에 맞추는 방법-->
    ```
- 미디어 쿼리(media queries)

  - 사용자가 어떤 미디어를 사용하는가에 따라 사이트의 형태가 바뀌도록 CSS를 작성하는 방법
  - 미디어 쿼리 구문
    ```css
    @media 미디어 유형[ex|screen, tv] and (조건[max-width: 1439]) {
      속성: 속성값;
    }
    ```
  - 적용 방법

    ```html css
    <!--외부 파일-->
    <link rel="stylesheet" media="미디어 쿼리 조건,유형" href="css 파일경로" />

    @import url(css 파일경로) 미디어 쿼리 조건,유형;

    <!--내부 파일-->
    <style media="조건"></style>

    <style>
      @media <조건> {
      }
    </style>
    ```
