#pragma once

// Spos�b naliczenia ca�ki
enum class TypCalkowania {
	PrzedSuma, // Domy�lny
	PodSuma
};

class RegulatorPID {
private:

	// Nastawa regulatora
	double m_wzmocnienieK = 0.5;
	double m_stalaCalkTi = 5.0;
	double m_stalaRoznD = 0.0;

	// Pamiec regulatora
	double m_sumaUchyb = 0.0;
	double m_poprzedniUchyb = 0.0;

	// Wyliczone sygnaly
	double m_proporcjonalnaP = 0.0;
	double m_calkujacaI = 0.0;
	double m_rozniczkujacaD = 0.0;
	double m_sumaSkladowychU = 0.0;

	TypCalkowania m_typCalkowania = TypCalkowania::PrzedSuma;

public:
	// Konstruktor
	RegulatorPID(double k = 0.5, double Ti = 5.0, double d = 0.0);

	// Funkcje resetuj�ce
	void resetPamiecCalki();
	void reset();

	// Setery
	void setwzmocnienieK(double k);
	void setstalaCalkiTi(double Ti);
	void setstalaRoznD(double d);
	void setTypCalkowania(TypCalkowania typ);

	// Getery
	double getwzmocnienieK() const { return m_wzmocnienieK; };
	double getstalaCalkiTi() const { return m_stalaCalkTi; };
	double getstalaRoznD() const { return m_stalaRoznD; };
	TypCalkowania getTypCalkowania() const { return m_typCalkowania; };

	// Odczyt warto�ci dla wykresow
	double getProporcjonalnaP() const { return m_proporcjonalnaP; };
	double getCalkujacaI() const { return m_calkujacaI; };
	double getRozniczkujacaD() const { return m_rozniczkujacaD; };
	double getSumaSkladowychU() const { return m_sumaSkladowychU; };

	// Funkcja symuluj�ca
	double symuluj(double sygWe);
};