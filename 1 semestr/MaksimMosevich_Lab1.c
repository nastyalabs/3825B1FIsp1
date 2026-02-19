#include <stdio.h>
#include <math.h>

void main() {
    float dsp, dvp, der;
    float h, w, d;
    float m, m_nakl, m_2bokovin, m_krshk, m_dver2, m_polk;
    float t_dsp = 0.015f, t_dvp = 0.005f, t_dver = 0.01f;
    do {
        printf("Vvedite dsp ot 550 do 820, dvp ot 400 do 800, der ot 400 do 500\n");
        scanf("%f %f %f", &dsp, &dvp, &der);
    }
    while(550.f > dsp || 820.f < dsp || 400.f > dvp || 800.f < dvp || 400.f > der || 500.f < der);
    do {
        printf("Vvedite h ot 1.8 do 2.2, w ot 0.8 do 1.2, d ot 0.5 do 0.9, vse v metrax\n");
        scanf("%f %f %f", &h, &w, &d);
    } while ((1.8f > h)|| (h > 2.2f) || (0.8f > w) ||  (w > 1.2f)||  (0.5f > d) || (d > 0.9f));
    m_nakl = h * w * t_dvp * dvp;
    m_2bokovin = 2.f * h * d * t_dsp * dsp;
    m_krshk = 2.f * w * d * t_dsp * dsp;
    m_dver2 = h * w * t_dver * der;
    m_polk = floor((h - t_dsp * 2.f) * 100.f / 40.f) * (w - 2.f * t_dsp) * d * t_dsp * dsp;
    m = m_nakl + m_2bokovin + m_krshk + m_dver2 + m_polk;
    printf("massa = %f", m);
}