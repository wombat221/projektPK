#pragma once
#include "ProstyUAR.h"
#include "ZegarSymulacji.h"

class Uslugi {
private:
	ProstyUAR  m_prostyUAR;
	ZegarSymulacji m_zegar;
	

	
	void setOkres_Generator();
public:
	Uslugi() = default;


	void setUmin_ARX(double uMin) { m_prostyUAR.getModelARX().setUmin(uMin); }
	void setUmax_ARX(double uMax) { m_prostyUAR.getModelARX().setUmax(uMax); }
	void setOgraniczeniaU_ARX(double uMin, double uMax) { m_prostyUAR.getModelARX().setOgraniczeniaU(uMin,uMax); }
	void setYmin_ARX(double yMin) { m_prostyUAR.getModelARX().setYmin(yMin); }
	void setYmax_ARX(double yMax) { m_prostyUAR.getModelARX().setYmax(yMax); }
	void setOgraniczeniaY_ARX(double yMin, double yMax) { m_prostyUAR.getModelARX().setOgraniczeniaY(yMin,yMax); }
	void setCzyOgraniczenieU_ARX(bool OgraniczenieU) { m_prostyUAR.getModelARX().setCzyOgraniczenieU(OgraniczenieU); }
	void setCzyOgraniczenieY_ARX(bool OgraniczenieY) { m_prostyUAR.getModelARX().setCzyOgraniczenieY(OgraniczenieY); }
	void setOpoznienie_ARX(int opoznienie) { m_prostyUAR.getModelARX().setOpoznienie(opoznienie); }
	void setZaklocenia_ARX(double zaklocenia) { m_prostyUAR.getModelARX().setZaklocenia(zaklocenia); }
	void setWspolczynnikiA_ARX(std::vector<double>& a) { m_prostyUAR.getModelARX().setWspolczynnikiA(a); }
	void setWspolczynnikiB_ARX(std::vector<double>& b) { m_prostyUAR.getModelARX().setWspolczynnikiB(b); }

	double getUmin_ARX() const { return m_prostyUAR.getModelARX().getUmin(); }
	double getUmax_ARX() const { return m_prostyUAR.getModelARX().getUmax(); }
	double getYmin_ARX() const { return m_prostyUAR.getModelARX().getYmax(); }
	double getYmax_ARX() const { return m_prostyUAR.getModelARX().getYmin(); }
	bool getczyOrganczenieY_ARX() const { return m_prostyUAR.getModelARX().getUmax(); }
	bool getCzyOgraniczenieU_ARX() const { return m_prostyUAR.getModelARX().czyOgraniczenieU(); }
	int getOpoznienie_ARX() const { return m_prostyUAR.getModelARX().getOpoznienie(); }
	double getZaklocenia_ARX() const { return m_prostyUAR.getModelARX().getZaklocenia(); }
	std::vector<double> getWspolczynnikiA_ARX() const { return m_prostyUAR.getModelARX().getWspolczynnikiA(); }
	std::vector<double> getWspolczynnikiB_ARX() const { return m_prostyUAR.getModelARX().getWspolczynnikiB(); }
	
	void resetPamiecCalki_PID() { m_prostyUAR.getRegulator().resetPamiecCalki(); }
	void reset_PID() { m_prostyUAR.getRegulator().reset(); }

	void setwzmocnienieK_PID(double k) { m_prostyUAR.getRegulator().setwzmocnienieK(k); }
	void setstalaCalkiTi_PID(double Ti) { m_prostyUAR.getRegulator().setstalaCalkiTi(Ti); }
	void setstalaRoznD_PID(double d) { m_prostyUAR.getRegulator().setstalaRoznD(d); }
	void setTypCalkowania(RegulatorPID::TypCalkowania typ) { m_prostyUAR.getRegulator().setTypCalkowania(typ); }

	double getwzmocnienieK() const { return m_prostyUAR.getRegulator().getwzmocnienieK(); };
	double getstalaCalkiTi() const { return m_prostyUAR.getRegulator().getstalaCalkiTi(); };
	double getstalaRoznD() const { return m_prostyUAR.getRegulator().getstalaRoznD(); };
	RegulatorPID::TypCalkowania getTypCalkowania() const { return m_prostyUAR.getRegulator().getTypCalkowania(); };

	double getProporcjonalnaP() const { return m_prostyUAR.getRegulator().getProporcjonalnaP(); };
	double getCalkujacaI() const { return m_prostyUAR.getRegulator().getCalkujacaI(); };
	double getRozniczkujacaD() const { return m_prostyUAR.getRegulator().getRozniczkujacaD(); };
	double getSumaSkladowychU() const { return m_prostyUAR.getRegulator().getSumaSkladowychU(); };

	void ustawGenerator(Generator::TypGeneratora typ, double amplituda,
		double okresS, int interwalMs,
		double stala, double wypelnienie);




	void setOkres_Generator(double okresS,int interwalMs);
	void setOkres_Zegar(double okresS);
	void setInterwal_Zegar(int interwalMs);
	void setOknoSymulacji_Zegar(double oknoSymulacji) { m_zegar.setOknoSymulacji(oknoSymulacji); }

	



};