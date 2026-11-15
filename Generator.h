#pragma once



enum class sygnal{
	sinusoida,prostokatny
};

class Generator {
private:
	double m_amplituda = 1.0;
	double m_wypelnienie = 0.5;
	double m_okres = 10.0; 
	double m_skladowaStala = 0.0;
	sygnal m_sygnal = sygnal::prostokatny;
public:
	Generator(double amplituda, double wypelnienie = 0.5, double okres = 10.0, double stala, sygnal sygnal);

	double generujSygnal();
};

