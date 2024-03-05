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
