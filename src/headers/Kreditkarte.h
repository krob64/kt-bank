/* #ifndef KARTE_H
#define KARTE_H */
#pragma once
#include "Bankkunde.h"

class Kreditkarte {
 public:
  static std::vector<unsigned long long> kreditkartenNummern;

  Kreditkarte();
  // ~Kreditkarte();

  void generateKartenNr();
  unsigned long long vecToInt(std::vector<int>);
  int generatePZ(std::vector<int>);
  bool checkUnique(unsigned long long, std::vector<unsigned long long>);
  void printKartenNr();

 private:
  std::vector<int> kreditkartenNr;
};

// #endif
