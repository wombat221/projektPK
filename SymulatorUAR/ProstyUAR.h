#pragma once
#include "ModelARX.h"
#include "RegulatorPID.h"
#include "Generator.h"


struct wynikiSymulacji
{
	double zadana;
	double wyjscie;
	double uchyb;
	double proporcjonalnaP;
	double CalkujacaI;
	double rozniczkujacaD;
};




class ProstyUAR {
private:	
	using GeneratorPtr = std::unique_ptr<Generator>;


	ModelARX m_modelARX;
	RegulatorPID m_regulatorPID;
	GeneratorPtr m_generator;


	bool czyJestWskaznik() {
		return (m_generator != nullptr);
	}
public:
	ProstyUAR() : m_modelARX(), m_regulatorPID(), m_generator(std::make_unique<GeneratorProstokatny>()) {};
	
	ProstyUAR(ModelARX modelARX, RegulatorPID regulatorPID, GeneratorPtr generator = nullptr) :
		m_modelARX(std::move(modelARX)),
		m_regulatorPID(std::move(regulatorPID)) {
		UstawGenerator(std::move(generator));
	}
	

	void UstawGenerator(GeneratorPtr generator);
	ModelARX& getModelARX() { return m_modelARX; };
	RegulatorPID& getRegulator() { return m_regulatorPID; };
	Generator& getGenerator();

	double symuluj(double sygWe);
	wynikiSymulacji symulujZGeneratorem();


	
};
