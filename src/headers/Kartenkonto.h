#pragma once

#include "Karte.h"
#include "Konto.h"

class KartenKonto : public Konto {
 protected:
  Karte* karte;

 public:
  virtual Karte* getKarte() = 0;
};
