# 2023OSS_TeamProject
<img src = "./WhynotBLogo.png">

### WhyNotB의 주제
---
메뉴 추천 기능이 있는 KIOSK

### WhyNotB에 대한 소개
---
음식점에 들어가서 음식을 주문하려고 KIOSK앞에 섰을 때 어떤 메뉴를 골라야 할지 고민한 적이 있으신가요?
뒤에서 줄 서있는 사람의 눈살에 떠밀려 허둥지둥 아무 메뉴나 고르신 경험이 있지는 않으신가요?

이제는 더 이상 그럴 필요가 없습니다! KIOSK에 내장되어 있는 메뉴 골라주기 기능을 사용해 빠르고 재미있게 메뉴를 선택해 보세요!


### WhyNotB에 포함시킬 기능
---
- 메뉴판 변경하기
  - 메뉴 추가
  - 메뉴 조회
  - 메뉴 수정
  - 메뉴 삭제
  - 현재 메뉴판 저장
- 메뉴 고르기
  - 랜덤 메뉴 추천 
  - 토너먼트로 메뉴 고르기
- 메뉴 주문하기
  - 장바구니 메뉴 추가
  - 장바구니 메뉴 수정
  - 장바구니 메뉴 조회
  - 장바구니 메뉴 삭제
  - 현재 장바구니 저장
  - 포인트 적립하기



### 개발 환경 및 언어
---
- 개발환경 
   - git
   - vscode
- 개발언어
  - C언어 



### 팀소개 및 팀원이 맡은 역할
---
- 정환
  - Repo Owner
  - WIKI 관리
  - Menu Interface 구현
  - FILE IO 구현
- 현준
  - 기능구현
  - README.md
  - 로고제작
- 승희
  - 기능구현
  - README.md

-----
### 코드설명
- [Mode 1]() : 메뉴판을 다루는 모드 🍽️
  - selectMenuOne() : 메뉴판 인터페이스를 출력하는 함수
  - addFood() : 메뉴판에 정보를 추가하는 함수
  - listFood() : 메뉴판을 보여주는 함수
  - updateFood() : 메뉴판을 수정하는 함수
  - deleteFood() : 메뉴판에서 메뉴를 삭제하는 함수
  - searchName() : 메뉴판에 있는 메뉴를 검색하는 함수
  - saveData() : 메뉴판에 등록된 정보를 따로 저장해, 후에 프로그램을 재시작해도 전의 메뉴판을 사용할 수 있게 하는 함수

<Mode 1 실행예시⬇️>

![Mode1](https://github.com/morehey/2023OSS_TeamProject/assets/126431810/a54cb994-e973-445a-95df-0f83fec69226)

-----
- [Mode 2]() : 고객이 메뉴를 고르도록 도와주는 모드 🏆
  - selectMenuTwo() : 메뉴 선택 도우미 인터페이스를 출력하는 함수
  - randomPick() : 고객이 음식의 종류를 고르면, 메뉴판에 있는 그 종류의 음식들 중 무작위로 한개를 골라주는 함수
  - worldCupPick() : 고객이 음식의 종류를 고르면, 메뉴판에 있는 그 종류의 음식들 중에서 토너먼트 형식으로 두 가지 중 한개의 음식을 고를 수 있게 하고, 최종적으로 1개의 메뉴만 선정하게 해 주는 함수

<Mode 2 실행예시⬇️>

![Mode2](https://github.com/morehey/2023OSS_TeamProject/assets/126431810/10ca5ad5-06a0-4df1-b640-cb1fe835a5b1)

-----
- [Mode 3]() : 메뉴를 장바구니에 담고 결제하는 모드 🧺
  - selectMenuThree() : 장바구니 메뉴 인터페이스를 출력하는 함수
  - saveMyFood() : 장바구니에 담긴 메뉴를 저장하는 함수
  - Buy() : 장바구니에 담긴 메뉴의 가격을 모두 더한 뒤, 얼마를 지불해야 하는지 알려주는 함수
  - searchMember() : 멤버로 등록이 되어 있는지 알려주는 함수
  - addMember() : 멤버로 등록시켜 주는 함수
  - saveMemberData() : 등록된 멤버를 저장해주는 함수

<Mode 3 실행예시⬇️>

![Mode3](https://github.com/morehey/2023OSS_TeamProject/assets/126431810/aa5ef389-65ae-40a9-b93a-046474ca1a09)

<br>
<br>
