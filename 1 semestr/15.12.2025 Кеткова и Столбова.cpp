#include <stdio.h>
#define N 4
typedef struct {
	char last_name[50];
	char num_group[20];
	double sr_ball;
} student;
void main() {
	student portal[] = { {"Lobanov","3825B1FIsp1",4.75},{"Lopatov","3825PMI1",3.75},{"Grablev","3825B1Ping1",5.0},{"Kuzmina","3825B1Povar",1.0} };
	int n = sizeof(portal) / sizeof(portal[0]);
	printf("Vyvod massiva: ");
	for (student *s = portal; s < portal + n; s++) {
		printf("Last_name:%s \t Num_group: %s \t Sr_ball: %lf \n", s->last_name, s->num_group, s->sr_ball);
	}
	printf("Otlychniki: ");
	for (int i = 0; i < n; i++) {
		if (portal[i].sr_ball >= 4.5) {
			printf("Last_name:%s \t Num_group: %s \t Sr_ball: %lf \n", portal[i].last_name, portal[i].num_group, portal[i].sr_ball);
		}
	}
}




