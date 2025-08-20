# Celestial Simulator
태양계 행성의 움직임을 간단히 시뮬레이션하는 프로젝트입니다.  
C언어를 사용하여 행성의 궤도를 구현합니다.

## 기능
- 2차원 사분면 상의 좌표로 하루마다 행성들의 공전 궤도를 출력

## 사용 기술
- 언어: C언어
- 버전 관리: Git, GitHub
- 개발환경: VS
- 수학: 삼각함수(`cos`, `sin`)를 이용한 원형 궤도 계산

## 실행 방법
### Visual Studio에서 실행
1. Visual Studio에서 `celestial-simulator.sln` 솔루션 파일 열기
2. 빌드(Build) → 실행(F5)
3. 콘솔 창에서 일수를 입력하면, 하루마다 행성의 좌표가 출력됨

### GCC(명령어 기반)에서 실행
1. Git Bash 또는 터미널에서 프로젝트 폴더로 이동
2. 아래 명령어로 컴파일
   ```bash
   gcc -o celestialSimulator 1.c -lm
3. 컴파일 후 실행
   ```bash
   ./celestialSimulator


## 앞으로 추가 예정
- 시각화
- 자전 궤도 구현

---
Made by JuHyoeun
