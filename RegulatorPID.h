#pragma once
#include <cstdint>

class RegulatorPID {
public:
	enum class TypCalkowania {
		PrzedSuma, // Domyslny
		PodSuma
	};
private:
	double m_wzmocnienieK = 0.5;
	double m_stalaCalkTi = 5.0;
	double m_stalaRoznD = 0.0;

	double m_sumaUchyb = 0.0;
	double m_poprzedniUchyb = 0.0;

	double m_proporcjonalnaP = 0.0;
	double m_calkujacaI = 0.0;
	double m_rozniczkujacaD = 0.0;
	double m_sumaSkladowychU = 0.0;

	TypCalkowania m_typCalkowania = TypCalkowania::PrzedSuma;

public:
	RegulatorPID() = default;
	RegulatorPID(double k, double Ti = 0.0, double d = 0.0);

	void resetPamiecCalki();
	void reset();

	void setwzmocnienieK(double k);
	void setstalaCalkiTi(double Ti);
	void setstalaRoznD(double d);
	void setTypCalkowania(TypCalkowania typ);

	double getwzmocnienieK() const { return m_wzmocnienieK; };
	double getstalaCalkiTi() const { return m_stalaCalkTi; };
	double getstalaRoznD() const { return m_stalaRoznD; };
	TypCalkowania getTypCalkowania() const { return m_typCalkowania; };

	double getProporcjonalnaP() const { return m_proporcjonalnaP; };
	double getCalkujacaI() const { return m_calkujacaI; };
	double getRozniczkujacaD() const { return m_rozniczkujacaD; };
	double getSumaSkladowychU() const { return m_sumaSkladowychU; };

	double symuluj(double sygWe);
};
