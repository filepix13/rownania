#include "Wektor.hh"
#include <math.h>  



/* 
    Konstuktor zmiennej Wektor, zeruje tabelę dane
    Argumenty:
        this
    Zwraca:
        this
*/
Wektor::Wektor()
{
    dane[0] = 0.0;
    dane[1] = 0.0;
    dane[2] = 0.0;
}


/* 
    Konstuktor parametryczny zmiennej Wektor
    Argumenty:
        this
        x, y, z - wartości podstawiane pod odpowiednie miejsca tabeli dane
    Zwraca:
        this
*/
Wektor::Wektor(double x, double y, double z)
{
    dane[0] = x;
    dane[1] = y;
    dane[2] = z;
}


/* 
    Funkcja ta oblicza długość wektora
    Argumenty:
        this
    Zwraca:
        dlugosc - długość wektora
*/
double Wektor::dlugosc() const
{
    double dlugosc,x,y,z;

    x = pow(this->dane[0], 2);
    y = pow(this->dane[1], 2);
    z = pow(this->dane[2], 2);

    dlugosc = sqrt(x+y+z);

    return dlugosc;
}


/* 
    Funkcja ta dodaje dwa wektory
    Argumenty:
        this
        W2 - drugi wektor
    Zwraca:
        W - suma dwóch wektorów
*/
const Wektor Wektor::operator + (const Wektor & W2) const
{
    Wektor W;

    W.dane[0] = this->dane[0] + W2.dane[0];
    W.dane[1] = this->dane[1] + W2.dane[1];
    W.dane[2] = this->dane[2] + W2.dane[2];

    return W;
}


/* 
    Funkcja ta odejmnuje dwa wektory
    Argumenty:
        this
        W2 - drugi wektor
    Zwraca:
        W - różnica dwóch wektorów
*/
const Wektor Wektor::operator - (const Wektor & W2) const
{
    Wektor W;

    W.dane[0] = this->dane[0] - W2.dane[0];
    W.dane[1] = this->dane[1] - W2.dane[1];
    W.dane[2] = this->dane[2] - W2.dane[2];

    return W;
}


/* 
    Funkcja ta przeciąża operator indeksujący
    Argumenty:
        this
        int indeks - indeks zmniennej którą chcemy uzyskać
    Zwraca:
        dane[indeks] - zwraca tą zmienną klasy, której indeks podaliśmy
*/
const double & Wektor::operator[] (int indeks) const
{
    if (indeks < 0 || indeks >= ROZMIAR) {
      std::cerr << "blad: zly indeks wektora";
      exit(1);
    }
    return this->dane[indeks];
}


/* 
    Funkcja ta przeciąża operator indeksujący
    Argumenty:
        this
        int indeks - indeks zmniennej którą chcemy uzyskać
    Zwraca:
        dane[indeks] - zwraca tą zmienną klasy, której indeks podaliśmy
*/
double & Wektor::operator[] (int indeks)
{
    if (indeks < 0 || indeks >= ROZMIAR) {
      std::cerr << "blad: zly indeks wektora";
      exit(1);
    }
    return this->dane[indeks];
}


/* 
    Funkcja ta wczytuje wektor z strumienia wejściowego
    Argumenty:
        Strm - strumień wejściowy
        Wek - wektor do którego wczytujemy dane
    Zwraca:
        Strumień wejściowy
*/
std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
    Strm >> Wek[0] >> Wek[1] >> Wek[2];

    if(std::cin.fail())
    {
        std::cerr << "Wpisany znak nie jest liczbą rzeczywistą" << std::endl << "Zamykanie programu...";
        exit(1);
    }

    return Strm;
}


/* 
    Funkcja ta wyświetla wektor na strumień wejściowy
    Argumenty:
        Strm - strumień wyjściowy
        Wek - wektor który wyświetlamy
    Zwraca:
        Strumień wyjściowy
*/
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
    return Strm << Wek[0] << "  " <<Wek[1] << "  " << Wek[2] << std::endl;
}
