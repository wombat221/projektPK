#include "Uslugi.h"

void Uslugi::setOkres_Generator() {
	double okresDyskretny = m_zegar.obliczOkresDyskretny();
	m_prostyUAR.getGenerator().setOkres(okresDyskretny);
}


void Uslugi::setOkres_Generator(double okresS,double interwalMs) {
	m_zegar.setInterwal(interwalMs);
	m_zegar.setOkres(okresS);
	setOkres_Generator();
}




void Uslugi::setOkres_Zegar(double okresS) {
	m_zegar.setOkres(okresS);
	setOkres_Generator();
}

void Uslugi::setInterwal_Zegar(double interwalMs) {
	m_zegar.setInterwal(interwalMs);
	setOkres_Generator();
}