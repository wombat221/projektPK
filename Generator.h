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
	
	
	Generator() = default;
	Generator(const Generator& generator) = default;
	Generator(Generator&& generator) = default;
	Generator& operator=(const Generator& generator) = default;
	Generator& operator=(Generator&& generator) = default;
public:
	virtual ~Generator() = default;
	virtual double generujSygnal() = 0;

	void setAmplituda(double amplituda) { m_amplituda = amplituda; };
	void setOkres(int okres) { m_okres = okres; };
	void setSkladowa(double stala) { m_skladowaStala = stala; };
	void setKrok(int krok) { m_krok = krok; };


	int getKrok() const { return m_krok; };
	double getAmplituda() const { return m_amplituda; };
	int getOkres() const { return m_okres; };
};

using GeneratorPtr = std::unique_ptr<Generator>;


class GeneratorProstokatny : public Generator {
private:
	double m_wypelnienie = 0.5;
public:
	GeneratorProstokatny() = default;
	GeneratorProstokatny(double amplituda, int okres, double Stala, double wypelnienie,int krok = 0) : Generator(amplituda, okres, Stala,krok) {
		setWypelnienie(wypelnienie);
	};

	void setWypelnienie(double wypelnienie) { m_wypelnienie = wypelnienie; };
	double getWypelnienie() const { return m_wypelnienie; };

	double generujSygnal() override;


};


class GeneratorSinusoidalny : public Generator {
private:
	double m_faza = 6.28;
public:
	GeneratorSinusoidalny(double amplituda, int okres, double Stala, int krok = 0) : Generator(amplituda, okres, Stala,krok) {};
	void setFaza(double faza) { m_faza = faza; };


	double generujSygnal() override;

};












