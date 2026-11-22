#pragma once
#include "ProstyUAR.h"

class Uslugi {
private:
	ProstyUAR  m_prostyUAR;
public:
	Uslugi() = default;




	void setOpoznienieARX(int opoznienie) { m_prostyUAR.getModelARX().setOpoznienie(opoznienie); }
};