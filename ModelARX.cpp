#include "ModelARX.h"

ModelARX::ModelARX(std::vector<double> a, std::vector<double> b, int opoznienie, double odchylenie)
   : m_AWspolczynniki(a), m_BWspolczynniki(b), m_opoznienie(opoznienie), m_odchylenie(odchylenie)
{
    m_buforWejscia.resize(m_BWspolczynniki.size() + m_opoznienie,0.0);
    m_buforWyjscia.resize(m_BWspolczynniki.size(), 0.0);
}




double ModelARX::LosoweZaklocenie() {
    return 2.0;
};


void ModelARX::setUmin(double uMin) {
    if (uMin > m_uMax)  {
        return;
    }
    m_uMin = uMin;
};

void ModelARX::setYmin(double yMin) {
    if (yMin > m_yMax) {
        return;
    }
    m_uMin = yMin;
};

double ModelARX::symuluj(double SygWe) {
    if (m_ograniczenieU) {
        if (SygWe < m_uMin) {
            SygWe = m_uMin;
        }
        if (SygWe > m_uMax) {
            SygWe = m_uMax;
        }
    }
    m_buforWejscia.push_front(SygWe);
    m_buforWejscia.pop_back();

    double wynik = 0.0;

    for (int i = 0; i < m_BWspolczynniki.size(); i++) {
        wynik += m_BWspolczynniki[i] * m_buforWejscia[i + m_opoznienie];
    }
    for (int i = 0; i < m_AWspolczynniki.size(); i++) {
        wynik -= m_AWspolczynniki[i] * m_buforWyjscia[i];
    }
    if (m_ograniczenieY) {
        if (wynik < m_yMin) {
            wynik = m_yMin;
        }
        if (wynik > m_yMax) {
            wynik = m_yMax;
        }
    }

  
    m_buforWyjscia.push_front(wynik);
    m_buforWyjscia.pop_back();
    
    return wynik;
};