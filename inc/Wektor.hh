#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.hh"
#include <iostream>



/*
  Klasa wektor modeluje pojęcie macierzy o 1 kolumnie i ROZMIAR wierszach
 */
class Wektor 
{
  
  double dane[ROZMIAR];

  public:

  //Deklaracja konstruktora
  Wektor();

  //Deklaracja konstruktora parametrycznego
  Wektor(double x, double y, double z);

  //Deklaracja funkcji obliczającej długość wektora 
  double dlugosc() const;

  //Deklaracja funkcji dodającej dwa wektory
  const Wektor operator + (const Wektor & W2) const;

  //Deklaracja funkcji odejmującej dwa wektory
  const Wektor operator - (const Wektor & W2) const;

  //Deklaracja przeciążenia funkcji indeksującej
  const double & operator [] (int indeks) const;

  //Deklaracja przeciążenia funkcji indeksującej
  double & operator[] (int indeks);  

};


/* 
  Funkcja wczytująca wektor ze strumienia wejściowego
*/
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
  Funkcja wyświetlająca wektor na strumień wejściowy
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);


#endif
