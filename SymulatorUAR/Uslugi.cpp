#include "Uslugi.h"

void Uslugi::setOkres_Generator() {
	double okresDyskretny = m_zegar.obliczOkresDyskretny();
	m_prostyUAR.getGenerator().setOkres(okresDyskretny);
}


void Uslugi::setOkres_Generator(double okresS,int interwalMs) {
	m_zegar.setInterwal(interwalMs);
	m_zegar.setOkres(okresS);
	setOkres_Generator();
}

void Uslugi::setOkres_Zegar(double okresS) {
	m_zegar.setOkres(okresS);
	setOkres_Generator();
}

void Uslugi::setInterwal_Zegar(int interwalMs) {
	m_zegar.setInterwal(interwalMs);
	setOkres_Generator();
}

void Uslugi::ustawGenerator(Generator::TypGeneratora typ, double amplituda,
							double okresS, int interwalMs, 
							double stala,double wypelnienie) 
{
	setOkres_Generator(okresS, interwalMs);

	if (typ == Generator::TypGeneratora::prostokat)
		m_prostyUAR.UstawGenerator(std::make_unique<GeneratorProstokatny>(amplituda, m_zegar.obliczOkresDyskretny(), stala, wypelnienie));
	else 
		m_prostyUAR.UstawGenerator(std::make_unique<GeneratorSinusoidalny>(amplituda, m_zegar.obliczOkresDyskretny(), stala));
}