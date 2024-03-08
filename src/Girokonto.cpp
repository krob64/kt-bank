#include "Girokonto.h"

Girokonto::Girokonto() {
  this->giroKarte = new Girokarte();
  this->karte = giroKarte;
}

Girokonto::~Girokonto() {
  delete giroKarte;
}

Karte* Girokonto::getKarte() {
  return this->giroKarte;
}
