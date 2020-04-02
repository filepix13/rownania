#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"


int main()
{
  Macierz M;
  Wektor W;

  std::cout << "Macierz A^T:" << std::endl;
  std::cin >> M;
  std::cout << std::endl << "Wektor wyrazów wolnych b:" << std::endl;
  std::cin >> W;

  UkladRownanLiniowych U(M,W);
  
  std::cout << std::endl <<"Rozwiazanie x = (x1, x2, x3):" << std::endl;

  std::cout << U.Oblicz() << std::endl;

  std::cout << "Wektor błędu: Ax-B = " << U.Blad();
  std::cout << "Długość wektora błędu: |Ax-B| = " << U.DlugoscBledu() << std::endl;

}
