#pragma once
#include <memory>


class Generator {
protected:
	double m_amplituda = 1.0;
	int m_probki = 200; 
	double m_skladowaStala = 0.0;
	int m_krok = 0;
    Generator(double amplituda, int okres, double stala) {
		setAmplituda(amplituda);
		setOkres(okres);
		setSkladowa(stala);
	};

	


	Generator() = default;
	Generator(Generator&& generator) = default;
	Generator& operator=(Generator&& generator) = default;
public:
	virtual ~Generator() = default;
	virtual double generujSygnal() = 0;

	void setAmplituda(double amplituda);
	void setOkres(int okres);
	void setSkladowa(double stala);
	
	void setKrok(int krok);
	int getKrok() const { return m_krok; };


	double getAmplituda() const { return m_amplituda; };
	int getOkres() const { return m_probki; };
	double getStala() const { return m_skladowaStala; };

	Generator(const Generator& generator) = delete;
	Generator& operator=(const Generator& generator) = delete;

	enum class TypGeneratora {
		sinus,prostokat
	};
};




class GeneratorProstokatny : public Generator {
private:
	double m_wypelnienie = 0.5;
public:
	GeneratorProstokatny() = default;
    GeneratorProstokatny(double amplituda, int okres, double Stala, double wypelnienie) : Generator(amplituda, okres, Stala) {
		setWypelnienie(wypelnienie);
	};

	void setWypelnienie(double wypelnienie);
	double getWypelnienie() const { return m_wypelnienie; };

	double generujSygnal() override;
};


class GeneratorSinusoidalny : public Generator {

public:
	GeneratorSinusoidalny() = default;

    GeneratorSinusoidalny(double amplituda, int okres, double Stala) : Generator(amplituda, okres, Stala) {};

	double generujSygnal() override;
};












