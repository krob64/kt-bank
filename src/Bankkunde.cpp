#include "Bankkunde.h"
#include <iostream>
#include <string>

// Konstruktordefinition
Bankkunde::Bankkunde(unsigned int kundenID,
                     std::string vorname,
                     std::string nachname,
                     Tagesgeldkonto* tagesgeldKonto,
                     Festgeldkonto* festgeldKonto,
                     Girokonto* giroKonto,
                     Kreditkonto* kreditkartenKonto)
    : KUNDEN_ID(kundenID),
      vorname(vorname),
      nachname(nachname),
      tagesgeldKonto(tagesgeldKonto),
      festgeldKonto(festgeldKonto),
      giroKonto(giroKonto),
      kreditkartenKonto(kreditkartenKonto) {}

Bankkunde::Bankkunde(std::string vorname, std::string nachname) {
  this->vorname = vorname;
  this->nachname = nachname;
  this->tagesgeldKonto = nullptr;
  this->festgeldKonto = nullptr;
  this->giroKonto = nullptr;
  this->kreditkartenKonto = nullptr;
  this->KUNDEN_ID = Bankkunde::kunden_id_counter;
  Bankkunde::kunden_id_counter++;
}

Bankkunde::~Bankkunde() {
  if (festgeldKonto) {
    delete festgeldKonto;
  };
  if (tagesgeldKonto) {
    delete tagesgeldKonto;
  };
  if (giroKonto) {
    delete giroKonto;
  };
  if (kreditkartenKonto) {
    delete kreditkartenKonto;
  };
}

// Getter und Setter f�r Kunden-ID

unsigned int Bankkunde::getKundenID() {
  return this->KUNDEN_ID;
}

// Getter und Setter f�r Vorname
void Bankkunde::setVorname(std::string vorname) {
  this->vorname = vorname;
}

std::string Bankkunde::Bankkunde::getVorname() {
  return this->vorname;
}
// Getter und Setter f�r Nachname
void Bankkunde::setNachname(std::string nachname) {
  this->nachname = nachname;
}
std::string Bankkunde::getNachname() {
  return this->nachname;
}
// Getter und Setter f�r Tagesgeldkonto
void Bankkunde::setTagesgeldKonto(Tagesgeldkonto* tagesgeldKonto) {
  this->tagesgeldKonto = tagesgeldKonto;
}
Tagesgeldkonto* Bankkunde::getTagesgeldKonto() {
  return this->tagesgeldKonto;
}

// Getter und Setter f�r FestgeldKonto
void Bankkunde::setFestgeldKonto(Festgeldkonto* festgeldKonto) {
  this->festgeldKonto = festgeldKonto;
}
Festgeldkonto* Bankkunde::getFestgeldKonto() {
  return this->festgeldKonto;
}

// Getter und Setter f�r Girokonto
void Bankkunde::setGiroKonto(Girokonto* giroKonto) {
  // 0x8723892 //0x8723892
  this->giroKonto = giroKonto;
}
Girokonto* Bankkunde::getGiroKonto() {
  return this->giroKonto;
}

// Getter und Setter f�r Kreditkartenkonto
void Bankkunde::setKreditkartenKonto(Kreditkonto* kreditkartenKonto) {
  this->kreditkartenKonto = kreditkartenKonto;
}
Kreditkonto* Bankkunde::getKreditkartenKonto() {
  return this->kreditkartenKonto;
}

void Bankkunde::print() {
  std::cout << this->vorname << " " << this->nachname << " Kunden ID: " << this->KUNDEN_ID << " Kontostand:" << std::endl;
}
