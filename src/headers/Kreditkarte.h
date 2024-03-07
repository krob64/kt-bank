/* #ifndef KARTE_H
#define KARTE_H */

/*
#pragma once

class Konto {
 protected:
  const unsigned int KONTO_NUMMER;
  double kontostand;
  bool gesperrt;
  Konto();

 public:
  ~Konto();

  double getKontostand();
  void setKontostand(double betrag);

  unsigned int getKontonummer();

  bool getGesperrt();
  void setGesperrt(bool value);

  bool kontoGedeckt(double betrag);
};
*/
#pragma once
#include "Bankkunde.h"
#include "Karte.h"

class Kreditkarte : public Karte { // Erben von Karte

 public:
  

  Kreditkarte();
  // ~Kreditkarte();

  void generateKartenNr();
  unsigned long long vecToInt(std::vector<int>);
  int generatePZ(std::vector<int>);
  bool checkUnique(unsigned long long, std::vector<unsigned long long>);
  void printKartenNr();
  bool checkKarte()override;
 private:
  std::vector<int> kreditkartenNr;
};

// #endif
