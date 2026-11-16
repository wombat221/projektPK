#include "Generator.h"
#include <cmath>
#include <iostream>
constexpr double M_Pi = 3.14159265359;

double GeneratorProstokatny::generujSygnal(double SygWe) {
	double wynik = 0.0;
	m_krok = m_krok % m_okres;
	if (m_krok < m_wypelnienie * m_okres) {
		wynik = m_amplituda + m_skladowaStala;
	}
	else {
		wynik = m_skladowaStala;
	}
	m_krok++;
	return wynik;
}

double GeneratorSinusoidalny::generujSygnal(double SygWe) {
	double wynik = 0.0;
	m_krok = m_krok % m_okres;
	wynik = m_amplituda * std::sin(m_krok / static_cast<double>(m_okres) * M_Pi) + m_skladowaStala;
	m_krok++;
	return wynik;
}