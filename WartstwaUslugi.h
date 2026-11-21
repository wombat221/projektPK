#pragma once
#include "ProstyUAR.h"

class Uslugi {
private:
	ProstyUAR  m_prostyUAR;
public:
	Uslugi() = default;

	void setOpoznienieARX(int opoznienie) {
		if (opoznienie < 1)
			opoznienie = 0;
		else if (opoznienie > 20)
			opoznienie = 20;
		m_prostyUAR.getModelARX().setOpoznienie(opoznienie);
	}
	

};