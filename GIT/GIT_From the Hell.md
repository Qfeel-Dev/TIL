# GIT📜

## Who is GIT❔

- 현대 코드의 복잡성으로 등장한 **버전관리 프로그램** (CVS,SVN 등)

- 버전관리란 프로그램 개발을 진행하면서 변경되는 이력들을 관리해주는 프로그램

- 이전에는 파일의 이름을 변경하며 그에 따른 구분을 하였지만, 버전관리 프로그램의 등장으로 파일의 이름 변경없이 이력관리가 가능해짐!

- GIT에서는 이력관리 뿐만 아닌 Backup, Recovery, Collaboration 기능을 제공

## GIT Structure🧱

- 정확한 정보로 찾아오겠습니다 😀

## GIT Command👨‍💻

- GIT의 명령어 들은 다양한 옵션 조합으로 사용될 수 있음으로, <br>`git command --HELP` 를 통해서 옵션을 알아본 뒤 사용하는 것이 좋다.
- 이곳에서는 주로 사용하는 명령어 위주로 기록하도록 하겠다!
  <br>

- 기초 셋팅 명령어 <br>

  ```
  git config  //버전관리 시 누가 했는지 알기위한 이름,이메일 설정 명령어
  ```

- 버전관리 시작 명령어 <br>

  ```git
  git init //신규 저장소 생성 명령어

  git clone //타인의 원격 저장소를 내 저장소로 불러오는 명령어
  ```

- 상태 확인 명령어 <br>

  ```git
   git status //현 저장소의 버전관리 상황을 보여주는 명령어(commit,add 여부 등)

   git log //커밋한 버전별로 이름,이메일,커밋 메세지를 확인하는 명령어
  ```

- 백업 명령어 <br>

  ```git
  git add [File Name] //stage area로 파일을 옮기는 명령어

  git commit //stage area의 파일들을 repo로 옮기는 명령어

  git push //local repo에 파일들을 remote repo로 옮기는 명령어
  ```

- Branch 관련 명령어 <br>

  ```git
  git branch // 현재 생성된 branch들을 보여주는 명령어
  // 뒤에 브랜치 이름을 추가로 작성할 경우 브랜치 생성 명령어

  git checkout [Branch Name] //Branch Name으로 선택한 브런치로 이동하는 명령어
  ```

- 원격 저장소 관련 명령어 <br>

  ```git
  git remote add [remote repo name] [addr] //초기 원격 저장소 연결 명령어

  git remote //연결된 원격 저장소 확인 명령어
  ```
