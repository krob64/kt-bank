#include "Bankautomat.h"
#include <iostream>

Bankautomat::Bankautomat(double startBetrag) {
  this->AUTOMAT_ID = 0;
  this->bargeld = startBetrag;
  Bankautomat::automatCounter += 1;
}

int Bankautomat::auszahlung(KartenKonto* karten_konto, int auszahlungsBetrag) {
  if (this->bargeld < auszahlungsBetrag) {
    std::cout << "nicht genug geld im automaten. bargeld: " << this->bargeld << std::endl;
  }

  if (karten_konto->isGesperrt()) {
    std::cout << "[ERROR] das konto ist gesperrt." << std::endl;
    return -1;
  }

  if (karten_konto->getKarte()->isGesperrt()) {
    std::cout << "[ERROR] die karte ist gesperrt." << std::endl;
    return -1;
  }

  if (!karten_konto->getKarte()->checkKarte()) {
    if (karten_konto->getKarte()->getKartenTyp() == Kartentypen::KREDITKARTE) {
      std::cout << "[ERROR] pruefziffercheck nicht erfolgreich." << std::endl;
      return -1;
    }
    std::cout << "[ERROR] falsche PIN." << std::endl;
  }

  if (!karten_konto->abheben(auszahlungsBetrag)) {
    return -1;
  }
  this->bargeld -= auszahlungsBetrag;

  std::string temp_konto_string;

  if (karten_konto->getKarte()->getKartenTyp() == Kartentypen::KREDITKARTE) {
    temp_konto_string = "Kreditkonto";
  } else {
    temp_konto_string = "Girokonto";
  }

  std::cout << auszahlungsBetrag << "eus werden von " << temp_konto_string << " ausgezahlt..." << std::endl;
  return auszahlungsBetrag;
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
