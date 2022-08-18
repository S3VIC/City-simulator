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
  double k1Cord[] = {k1.getX(), k1.getY()};

  double k2Cord[] = {k2.getX(), k2.getY()};

  double dystans = pow(k2Cord[0] - k1Cord[0], 2) - pow(k2Cord[1] - k1Cord[1], 2);
  
  if(dystans <= 1 && k1.getKolor() == k2.getKolor())
    k1.zwiekszZadowolenie();
  
  else if (dystans <= 1 && k1.getKolor() != k2.getKolor())
    k1.zmniejszZadowolenie();
}

void Miasto::wyznaczCalkZadowKibicow(){
  for(int i = 0; i < this->liczbaMieszkancow; i++){
    for(int j = i+1; j < this->liczbaMieszkancow; j++){
        this->wyznaczZadowKibica(this->kibice[i], this->kibice[j]);
    }
  }
}

void Miasto::wyznaczZadowMiasta(){
  
  if(this->zadowolenieMiasta != 0)
    this->zadowolenieMiasta = 0;


  for(int i = 0; i < this->liczbaMieszkancow; i++){
    this->zadowolenieMiasta += kibice[i].getZadowolenie();
  }
  this->zadowolenieMiasta = this->zadowolenieMiasta / this->liczbaMieszkancow;
}

int Miasto::getZadowolenieMiasta(){
  return this->zadowolenieMiasta;
}

void Miasto::ewolucja(){
  for(int i = 0; i < this->liczbaMieszkancow; i++){
    if(this->kibice[i].getZadowolenie() <= 0){
      double kierunek = 2 * rand()/RAND_MAX * M_PI;
      this->kibice[i].zmienX(cos(kierunek));
      this->kibice[i].zmienY(sin(kierunek));
    }
    else
      continue;
  }
}

void Miasto::resetZadowKibicow(){
  for(int i = 0; i < this->liczbaMieszkancow; i++){
    this->kibice[i].resetZadow();
  }
}
Miasto::~Miasto(){
}
