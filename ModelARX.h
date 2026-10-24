#pragma once
#include <iostream>
#include <deque>
#include <random>

class ModelARX {
private:
	bool m_ograniczenieU = true;
	double m_uMin = -10.0;
	double m_uMax = 10.0;

	double m_yMin = -10.0;
	double m_yMax = 10.0;
	bool m_ograniczenieY = true;

	std::vector<double> m_AWspolczynniki = { -0.4 };
	std::vector<double> m_BWspolczynniki = { 0.6 };

	int m_opoznienie;
	double m_odchylenie = 0.0;

	std::deque<double> m_buforWejscia;
	std::deque<double> m_buforWyjscia;

	std::mt19937 m_generator{ std::random_device{}() };
	

	double LosoweZaklocenie();
public:
    ModelARX(std::vector<double> a, std::vector<double> b, int opoznienie, double odchylenie);

	void setUmin(double uMin);
	void setUmax(double uMax) { m_uMax = uMax; };

	void setYmin(double yMin);
	void setYmax(double yMax) { m_yMax = yMax; };

	void setOgraniczenieU(bool OgraniczenieU) { m_ograniczenieU = OgraniczenieU; };
	void setOgraniczeniey(bool OgraniczenieY) { m_ograniczenieY = OgraniczenieY; };


	double symuluj(double sygWe);
};




