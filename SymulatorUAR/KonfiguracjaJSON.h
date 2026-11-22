#pragma once

#include "Uslugi.h"

class KonfiguracjaJSON {
public:
	static bool zapisz(const std::string& sciezkaDoPliku, const Uslugi& konfiguracja);
	static bool odczytaj(const std::string& sciezkaDoPliku, Uslugi& konfiguracja);
};