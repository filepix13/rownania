#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"


/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  Wektor Wek1(1,2,3);
  Wektor Wek2(4,5,6);
  Wektor Wek3(7,8,9);

  Macierz Ma(Wek1,Wek2,Wek3);
  Macierz M;

  M = Ma.transpozycja();

  //std::cout << Ma.transpozycja();


  std::cout << std::endl << " Start programu " << std::endl << std::endl;
}
