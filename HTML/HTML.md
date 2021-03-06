# HTML📜

## Hello HTML👋

- **"Hyper Text Markup Language"** 의 줄임말로, 웹 문서를 만드는 **기본적인** 언어

- 기본적으로 웹 브라우저에 내용을 표시하고, 문서끼리 서로 연결하는 기능을 가진 언어

- HTML의 확장자는 `".html"`이며,<br>작성은 코드에디터(ex| notepad, vs code)한 뒤,<br> 실행은 웹 브라우저(ex| chrome,IE)로 실행이 가능하다

## HTML Basic Structure🧱

- HTML은 다른 문서들과 달리 정해진 기본 형식`(htnml,head,body)`을 따라야한다.

  ```html
  <!--현재 문서가 html임을 알리는 tag-->
  <!DOCTYPE html>
  <!--웹 문서의 시작-->
  <html lang="en">
    <!--웹의 필요한 정보 시작-->
    <head>
      <!--웹의 필요한 정보-->
    </head>
    <!--웹의 필요한 정보 끝-->

    <!--웹의 표현할 정보 시작-->
    <body>
      <!--웹의 표현한 정보-->
    </body>
    <!--웹의 표현할 정보 끝-->
  </html>
  <!--웹 문서의 끝-->
  ```

- 위의 코드와 같이 시작과 끝 사이에 적절한 태그를 작성하는 것으로 HTML을 통한 웹 문서 제작이 진행된다.

## How to use HTML📕

- 위에 말한 HTML 기본 형식에 따른 각 상황별 적절한 태그에 대해서 소개할 것이다.

- Head 영역

  ```html
  <meta />
  <!--브라우저에 보이진 않지만 필요한 정보를 담음 (ex|인코딩,키워드 등)-->

  <title>문서 제목</title>
  <!--웹문서의 제목을 작성 -->
  ```

- Body 영역

  - 추가적인 구조를 만드는 태그

    ```html
    <header></header>
    <!--헤더 영역의 들어갈 내용들을 감싸는 역할 -->

    <nav></nav>
    <!-- 타 웹 문서로 이동할때 필요한 링크를 모아 내비게이션을 만드는 역할 -->

    <main></main>
    <!--웹문서의 핵심이 되는 내용이 들어가는 태그-->

    <article></article>

    <section></section>

    <footer></footer>
    <!--푸터 영역의 들어갈 내용을 감싸는 역할-->

    <div></div>
    <!--소스를 묶는 역할, 주로 구조,스타일을 만들고 적용 시키기 위해 사용-->
    ```

  - 웹 문서의 내용 출력에 관한 태그 (테이블,이미지 등 포함)

    ```html
    <h1>제목</h1>
    <!--Heading Tag-->
    <!--웹 문서 콘텐츠의 제목을 표시하는 태그 (!= title) 1이아닌 다른 숫자로 변경 가능-->

    <p>문단</p>
    <!--Paragraph Tag-->
    <!--문단을 구별하기 위해 문단을 감싸주는 태그-->

    <br />
    <!--줄 바꿈 태그-->

    <blockquote>인용문</blockquote>
    <!--인용문을 표시하기 위한 태그-->

    <strong> </strong>
    <b> </b>
    <!--텍스트를 굵게 표시하는 태그-->
    <!--strong은 주의사항, 경고의 내용이 있는 경우 사용하고, b는 일반적인 경우 사용-->

    <em>> </em>
    <i> </i>
    <!--텍스트를 이탤릭체로 표시하는 태그-->
    <!--strong은 주의사항, 경고의 내용이 있는 경우 사용하고, b는 일반적인 경우 사용-->

    <ol></ol>
    <!--Ordered list-->
    <!--순서있는 리스트를 생성하는 태그, type,start 속성을 통해 형식과 초기값 변경 가능 -->

    <ul></ul>
    <!--Unordered list-->
    <!--순서없는 리스트를 생성하는 태그-->

    <li></li>
    <!--list-->
    <!--ol,ul 사이에 들어가서 리스트 항목을 생성하는 태그-->

    <table></table>
    <!--표의 시작,끝을 알리는 태그 표의 내용들은 여기에 들어가야 함-->

    <caption></caption>
    <!--표의 제목을 알리는 태그-->

    <tr></tr>
    <!--행을 만드는 태그-->

    <td></td>
    <th></th>
    <!--행 안에 있는 셀을 표현하는 태그 임으로 tr태그 안에 들어가 있어야함-->
    <!--rowspan,colspan 옵션을 통해서 셀을 병합할 수 있음 (본인기준 row오른 col은 아래)-->

    <thead></thead>
    <tbody></tbody>
    <tfoot></tfoot>
    <!--표의 구조를 설계하는 태그 header,main,footer와 비슷-->

    <colgroup>
      <col />
    </colgroup>
    <!--열 서식을 지정하기 위해 사용하는 태그, 열의 갯수만큼 col태그를 사용-->

    <img src="img 주소" alt="대체 택스터" width="50%" height="50px" />
    <!--문서내에 이미지를 표현을 위한 태그,-->
    <!--이미지의 주소,택스트,크기는 옵션으로 입력-->

    <object width="50px" height="50%" data="멀티미디어 파일"></object>
    <embed src="파일 경로" width="50px" height="50%" />
    <!--멀티미디어 파일을 웹문서에 삽입하기 위한 태그-->
    <!--멀티미디어 파일의 주소,택스트,크기는 옵션으로 입력-->

    <audio src="오디오 파일 경로"></audio>
    <video src="비디오 파일 경로"></video>
    <!--비디오,오디오 파일을 웹문서에 삽입하기 위한 태그-->
    <!--파일의 주소,택스트,크기,동작 방식은 옵션으로 입력-->

    <a href="링크걸어줄 주소">누르면 이동할 텍스트 또는 이미지</a>
    <!--anchor-->
    <!--HTML의 핵심 기능인 문서와 문서를 링크해주는 테그-->
    ```

  - 웹 문서의 입력에 관한 태그

    ```html
    <form action="입력 폼을 처리해줄 서버 주소">
      <!--여러 폼 요소 -->
    </form>
    <!--입력 폼을 만드는 가장 기본적인 태그-->
    <!--어떤 식으로 서버를 활용할 것인지 옵션을 통해 추가 입력-->

    <fieldset>
      <legend>그룹 이름</legend>
    </fieldset>
    <!--입력 폼을 그룹으로 묶는 태그(fieldset) -->
    <!--그룹으로 묶인 태그의 이름을 부여하는 태그(legend) -->

    <label>레이블명</label>
    <!--폼 요소에 레이블을 붙일 때 사용되는 태그-->
    <!--폼 요소를 감싸는 방식 vs for,id를 사용하는 방식-->

    <input type="###" />
    <!--입력을 받을 수 있는 태그-->
    <!--type속성을 통해 다양한 데이터 입력가능 속성은 하단 표로 정리-->
    <!--type속성에 따른 각기 다른 옵션 설정-->

    <textarea> 내용 </textarea>
    <!--폼에서 텍스트를 여러 줄 입력하는 영역을 만드는 태그-->

    <select>
      <option value="값1">내용</option>
      <option value="값2">내용</option>
    </select>
    <!--드롭다운 목록을 만들어 주는 태그-->
    <!--select 틀, option 목록-->

    <button>내용</button>
    <!--버튼을 만들어 주는 태그-->
    <!--input태그로도 구현가능-->
    ```

    - input 태그 type 정리

      | 종류     | 설정                                           |
      | :------- | :--------------------------------------------- |
      | text     | 텍스트 박스 생성                               |
      | password | 비밀번호 전용 텍스트 박스 생성                 |
      | search   | 검색 전용 텍스트 박스 생성                     |
      | email    | 이메일 전용 텍스트 박스 생성                   |
      | tel      | 전화번호 전용 텍스트 박스 생성                 |
      | number   | 숫자 입력 및 조절할 수 있는 스핀 박스 생성     |
      | range    | 숫자 입력 및 조절할 수 있는 슬라이드 막대 생성 |
      | checkbox | 항목 선택 가능한 체크박스 생성(2개 이상 가능)  |
      | radio    | 항목 선택 가능한 라디오 버튼 생성(1개만 가능)  |
      | data     | 지역기준 날짜(연,월,일)를 넣는 박스 생성       |
      | month    | 지역기준 날짜(연,월,일)를 넣는 박스 생성       |
      | time     | 지역기준 시간을 넣는 박스 생성                 |
      | reseet   | 리셋 버튼 생성                                 |
      | sumbut   | 전송 버튼 생성                                 |
      | button   | 사용자 지정 버튼 생성                          |
      | hidden   | 보이지 않지만 서버로 값을 넘겨주는 필드 생성   |
      |          |                                                |
