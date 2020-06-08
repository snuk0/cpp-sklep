#include <bits/stdc++.h>

using namespace std;

fstream plik;
ofstream plik2;

class towar
{
    public:
        string nazwa;
        int cena, id;

        void wczytaj()
        {
            plik >> cena >> id >> nazwa;
        }
        void wypisz()
        {
            plik2.open("b.txt");
            plik2 << cena << " "<< id << " " << nazwa << " ";
        }
};

class buty : public towar
{
    public:
        string kolor, model;
        int rozmiar;

        void wczytaj_buty()
        {
           wczytaj();
           plik >> rozmiar >> kolor >> model;
        }
        void wypisz_buty()
        {
           wypisz();
           plik2 << rozmiar << " " << kolor << " " << model << "\n";
        }
};

class pasty : public towar
{
    public:
        string kolor;

        void wczytaj_pasty()
        {
            wczytaj();
            plik >> kolor;
        }
        void wypisz_pasty()
        {
            wypisz();
            plik2 << kolor << "\n";
        }
};

class sklep_buty : public buty
{
    struct value_buty
    {
        string nazwa, kolor, model;
        int cena, id, rozmiar;
    };

    public:

        value_buty dane_buty;
        vector <value_buty> kolekcja_butow;

        void wczytaj_z_pliku()
        {
            wczytaj_buty();
            dane_buty.cena = cena;
            dane_buty.id = id;
            dane_buty.rozmiar = rozmiar;
            dane_buty.nazwa = nazwa;
            dane_buty.kolor = kolor;
            dane_buty.model = model;
            kolekcja_butow.push_back(dane_buty);
        }

        void zapisz_do_pliku()
        {
            for (auto it : kolekcja_butow)
            {
                char x = '#'-1;
                plik2 <<
                         "{ \n" << "   " << x << "cena" << x << ":" << x << it.cena << x << "\n"
                                 << "   " << x << "id" << x << ":" << x << it.id << x << "\n"
                                 << "   " << x << "rozmiar" << x << ":" << x << it.rozmiar << x << "\n"
                                 << "   " << x << "nazwa" << x << ":" << x << it.nazwa << x << "\n"
                                 << "   " << x << "kolor" << x << ":" << x << it.kolor << x << "\n"
                                 << "   " << x << "model" << x << ":" << x << it.model << x << "\n}";

                    plik2 << ",";
                plik2 << "\n";
            }
        }
};

class sklep_pasty : public pasty
{
    struct value_pasty
    {
        string nazwa, kolor;
        int cena, id;
    };

    public:
        value_pasty dane_pasty;
        vector <value_pasty> kolekcja_past;

        void wczytaj_z_pliku()
        {
            wczytaj_pasty();
            dane_pasty.cena = cena;
            dane_pasty.id = id;
            dane_pasty.nazwa = nazwa;
            dane_pasty.kolor = kolor;
            kolekcja_past.push_back(dane_pasty);
        }

        void zapisz_do_pliku()
        {
            for (auto it : kolekcja_past)
            {
                char x = '#'-1;
                plik2 <<
                         "{ \n" << "   " << x << "cena" << x << ":" << x << it.cena << x << "\n"
                                 << "   " << x << "id" << x << ":" << x << it.id << x << "\n"
                                 << "   " << x << "nazwa" << x << ":" << x << it.nazwa << x << "\n"
                                 << "   " << x << "kolor" << x << ":" << x << it.kolor << x << "\n}";

                    plik2 << ",";
                plik2 << "\n";
            }
        }
};

int main()
{
    sklep_buty spis_buty;
  	sklep_pasty spis_past;
  	plik.open("a.txt", ios::in);
  	spis_past.wczytaj_z_pliku();
  	spis_past.wczytaj_z_pliku();
  	spis_buty.wczytaj_z_pliku();
  	plik2.open("b.txt");
  	spis_past.zapisz_do_pliku();
  	spis_buty.zapisz_do_pliku();
    return 0;
}
