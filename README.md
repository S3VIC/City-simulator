# SymulatorMiasta
Projekt tworzony w ramach przedmiotu Programowanie IN na kierunku Inżynieria Nanostruktur.
Program jest symulacją miasta, w której tworzone jest wirtualne miasto z określoną przez użytkownika liczbą kibiców
(mieszkańców) podzielonych na dwa "kluby" - czerwoni oraz zieloni. Użytkownik może również zdefiniować w jakiej proporcji względem siebie poszczególni kibice występują w symulowanym mieście poprzez zdefiniowanie czesci jaką stanowią kibice czerwoni.

Symulacja moze pracowac w trybie, w którym liczba kibicow i ich pozycje sa losowane. 

Pozycje wszystkich kibiców losowane są w obrębie miasta. Każdy z kibiców w trakcie symulacji charakteryzuje się poziomem zadowolenia,
które wyznaczane jest na bazie innych mieszkańców znajdujących się wokół niego. Jeżeli mieszkaniec jest "tego samego typu" zadowolenie wzrasta,
jeśli innego - spada. Na ich bazie wyznaczane jest ogólne zadowolenie miasta jako srednia arytmetyczna poziomów zadowolenia wszystkich kibiców.

Dla miasta może zostać określona pewna liczba ewolucji jakie przejdzie. Ewolucja jest procesem, w trakcie którego mieszkańcy zmieniają swoje pozycje w losowym kierunku
o ustalony dystans w przypadku gdy ich poziom zadowolenia jest zbyt niski. Ponownie wyznaczane są poziomy zadowolenia mieszkańców, a z nimi również ogólne zadowolenie miasta. Symulator informuje o przebiegu procesu ewolucji wyswietlajac komunikaty o numerze ewolucji i poziomie zadowolenia przypadajacym danej ewolucji.
