#include "Kreditkarte.h"
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::knuth_b genRand(seed);
std::uniform_int_distribution<int> w10{0, 9};

// TODO: KREDITKARTEN_NR bei init generieren und setzen
Kreditkarte::Kreditkarte() {
  this->validKarte = false;
  this->KARTEN_TYP = Kartentypen::KREDITKARTE;
  this->gesperrt = false;

  generateKartenNr();  // generiert eine 15stellige Nummer + PZ

  while (!checkUnique(vecToInt(KREDITKARTEN_NR), Kreditkarte::kreditkartenNummern)) {
    generateKartenNr();
  }

  Kreditkarte::kreditkartenNummern.push_back(vecToInt(KREDITKARTEN_NR));
  std::cout << "KREDITKARTEN_NR: " << vecToInt(KREDITKARTEN_NR) << std::endl;
}

unsigned long long Kreditkarte::vecToInt(std::vector<int> p_vector) {
  unsigned long long vecInt = 0;

  for (size_t i = 0; i < p_vector.size(); ++i) {
    vecInt += p_vector.at(i) * pow(10, p_vector.size() - i - 1);  //(  1,          2,          4)    -> 100 + 20 + 4 = 124
                                                                  //(*10 ^ 2, * 10 ^ 1, * 10 ^ 0)
  }

  return vecInt;
}

void Kreditkarte::generateKartenNr() {
  for (int i = 0; i < 15; ++i) {
    KREDITKARTEN_NR.push_back(w10(genRand));
  }

  KREDITKARTEN_NR.push_back(generatePZ(KREDITKARTEN_NR));
}

int Kreditkarte::generatePZ(std::vector<int> p_vector) {
  std::vector<int> vecNeu = p_vector;

  for (size_t i = 0; i < vecNeu.size(); ++i)  // Schritt 1 (aus Prüfzifferberechnung.docx) multipliziert jede zweite Zahl mit 2
  {
    if (i % 2 == 0) {
      vecNeu.at(i) *= 2;
    }
  }

  for (size_t i = 0; i < vecNeu.size(); ++i)  // Schritt 2.1 jeweils Quersumme bilden
  {
    vecNeu.at(i) = vecNeu.at(i) % 10 + ((vecNeu.at(i) - vecNeu.at(i) % 10)) / 10;
  }

  int gesamtQuersumme = 0;
  for (size_t i = 0; i < vecNeu.size(); ++i)  // Schritt 2.2 Quersummen addieren
  {
    gesamtQuersumme += vecNeu.at(i);
  }

  int pz = (10 - gesamtQuersumme % 10) % 10;  // Schritt 3 + 4

  return pz;
}

bool Kreditkarte::checkUnique(unsigned long long nummer, std::vector<unsigned long long> nummerListen) {
  bool einzigartig = true;
  for (size_t i = 0; i < nummerListen.size(); ++i) {
    if (nummer == nummerListen.at(i)) {
      einzigartig = false;
      break;
    }
  }

  return einzigartig;
}

void Kreditkarte::printKartenNr() {
  for (size_t i = 0; i < KREDITKARTEN_NR.size(); ++i) {
    std::cout << KREDITKARTEN_NR.at(i);

    if (i < KREDITKARTEN_NR.size() - 1) {
      std::cout << ", ";
    }

    else {
      std::cout << std::endl;
    }
  }
}

bool Kreditkarte::checkKarte() {
  std::vector<int> vecTest = KREDITKARTEN_NR;
  int pz = vecTest.back();  // letze Ziffer (PZ)
  vecTest.pop_back();

  bool gueltig = pz == generatePZ(vecTest);
  if (gueltig) {
    // std::cout << "Die Karte ist gueltig." << std::endl;
  } else {
    std::cout << "Die Karte ist nicht gueltig." << std::endl;
  }

  return gueltig;
}
