#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.hh"



/*
  Klasa UkladRownanLiniowych modeluje pojęcie układu równań składającego się z macierzy i wektora
 */
class UkladRownanLiniowych 
{
  Macierz A;
  Wektor B;

  public:

  //Deklaracja konstruktora
  UkladRownanLiniowych();

  //Deklaracja konstruktora parametrycznego
  UkladRownanLiniowych(Macierz AA, Wektor BB);

  //Deklaracja funkcji obliczającej równanie macierzowe(const)
  Wektor Oblicz() const;

  //Deklaracja funkcji zamieniającej pierwszą kolumnę macierzy na wektor
  Macierz ZamienX() const;

  //Deklaracja funkcji zamieniającej drugą kolumnę macierzy na wektor
  Macierz ZamienY() const;

  //Deklaracja funkcji zamieniającej trzecią kolumnę macierzy na wektor
  Macierz ZamienZ() const;

  //Deklaracja funkcji przekazującej nam macierz z klasy do odczytu
  Macierz wez_macierz() const;

  //Deklaracja funkcji przekazującej nam macierz z klasy do zapisu
  void zmien_macierz(Macierz M);

  //Deklaracja funkcji przekazującej nam wektor z klasy do odczytu
  Wektor wez_wektor() const;

  //Deklaracja funkcji przekazującej nam wektor z klasy do zapisu
  void zmien_wektor(Wektor W);

  //Deklaracja funkcji obliczającej wektor błędu
  Wektor Blad() const;

  //Deklaracja funkcji obliczającej długość wektora błędu
  double DlugoscBledu() const;
};


/* 
  Funkcja wczytująca układ równań ze strumienia wejściowego
*/
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

/*
  Funkcja wyświetlająca układ równań na strumień wejściowy
 */
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown);


#endif
