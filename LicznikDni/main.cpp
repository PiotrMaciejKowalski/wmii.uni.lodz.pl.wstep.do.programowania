#include <iostream>

using namespace std;
/*
Program ma za zadanie wziac od uzytkownika dwie daty w kalendarzu
gregorianskim i policzyc ile dni rozni te dwie daty
*/
int main()
{
    // 1. Wczytac od uzytkownika te daty

    // trzeba wczytac date poczatkowa

    int rokPoczatkowy;
    int miesiacPoczatkowy;
    int dzienPoczatkowy;

    cout << "Prosze podaj rok, potem miesiac, potem dzien\n"
         << "oddzielone enterem, daty poczatkowej\n";
    cout << ">";
    cin >> rokPoczatkowy;
    cout << ">";
    cin >> miesiacPoczatkowy;
    cout <<">";
    cin >> dzienPoczatkowy;
    // trzeba wczytac date koncowa

    int rokKoncowy;
    int miesiacKoncowy;
    int dzienKoncowy;

    cout << "Prosze podaj rok, potem miesiac, potem dzien\n"
         << "oddzielone enterem, daty koncowej\n";
    cout << ">";
    cin >> rokKoncowy;
    cout << ">";
    cin >> miesiacKoncowy;
    cout <<">";
    cin >> dzienKoncowy;

    // 2. Musze policzyc ilosc dni miedzy tymi datami

    // skopiujmy date poczatkowa i zwiekszajkmy o jeden dzien az dojdziemy
    // do daty koncowej
    int rok = rokPoczatkowy;
    int miesiac = miesiacPoczatkowy;
    int dzien = dzienPoczatkowy;
    const int ILOSC_MIESIECY_W_ROKU = 12;
    int licznikDni = 0;
    int iloscDniWMiesiacu; 
    bool czyPrzestepny;
    while ( !( (rok == rokKoncowy) && (miesiac == miesiacKoncowy) 
               && (dzien == dzienKoncowy)) )
     {
          // musimy nasz dzien w kalendarzu przesunac na nastepny
          dzien++;
          // mozemy naszym dniem przekroczyc liczbe dni w miesiacu
          // potrzebujemy ustalic czy dany rok jest przestepny
          if (rok % 400 == 0)
               czyPrzestepny = true;
          else if (rok % 100 == 0)
               czyPrzestepny = false;
          else if (rok % 4 ==0)
               czyPrzestepny = true;
          else 
               czyPrzestepny = false;
          // musimy wyliczyc ile dni ma nasz miesiac
          if ((miesiac == 2) && czyPrzestepny){
               iloscDniWMiesiacu = 29;
          } 
          else if ( miesiac == 2 ) {
               iloscDniWMiesiacu = 28;
          }
          else if ( (miesiac == 4) || (miesiac == 6) ||
               (miesiac == 9) || (miesiac == 11))
          {
               iloscDniWMiesiacu = 30;
          }
          else 
          {
               iloscDniWMiesiacu = 31;
          }
          // trzeba wykryc przekroczenie i dokonac korekty
          if (dzien > iloscDniWMiesiacu){
               // korekta
               miesiac++;
               dzien = 1;
          }
          // moglismy przekroczyc do nowego roku
          if (miesiac > ILOSC_MIESIECY_W_ROKU)
          {
               rok++;
               miesiac = 1;
          }
          // musimy zwiekszyc nasz linik dni odliczonych
          licznikDni++;
     }

    // 3. Musze uzytkownikowi wypisac wyliczony wynik
     cout << "Pomiedzy data poczatkowa\n"
          << rokPoczatkowy<<"-"<<miesiacPoczatkowy<<"-"<<dzienPoczatkowy<<"\n"
          << "a \n"
          << rokKoncowy<<"-"<<miesiacKoncowy<<"-"<<dzienKoncowy<<"\n"
          << "wynosi " << licznikDni <<" dni.\n";

    return 0;
}
