#include "ProstyUAR.h"
#include <exception>


double ProstyUAR::symuluj(double SygWe) {
	double uchyb = SygWe - m_modelARX.getOstatnieWyjscie();
	double wyjscieRegulator = m_regulatorPID.symuluj(uchyb);
	return m_modelARX.symuluj(wyjscieRegulator);
}




double ProstyUAR::symulujZGeneratorem() {
	if (czyJestWskaznik(m_generator)) {
		double SygGen = m_generator->generujSygnal();
		return symuluj(SygGen);
	}else
		throw std::invalid_argument("Pusty Wska¿nik generatora");
}





void ProstyUAR::UstawGenerator(GeneratorPtr generator) {
	if (!czyJestWskaznik(generator)) 
		throw std::invalid_argument("Pusty wskaznik nowego generatora");
	if (!czyJestWskaznik(m_generator)) {
		generator->setKrok(m_generator->getKrok());
	}
	m_generator = std::move(generator);
}



