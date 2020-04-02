#include "UkladRownanLiniowych.hh"



/* 
    Konstuktor zmiennej UkladRownanLiniowych, zeruje macierz oraz wektor
    Argumenty:
        this
    Zwraca:
        this
*/
UkladRownanLiniowych::UkladRownanLiniowych()
{
    Macierz A;
    Wektor B;
}


/* 
    Konstuktor parametryczny zmiennej UkladRownanLiniowych, zeruje macierz oraz wektor
    Argumenty:
        this
    Zwraca:
        this
*/
UkladRownanLiniowych::UkladRownanLiniowych(Macierz AA, Wektor BB)
{
    A = AA;
    B = BB;
}


/* 
    Funkcja rozwiązuje układ Cramera
    Argumenty:
        this
    Zwraca:
        W - wektor wynikowy
*/
Wektor UkladRownanLiniowych::Oblicz() const
{
    Wektor W;
    Macierz MaX, MaY, MaZ;
    double det, detX, detY, detZ;

    MaX = this->ZamienX();
    MaY = this->ZamienY();
    MaZ = this->ZamienZ();

    det = this->A.Wyznacznik();
    detX = MaX.Wyznacznik();
    detY = MaY.Wyznacznik();
    detZ = MaZ.Wyznacznik();

    W[0] = detX/det;
    W[1] = detY/det;
    W[2] = detZ/det;
    
    return W;
}


/* 
    Funkcja ta zamienia pierwszą kolumnę macierzy na wektor
    Argumenty:
        this
    Zwraca:
        M - macierz z zamienioną pierwszą kolumną
*/
const Macierz UkladRownanLiniowych::ZamienX() const
{
    Macierz M = this->A;

    M[0][0] = this->B[0];
    M[1][0] = this->B[1];
    M[2][0] = this->B[2];

    return M;
}


/* 
    Funkcja ta zamienia drugą kolumnę macierzy na wektor
    Argumenty:
        this
    Zwraca:
        M - macierz z zamienioną drugą kolumną
*/
const Macierz UkladRownanLiniowych::ZamienY() const
{
    Macierz M = this->A;

    M[0][1] = this->B[0];
    M[1][1] = this->B[1];
    M[2][1] = this->B[2];

    return M;
}


/* 
    Funkcja ta zamienia trzecią kolumnę macierzy na wektor
    Argumenty:
        this
    Zwraca:
        M - macierz z zamienioną trzecią kolumną
*/
const Macierz UkladRownanLiniowych::ZamienZ() const
{
    Macierz M = this->A;

    M[0][2] = this->B[0];
    M[1][2] = this->B[1];
    M[2][2] = this->B[2];

    return M;
}


/* 
    Funkcja przekazująca macierz z klasy do odczytu
    Argumenty:
        this
    Zwraca:
        A - macierz
*/
const Macierz UkladRownanLiniowych::wez_macierz() const
{
    return this->A;
}


/* 
    Funkcja przekazująca macierz z klasy do zapisu
    Argumenty:
        this
    Zwraca:
        brak
*/
void UkladRownanLiniowych::zmien_macierz(Macierz M)
{
    this->A = M;
}


/* 
    Funkcja przekazująca wektor z klasy do odczytu
    Argumenty:
        this
    Zwraca:
        B - wektor
*/
const Wektor UkladRownanLiniowych::wez_wektor() const
{
    return this->B;
}


/* 
    Funkcja przekazująca wektor z klasy do zapisu
    Argumenty:
        this
    Zwraca:
        brak
*/
void UkladRownanLiniowych::zmien_wektor(Wektor W)
{
    this->B = W;
}


/* 
    Funkcja ta oblicza wektor błędu wynikający z obliczeń
    Argumenty:
        this
    Zwraca:
        Wektor błędu
*/
const Wektor UkladRownanLiniowych::Blad() const
{
    return this->A * this->Oblicz() - this->B;
}


/* 
    Funkcja ta oblicza długość wektora błędu wynikającą z obliczeń
    Argumenty:
        this
    Zwraca:
        Długość wektora błędu
*/
const double UkladRownanLiniowych::DlugoscBledu() const
{
    return this->Blad().dlugosc();
}


/* 
    Funkcja ta wczytuje układ równań z strumienia wejściowego
    Argumenty:
        Strm - strumień wejściowy
        Wek - układ równań do którego wczytujemy dane
    Zwraca:
        Strumień wejściowy
*/
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    Macierz AA;
    Wektor BB;

    Strm >> AA >> BB;
    UklRown.zmien_macierz(AA);
    UklRown.zmien_wektor(BB);

    return Strm;
}


/* 
    Funkcja ta wyświetla układ równań na strumień wejściowy
    Argumenty:
        Strm - strumień wyjściowy
        Wek - układ równań który wyświetlamy
    Zwraca:
        Strumień wyjściowy
*/
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown)
{
    return Strm << UklRown.wez_macierz() << UklRown.wez_wektor() << std::endl;
}
