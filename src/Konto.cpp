#include "Konto.h"
#include <iostream>

Konto::Konto() : KONTO_NUMMER(0) {
  this->gesperrt = false;
  this->kontostand = 0;
};

Konto::~Konto() {}

/**
 * @brief
 *
 * @param betrag
 * @param plusminus : true für einzahlen, false für auszahlen
 */
void Konto::setKontostand(double betrag) {
  this->kontostand = betrag;
};

double Konto::getKontostand() {
  return this->kontostand;
};

unsigned int Konto::getKontonummer() {
  return this->KONTO_NUMMER;
}

bool Konto::isGesperrt() {
  return this->gesperrt;
}

void Konto::setGesperrt(bool value) {
  this->gesperrt = value;
}

bool Konto::abheben(double betrag) {
  if (!this->isGedeckt(betrag)) {
    std::cout << "nicht genug geld auf dem konto. Kontostand: " << this->kontostand << std::endl;
    return false;
  }
  this->kontostand -= betrag;
  return true;
}

bool Konto::isGedeckt(double betrag) {
  if (this->kontostand >= betrag) {
    return true;
  }
  return false;
}
