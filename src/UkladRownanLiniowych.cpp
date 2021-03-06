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

    det = this->A.Wyznacznik();

    if(det == 0)
    {
        std::cerr << "Wyznacznik równy zero, brak możliwości obliczenia równania." << std::endl << "Zamykanie programu...";
        exit(1);
    }

    MaX = this->ZamienX();
    MaY = this->ZamienY();
    MaZ = this->ZamienZ();

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
Macierz UkladRownanLiniowych::ZamienX() const
{
    Macierz M = this->A;

    for(int i=0; i<ROZMIAR; i++)
    {
        M[i][0] = this->B[i];
    }

    return M;
}


/* 
    Funkcja ta zamienia drugą kolumnę macierzy na wektor
    Argumenty:
        this
    Zwraca:
        M - macierz z zamienioną drugą kolumną
*/
Macierz UkladRownanLiniowych::ZamienY() const
{
    Macierz M = this->A;

   for(int i=0; i<ROZMIAR; i++)
    {
        M[i][1] = this->B[i];
    }

    return M;
}


/* 
    Funkcja ta zamienia trzecią kolumnę macierzy na wektor
    Argumenty:
        this
    Zwraca:
        M - macierz z zamienioną trzecią kolumną
*/
Macierz UkladRownanLiniowych::ZamienZ() const
{
    Macierz M = this->A;

    for(int i=0; i<ROZMIAR; i++)
    {
        M[i][2] = this->B[i];
    }

    return M;
}


/* 
    Funkcja przekazująca macierz z klasy do odczytu
    Argumenty:
        this
    Zwraca:
        A - macierz
*/
Macierz UkladRownanLiniowych::wez_macierz() const
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
Wektor UkladRownanLiniowych::wez_wektor() const
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
Wektor UkladRownanLiniowych::Blad() const
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
double UkladRownanLiniowych::DlugoscBledu() const
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
