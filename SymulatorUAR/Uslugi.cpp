#include "Uslugi.h"

void Uslugi::setOkres_Gen() {
	double okresDyskretny = m_zegar.obliczOkresDyskretny();
	m_prostyUAR.getGenerator().setProbki(okresDyskretny);
}


void Uslugi::setOkres_Gen(double okresS,int interwalMs) {
	m_zegar.setInterwal(interwalMs);
	m_zegar.setOkres(okresS);
	setOkres_Gen();
}

void Uslugi::setOkres_Zegar(double okresS) {
	m_zegar.setOkres(okresS);
	setOkres_Gen();
}

void Uslugi::setInterwal_Zegar(int interwalMs) {
	m_zegar.setInterwal(interwalMs);
	setOkres_Gen();
}

void Uslugi::ustawGenerator_UAR(Generator::TypGeneratora typ, double amplituda,
							double okresS, int interwalMs, 
							double stala,double wypelnienie = 0.5) 
{
	setOkres_Gen(okresS, interwalMs);

	if (typ == Generator::TypGeneratora::prostokat)
		m_prostyUAR.UstawGenerator(std::make_unique<GeneratorProstokatny>(amplituda, m_zegar.obliczOkresDyskretny(), stala, wypelnienie));
	else 
		m_prostyUAR.UstawGenerator(std::make_unique<GeneratorSinusoidalny>(amplituda, m_zegar.obliczOkresDyskretny(), stala));
}

void Uslugi::setWypelnienie_GenProstokatny(double wypelnienie) {
	GeneratorProstokatny* genProstokatny = dynamic_cast<GeneratorProstokatny*>(&m_prostyUAR.getGenerator());
	if (genProstokatny != nullptr)
		genProstokatny->setWypelnienie(wypelnienie);
		
}
double Uslugi::getWypelnienie_genProstokatny() const {
	const GeneratorProstokatny* genProstokatny = dynamic_cast<const GeneratorProstokatny*>(&m_prostyUAR.getGenerator());
	if (genProstokatny != nullptr)
		return genProstokatny->getWypelnienie();
	return -1.0; 
}