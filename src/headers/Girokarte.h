#pragma once
#include "Karte.h"

class Girokarte : public Karte {
 private:
  const unsigned int PIN;
  unsigned int userPIN;

 public:
  Girokarte();
  bool checkKarte() override;
  void setUserPIN(unsigned int pin);
};
