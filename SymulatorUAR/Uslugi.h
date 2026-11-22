#pragma once
#include "ProstyUAR.h"
#include "ZegarSymulacji.h"

class Uslugi {
private:
	ProstyUAR  m_prostyUAR;
	ZegarSymulacji m_zegar;
	

	
	void setOkres_Gen();
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
	void setWspolczynnikiA_ARX(std::vector<double> a) { m_prostyUAR.getModelARX().setWspolczynnikiA(a); }
	void setWspolczynnikiB_ARX(std::vector<double> b) { m_prostyUAR.getModelARX().setWspolczynnikiB(b); }

	double getUmin_ARX() const { return m_prostyUAR.getModelARX().getUmin(); }
	double getUmax_ARX() const { return m_prostyUAR.getModelARX().getUmax(); }
	double getYmin_ARX() const { return m_prostyUAR.getModelARX().getYmin(); }
	double getYmax_ARX() const { return m_prostyUAR.getModelARX().getYmax(); }
	bool getczyOrganczenieY_ARX() const { return m_prostyUAR.getModelARX().czyOgraniczenieY(); }
	bool getCzyOgraniczenieU_ARX() const { return m_prostyUAR.getModelARX().czyOgraniczenieU(); }
	int getOpoznienie_ARX() const { return m_prostyUAR.getModelARX().getOpoznienie(); }
	double getZaklocenia_ARX() const { return m_prostyUAR.getModelARX().getZaklocenia(); }
	std::vector<double> getWspolczynnikiA_ARX() const { return m_prostyUAR.getModelARX().getWspolczynnikiA(); }
	std::vector<double> getWspolczynnikiB_ARX() const { return m_prostyUAR.getModelARX().getWspolczynnikiB(); }
	void reset_ARX() { m_prostyUAR.getModelARX().reset(); }

	void resetPamiecCalki_PID() { m_prostyUAR.getRegulator().resetPamiecCalki(); }
	void reset_PID() { m_prostyUAR.getRegulator().reset(); }

	void setwzmocnienieK_PID(double k) { m_prostyUAR.getRegulator().setwzmocnienieK(k); }
	void setstalaCalkiTi_PID(double Ti) { m_prostyUAR.getRegulator().setstalaCalkiTi(Ti); }
	void setstalaRoznD_PID(double d) { m_prostyUAR.getRegulator().setstalaRoznD(d); }
	void setTypCalkowania_PID(RegulatorPID::TypCalkowania typ) { m_prostyUAR.getRegulator().setTypCalkowania(typ); }

	double getwzmocnienieK_PID() const { return m_prostyUAR.getRegulator().getwzmocnienieK(); };
	double getstalaCalkiTi_PID() const { return m_prostyUAR.getRegulator().getstalaCalkiTi(); };
	double getstalaRoznD_PID() const { return m_prostyUAR.getRegulator().getstalaRoznD(); };
	RegulatorPID::TypCalkowania getTypCalkowania() const { return m_prostyUAR.getRegulator().getTypCalkowania(); };

	double getProporcjonalnaP_PID() const { return m_prostyUAR.getRegulator().getProporcjonalnaP(); };
	double getCalkujacaI_PID() const { return m_prostyUAR.getRegulator().getCalkujacaI(); };
	double getRozniczkujacaD_PID() const { return m_prostyUAR.getRegulator().getRozniczkujacaD(); };
	double getSumaSkladowychU_PID() const { return m_prostyUAR.getRegulator().getSumaSkladowychU(); };


	void setAmplituda_Gen(double amplituda) { m_prostyUAR.getGenerator().setAmplituda(amplituda); }
	void setOkres_Gen(double okresS, int interwalMs);
	void setSkladowa_Gen(double stala) { m_prostyUAR.getGenerator().setSkladowa(stala); };
	void setWypelnienie_GenProstokatny(double wypelnienie);

	double getAmplituda_Generator() const { return m_prostyUAR.getGenerator().getAmplituda(); };
	int getOkres_Generator() const { return m_prostyUAR.getGenerator().getOkres(); };
	double getStala_Generator() const { return m_prostyUAR.getGenerator().getStala(); };
	double getWypelnienie_genProstokatny() const;


	void setOkres_Zegar(double okresS);
	void setInterwal_Zegar(int interwalMs);
	void setOknoSymulacji_Zegar(double oknoSymulacji) { m_zegar.setOknoSymulacji(oknoSymulacji); }

	double getOkres_Zegar() const { return m_zegar.getOkres(); }
	int getInterwal_Zegar() const { return m_zegar.getInterwal(); }
	int getProbkiOkna_Zegar() const { return m_zegar.getProbkiOkna(); }



	void ustawGenerator_UAR(Generator::TypGeneratora typ, double amplituda,
		double okresS, int interwalMs,
		double stala, double wypelnienie);

	void reset_UAR() { m_prostyUAR.reset(); };
	
	



};


