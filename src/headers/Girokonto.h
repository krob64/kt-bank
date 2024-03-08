#pragma once
#include "Girokarte.h"
#include "Kartenkonto.h"

class Girokonto : public KartenKonto {
 private:
  Girokarte* giroKarte;

 public:
  Girokonto();
  ~Girokonto();

  Karte* getKarte() override;
};
