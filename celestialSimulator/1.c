#include <stdio.h>
#define AU 150000000 // km

// 하나의 행성에 담을 정보가 많기 때문에 구조체 사용
struct planet {
	char name[20];
	float radian; // 행성의 공전궤도 반지름
	// 행성의 현재 위치
	float x;
	float y;
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
}

int main(void) {
	// sun을 (0, 0)으로, 2차원 사분면에서 행성의 위치를 표현
	// 단위는 1AU
	// 초기 위치는 x축 위에서 시작

	struct planet mercury = { "mercury", 0.4 * AU, 0.4 * AU, 0 };
	struct planet venus = { "venus", 0.7 * AU, 0.7 * AU, 0 };
	struct planet earth = { "earth", 1 * AU, 1 * AU, 0 };
	struct planet mars = { "mars", 1.5 * AU, 1.5 * AU, 0 };
	struct planet jupiter = { "jupiter", 5.2 * AU, 5.2 * AU, 0 };
	struct planet saturn = { "saturn", 9.5 * AU, 9.5 * AU, 0 };
	struct planet uranus = { "uranus", 19.2 * AU, 19.2 * AU, 0 };
	struct planet neptune = { "neptune", 30.1 * AU, 30.1 * AU, 0 };

	printPlanet(mercury, venus, earth, mars, jupiter, saturn, uranus, neptune);
}