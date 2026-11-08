#pragma once
#include "ModelARX.h"
#include "RegulatorPID.h"

class ProstyUAR {
private:	
	std::unique_ptr<ModelARX> m_modelARX;
	std::unique_ptr<RegulatorPID> m_regulatorPID;
public:
	ProstyUAR(ModelARX modelARX, RegulatorPID regulatorPID) {
		m_modelARX = std::make_unique<ModelARX>(modelARX);
		m_regulatorPID = std::make_unique<RegulatorPID>(regulatorPID);
	}
	
	double symuluj(double sygWe);
};
