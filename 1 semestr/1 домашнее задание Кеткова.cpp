#include <stdio.h>
void main() {
	float h, w, d;
	float plot_dsp, plot_dvp, plot_wood;
	printf("Vvedite h:");
	scanf_s("%f", &h);
	printf("Vvedite w:");
	scanf_s("%f", &w);
	printf("Vvedite d:");
	scanf_s("%f", &d);
	printf("Vvedite plot_dsp:");
	scanf_s("%f", &plot_dsp);
	printf("Vvedite plot_dvp:");
	scanf_s("%f", &plot_dvp);
	printf("Vvedite plot_wood:");
	scanf_s("%f", &plot_wood);
	float t_dsp = 1.5;
	float t_dvp = 0.5;
	float t_wood = 1.0;
	float v_back = h * w * t_dvp;
	float m_back = v_back * plot_dvp;
	float v_side = 2 * h * d * t_dsp;
	float m_side = v_side * plot_dsp;
	float v_top_bottom = 2 * w * d * t_dsp;
	float m_top_bottom = v_top_bottom * plot_dsp;
	float v_door = w * h * t_wood;
	float m_door = v_door * plot_wood;
	int num_shelf = (int)(h / 40);
	float v_shelf = num_shelf * w * d * t_dsp;
	float m_shelf = v_shelf * plot_dsp;
	float total_m_g = m_back + m_side + m_top_bottom + m_door + m_shelf;
	float total_m_kg = total_m_g / 1000.0;
	printf("Massa= %f", total_m_kg);

}
