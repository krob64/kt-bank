#include "Kreditkarte.h"
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::knuth_b genRand(seed);
std::uniform_int_distribution<int> w10{0, 9};
static std::vector<unsigned long long> kreditkartenNummern = {};

class Kreditkarte {
  std::vector<int> kreditkartenNr = {};  // vector ist einfacher als C-Array

 public:
    Kreditkarte() {
    generateKartenNr();  // generiert eine 15stellige Nummer + PZ

    while (!checkUnique(vecToInt(kreditkartenNr), kreditkartenNummern)) {
      generateKartenNr();
    }

    kreditkartenNummern.push_back(vecToInt(kreditkartenNr));
  }

  void generateKartenNr() {
    for (int i = 0; i < 15; ++i) {
      kreditkartenNr.push_back(w10(genRand));
    }

    kreditkartenNr.push_back(generatePZ(kreditkartenNr));
  }

  unsigned long long vecToInt(std::vector<int> vec)  // Hilfsfunktion wandelt einen vector in eine Zahl um - gehören Hilfsfunktionen ins UML?
  {
    unsigned long long vecInt = 0;

    for (size_t i = 0; i < vec.size(); ++i) {
      vecInt += vec.at(i) * pow(10, vec.size() - i - 1);  //(  1,          2,          4)    -> 100 + 20 + 4 = 124
                                                          //(*10 ^ 2, * 10 ^ 1, * 10 ^ 0)
    }

    return vecInt;
  }

  int generatePZ(std::vector<int> kartenNummer) {
    std::vector<int> vecNeu = kartenNummer;

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

  bool checkKarte() {
    std::vector<int> vecTest = kreditkartenNr;
    int pz = vecTest.back();  // letze Ziffer (PZ)
    vecTest.pop_back();

    bool gueltig = pz == generatePZ(vecTest);
    if (gueltig) {
      std::cout << "Die Karte ist gueltig." << std::endl;
    } else {
      std::cout << "Die Karte ist nicht gueltig." << std::endl;
    }

    return gueltig;
  }

  bool checkUnique(unsigned long long nummer, std::vector<unsigned long long> nummerListen) {
    bool einzigartig = true;
    for (size_t i = 0; i < nummerListen.size(); ++i) {
      if (nummer == nummerListen.at(i)) {
        einzigartig = false;
        break;
      }
    }

    return einzigartig;
  }

  void printKartenNr()  // Hilfsfunktion
  {
    for (size_t i = 0; i < kreditkartenNr.size(); ++i) {
      std::cout << kreditkartenNr.at(i);

      if (i < kreditkartenNr.size() - 1) {
        std::cout << ", ";
      }

      else {
        std::cout << std::endl;
      }
    }
  }
};