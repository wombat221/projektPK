#include "ProstyUAR.h"

double ProstyUAR::symuluj(double sygWe) {
	return m_modelARX->symuluj(m_regulatorPID->symuluj(sygWe - m_modelARX->getOstatnieWyjscie()));
}