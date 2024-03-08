#include "Bankautomat.h"
#include <iostream>

Bankautomat::Bankautomat(double startBetrag) {
	this->bargeld = startBetrag;
}


int Bankautomat::auszahlung(KartenKonto* kkonto, int auszahlungsBetrag) {    

  // bargeld-check
  if (this->bargeld < auszahlungsBetrag) {
    std::cout << "Nicht genug Geld im Automaten. Sie können momentan maximal: " << getBargeld() << "Euro abheben." << std::endl;
    return -1;
  }

  // kredit UND giro-konto sperrcheck
  if (kkonto->isGesperrt()) {
    std::cout << "Das Konto ist gesperrt." << std::endl;
    return -1;
  }

  // kredit und giro-karte sperrcheck
  if (kkonto->getKarte()->isGesperrt()) {
    std::cout << "Die Karte ist gesperrt. Der Vorgang wird abgebrochen!" << std::endl;
    return -1;
  }

  // kredit und giro-karten check
  if (!kkonto->getKarte()->checkKarte()) {
    std::cout << "Error: kartenCheck nicht erfolgreich." << std::endl;
    return -1;
  }

  if (!kkonto->abheben(auszahlungsBetrag)) {
    // wenn das abheben erfolgreich war, subtrahiere den betrag vom bargeld im
    // automaten
    return -1;
  }
  this->bargeld -= auszahlungsBetrag;

  std::string temp_string = (kkonto->getKarte()->getKartentyp() == 1) ? "Kreditkonto" : "Girokonto";

  std::cout << auszahlungsBetrag << "Euro werden von " << temp_string << " ausgezahlt..." << std::endl;
  return auszahlungsBetrag;
  
}


int Bankautomat::einzahlung(KartenKonto* kkonto, int einzahlungsBetrag) {
  // kredit UND giro-konto sperrcheck
  if (kkonto->isGesperrt()) {
    std::cout << "Das Konto ist gesperrt. Der Vorgang wird abgebrochen!" << std::endl;
    return -1;
  }

  // kredit und giro-karte sperrcheck
  if (kkonto->getKarte()->isGesperrt()) {
    std::cout << "Die Karte ist gesperrt. Der Vorgang wird abgebrochen!" << std::endl;
    return -1;
  }

  // kredit und giro-karten check
  if (!kkonto->getKarte()->checkKarte()) {
    std::cout << "Error: kartenCheck nicht erfolgreich." << std::endl;
    return -1;
  }

  // Der Einzahlungsbetrag wird dem Bargeldbestand vom Bankautomaten hinzugerechnet. 
  this->bargeld += einzahlungsBetrag;

  // Der Einzahlungsbetrag wird dem Konto (Kredit-/Girokonto) hinzugerechnet 
  kkonto->setKontoStand(kkonto->getKontostand() + einzahlungsBetrag);
    

  std::string temp_string = (kkonto->getKarte()->getKartentyp() == 1) ? "Kreditkonto" : "Girokonto";
  std::cout << einzahlungsBetrag << "Euro werden auf das " << temp_string << " eingezahlt." << std::endl;
  
  return einzahlungsBetrag;
}

// Getter und Setter für Bargeld
double Bankautomat::getBargeld() {
  return this->bargeld;
}

void Bankautomat::setBargeld(double betrag) {
  this->bargeld += betrag;
}

// Getter und Setter für AutomatID
unsigned int Bankautomat::getAutomatID() {
  return this->AUTOMAT_ID;
}
