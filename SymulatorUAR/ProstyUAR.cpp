#include "ProstyUAR.h"


double ProstyUAR::symuluj(double SygWe) {
	double uchyb = SygWe - m_modelARX.getOstatnieWyjscie();
	double wyjscieRegulatora = m_regulatorPID.symuluj(uchyb);
	return m_modelARX.symuluj(wyjscieRegulatora);
}




wynikiSymulacji ProstyUAR::symulujZGeneratorem() {
	if (czyJestWskaznik()) {
		wynikiSymulacji wynik;
		wynik.zadana = m_generator->generujSygnal();
		wynik.uchyb = wynik.zadana - m_modelARX.getOstatnieWyjscie();
		double wyjscieRegulatora = m_regulatorPID.symuluj(wynik.uchyb);
		wynik.proporcjonalnaP = m_regulatorPID.getProporcjonalnaP();
		wynik.CalkujacaI = m_regulatorPID.getCalkujacaI();
		wynik.rozniczkujacaD = m_regulatorPID.getRozniczkujacaD();
		wynik.wyjscie = m_modelARX.symuluj(wyjscieRegulatora);
		return wynik;
	}else
		throw std::logic_error("Pusty Wskażnik generatora");
}

Generator& ProstyUAR::getGenerator() {
	if (czyJestWskaznik())
		return *m_generator;
	else
		throw std::logic_error("Nie ma generatora");
}

const Generator& ProstyUAR::getGenerator() const {
	if (m_generator != nullptr)
		return *m_generator;
	else
		throw std::logic_error("Nie ma generatora");
}


void ProstyUAR::UstawGenerator(GeneratorPtr generator) {
    if (czyJestWskaznik() && generator != nullptr)
		generator->setKrok(m_generator->getKrok());
	m_generator = std::move(generator);
}




