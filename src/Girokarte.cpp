#include "Girokarte.h"

Girokarte::Girokarte() : PIN(0) {
  this->userPIN = 0;
  this->gesperrt = false;
  this->KARTEN_TYP = Kartentypen::GIROKARTE;
  this->validKarte = false;
}

bool Girokarte::checkKarte() {
  // return userPIN == PIN;
  return true;
}

void Girokarte::setUserPIN(unsigned int pin) {
  this->userPIN = pin;
}
