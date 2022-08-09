#include "miasto.h"

Miasto::Miasto(std::string _nazwaMiasta)
  : liczbaMieszkancow(0), procent(0), nazwaMiasta(_nazwaMiasta){
  }

Miasto::Miasto(int _N, int _p, std::string _nazwaMiasta)
  : liczbaMieszkancow(_N), procent(_p), nazwaMiasta(_nazwaMiasta){
  zaludnijMiasto();
}

void Miasto::zaludnijMiasto(){
  int liczbaCzerwonych = this->procent/100 * this->liczbaMieszkancow;
  int liczbaZielonych = this->liczbaMieszkancow - liczbaCzerwonych;

  for(int i = 0; i < liczbaCzerwonych; i++)
      this->kibice.push_back(Kibic('c'));

  for(int k = 0; k < liczbaZielonych; k++)
    this->kibice.push_back(Kibic('z'));
}

void Miasto::getPozycjeKibicow(){
  for(unsigned int i = 0; i < this->kibice.size(); i++)
    std::cout << kibice[i].getX() << "\t" << kibice[i].getY() << "\t" << kibice[i].getKolor() << std::endl;
}

Miasto::~Miasto(){
}
