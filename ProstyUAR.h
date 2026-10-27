#pragma once


class ProstyUAR {
private:	
	ModelARX m_obiekt;
	RegulatorPID m_regulatorPID;
	

public:
	ProstyUAR(ModelARX obiekt, RegulatorPID regulatorPID) { m_obiekt = obiekt; m_regulatorPID = regulatorPID; };
	
	double symuluj(double sygWe);
};