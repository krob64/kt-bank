#include "Konto.h"

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

bool Konto::getGesperrt() {
  return this->gesperrt;
}

void Konto::setGesperrt(bool value) {
  this->gesperrt = value;
}

bool Konto::kontoGedeckt(double betrag) {
  if (this->kontostand >= betrag) {
    return true;
  }
  return false;
}
