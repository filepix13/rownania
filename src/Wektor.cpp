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
    for(int i=0; i<ROZMIAR; i++)
    {
        dane[i]=0;
    }
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
Wektor Wektor::operator + (const Wektor & W2) const
{
    Wektor W;

    for(int i=0; i<ROZMIAR; i++)
    {
        W.dane[i] = this->dane[i] + W2.dane[i];
    }

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
Wektor Wektor::operator - (const Wektor & W2) const
{
    Wektor W;

    for(int i=0; i<ROZMIAR; i++)
    {
        W.dane[i] = this->dane[i] - W2.dane[i];
    }

    return W;
}


/* 
    Funkcja ta oblicza iloczyn sklarny dwóch wektorów
    Argumenty:
        this
        W2 - drugi wektor
    Zwraca:
        Iloczyn skalarny(double)
*/
double Wektor::operator * (const Wektor & W2) const
{
    double d;

    for(int i=0; i<ROZMIAR; i++)
    {
        d += dane[i] * W2.dane[i];
    }

    return d;
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
    for(int i=0; i<ROZMIAR; i++)
    {
        Strm >> Wek[i];
    }

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
    for(int i=0; i<ROZMIAR; i++)
    {
        Strm << Wek[i] << "  ";
    }

    Strm << std::endl;

    return Strm;
}
