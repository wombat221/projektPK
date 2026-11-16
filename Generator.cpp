
#include "Generator.h";
#include <cmath>
#include <iostream>
constexpr double Pi = 3.14159265359;



Generator::Generator(double amplituda, double wypelnienie, double okres, double stala, sygnal sygnal) {
	
}

double Generator::generujSygnal(double SygWe){
	double wynik = 0.0;
	if (m_sygnal == sygnal::prostokatny) {
		if (m_krok % m_okres < m_wypelnienie * m_okres) {
			wynik =  m_amplituda + m_skladowaStala;
		}
		else {
			wynik =  m_skladowaStala;
		}
	}
	else {
		wynik = m_amplituda * std::sin(m_krok % m_okres / static_cast<double>(m_okres) * Pi) + m_skladowaStala;
	}
	m_krok++;
	return wynik;
}
