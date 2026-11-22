#pragma once
#include <string>
#include <iostream>




class TestyARX {
	TestyARX = delete;
};


class TestyPID {
	TestyPID() = delete;
};

class TestyGenerator {
	TestyGenerator() = delete;
};

class TestyUAR {
public:
	TestyUAR() = delete;
	
	

	
	
	
	static void TESTY_WszysztkieTesty(){
	
	}

};

class WszystkieTesty {
	static int s_liczbaTestow;
	static int s_poprawneTesty;

	void sprawdz(bool wynik,const std::string& sygnatura,const std::string& opis = " ") {
		s_liczbaTestow++;
		if (wynik) {
			s_poprawneTesty++;
		}
		else {
			std::cerr << "FAIL " << sygnatura << "  " << opis;
		}
	}


public:


};