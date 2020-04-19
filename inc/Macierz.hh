#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.hh"
#include <iostream>
#include <algorithm> 


//Uławtwia konstuowanie macierzy 
enum Operator{a, b, c, d, e, f, g, h, i};


/*
  Klasa Macierz modeluje pojęcie macierzy kwadratowej o ROZMIAR kolumnach i ROZMIAR wierszach
 */
class Macierz 
{

  Wektor tab[ROZMIAR];

  public:

  //Deklaracja konstruktora
  Macierz();

  //Deklaracja konstruktora parametrycznego(3 wektory)
  Macierz(Wektor Wek1, Wektor Wek2, Wektor Wek3);

  //Deklaracja konstruktora parametrycznego(9 liczb rzeczywistych)
  Macierz(double a, double b, double c, double d, double e, double f, double g, double h, double i);

  //Deklaracja przeciążenia operatora indeksującego(const)
  const Wektor & operator[] (int indeks) const;

  //Deklaracja przeciążenia operatora indeksującego
  Wektor & operator[] (int indeks);

  //Deklaracja przeciążnie operatora funkcyjnego(const)
  const double & operator() (int ind1, int ind2) const;

  //Deklaracja przeciążnie operatora funkcyjnego
  double & operator() (int ind1, int ind2);

  //Deklaracja funkcji transponującej macierz(const)
  Macierz transpozycja2() const;

  //Deklaracja funkcji transponującej macierz
  void transpozycja();

  //Deklaracja funkcji obliczającej wyznacznik macierzy(const)
  double Wyznacznik() const;

  //Deklaracja funkcji obliczającej macierz odwrotną(const)
  Macierz odwrotnosc() const;

  //Deklaracja funkcji dodającej dwie macierze(const)
  Macierz operator + (const Macierz & M) const;

  //Deklaracja funkcji odejmującej dwie macierze(const) 
  Macierz operator - (const Macierz & M) const;

  //Deklaracja funkcji mnożącej dwie macierze 
  Macierz operator * (const Macierz & M) const;

  //Deklaracja funkcji mnożącej macierz i wektor
  Wektor operator * (const Wektor & W) const;  
};


/* 
  Funkcja wczytująca macierz ze strumienia wejściowego
*/
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
  Funkcja wyświetlająca macierz na strumień wejściowy
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
