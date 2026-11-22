#include "Uslugi.h"


void Uslugi::setOkres_Generator(double okres,double interwal) {
	int okresDyskretny = 1000 * okres /  interwal;
	m_prostyUAR.getGenerator().setOkres(okresDyskretny);
}