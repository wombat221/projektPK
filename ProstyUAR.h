#pragma once
#include "ModelARX.h"
#include "RegulatorPID.h"

class ProstyUAR {
private:	
	ModelARX m_modelARX;
	RegulatorPID m_regulatorPID;
	

public:
	ProstyUAR(ModelARX modelARX, RegulatorPID regulatorPID) { m_modelARX = modelARX; m_regulatorPID = regulatorPID; };
	
	double symuluj(double sygWe);
};

