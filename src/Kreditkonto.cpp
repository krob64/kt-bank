#include "Kreditkonto.h"

Kreditkonto::Kreditkonto() {
  this->kreditKarte = new Kreditkarte();
  this->karte = kreditKarte;
}

Kreditkonto::~Kreditkonto() {
  delete kreditKarte;
}

Karte* Kreditkonto::getKarte() {
  return this->kreditKarte;
}
