#pragma once
#include <iostream>
#include <string>
#include "Festgeldkonto.h"
#include "Girokonto.h"
#include "Kreditkonto.h"
#include "Tagesgeldkonto.h"

class Bankkunde {
 private:
  unsigned int KUNDEN_ID;
  std::string vorname;
  std::string nachname;
  Tagesgeldkonto* tagesgeldKonto;
  Festgeldkonto* festgeldKonto;
  Girokonto* giroKonto;
  Kreditkonto* kreditkartenKonto;

 public:
  Bankkunde(unsigned int kundenID,
            std::string vorname,
            std::string nachname,
            Tagesgeldkonto* tagesgeldKonto,
            Festgeldkonto* festgeldKonto,
            Girokonto* giroKonto,
            Kreditkonto* kreditkartenKonto);

  Bankkunde(std::string vorname, std::string nachname, unsigned int p_kundenID);
  ~Bankkunde();

  unsigned int getKundenID();

  void setVorname(std::string vorname);
  std::string getVorname();

  void setNachname(std::string nachname);
  std::string getNachname();

  void setTagesgeldKonto(Tagesgeldkonto* tagesgeldKonto);
  Tagesgeldkonto* getTagesgeldKonto();

  void setFestgeldKonto(Festgeldkonto* festgelgKonto);
  Festgeldkonto* getFestgeldKonto();

  void setGiroKonto(Girokonto* giroKonto);
  Girokonto* getGiroKonto();

  void setKreditkartenKonto(Kreditkonto* kreditkartenKonto);
  Kreditkonto* getKreditkartenKonto();
};
