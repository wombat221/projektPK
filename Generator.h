#pragma once



enum class sygnal{
	sinusoida,prostokatny
};


class Generator {
private:
	double m_amplituda = 1.0;
	double m_wypelnienie = 0.5;
	int m_okres = 10; 
	double m_skladowaStala = 0.0;
	int m_krok = 0;
	sygnal m_sygnal = sygnal::prostokatny;
public:
	Generator(double amplituda, double wypelnienie, double okres, double stala, sygnal sygnal);

	double generujSygnal(double SygWe);
};