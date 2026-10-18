#pragma once
#include <iostream>
#include <vector>
#include <deque>

class ModelARX {
private:
	std::vector<double> m_AWspolczynniki;
	std::vector<double> m_BWspolczynniki;
	int m_Opoznienie;
	double m_Zaklocenia;
	std::deque<double> m_buforOpoznienia;
	std::deque<double> m_buforU; 
	std::deque<double> m_buforY;
public:
	ModelARX(std::vector<double> a, std::vector<double> b, int k, double zak) :
		m_AWspolczynniki(a), m_BWspolczynniki(b), m_Opoznienie(k), m_Zaklocenia(zak) {
			m_buforOpoznienia.assign(m_Opoznienie, 0.0);
			m_buforU.assign(m_BWspolczynniki.size(), 0);
			m_buforY.assign(m_AWspolczynniki.size(), 0);
	};

	double symuluj(double sygWe);
};