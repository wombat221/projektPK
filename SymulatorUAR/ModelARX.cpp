#include "ModelARX.h"

ModelARX::ModelARX(std::vector<double> a,std::vector<double> b, int opoznienie, double odchylenie)  {
    setOpoznienie(opoznienie);
    setWspolczynnikiA(a);
    setWspolczynnikiB(b);
    setZaklocenia(odchylenie);
}




double ModelARX::Zaklocenie() {
    if (m_zaklocenia <= 0.0)
        return 0.0;
    std::normal_distribution<double> uniDistReal(0.0, m_zaklocenia);
    return uniDistReal(gen_plos);
}

double ModelARX::symuluj(double SygWe) {
    if (czyOgraniczenieU()) {
        SygWe = std::clamp(SygWe, m_uMin, m_uMax);
    }
    m_buforWejscia.push_front(SygWe);
    m_buforWejscia.pop_back();

    double wynik = 0.0;

    for (int i = 0; i < m_WspolczynnikiB.size(); i++) {
        wynik += m_WspolczynnikiB[i] * m_buforWejscia[i + m_opoznienie];
    }
    for (int i = 0; i < m_WspolczynnikiA.size(); i++) {
        wynik -= m_WspolczynnikiA[i] * m_buforWyjscia[i];
    }
    wynik += Zaklocenie();

    if (czyOgraniczenieY()) {
        wynik = std::clamp(wynik, m_yMin, m_yMax);
    }
    
    m_buforWyjscia.push_front(wynik);
    m_buforWyjscia.pop_back();

    return wynik;
}



void ModelARX::setUmin(double uMin) {
    m_uMin = std::clamp(uMin, -100.0, m_uMax);
}

void ModelARX::setUmax(double uMax) {
    m_uMax = std::clamp(uMax, m_uMin, 100.0);
}
void ModelARX::setOgraniczeniaU(double uMin, double uMax) {
    uMin = std::clamp(uMin, -100.0, 100.0);
    uMax = std::clamp(uMax, -100.0, 100.0);

    if (uMin > uMax) {
        return;
    }
    m_uMin = uMin;
    m_uMax = uMax;
}

void ModelARX::setYmin(double yMin) {
    m_yMin = std::clamp(yMin, -100.0, m_yMax);
}

void ModelARX::setYmax(double yMax) {
    m_yMax = std::clamp(yMax, m_yMin, 100.0);
}

void ModelARX::setOgraniczeniaY(double yMin, double yMax) {
    yMin = std::clamp(yMin, -100.0, 100.0);
    yMax = std::clamp(yMax, -100.0, 100.0);

    if (yMin > yMax) {
        return;
    }
    m_yMin = yMin;
    m_yMax = yMax;
}

void ModelARX::setCzyOgraniczenieU(bool OgraniczenieU) {
    m_ograniczenieU = OgraniczenieU;
}

void ModelARX::setCzyOgraniczenieY(bool OgraniczenieY) {
    m_ograniczenieY = OgraniczenieY;
}

void ModelARX::setOpoznienie(int opoznienie) {
   m_opoznienie = std::clamp(opoznienie, 1, 20);
   m_buforWejscia.resize(m_WspolczynnikiB.size() + m_opoznienie, 0.0);
}

void ModelARX::setZaklocenia(double zaklocenia) {
    m_zaklocenia = std::clamp(zaklocenia, 0.0, 0.1);
}

void ModelARX::setWspolczynnikiA(std::vector<double> a){
    if (a.empty())
        return;
    if (a == m_WspolczynnikiA)
        return;
    for (double& wspolczynnikA : a)
        wspolczynnikA = std::clamp(wspolczynnikA, -2.0, 2.0);

    m_WspolczynnikiA = a;
    m_buforWyjscia.resize(m_WspolczynnikiA.size(), 0.0);
}
void ModelARX::setWspolczynnikiB(std::vector<double> b) {
    if (b.empty())
        return;
    if (b == m_WspolczynnikiB)
        return;
    for (double& wspolczynnikB : b)
        wspolczynnikB = std::clamp(wspolczynnikB, -2.0, 2.0);

    m_WspolczynnikiB = b;
    m_buforWejscia.resize(m_WspolczynnikiB.size() + m_opoznienie, 0.0);
}

void ModelARX::reset() {
    m_buforWejscia.assign(m_buforWejscia.size(),0.0);
    m_buforWyjscia.assign(m_buforWyjscia.size(),0.0);
}