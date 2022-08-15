# SymulatorMiasta
Projekt tworzony w ramach przedmiotu Programowanie IN na kierunku Inżynieria Nanostruktur.
Program jest symulacją miasta, w której tworzone jest wirtualne miasto z określoną przez użytkownika liczbą mieszkańców 
(kibiców) dwojakiego rodzaju. Użytkownik może również zdefiniować w jakiej proporcji względem siebie poszczególni kibice występują w symulowanym mieście.

Pozycje wszystkich kibiców losowane są w obrębie miasta. Każdy z kibiców w trakcie symulacji charakteryzuje się poziomem zadowolenia,
które wyznaczane jest na bazie innych mieszkańców znajdujących się wokół niego. Jeżeli mieszkaniec jest "tego samego typu" zadowolenie wzrasta,
jeśli innego - spada. Na ich bazie wyznaczane jest ogólne zadowolenie miasta.

Dla miasta określona zostaje liczba ewolucji jakie przejdzie. Ewolucja jest procesem, w trakcie którego mieszkańcy zmieniają swoje pozycje w losowym kierunku
o określony dystans. Ponownie wyznaczane są poziomy zadowolenia mieszkańców, a z nimi również ogólne zadowolenie miasta.
