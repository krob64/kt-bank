#include "Girokarte.h"
#include <chrono>
#include <random>
#include <iostream>




Girokarte::Girokarte() : PIN(Girokarte::generatPIN()) {
  this->userPIN = 0;
  this->gesperrt = false;
  this->KARTEN_TYP = Kartentypen::GIROKARTE;
  this->validKarte = false;
}

bool Girokarte::checkKarte() {
  std::cout << "Deine PIN lautet: " << PIN << std::endl;
  setUserPIN();
  return userPIN == PIN;
  
}

int Girokarte::generatPIN() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::knuth_b genRand(seed);
  std::uniform_int_distribution<int> w10{1000, 9999};
  
  return w10(genRand);
  
}

void Girokarte::setUserPIN() {
  std::cout << "Bitte geben Sie den PIN ein: " << std::endl;
  int pinEingabe = 0;
  std::cin >> pinEingabe;

  this->userPIN = pinEingabe;

}