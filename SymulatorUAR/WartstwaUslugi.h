#pragma once
#include "ProstyUAR.h"

class Uslugi {
private:
	ProstyUAR  m_prostyUAR;
public:
	Uslugi() = default;


	void setUminARX(double uMin);
	void setUmaxARX(double uMax);
	void setOgraniczeniaUARX(double uMin, double uMax);
	void setYminARX(double yMin);
	void setYmaxARX(double yMax);
	void setOgraniczeniaYARX(double yMin, double yMax);
	void setCzyOgraniczenieU_ARX(bool OgraniczenieU);
	void setCzyOgraniczenieY_ARX(bool OgraniczenieY);
	void setOpoznienie_ARX(int opoznienie);
	void setZaklocenia_ARX(double zaklocenia);
	void setWspolczynnikiA_ARX(std::vector<double> a);
	void setWspolczynnikiB(std::vector<double> b);

};