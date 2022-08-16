#include "miasto.h"

Miasto::Miasto(std::string _nazwaMiasta)
  : liczbaMieszkancow(0), procent(0), nazwaMiasta(_nazwaMiasta), zadowolenieMiasta(0){
  }

Miasto::Miasto(int _N, int _p, std::string _nazwaMiasta)
  : liczbaMieszkancow(_N), procent(_p), nazwaMiasta(_nazwaMiasta), zadowolenieMiasta(0){
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

void Miasto::wyznaczZadowKibica(Kibic& k1, Kibic& k2){
  double k1X = k1.getX();
  double k1Y = k1.getY();

  double k2X = k2.getX();
  double k2Y = k2.getY();

  double dystans = pow(k2X - k1X, 2) - pow(k2Y - k1Y, 2);
  
  if(dystans <= 1 && k1.getKolor() == k2.getKolor())
    k1.zwiekszZadowolenie();
  
  else if (dystans <= 1 && k1.getKolor() != k2.getKolor())
    k1.zmniejszZadowolenie();
  else { }
}

void Miasto::wyznaczCalkZadowKibicow(){
  for(int i = 0; i < this->liczbaMieszkancow; i++){
    for(int j = 0; j < this->liczbaMieszkancow; j++){
      if(i == j)
        continue;
      else{
        this->wyznaczZadowKibica(this->kibice[i], this->kibice[j]);
      }
    }
  }
}

void Miasto::wyznaczZadowMiasta(){
  for(int i = 0; i < this->liczbaMieszkancow; i++){
    this->zadowolenieMiasta += kibice[i].getZadowolenie();
  }
  this->zadowolenieMiasta = this->zadowolenieMiasta / this->liczbaMieszkancow;
}

int Miasto::getZadowolenieMiasta(){
  return this->zadowolenieMiasta;
}
Miasto::~Miasto(){
}
