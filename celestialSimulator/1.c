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
void printPlanet(struct planet planets[], int count) {
	for (int i = 0; i < count; i++) {
		printf("%s : (%.3f, %.3f)\n", planets[i].name, planets[i].x, planets[i].y);
	}
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
	// 초기 위치는 x축 위
	int days;
	int planet_count = 8;

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

	printf("n일 동안의 행성의 움직임을 구현합니다. 단위: AU\n");
	printf("n을 입력: ");
	scanf("%d", &days);

	// 하루마다 행성의 위치를 출력
	for (int i = 0; i <= days; i++) {
		for (int j = 0; j < planet_count; j++) {
			planet_position_cal(&planets[j], i);
		}
		printf("%d일차 행성의 위치\n", i);
		printPlanet(planets, planet_count);
	}

	return 0;
}