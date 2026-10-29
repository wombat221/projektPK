#include "ProstyUAR.h"

double ProstyUAR::symuluj(double sygWe) {
	return sygWe -  m_modelARX.getOstatnieWyjscie();
}