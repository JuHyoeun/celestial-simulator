#include <stdio.h>

// 하나의 행성에 담을 정보가 많기 때문에 구조체 사용
struct planet {
	char name[20];
	float x;
	float y;
};

void printPlanet(struct planet a) {
	printf("%s : (%.3f, %.3f)\n", a.name, a.x, a.y);
}

int main(void) {
	// sun을 (0, 0)으로, 2차원 사분면에서 행성의 위치를 표현
	// 단위는 1AU
	// 초기 위치는 x축 위에서 시작

	struct planet mercury = { "mercury", 0.4, 0 };
	struct planet venus = { "venus", 0.7, 0 };
	struct planet earth = { "earth", 1, 0 };
	struct planet mars = { "mars", 1.5, 0 };
	struct planet jupiter = { "jupiter", 5.2, 0 };
	struct planet saturn = { "saturn", 9.5, 0 };
	struct planet uranus = { "uranus", 19.2, 0 };
	struct planet neptune = { "neptune", 30.1, 0 };

	printPlanet(mercury);
	printPlanet(venus);
	printPlanet(earth);
	printPlanet(mars);
	printPlanet(jupiter);
	printPlanet(saturn);
	printPlanet(uranus);
	printPlanet(neptune);
}