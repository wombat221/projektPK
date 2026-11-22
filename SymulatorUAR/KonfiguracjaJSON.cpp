#include "KonfiguracjaJSON.h"

#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;

bool KonfiguracjaJSON::zapisz(const std::string& sciezkaDoPliku, const Uslugi& konfiguracja)
{
	return true;
}

bool KonfiguracjaJSON::odczytaj(const std::string& sciezkaDoPliku, Uslugi& konfiguracja)
{
	return true;
}