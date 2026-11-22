#include "ZegarSymulacji.h"


class ZegarSymulacji {
private:
    int m_interwalMs = 50;        
    double m_okresS = 10.0; 
    double m_oknoSymulacji = 10.0;
public:
    ZegarSymulacji() = default;
    ZegarSymulacji(int interwalMs, double okresS, double oknoSymulacji);
    void setInterwal(double interwalMs);
    void setOkres(double okresS);
    void setOknoSymulacji(double oknoSymulacji)

    int obliczOkresDyskretny() const {
        int probki = m_okresS * 1000 / m_interwalMs;
        return (probki < 1) ? 1 : probki;
    }

    int obliczProbkiOkna() const {
        int probki = m_oknoSymulacji * 1000 / m_interwalMs;
        return (probki < 1) ? 1 : probki;
    }
};