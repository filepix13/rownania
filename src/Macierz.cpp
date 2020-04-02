#include "Macierz.hh"
#include <math.h>



/* 
    Konstuktor zmiennej Macierz, zeruje tabelę tab
    Argumenty:
        this
    Zwraca:
        this
*/
Macierz::Macierz()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            tab[i][j] = 0;
        }
    }
}


/* 
    Konstuktor parametryczny zmiennej Wektor
    Argumenty:
        this
        Wek1, Wek2, Wek3 - wektory wstawiane do tabeli tab
    Zwraca:
        this
*/
Macierz::Macierz(Wektor Wek1, Wektor Wek2, Wektor Wek3)
{
    tab[0] = Wek1;
    tab[1] = Wek2;
    tab[2] = Wek3;
}


/* 
    Konstuktor parametryczny zmiennej Wektor
    Argumenty:
        this
        a, b, c, d, e, f, g, h, i - liczby rzeczywiste podstawiane do tabeli tab
    Zwraca:
        this
*/
Macierz::Macierz(double a, double b, double c, double d, double e, double f, double g, double h, double i)
{
    tab[0][0] = a;
    tab[0][1] = b;
    tab[0][2] = c;
    tab[1][0] = d;
    tab[1][1] = e;
    tab[1][2] = f;
    tab[2][0] = g;
    tab[2][1] = h;
    tab[2][2] = i;
}


/* 
    Funkcja ta przeciąża operator indeksujący
    Argumenty:
        this
        int indeks - indeks zmniennej którą chcemy uzyskać
    Zwraca:
        tab[indeks] - zwraca tą zmienną klasy, której indeks podaliśmy
*/
const Wektor & Macierz::operator[] (int indeks) const
{
    if (indeks < 0 || indeks >= ROZMIAR) {
      std::cerr << "blad: zly indeks macierzy";
      exit(1);
    }
    return this->tab[indeks];
}


/* 
    Funkcja ta przeciąża operator indeksujący
    Argumenty:
        this
        int indeks - indeks zmniennej którą chcemy uzyskać
    Zwraca:
        tab[indeks] - zwraca tą zmienną klasy, której indeks podaliśmy
*/
Wektor & Macierz::operator[] (int indeks)
{
    if (indeks < 0 || indeks >= ROZMIAR) {
      std::cerr << "blad: zly indeks macierzy";
      exit(1);
    }
    return this->tab[indeks];
}


/* 
    Funkcja ta przeciąża operator funkcjonalny
    Argumenty:
        this
        int ind1 - pierwszy indeks(wiersze)
        int ind2 - drugi indeks(kolumny)
    Zwraca:
        tab[ind1][ind2] - zwraca tą zmienną klasy, której indeksy podaliśmy
*/
const double & Macierz::operator() (int ind1, int ind2) const
{
    if (ind1 < 0 || ind1 >= ROZMIAR || ind2 < 0 || ind2 >= ROZMIAR) {
      std::cerr << "blad: zly indeks macierzy";
      exit(1);
    }
    return this->tab[ind1][ind2];
}


/* 
    Funkcja ta przeciąża operator funkcjonalny
    Argumenty:
        this
        int ind1 - pierwszy indeks(wiersze)
        int ind2 - drugi indeks(kolumny)
    Zwraca:
        tab[ind1][ind2] - zwraca tą zmienną klasy, której indeksy podaliśmy
*/
double & Macierz::operator() (int ind1, int ind2)
{
    if (ind1 < 0 || ind1 >= ROZMIAR || ind2 < 0 || ind2 >= ROZMIAR) {
      std::cerr << "blad: zly indeks macierzy";
      exit(1);
    }
    return this->tab[ind1][ind2];
}


/* 
    Funkcja ta transponuje macierz
    Argumenty:
        this
    Zwraca:
        Mac - transponowana macierz
*/
const Macierz Macierz::transpozycja2() const
{
    Macierz Mac;

    Mac.tab[0][0] = this->tab[0][0];
    Mac.tab[1][1] = this->tab[1][1];
    Mac.tab[2][2] = this->tab[2][2];
    Mac.tab[0][1] = this->tab[1][0];
    Mac.tab[1][0] = this->tab[0][1];
    Mac.tab[0][2] = this->tab[2][0];
    Mac.tab[2][0] = this->tab[0][2];
    Mac.tab[2][1] = this->tab[1][2];
    Mac.tab[1][2] = this->tab[2][1];

    return Mac;
}


/* 
    Funkcja ta transponuje macierz
    Argumenty:
        this
    Zwraca:
        this
*/
void Macierz::transpozycja()
{
    double a,b,c;
    a = this->tab[0][1];
    b = this->tab[0][2];
    c = this->tab[2][1];

    this->tab[0][1] = this->tab[1][0];
    this->tab[1][0] = a;
    this->tab[0][2] = this->tab[2][0];
    this->tab[2][0] = b;
    this->tab[2][1] = this->tab[1][2];
    this->tab[1][2] = c;
}


/* 
    Funkcja ta oblicza wyznacznik macierzy metodą Laplaca
    Argumenty:
        this
    Zwraca:
        d - wynacznik macierzy
*/
double Macierz::Wyznacznik() const
{
    double d;

    d = this->tab[0][0]*(this->tab[1][1]*this->tab[2][2]-this->tab[2][1]*this->tab[1][2]);
    d += -(this->tab[0][1]*(this->tab[1][0]*this->tab[2][2]-this->tab[2][0]*this->tab[1][2]));
    d += this->tab[0][2]*(this->tab[1][0]*this->tab[2][1]-this->tab[2][0]*this->tab[1][1]);

    return d;
}


/* 
    Funkcja ta tworzy macierz odwrotną
    Argumenty:
        this
    Zwraca:
        Mac - macierz odwócona
*/
const Macierz Macierz::odwrotnosc() const
{
    Macierz Mac;
    double det;

    det = 1/this->Wyznacznik();

    Mac.tab[0][0] = det * pow(-1, 2) * (tab[1][1] * tab[2][2] - tab[2][1] * tab[1][2]);
    Mac.tab[0][1] = det * pow(-1, 3) * (tab[1][0] * tab[2][2] - tab[2][0] * tab[1][2]);
    Mac.tab[0][2] = det * pow(-1, 4) * (tab[1][0] * tab[2][1] - tab[2][0] * tab[1][1]);
    Mac.tab[1][0] = det * pow(-1, 5) * (tab[0][1] * tab[2][2] - tab[2][1] * tab[0][2]);
    Mac.tab[1][1] = det * pow(-1, 6) * (tab[0][0] * tab[2][2] - tab[2][0] * tab[0][2]);
    Mac.tab[1][2] = det * pow(-1, 7) * (tab[0][0] * tab[2][1] - tab[2][0] * tab[0][1]);
    Mac.tab[2][0] = det * pow(-1, 8) * (tab[0][1] * tab[1][2] - tab[1][1] * tab[0][2]);
    Mac.tab[2][1] = det * pow(-1, 9) * (tab[0][0] * tab[1][2] - tab[1][0] * tab[0][2]);
    Mac.tab[2][2] = det * pow(-1, 10) *(tab[0][0] * tab[1][1] - tab[1][0] * tab[0][1]);

    Mac.transpozycja();

    return Mac;
}


/* 
    Funkcja ta dodaje dwie macierze
    Argumenty:
        this
        M - druga macierz
    Zwraca:
        Mac - suma dwóch macierzy wejściowych
*/
const Macierz Macierz::operator + (const Macierz & M) const
{
    Macierz Mac;

    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Mac.tab[i][j] = this->tab[i][j] + M.tab[i][j];
        }
    }

    return Mac;
}


/* 
    Funkcja ta odejmnuje dwie macierze
    Argumenty:
        this
        M - druga macierz
    Zwraca:
        Mac - różnica dwóch macierzy wejściowych
*/
const Macierz Macierz::operator - (const Macierz & M) const
{
    Macierz Mac;

    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Mac.tab[i][j] = this->tab[i][j] - M.tab[i][j];
        }
    }

    return Mac;
}


/* 
    Funkcja ta mnoży dwie macierze
    Argumenty:
        this
        M - druga macierz
    Zwraca:
        Mac - iloraz dwóch macierzy wejściowych
*/
const Macierz Macierz::operator * (const Macierz & M) const
{
   Macierz Mac;

    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Mac.tab[i][j] = this->tab[i][0] * M.tab[0][j] + this->tab[i][1] * M.tab[1][j] + this->tab[i][2] * M.tab[2][j];
        }
    }

    return Mac;
}


/* 
    Funkcja ta mnoży macierz z wektorem
    Argumenty:
        this
        W - wektor
    Zwraca:
        Wek - Iloraz macierzy i wektora wejściowego
*/
const Wektor Macierz::operator * (const Wektor & W) const
{
    Wektor Wek;

    for(int i=0; i<ROZMIAR; i++)
    {
       Wek[i] = this->tab[i][0] * W[0] + this->tab[i][1] * W[1] + this->tab[i][2] * W[2];
    }

    return Wek;
}


/* 
    Funkcja ta wczytuje macierz z strumienia wejściowego
    Argumenty:
        Strm - strumień wejściowy
        Wek - macierz do której wczytujemy dane
    Zwraca:
        Strumień wejściowy
*/
std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
    Strm >> Mac[0] >> Mac[1] >> Mac[2];
    Mac.transpozycja();
    return Strm;
}


/* 
    Funkcja ta wyświetla macierz na strumień wejściowy
    Argumenty:
        Strm - strumień wyjściowy
        Wek - macierz którą wyświetlamy
    Zwraca:
        Strumień wyjściowy
*/
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{   
    Macierz M;
    M = Mac.transpozycja2();
    return Strm << M[0] << std::endl << M[1] << std::endl << M[2] << std::endl;
}
