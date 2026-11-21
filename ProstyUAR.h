#pragma once
#include "ModelARX.h"
#include "RegulatorPID.h"
#include "Generator.h"
#include <memory>



class ProstyUAR {
public:
	using GeneratorPtr = std::unique_ptr<Generator>;

private:	

	ModelARX m_modelARX;
	RegulatorPID m_regulatorPID;
	GeneratorPtr m_generator;

	bool czyJestWskaznik(GeneratorPtr& generator) {
		return (generator != nullptr);
	}
public:
	ProstyUAR(ModelARX modelARX, RegulatorPID regulatorPID, GeneratorPtr generator = nullptr) :
		m_modelARX(std::move(modelARX)),
		m_regulatorPID(std::move(regulatorPID)),
		m_generator(std::move(generator)) {};
	




	
	

	void UstawGenerator(GeneratorPtr generator);
	double symuluj(double sygWe);
	double symulujZGeneratorem();
	
};
