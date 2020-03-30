#include "Wektor.hh"
#include <math.h>  

Wektor::Wektor()
{
    dane[0] = 0.0;
    dane[1] = 0.0;
    dane[2] = 0.0;
}


Wektor::Wektor(double x, double y, double z)
{
    dane[0] = x;
    dane[1] = y;
    dane[2] = z;
}

double Wektor::dlugosc() const
{
    double dlugosc,x,y,z;

    x = pow(this->dane[0], 2);
    y = pow(this->dane[1], 2);
    z = pow(this->dane[2], 2);

    dlugosc = sqrt(x+y+z);

    return dlugosc;
}


/*double Wektor::operator * (const Wektor & W2) const
{

}*/


const Wektor & Wektor::operator + (const Wektor & W2) const
{
    Wektor W;

    W.dane[0] = this->dane[0] + W2.dane[0];
    W.dane[1] = this->dane[1] + W2.dane[1];
    W.dane[2] = this->dane[2] + W2.dane[2];

    return W;
}

const Wektor & Wektor::operator - (const Wektor & W2) const
{
    Wektor W;

    W.dane[0] = this->dane[0] - W2.dane[0];
    W.dane[1] = this->dane[1] - W2.dane[1];
    W.dane[2] = this->dane[2] - W2.dane[2];

    return W;
}

const double & Wektor::operator[] (int indeks) const
{
    if (indeks < 0 || indeks >= ROZMIAR) {
      std::cerr << "blad: zly indeks wektora";
      exit(1);
    }
    return this->dane[indeks];
}


double & Wektor::operator[] (int indeks)
{
    if (indeks < 0 || indeks >= ROZMIAR) {
      std::cerr << "blad: zly indeks wektora";
      exit(1);
    }
    return this->dane[indeks];
}

std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
    Strm >> Wek[0] >> Wek[1] >> Wek[2];
    return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
    return Strm << Wek[0] << "  " <<Wek[1] << "  " << Wek[2] << std::endl;
}