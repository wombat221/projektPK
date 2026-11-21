#include "ProstyUAR.h"
#include <exception>


double ProstyUAR::symuluj(double SygWe) {
	double uchyb = SygWe - m_modelARX.getOstatnieWyjscie();
	double wyjscieRegulator = m_regulatorPID.symuluj(uchyb);
	return m_modelARX.symuluj(wyjscieRegulator);
}




double ProstyUAR::symulujZGeneratorem() {
	if (czyJestWskaznik()) {
		double SygGen = m_generator->generujSygnal();
		return symuluj(SygGen);
	}else
		throw std::invalid_argument("Pusty Wska¿nik generatora");
}

Generator& ProstyUAR::getGenerator() {
	if (czyJestWskaznik()) {
		return *m_generator;
	}
	else
		throw std::invalid_argument("Nie ma generatora");
};



void ProstyUAR::UstawGenerator(GeneratorPtr generator) {
	if (generator == nullptr)
		throw std::invalid_argument("Pusty wskaznik nowego generatora");
	if (!czyJestWskaznik()) {
		generator->setKrok(m_generator->getKrok());
	}
	m_generator = std::move(generator);
}




