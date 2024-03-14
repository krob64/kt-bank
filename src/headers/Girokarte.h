#pragma once
#include "Karte.h"


class Girokarte : public Karte {
 private:
  const unsigned int PIN;
  unsigned int userPIN;

  static int generatPIN();

  void setUserPIN();

 public:
  Girokarte();
  bool checkKarte() override;
  
  
};
