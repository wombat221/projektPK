#pragma once





class Generator {
protected:
	double m_amplituda = 1.0;
	int m_okres = 10; 
	double m_skladowaStala = 0.0;
	int m_krok = 0;
	Generator(double amplituda, int okres, double stala,int krok) {
		setAmplituda(amplituda);
		setOkres(okres);
		setSkladowa(stala);
	};
	virtual double generujSygnal(double SygWe) = 0;
	Generator() {};
public:

	void setAmplituda(double amplituda);
	void setOkres(int okres);
	void setSkladowa(double stala);
};

class GeneratorSinusoidalny; 


class GeneratorProstokatny : public Generator {
private:
	double m_wypelnienie = 0.5;
public:
	GeneratorProstokatny();
	GeneratorProstokatny(double amplituda, int okres, double Stala, double wypelnienie,int krok = 0) : Generator(amplituda, okres, Stala,krok) {
		setWypelnienie(wypelnienie);
	};

	void setWypelnienie(double wypelnienie);
	
	double generujSygnal(double SygWe) override;

	GeneratorSinusoidalny konwersjaNaSinusoidalny();
	
};


class GeneratorSinusoidalny : public Generator {
private:
	double m_faza = 6.28;
public:
	GeneratorSinusoidalny() {};
	GeneratorSinusoidalny(double amplituda, int okres, double Stala, int krok = 0) : Generator(amplituda, okres, Stala,krok) {};


	double generujSygnal(double SygWe) override;

	GeneratorProstokatny konwersjaNaProstokatny(double wypelnienie);

};



