#pragma once
#include <deque>
#include <random>

class ModelARX {
private:
	
	double m_uMin = -10.0;
	double m_uMax = 10.0;

	double m_yMin = -10.0;
	double m_yMax = 10.0;
	

	std::vector<double> m_WspolczynnikiA = { -0.4 };
	std::vector<double> m_WspolczynnikiB = { 0.6 };

	int m_opoznienie = 1;
	double m_zaklocenia = 0.0;

	std::deque<double> m_buforWejscia = {0.0,0.0};
	std::deque<double> m_buforWyjscia = {0.0};


	bool m_ograniczenieU = true;
	bool m_ograniczenieY = true;

	std::mt19937 gen_plos;

	double Zaklocenie();
public:
	ModelARX() = default;
	ModelARX(std::vector<double> a, std::vector<double> b, int opoznienie = 1, double odchylenie = 0.0);

	void setUmin(double uMin);
	void setUmax(double uMax);
	void setOgraniczeniaU(double uMin,double uMax);
	void setYmin(double yMin);
	void setYmax(double yMax);
	void setOgraniczeniaY(double yMin, double yMax);
	void setCzyOgraniczenieU(bool OgraniczenieU);
	void setCzyOgraniczenieY(bool OgraniczenieY);
	void setOpoznienie(int opoznienie);
	void setZaklocenia(double zaklocenia);
	void setWspolczynnikiA(std::vector<double> a);
	void setWspolczynnikiB(std::vector<double> b);


	double getUmin() const { return m_uMin; };
	double getUmax() const { return m_uMax; };
	double getYmin() const { return m_uMin; };
	double getYmax() const { return m_uMax; };
	bool czyOgraniczenieU() const { return m_ograniczenieU; };
	bool czyOgraniczenieY() const { return m_ograniczenieY; };
	int getOpoznienie() const { return m_opoznienie; };
    double getZaklocenia() const { return m_zaklocenia; };
	std::vector<double> getWspolczynnikiA() const { return m_WspolczynnikiA; };
	std::vector<double> getWspolczynnikiB() const { return m_WspolczynnikiB; };

	double getOstatnieWyjscie() const { return m_buforWyjscia[0]; };

	double symuluj(double sygWe);

	void reset();
};




