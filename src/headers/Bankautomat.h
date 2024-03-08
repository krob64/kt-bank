#pragma once
#include "Kartenkonto.h"

class Bankautomat {
 private:
  double bargeld = 0.0;
  unsigned int automatCounter;
  unsigned int AUTOMAT_ID;  // erstmal nur deklariert, weil die ID von der Bank kommt

 public:
  Bankautomat(double startBetrag);
  //~Bankautomat();

  int auszahlung(KartenKonto* karten_konto, int auszahlungsBetrag);

  double getBargeld();
  void setBargeld(double betrag);
  unsigned int getAutomatID();
  void setAutomatID(unsigned int nummer);
};
