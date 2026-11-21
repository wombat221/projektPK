#pragma once
#include "ModelARX.h"
#include "RegulatorPID.h"
#include "Generator.h"
#include <memory>




class ProstyUAR {
private:	

	ModelARX m_modelARX;
	RegulatorPID m_regulatorPID;
	GeneratorPtr m_generator;

	bool czyJestWskaznik() {
		return (m_generator != nullptr);
	}
public:
	ProstyUAR(ModelARX modelARX, RegulatorPID regulatorPID, GeneratorPtr generator = nullptr) :
		m_modelARX(std::move(modelARX)),
		m_regulatorPID(std::move(regulatorPID)),
		m_generator(std::move(generator)) {};
	

	void UstawGenerator(GeneratorPtr generator);
	ModelARX& getModelARX() { return m_modelARX; };
	RegulatorPID& getRegulator() { return m_regulatorPID; };
	Generator& getGenerator();

	double symuluj(double sygWe);
	double symulujZGeneratorem();
	
};
