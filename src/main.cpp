#include <iostream>
#include <string>

#include "Bank.h"

int main() {
  Bank sparkasse = Bank::instance();

  sparkasse.kundeAnlegen("Klabuster", "Beere");
  sparkasse.kundeAnlegen("Ben", "Dover");
  sparkasse.kundeAnlegen("Alexander", "Platz");

  sparkasse.automatAnlegen(1200);
  sparkasse.automatAnlegen(70000);
  sparkasse.automatAnlegen(90);

  Bankkunde* current_kunde = 0;
  sparkasse.getKunde(1, &current_kunde);

  Kreditkonto* neues_girokonto = new Kreditkonto();
  current_kunde->setKreditkartenKonto(neues_girokonto);
  current_kunde->getKreditkartenKonto()->setKontostand(7000);

  Bankautomat* current_automat = 0;
  sparkasse.getAutomat(1, &current_automat);

  current_automat->auszahlung(current_kunde->getKreditkartenKonto(), 600);
  std::cout << current_automat->getBargeld() << std::endl;
  std::cout << current_kunde->getKreditkartenKonto()->getKontostand() << std::endl;

  current_automat->einzahlung(current_kunde->getKreditkartenKonto(), 1230);
  std::cout << current_automat->getBargeld() << std::endl;
  std::cout << current_kunde->getKreditkartenKonto()->getKontostand() << std::endl;
}
