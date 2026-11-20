#include "Generator.h"
#include <cmath>
#include <iostream>
constexpr double Pi = 3.14159265359;


void Generator::setAmplituda(double amplituda) {
	m_amplituda = amplituda;
}


void Generator::setOkres(int okres) {
	m_okres = okres;
}

void Generator::setSkladowa(double stala) {
	m_skladowaStala = stala;
}


void GeneratorProstokatny::setWypelnienie(double wypelnienie) {
	m_wypelnienie = wypelnienie;
};




double GeneratorProstokatny::generujSygnal(double SygWe) {
	double wynik = 0.0;
	if (m_krok < m_wypelnienie * m_okres) {
		wynik = m_amplituda + m_skladowaStala;
	}
	else {
		wynik = m_skladowaStala;
	}
	m_krok = (m_krok + 1) % m_okres;
	return wynik;
}

double GeneratorSinusoidalny::generujSygnal(double SygWe) {
	double wynik = 0.0;
	wynik = m_amplituda * std::sin(m_krok / static_cast<double>(m_okres) * 2 * Pi) + m_skladowaStala;
	m_krok = (m_krok + 1) % m_okres;
	return wynik;
}



GeneratorSinusoidalny GeneratorProstokatny::konwersjaNaSinusoidalny(){
	return GeneratorSinusoidalny(this->m_amplituda, this->m_okres,this->m_skladowaStala,this->m_krok);
}

GeneratorProstokatny GeneratorSinusoidalny::konwersjaNaProstokatny(double wypelnienie) {
	return GeneratorProstokatny(this->m_amplituda, this->m_okres, this->m_skladowaStala,wypelnienie, this->m_krok);
}