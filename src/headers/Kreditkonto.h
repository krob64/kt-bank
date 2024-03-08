#pragma once
#include "Kartenkonto.h"
#include "Kreditkarte.h"

class Kreditkonto : public KartenKonto {
 private:
  Kreditkarte* kreditKarte;

 public:
  Kreditkonto();
  ~Kreditkonto();

  Karte* getKarte() override;
};
