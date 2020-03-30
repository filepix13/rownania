#include "Macierz.hh"


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


Macierz::Macierz(Wektor Wek1, Wektor Wek2, Wektor Wek3)
{
    tab[0] = Wek1;
    tab[1] = Wek2;
    tab[2] = Wek3;
}

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


const Wektor & Macierz::operator[] (int indeks) const
{
    if (indeks < 0 || indeks >= ROZMIAR) {
      std::cerr << "blad: zly indeks macierzy";
      exit(1);
    }
    return this->tab[indeks];
}


Wektor & Macierz::operator[] (int indeks)
{
    if (indeks < 0 || indeks >= ROZMIAR) {
      std::cerr << "blad: zly indeks macierzy";
      exit(1);
    }
    return this->tab[indeks];
}


const Macierz & Macierz::transpozycja() const
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


/*std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{

}
*/

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
    return Strm << Mac[0] << std::endl << Mac[1] << std::endl << Mac[2] << std::endl;
}