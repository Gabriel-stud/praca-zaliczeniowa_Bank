#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>

int main() {
  double saldo[5]={{1457.23}, {3600.18}, {2745.03}, {7344.00}, {455.38}};
  char imiona[5][19]={{"Jan Nowak"},{"Agnieszka Kowalska"},{"Robert Lewandowski"},{"Zofia Plucińska"},{"Grzegorz Braun"}};
  int k;
  int x=0, y=0; 
  opcje:
  std::cout << "WYBIERZ OPCJĘ:\n";
  std::cout << "1 => LISTA WSZYSTKICH KLIENTÓW BANKU\n";
  std::cout << "2 => LOGOWANIE\n";
  std::cout << "3 => ZAKOŃCZ PROGRAM\n";
  std::cout << "WYBIERZ 1, 2 LUB 3: ";
  std::cin >> x;
  switch (x)
    {
      case 1:
        //system("cls");
        salda: 
        std::cout << "ID | IMIĘ I NAZWISKO | NR KONTA | SALDO\n";
        for(int i=0; i<5; i++)
          {
            std::cout << i+1 <<" | "<<imiona[i]<<" | "<<"00"<<i+1<<" | "<<saldo[i]<<" zł"<<"\n"; 
          }
        goto opcje;
        break;
      case 2:{
        std::cout << "ZALOGUJ SIĘ WYBIERAJĄC ID KLIENTA: ";
        std::cin >> y; 
        if(y<1 || y>5) 
        {
          std::cout << "LOGOWANIE NIEUDANE\n";
          goto opcje;
        }
        std::cout << "ID: "<<y<<"\n";
        std::cout << "IMIĘ I NAZWISKO: "<<imiona[y-1]<<"\n";
        std::cout << "NR KONTA: 00"<<y<<"\n";
        std::cout << "SALDO: "<<saldo[y-1]<<" zł\n";
        std::cout << "WPISZ NUMER KONTA NA KTÓRY CHCESZ WYKONAĆ PRZELEW: ";
        std::cin.ignore(); 
        std::string przelew;
        std::cin >> przelew; 
        int konto = stoi(przelew); 
        if(przelew[0]!='0' && przelew[1]!='0' && ((int)przelew[2]>5 ||   (int)przelew[2]<1) && konto!=y) 
        {
          std::cout << "NIEPRAWIDŁOWY NUMER KONTA";
          goto opcje;
        }
        std::cout << "PODAJ KWOTĘ PRZELEWU: ";
        std::cin.ignore();
        std::cin >> k; 
        if(k>saldo[y-1] && k<=0) 
        {
          std::cout << "NIEWYSTARCZAJĄCE ŚRODKI NA RACHUNKU";
          goto opcje;
        }
        else
        {
          saldo[y-1]=saldo[y-1]-k;
          saldo[konto-1]=saldo[konto-1]+k;
          std::cout << "PRZELEW ZOSTAŁ WYSŁANY\n";
        }
        goto salda; 
        break;}
      case 3:
        return 0;
        break;
      default:
        std::cout << "BŁĘDNA WARTOŚĆ\n";
        goto opcje;
        break;
    }
  
}