#pragma once
#include <iostream>
#include <deque>
#include <random>

class ModelARX {
private:
	
	double m_uMin = -10.0;
	double m_uMax = 10.0;

	double m_yMin = -10.0;
	double m_yMax = 10.0;
	

	std::vector<double> m_AWspolczynniki = { -0.4 };
	std::vector<double> m_BWspolczynniki = { 0.6 };

	int m_opoznienie = 1;
	double m_odchylenie = 0.0;

	std::deque<double> m_buforWejscia = {0.0};
	std::deque<double> m_buforWyjscia = {0.0};


	bool m_ograniczenieU = true;
	bool m_ograniczenieY = true;

	std::mt19937 m_szum;

	double Zaklocenie();
public:
	ModelARX() = default;
	ModelARX(std::vector<double> a, std::vector<double> b, int opoznienie = 1, double odchylenie = 0.0);

	void setUmin(double uMin);
	void setUmax(double uMax);

	void setYmin(double yMin);
	void setYmax(double yMax);

	void setOgraniczenieU(bool OgraniczenieU) { m_ograniczenieU = OgraniczenieU; };
	void setOgraniczeniey(bool OgraniczenieY) { m_ograniczenieY = OgraniczenieY; };


	double getOstatnieWyjscie() { return m_buforWyjscia[0]; };


	double symuluj(double sygWe);
};




