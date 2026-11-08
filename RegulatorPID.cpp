#include "RegulatorPID.h"

// Konstruktor
RegulatorPID::RegulatorPID(double k, double Ti, double d)
	: m_sumaUchyb(0.0), m_poprzedniUchyb(0.0), m_proporcjonalnaP(0.0), m_calkujacaI(0.0), 
	m_rozniczkujacaD(0.0), m_sumaSkladowychU(0.0), m_typCalkowania(TypCalkowania::PrzedSuma) 
{
	setwzmocnienieK(k);
	setstalaCalkiTi(Ti);
	setstalaRoznD(d);
}

// Funkcje resetuj¹ce
void RegulatorPID::resetPamiecCalki()
{
	m_sumaUchyb = 0.0;
	m_poprzedniUchyb = 0.0;
};

void RegulatorPID::reset()
{
	resetPamiecCalki();
	m_proporcjonalnaP = 0.0;
	m_calkujacaI = 0.0;
	m_rozniczkujacaD = 0.0;
	m_sumaSkladowychU = 0.0;
};

// Setery
void RegulatorPID::setwzmocnienieK(double k)
{
	m_wzmocnienieK = k;
};

void RegulatorPID::setstalaCalkiTi(double Ti)
{
	if (Ti < 0.0) Ti = 0.0;
	m_stalaCalkTi = Ti;
};

void RegulatorPID::setstalaRoznD(double d)
{
	m_stalaRoznD = d;
};

void RegulatorPID::setTypCalkowania(TypCalkowania typ)
{
	if (m_typCalkowania == typ) return;

	if (m_typCalkowania == TypCalkowania::PrzedSuma) {
		m_sumaUchyb /= m_stalaCalkTi;
	}
	else {
		m_sumaUchyb *= m_stalaCalkTi;
	};

	m_typCalkowania = typ;
};

// Funkcja symuluj¹ca
double RegulatorPID::symuluj(double sygWe) 
{
	m_proporcjonalnaP = m_wzmocnienieK * sygWe;

	if (m_stalaCalkTi <= 0.0) {
		m_calkujacaI = 0.0;
	}
	else {
		if (m_typCalkowania == TypCalkowania::PrzedSuma)
		{
			m_sumaUchyb += sygWe;
			m_calkujacaI = (1.0 / m_stalaCalkTi) * m_sumaUchyb;
		}
		else {
			m_sumaUchyb += (sygWe / m_stalaCalkTi);
			m_calkujacaI = m_sumaUchyb;
		}
	}

	m_rozniczkujacaD = m_stalaCalkTi * (sygWe - m_poprzedniUchyb);
	m_poprzedniUchyb = sygWe;

	m_sumaSkladowychU = m_proporcjonalnaP + m_calkujacaI + m_rozniczkujacaD;
};
