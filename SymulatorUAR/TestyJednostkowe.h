#pragma once
#include <string>
#include <vector>

class WszystkieTesty {
private:
	static int s_liczbaTestow;
	static int s_poprawneTesty;

	static void raportBleduSekwencji(const std::vector<double>& spodz, const std::vector<double>& fakt);
	static bool porownanieSekwencji(const std::vector<double>& spodz, const std::vector<double>& fakt);
	static void myAssert(const std::vector<double>& spodz, const std::vector<double>& fakt, const std::string& sygnatura);

	
	static void test_brakPobudzenia();
	static void test_skokJednostkowy_1();
	static void test_skokJednostkowy_2();
	static void test_skokJednostkowy_3();

	
	static void test_P_brakPobudzenia();
	static void test_P_skokJednostkowy();
	static void test_PI_skokJednostkowy_1();
	static void test_PI_skokJednostkowy_2();
	static void test_PID_skokJednostkowy();
	static void test_PI_skokJednostkowy_3();

	
	static void test_UAR_1_brakPobudzenia();
	static void test_UAR_1_skokJednostkowyPID();
	static void test_UAR_2_skokJednostkowyPID();
	static void test_UAR_3_skokJednostkowyPID();
	
	static void test_Generator_1_GeneratorProstokatny();
	static void test_Generator_2_GeneratorSinusoidalny();
	static void test_Generator_3_PrzelaczenietypuGeneratora();
	static void test_generator_4_Reset();

	static void sprawdz(bool wynik, const std::string& sygnatura, const std::string& opis = "");

public:
	WszystkieTesty() = delete;
	static void uruchomWszystkieNasze();
	static void uruchomWszystkie();
};