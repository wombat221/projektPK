#include "ModelARX.h"

double ModelARX::symuluj(double SygWe) {
  
    m_buforOpoznienia.push_front(SygWe);
   
    double u_opoznione = m_buforOpoznienia.back();
    m_buforOpoznienia.pop_back();

    m_buforU.push_front(u_opoznione);
    m_buforU.pop_back();

    double wynik = 0.0;

    for (int i = 0; i < m_BWspolczynniki.size(); i++) {
        wynik += m_BWspolczynniki[i] * m_buforU[i];
    }
    for (int i = 0; i < m_AWspolczynniki.size(); i++) {
        wynik -= m_AWspolczynniki[i] * m_buforY[i];
    }

   
    m_buforY.push_front(wynik);
    m_buforY.pop_back();
    

    return wynik;
};