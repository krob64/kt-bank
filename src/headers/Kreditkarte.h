#pragma once
#include <vector>
#include "Karte.h"

class Kreditkarte : public Karte {
 public:
  static inline std::vector<unsigned long long> kreditkartenNummern = {};

  Kreditkarte();
  // ~Kreditkarte();

  void generateKartenNr();
  unsigned long long vecToInt(std::vector<int> p_vector);
  int generatePZ(std::vector<int> p_vector);
  bool checkUnique(unsigned long long kartenNr, std::vector<unsigned long long> nummerListen);
  void printKartenNr();
  bool checkKarte() override;

 private:
  std::vector<int> KREDITKARTEN_NR;
};

// #endif
