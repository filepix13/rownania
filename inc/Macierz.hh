#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.hh"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz 
{

  Wektor tab[ROZMIAR];

  public:

  Macierz();
  Macierz(Wektor Wek1, Wektor Wek2, Wektor Wek3);
  Macierz(double a, double b, double c, double d, double e, double f, double g, double h, double i);
  const Wektor & operator[] (int indeks) const;
  Wektor & operator[] (int indeks);
  const Macierz & transpozycja() const;
  /*
  

  const double & operator() (int ind1, int ind2) const;
  double & operator() (int ind1, int ind2);

  const Wektor & wez_kolumne(int ind) const;//pomocnicze, analogicznie dla wiersza i dla zmien
  Wektor & wez_kolumne(int ind);
  
  void odwrotnosc(); //1.
  const Macierz & odwrotnosc() const; //2.
  
  double Wyznacznik() const;
  // Laplace, Gauss, Sarrus
  double WyznacznikGauss() const;
  double Wyznacznik(Gauss) const; //enum
  
  void transpozycja(); //1.
  const Macierz & transpozycja() const; //2.
  
  const Macierz & operator + (const Macierz & W) const; 
  const Macierz & operator - (const Macierz & W) const; 
  const Macierz & operator * (const Macierz & W) const;  
*/
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
