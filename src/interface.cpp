#include "interface.h"

Interface::Interface(){}
//void Interface::inicjalizuj(){
//  this->ustalWartParametrow()
//}
void Interface::ustalWartParametrow(std::string* nazwaMiasta, int* liczbaMieszkancow, int* procent, int* liczbaEwolucji){
  this->komunikatNazwaMiasta();
  std::cin >> *nazwaMiasta;

  this->komunikatLiczbaMieszk();
  scanf("%d", liczbaMieszkancow);

  this->komunikatProcentCzerw();
  scanf("%d", procent);

  this->komunikatLiczbaEwol();
  scanf("%d", liczbaEwolucji);
}

void Interface::komunikatLiczbaEwol(){
    printf("Liczba ewolucji: ");
}

void Interface::komunikatProcentCzerw(){
  printf("Procent mieszkańców jaki stanowią kibice czerwoni: ");
}

void Interface::komunikatLiczbaMieszk(){
  printf("Liczba mieszkańców: ");
}

void Interface::komunikatNazwaMiasta(){
  printf("Nazwa miasta: ");
}

Interface::~Interface(){}