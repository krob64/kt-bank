/* #ifndef KARTE_H
#define KARTE_H */
#pragma once
//#include "Bankkunde.h"
//#include "Kreditkarte.h"

class Karte {
 //protected:
 public:
  Karte();  // Konstruktor protected setzen um Instanzierung zu verhindern => nur Unterklassen (Kredit/Giro) instanzieren

 private:
  bool validKarte;  // Korrekte Überprüfung (PIN/PZ)
  bool kartenTyp;   // Kreditkarte: true, Girokarte: false

 public:
  bool getKartenTyp();
  bool getValidKarte();
 // bool checkKarte();  // Setter für validKarte
};
