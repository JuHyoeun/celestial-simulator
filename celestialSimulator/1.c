#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

// 하나의 행성에 담을 정보가 많기 때문에 구조체 사용
struct planet {
	char name[20];
	double radius; // 행성의 공전궤도 반지름, 단위: AU
	double orbit_cycle;// 단위: 일
	// 행성의 현재 위치, 단위: AU
	double x;
	double y;
};

// 행성들의 위치 출력함수
void printPlanet(struct planet mercury, struct planet venus, 
				struct planet earth , struct planet mars, struct planet jupiter, 
				struct planet saturn, struct planet uranus, struct planet neptune) {
	printf("%s : (%.3f, %.3f)\n", mercury.name, mercury.x, mercury.y);
	printf("%s : (%.3f, %.3f)\n", venus.name, venus.x, venus.y);
	printf("%s : (%.3f, %.3f)\n", earth.name, earth.x, earth.y);
	printf("%s : (%.3f, %.3f)\n", mars.name, mars.x, mars.y);
	printf("%s : (%.3f, %.3f)\n", jupiter.name, jupiter.x, jupiter.y);
	printf("%s : (%.3f, %.3f)\n", saturn.name, saturn.x, saturn.y);
	printf("%s : (%.3f, %.3f)\n", uranus.name, uranus.x, uranus.y);
	printf("%s : (%.3f, %.3f)\n", neptune.name, neptune.x, neptune.y);
	printf("\n");
}

void planet_position_cal(struct planet* a, int day) {
	double angle = 2 * M_PI * day / a->orbit_cycle;// 현재 궤도상 각도
	// 위치 좌표 계산
	a->x = a->radius * cos(angle);
	a->y = a->radius * sin(angle);
}

int main(void) {
	// sun을 (0, 0)으로, 2차원 사분면에서 행성의 위치를 표현
	// 단위는 1AU
	// 초기 위치는 x축 위에서 시작
	int days;

	struct planet mercury = { "mercury", 0.4, 87.97, 0.4, 0 };
	struct planet venus = { "venus", 0.7, 224.7, 0.7, 0 };
	struct planet earth = { "earth", 1, 365.26,  1, 0 };
	struct planet mars = { "mars", 1.5, 686.96, 1.5, 0 };
	struct planet jupiter = { "jupiter", 5.2, 4333.29, 5.2, 0 };
	struct planet saturn = { "saturn", 9.5, 10756.2, 9.5, 0 };
	struct planet uranus = { "uranus", 19.2, 30707.49, 19.2, 0 };
	struct planet neptune = { "neptune", 30.1, 60223.35, 30.1, 0 };

	printf("n일 동안의 행성의 움직임을 구현합니다.\n");
	printf("n을 입력: ");
	scanf("%d", &days);

	// 하루마다 행성의 위치를 출력
	// 수성
	for (int i = 0; i < days; i++) {
		planet_position_cal(&mercury, i);
		planet_position_cal(&venus, i);
		planet_position_cal(&earth, i);
		planet_position_cal(&mars, i);
		planet_position_cal(&jupiter, i);
		planet_position_cal(&saturn, i);
		planet_position_cal(&uranus, i);
		planet_position_cal(&neptune, i);
		printf("%d일차 행성의 위치\n", i);
		printPlanet(mercury, venus, earth, mars, jupiter, saturn, uranus, neptune);
	}

	return 0;
}