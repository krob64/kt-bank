#pragma once
#include <iostream>
#include <string>
#include "Konto.h"
class Bankkunde {
 private:
  unsigned int kundenID;
  std::string vorname;
  std::string nachname;
  Tagesgeldkonto* tagesgeldKonto;
  Festgeldkonto* festgeldKonto;
  Girokonto* giroKonto;
  Kreditkartenkonto* kreditkartenKonto;

 public:
  Bankkunde(unsigned int kundenID,
            std::string vorname,
            std::string nachname,
            Tagesgeldkonto* tagesgeldKonto,
            Festgeldkonto* festgeldKonto,
            Girokonto* giroKonto,
            Kreditkartenkonto* kreditkartenKonto);
  Bankkunde(std::string vorname, std::string nachname);

  void setKundenID(unsigned int Id);
  unsigned int getKundenID();

  void setVorname(std::string vname);
  std::string getVorname();

  void setNahname(std::string nname);
  std::string getNachname();

  void setTagesgeldKonto(Tagesgeldkonto* tagesgeldKonto);
  Tagesgeldkonto* getTagesgeldKonto();

  void setFestgeldKonto(Festgeldkonto* festgelgKonto);
  Festgeldkonto* getFestgeldKonto();

  void setGiroKonto(Girokonto* giroKonto);
  Girokonto* grtGiroKonto();

  void setKreditkartenKonto(Kreditkartenkonto* kreditkartenKonto);
  Kreditkartenkonto* getKreditkartenKonto();
};
