#pragma once





class Generator {
protected:
	double m_amplituda = 1.0;
	int m_okres = 10; 
	double m_skladowaStala = 0.0;
	int m_krok = 0;
public:
	virtual double generujSygnal(double SygWe) = 0;
};

class GeneratorProstokatny : public Generator {
private:
	double m_wypelnienie = 0.5;
public:
	double generujSygnal(double SygWe) override ;

};


class GeneratorSinusoidalny : public Generator {
public:
	double generujSygnal(double SygWe) override;
};