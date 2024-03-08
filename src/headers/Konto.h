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
  bool abheben(double betrag);

  unsigned int getKontonummer();

  bool isGesperrt();
  void setGesperrt(bool value);

  bool isGedeckt(double betrag);
};
