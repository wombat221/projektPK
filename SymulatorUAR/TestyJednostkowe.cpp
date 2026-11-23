#include "TestyJednostkowe.h"
#include <iostream>
#include <iomanip>
#include <cmath>

#include "ModelARX.h"
#include "RegulatorPID.h"
#include "ProstyUAR.h"
#include "Generator.h"

int WszystkieTesty::s_liczbaTestow = 0;
int WszystkieTesty::s_poprawneTesty = 0;

void WszystkieTesty::raportBleduSekwencji(const std::vector<double>& spodz, const std::vector<double>& fakt)
{
	constexpr size_t PREC = 3;
	std::cerr << std::fixed << std::setprecision(PREC);
	std::cerr << "  Spodziewany:\t";
	for (const auto& el : spodz)
		std::cerr << el << " ";
	std::cerr << "\n  Faktyczny:\t";
	for (const auto& el : fakt)
		std::cerr << el << " ";
	std::cerr << "\n\n";
}

bool WszystkieTesty::porownanieSekwencji(const std::vector<double>& spodz, const std::vector<double>& fakt)
{
	constexpr double TOL = 1e-3;
	bool result = fakt.size() == spodz.size();
	for (size_t i = 0; result && i < fakt.size(); i++)
		result = std::fabs(fakt[i] - spodz[i]) < TOL;
	return result;
}

void WszystkieTesty::myAssert(const std::vector<double>& spodz, const std::vector<double>& fakt, const std::string& sygnatura)
{
	s_liczbaTestow++;
	if (porownanieSekwencji(spodz, fakt)) {
		s_poprawneTesty++;
	}
	else {
		std::cerr << "[FAIL] " << sygnatura << "\n";
		raportBleduSekwencji(spodz, fakt);
	}
}

void WszystkieTesty::sprawdz(bool wynik, const std::string& sygnatura, const std::string& opis)
{
	s_liczbaTestow++;
	if (wynik) {
		s_poprawneTesty++;
	}
	else {
		std::cerr << "[FAIL] " << sygnatura << " | " << opis << "\n";
	}
}


void WszystkieTesty::test_brakPobudzenia()
{
	const std::string sygnatura = "ModelARX (-0.4 | 0.6 | 1 | 0 ) -> test zerowego pobudzenia";
	try
	{
		ModelARX instancjaTestowa({ -0.4 }, { 0.6 }, 1, 0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}

void WszystkieTesty::test_skokJednostkowy_1()
{
	const std::string sygnatura = "ModelARX (-0.4 | 0.6 | 1 | 0 ) -> test skoku jednostkowego nr 1";
	try
	{
		ModelARX instancjaTestowa({ -0.4 }, { 0.6 }, 1, 0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER+ 1);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0, 0.6, 0.84, 0.936, 0.9744, 0.98976, 0.995904, 0.998362,
					   0.999345, 0.999738, 0.999895, 0.999958, 0.999983, 0.999993, 0.999997, 0.999999,
					   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}

void WszystkieTesty::test_skokJednostkowy_2()
{
	const std::string sygnatura = "ModelARX (-0.4 | 0.6 | 2 | 0 ) -> test skoku jednostkowego nr 2";
	try
	{
		ModelARX instancjaTestowa({ -0.4 }, { 0.6 }, 2, 0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0, 0, 0.6, 0.84, 0.936, 0.9744, 0.98976, 0.995904, 0.998362, 0.999345, 0.999738, 0.999895, 0.999958, 0.999983, 0.999993, 0.999997, 0.999999, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}

void WszystkieTesty::test_skokJednostkowy_3()
{
	const std::string sygnatura = "ModelARX (-0.4, 0.2 | 0.6, 0.3 | 2 | 0 ) -> test skoku jednostkowego nr 3";
	try
	{
		ModelARX instancjaTestowa({ -0.4, 0.2 }, { 0.6, 0.3 }, 2, 0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0, 0, 0.6, 1.14, 1.236, 1.1664, 1.11936, 1.11446, 1.12191, 1.12587, 1.12597, 1.12521, 1.12489, 1.12491, 1.12499, 1.12501, 1.12501, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125 };

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}



void WszystkieTesty::test_P_brakPobudzenia()
{
	const std::string sygnatura = "RegP (k = 0.5) -> test zerowego pobudzenia";
	try
	{
		RegulatorPID instancjaTestowa(0.5);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}

void WszystkieTesty::test_P_skokJednostkowy()
{
	const std::string sygnatura = "RegP (k = 0.5) -> test skoku jednostkowego";
	try
	{
		RegulatorPID instancjaTestowa(0.5);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
					   0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5 };

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}

void WszystkieTesty::test_PI_skokJednostkowy_1()
{
	const std::string sygnatura = "RegPI (k = 0.5, TI = 1.0) -> test skoku jednostkowego nr 1";
	try
	{
		RegulatorPID instancjaTestowa(0.5, 1.0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5, 11.5, 12.5,
					   13.5, 14.5, 15.5, 16.5, 17.5, 18.5, 19.5, 20.5, 21.5, 22.5, 23.5,
					   24.5, 25.5, 26.5, 27.5, 28.5, 29.5 };

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}

void WszystkieTesty::test_PI_skokJednostkowy_2()
{
	const std::string sygnatura = "RegPI (k = 0.5, TI = 10.0) -> test skoku jednostkowego nr 2";
	try
	{
		RegulatorPID instancjaTestowa(0.5, 10.0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9,
					   2, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3, 3.1, 3.2, 3.3, 3.4 };

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}

void WszystkieTesty::test_PID_skokJednostkowy()
{
	const std::string sygnatura = "RegPID (k = 0.5, TI = 10.0, TD = 0.2) -> test skoku jednostkowego";
	try
	{
		RegulatorPID instancjaTestowa(0.5, 10.0, 0.2);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0.8, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2, 2.1,
					   2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3, 3.1, 3.2, 3.3, 3.4 };

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}

void WszystkieTesty::test_PI_skokJednostkowy_3()
{
	const std::string sygnatura = "RegPI (k = 0.5, TI = 10.0 -> 5.0 -> 10.0) -> test skoku jednostkowego nr 3";
	try
	{
		RegulatorPID instancjaTestowa(0.5, 10.0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.8, 2, 2.2, 2.4,
					   2.6, 2.8, 3, 3.2, 3.4, 3.6, 3.8, 4, 2.35, 2.45, 2.55, 2.65, 2.75, 2.85 };

		for (size_t i = 0; i < LICZ_ITER; i++)
		{
			if (i == LICZ_ITER * 1 / 5)
				instancjaTestowa.setTypCalkowania(RegulatorPID::TypCalkowania::PodSuma);
			if (i == LICZ_ITER * 2 / 5)
				instancjaTestowa.setstalaCalkiTi(5.0);
			if (i == LICZ_ITER * 3 / 5)
				instancjaTestowa.setTypCalkowania(RegulatorPID::TypCalkowania::PrzedSuma);
			if (i == LICZ_ITER * 4 / 5)
				instancjaTestowa.setstalaCalkiTi(10.0);
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);
		}

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}



void WszystkieTesty::test_UAR_1_brakPobudzenia()
{
	const std::string sygnatura = "UAR_1 -> test zerowego pobudzenia";
	try
	{
		RegulatorPID testPID(0.5, 5.0, 0.2);
		ModelARX testARX({ -0.4 }, { 0.6 });
		ProstyUAR instancjaTestowa(testARX, testPID);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}

void WszystkieTesty::test_UAR_1_skokJednostkowyPID()
{
	const std::string sygnatura = "UAR_1 PID -> test skoku jednostkowego";
	try
	{
		RegulatorPID testPID(0.5, 5.0, 0.2);
		ModelARX testARX({ -0.4 }, { 0.6 });
		ProstyUAR instancjaTestowa(testARX, testPID);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0.0, 0.0, 0.54, 0.756, 0.6708, 0.64008, 0.729, 0.810437, 0.834499,
					   0.843338, 0.8664, 0.8936, 0.911886, 0.923312, 0.93404, 0.944929,
					   0.954065, 0.961042, 0.966815, 0.971965, 0.97642, 0.980096, 0.983143,
					   0.985741, 0.987964, 0.989839, 0.991411, 0.992739, 0.993865, 0.994818 };

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}

void WszystkieTesty::test_UAR_2_skokJednostkowyPID()
{
	const std::string sygnatura = "UAR_2 PID (k = 2) -> test skoku jednostkowego";
	try
	{
		RegulatorPID testPID(0.5, 5.0, 0.2);
		ModelARX testARX({ -0.4 }, { 0.6 }, 2);
		ProstyUAR instancjaTestowa(testARX, testPID);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0.0, 0.0, 0.0, 0.54, 0.756, 0.9624, 0.87336, 0.841104, 0.771946, 0.821644,
					   0.863453, 0.93272, 0.952656, 0.965421, 0.954525, 0.955787, 0.957472,
					   0.969711, 0.978075, 0.985968, 0.987821, 0.989149, 0.989053, 0.990645,
					   0.992248, 0.994403, 0.995707, 0.996677, 0.997024, 0.997388 };

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (std::exception& e) {
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> " << e.what() << "\n";
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}

void WszystkieTesty::test_UAR_3_skokJednostkowyPID()
{
	const std::string sygnatura = "UAR_3 PID (kP=1.0,Ti=2.0) -> test skoku jednostkowego";
	try
	{
		RegulatorPID testPID(1.0, 2.0, 0.2);
		ModelARX testARX({ -0.4 }, { 0.6 }, 1);
		ProstyUAR instancjaTestowa(testARX, testPID);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0.0, 0.0, 1.02, 1.608, 1.1028, 0.41736, 0.546648, 1.20605, 1.43047,
					   0.999176, 0.615056, 0.799121, 1.21304, 1.26025, 0.939289, 0.748507,
					   0.927166, 1.17292, 1.14155, 0.921616, 0.843258, 0.990018, 1.12577,
					   1.068, 0.927024, 0.908125, 1.01702, 1.08484, 1.02618, 0.941508 };

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}





void WszystkieTesty::test_Generator_1_GeneratorProstokatny()
{
	const std::string sygnatura = "Test Generatora Prostokatny";
	try
	{
		GeneratorProstokatny instancjaTestowa;
		instancjaTestowa.setProbki(4);
		size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
					   0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
					   1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0 };

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.generujSygnal();

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}



void WszystkieTesty::test_Generator_2_GeneratorSinusoidalny()
{
	const std::string sygnatura = "Test Generatora Sinusoidalny";
	try
	{
		GeneratorSinusoidalny instancjaTestowa;
		instancjaTestowa.setProbki(4);
		size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);
		std::vector<double> spodzSygWy(LICZ_ITER);
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0.0, 1.0, 0.0, -1.0, 0.0, 1.0, 0.0, -1.0, 0.0, 1.0,
					   0.0, -1.0, 0.0, 1.0, 0.0, -1.0, 0.0, 1.0, 0.0, -1.0,
					   0.0, 1.0, 0.0, -1.0, 0.0, 1.0, 0.0, -1.0, 0.0, 1.0 }; 

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.generujSygnal();

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}

void WszystkieTesty::test_Generator_3_PrzelaczenietypuGeneratora()
{
	const std::string sygnatura = "ProstyUAR -> przelaczenie generatora w 15 kroku (z zachowaniem kroku)";
	try
	{
		ProstyUAR instancjaTestowa;
		instancjaTestowa.UstawGenerator(std::make_unique<GeneratorProstokatny>(1.0, 4, 0.0, 0.5));

		constexpr size_t LICZ_ITER = 30;
		std::vector<double> spodzSygWy = { 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
										   0.0, 0.0, 1.0, 1.0, 0.0, -1.0, 0.0, 1.0, 0.0, -1.0,
										   0.0, 1.0, 0.0, -1.0, 0.0, 1.0, 0.0, -1.0, 0.0, 1.0 };
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
		{
			if (i == 15) {
				instancjaTestowa.UstawGenerator(std::make_unique<GeneratorSinusoidalny>(1.0, 4, 0.0));
			}
			faktSygWy[i] = instancjaTestowa.getGenerator().generujSygnal();
		}

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED! (niespodziewany wyjatek)\n";
	}
}

void WszystkieTesty::test_generator_4_Reset()
{
	const std::string sygnatura = "GeneratorSinusoidalny -> reset licznika kroku w polowie okresu";
	try
	{
		GeneratorSinusoidalny gen(1.0, 4, 0.0);
		gen.generujSygnal(); 
		gen.generujSygnal(); 

		gen.reset(); 

		std::vector<double> spodz = { 0.0, 1.0, 0.0, -1.0 };
		std::vector<double> fakt(spodz.size());

		for (size_t i = 0; i < fakt.size(); i++)
			fakt[i] = gen.generujSygnal();

		myAssert(spodz, fakt, sygnatura);
	}
	catch (...)
	{
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED!\n";
	}
}

void WszystkieTesty::test_ARX_5_nasycenieU()
{
	const std::string sygnatura = "ModelARX -> test nasycenia sygnalu wejsciowego U"; 
	try {
		ModelARX test({ -0.4 }, { 0.6 }, 1, 0.0); 
		test.setOgraniczeniaU(-5.0, 5.0);
		test.setCzyOgraniczenieU(true);
		
		constexpr size_t LICZ_ITER = 5; 
		std::vector<double> sygWe = { 0.0, 10.0, 10.0, 10.0, 10.0 };

		std::vector<double> spodzSygWy = { 0.0, 0.0, 3.0, 4.2, 4.68 };
		std::vector<double> faktSygWy(LICZ_ITER);

		for (size_t i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = test.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...) {
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED!\n";
	}
}

void WszystkieTesty::test_ARX_6_resetBuforow()
{
	const std::string sygnatura = "ModelARX -> test resetowania buforow";
	try {
		ModelARX test({ -0.4 }, { 0.6 }, 1, 0.0);
		test.symuluj(0.0);
		test.symuluj(1.0);
		test.symuluj(1.0);
		test.symuluj(1.0);

		test.reset();

		std::vector<double> spodzSygWy = {0.0, 0.0};
		std::vector<double> faktSygWy(2);

		faktSygWy[0] = test.symuluj(0.0);
		faktSygWy[1] = test.symuluj(0.0);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...) {
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED!\n";
	}
}

void WszystkieTesty::test_PID_7_resetPamieciCalki()
{
	const std::string sygnatura = "RegulatorPID -> test resetu pamieci calki";
	try {
		RegulatorPID test(1.0, 2.0, 0.0);

		std::vector<double> faktSygWy(6);
		faktSygWy[0] = test.symuluj(0.0);
		faktSygWy[1] = test.symuluj(1.0); 
		faktSygWy[2] = test.symuluj(1.0); 
		faktSygWy[3] = test.symuluj(1.0);

		test.resetPamiecCalki();

		faktSygWy[4] = test.symuluj(1.0);
		faktSygWy[5] = test.symuluj(1.0);

		std::vector<double> spodzSygWy = { 0.0, 1.5, 2.0, 2.5, 1.5, 2.0 };

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...) {
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED!\n";
	}
}

void WszystkieTesty::test_PID_8_wylaczenieCalki()
{
	const std::string sygnatura = "RegulatorPID -> wylaczenie calki";
	try {
		RegulatorPID test(1.0, 0.0, 0.0);
		std::vector<double> sygWe = { 0.0, 1.0, 1.0, 1.0 };
		std::vector<double> spodzSygWy = { 0.0, 1.0, 1.0, 1.0 };
		std::vector<double> faktSygWy(4);

		for (size_t i = 0; i < 4; i++)
			faktSygWy[i] = test.symuluj(sygWe[i]);
		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...) {
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED!\n";
	}
}

void WszystkieTesty::test_UAR_9_SkokIPowrot()
{
	const std::string sygnatura = "ProstyUAR -> skok i powrot wartosci zadanej";
	try {
		RegulatorPID testPID(0.5, 0.0, 0.0);
		ModelARX testARX({ -0.4 }, { 0.6 }, 1, 0.0);
		ProstyUAR test(testARX, testPID);

		std::vector<double> sygWe = { 0.0, 1.0, 1.0, 0.0, 0.0 };
		std::vector<double> spodzSygWy = { 0.0, 0.0, 0.3, 0.42, 0.078 };
		std::vector<double> faktSygWy(5);

		for (size_t i = 0; i < 5; i++)
			faktSygWy[i] = test.symuluj(sygWe[i]);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...) {
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED!\n";
	}
}

void WszystkieTesty::test_UAR_10_reset()
{
	const std::string sygnatura = "ProstyUAR -> test resetu symulacji";
	try {
		RegulatorPID testPID(0.5, 0.0, 0.0);
		ModelARX testARX({ -0.4 }, { 0.6 }, 1, 0.0);
		auto testGenerator = std::make_unique<GeneratorProstokatny>();
		ProstyUAR test(testARX, testPID, std::move(testGenerator));

		test.symuluj(0.0);
		test.symuluj(1.0);
		test.symuluj(1.0);

		test.reset();

		std::vector<double> spodzSygWy = { 0.0, 0.0 };
		std::vector<double> faktSygWy(2);

		faktSygWy[0] = test.symuluj(0.0);
		faktSygWy[1] = test.symuluj(0.0);

		myAssert(spodzSygWy, faktSygWy, sygnatura);
	}
	catch (...) {
		s_liczbaTestow++;
		std::cerr << "[FAIL] " << sygnatura << " -> INTERUPTED!\n";
	}
}


void WszystkieTesty::uruchomWszystkieNasze() {
	test_Generator_1_GeneratorProstokatny();
	test_Generator_2_GeneratorSinusoidalny();
	test_Generator_3_PrzelaczenietypuGeneratora();
	test_generator_4_Reset();
	test_ARX_5_nasycenieU();
	test_ARX_6_resetBuforow();
	test_PID_7_resetPamieciCalki();
	test_PID_8_wylaczenieCalki();
	test_UAR_9_SkokIPowrot();
	test_UAR_10_reset();


	std::cout << "Testy zakonczone powodzeniem: "
		<< s_poprawneTesty << "/" << s_liczbaTestow << "\n";
};


void WszystkieTesty::uruchomWszystkie()
{
	s_liczbaTestow = 0;
	s_poprawneTesty = 0;

	
	test_brakPobudzenia();
	test_skokJednostkowy_1();
	test_skokJednostkowy_2();
	test_skokJednostkowy_3();

	
	test_P_brakPobudzenia();
	test_P_skokJednostkowy();
	test_PI_skokJednostkowy_1();
	test_PI_skokJednostkowy_2();
	test_PID_skokJednostkowy();
	test_PI_skokJednostkowy_3();

	
	test_UAR_1_brakPobudzenia();
	test_UAR_1_skokJednostkowyPID();
	test_UAR_2_skokJednostkowyPID();
	test_UAR_3_skokJednostkowyPID();

	test_Generator_1_GeneratorProstokatny();
	test_Generator_2_GeneratorSinusoidalny();
	test_Generator_3_PrzelaczenietypuGeneratora();
	test_generator_4_Reset();
	test_ARX_5_nasycenieU();
	test_ARX_6_resetBuforow();
	test_PID_7_resetPamieciCalki();
	test_PID_8_wylaczenieCalki();
	test_UAR_9_SkokIPowrot();
	test_UAR_10_reset();

	std::cout << "Testy zakonczone powodzeniem: "
		<< s_poprawneTesty << "/" << s_liczbaTestow << "\n";
}