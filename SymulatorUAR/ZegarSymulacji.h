#pragma once


class ZegarSymulacji {
private:
    int m_interwalMs = 50;
    double m_okresS = 10.0;
    double m_oknoSymulacji = 10.0;
public:
    ZegarSymulacji() = default;
    ZegarSymulacji(int interwalMs, double okresS, double oknoSymulacji);
    
    void setInterwal(int interwalMs);
    void setOkres(double okresS);
    void setOknoSymulacji(double oknoSymulacji);
    
    int getInterwal() const { return m_interwalMs; }
    double getOkres() const { return m_okresS; }


    int obliczOkresDyskretny() const;
    int getProbkiOkna() const;
};