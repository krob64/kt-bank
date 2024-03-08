#pragma once

enum Kartentypen { KREDITKARTE = 1, GIROKARTE };

class Karte {
 protected:
  Kartentypen KARTEN_TYP;
  bool validKarte;  // Korrekte Überprüfung (PIN/PZ)
  bool gesperrt;

 public:
  Karte();
  Kartentypen getKartenTyp();
  bool getValidKarte();
  bool isGesperrt();
  virtual bool checkKarte() = 0;  // Setter für validKarte
};
