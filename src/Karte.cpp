#include "Karte.h"

Karte::Karte() {}

Kartentypen Karte::getKartenTyp() {
  return KARTEN_TYP;
}

bool Karte::getValidKarte() {
  return validKarte;
}

bool Karte::isGesperrt() {
  return this->gesperrt;
}
