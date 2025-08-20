#define _USE_MATH_DEFINES
#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>

// 하나의 행성에 담을 정보가 많기 때문에 구조체 사용
struct planet {
	char name[20];
	double radius; // 행성의 공전궤도 반지름, 단위: AU
	double orbit_cycle;// 단위: 일
	// 행성의 현재 위치, 단위: AU
	double x;
	double y;
};

// 코드 반복 줄이기 위해 구조체 배열 사용
struct planet planets[8] = {
	{ "mercury", 0.4, 87.97, 0.4, 0 },
	{ "venus",   0.7, 224.7, 0.7, 0 },
	{ "earth",   1.0, 365.26, 1.0, 0 },
	{ "mars",    1.5, 686.96, 1.5, 0 },
	{ "jupiter", 5.2, 4333.29, 5.2, 0 },
	{ "saturn",  9.5, 10756.2, 9.5, 0 },
	{ "uranus", 19.2, 30707.49, 19.2, 0 },
	{ "neptune",30.1, 60223.35, 30.1, 0 }
};

int day = 0; // 현재 시뮬레이션 일 수

void planet_position_cal(struct planet* a, int day) {
	double angle = 2 * M_PI * day / a->orbit_cycle;// 현재 궤도상 각도
	// 위치 좌표 계산
	a->x = a->radius * cos(angle);
	a->y = a->radius * sin(angle);
}

// 화면에 점으로 행성 그리기
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBegin(GL_POINTS);
	for (int i = 0; i < 8; i++) {
		planet_position_cal(&planets[i], day);
		glVertex2d(planets[i].x, planets[i].y); // AU좌표 그대로 사용
	}
	glEnd();

	glutSwapBuffers();
}

// 시뮬레이션 업데이트
void update(int value) {
	day++; // 하루 증가
	glutPostRedisplay(); // 화면 다시 그리기
	glutTimerFunc(50, update, 0); // 0.05초마다 update 호출
}

void initOpenGL() {
	glEnable(GL_DEPTH_TEST);       // 깊이 테스트 활성화
	glClearColor(0, 0, 0, 1);  // 배경 검은색
	glPointSize(8);

	// 좌표계를 AU 단위에 맞춤
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-35, 35, -35, 35, -1, 1); // 화면 안에 모든 행성 포함
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Solar System Simulation");

	initOpenGL();
	glutDisplayFunc(display);  // 디스플레이 콜백 등록
	glutTimerFunc(50, update, 0);

	glutMainLoop();            // 이벤트 루프 시작
	return 0;
}