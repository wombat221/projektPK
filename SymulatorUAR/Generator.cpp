#include "Generator.h"
#include <cmath>
#include <algorithm>

constexpr double Pi = 3.14159265359;


double GeneratorProstokatny::generujSygnal() {
	double wynik = 0.0;
	if (m_krok < m_wypelnienie * m_probki) {
		wynik = m_amplituda + m_skladowaStala;
	}
	else {
		wynik = m_skladowaStala;
	}
	m_krok = (m_krok + 1) % m_probki;
	return wynik;
}



double GeneratorSinusoidalny::generujSygnal() {
    double wynik = 0.0;
    wynik = m_amplituda * std::sin(m_krok / static_cast<double>(m_probki) * 2 * Pi) + m_skladowaStala;
    m_krok = (m_krok + 1) % m_probki;
    return wynik;
}


void Generator::setAmplituda(double amplituda) {
	m_amplituda = std::clamp(amplituda, 0.0, 100.0);
}

void Generator::setProbki(int Probki) {
	if (Probki < 1)
		Probki = 1;
	m_probki = Probki;
	m_krok %= m_probki;
}

void Generator::setSkladowa(double stala) {
	m_skladowaStala = std::clamp(stala, -100.0, 100.0);
}

void Generator::setKrok(int krok) {
	m_krok = krok;
}


void GeneratorProstokatny::setWypelnienie(double wypelnienie) {
	m_wypelnienie = std::clamp(wypelnienie, 0.0, 1.0);
}








