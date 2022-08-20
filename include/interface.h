#pragma once
#include<iostream>

class Interface{
  public:
  Interface();
  // void inicjalizuj();
  void ustalWartParametrow(std::string* nazwaMiasta, int* liczbaMieszkancow, int* procent, int* liczbaEwolucji);
  void komunikatNazwaMiasta();
  void komunikatLiczbaMieszk();
  void komunikatProcentCzerw();
  void komunikatLiczbaEwol();

  ~Interface();
};