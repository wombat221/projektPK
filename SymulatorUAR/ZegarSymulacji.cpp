#include "ZegarSymulacji.h"
#include <algorithm>


ZegarSymulacji::ZegarSymulacji(int interwalMs, double okresS, double oknoSymulacji) {
    setInterwal(interwalMs);
    setOkres(okresS);
    setOknoSymulacji(oknoSymulacji);
}


void ZegarSymulacji::setInterwal(int interwalMs) {
    m_interwalMs = std::clamp(interwalMs, 10, 200);
}

void ZegarSymulacji::setOkres(double okresS) {
    m_okresS = std::clamp(okresS, 0.0, 10.0);
}

void ZegarSymulacji::setOknoSymulacji(double oknoSymulacji) {
    m_oknoSymulacji = std::clamp(oknoSymulacji, 1.0, 30.0);
}

int ZegarSymulacji::obliczOkresDyskretny() const {
    int probki = m_okresS * 1000 / m_interwalMs;
    return (probki < 1) ? 1 : probki;
}

int ZegarSymulacji::obliczProbkiOkna() const {
    int probki = m_oknoSymulacji * 1000 / m_interwalMs;
    return (probki < 1) ? 1 : probki;
}
