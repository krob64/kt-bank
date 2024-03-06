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
                     Kreditkartenkonto* kreditkartenKonto)
    : kundenID(kundenID),
      vorname(vorname),
      nachname(nachname),
      tagesgeldKonto(tagesgeldKonto),
      festgeldKonto(festgeldKonto),
      giroKonto(giroKonto),
      kreditkartenKonto(kreditkartenKonto) 
{
  this->kundenID = 0;
  this->vorname = "";
  this->nachname = "";
  this->tagesgeldKonto = "";
  this->festgeldKonto = "";
  this->giroKonto = "";
  this->kreditkartenKonto = "";
}

Bankkunde::Bankkunde(std::string vorname, std::string nachname) : vorname(vorname),nachname(nachname){
  this->vorname = vorname;
  this->nachname = nachname;
}

// Getter und Setter für Kunden-ID
void Bankkunde::setKundenID(unsigned int kundenID) {
  this->kundenID =kundenID;
}

unsigned int Bankkunde::getKundenID() {
  return this->kundenID;
}

// Getter und Setter für Vorname
void Bankkunde::setVorname(std::string vorname) {
  this->vorname = vorname;
}

std::string Bankkunde::Bankkunde::getVorname() {
  return this->vorname;
}
// Getter und Setter für Nachname
void Bankkunde::Bankkunde::setNachname(std::string nachname) {
  this->nachname = nachname;
}
std::string Bankkunde::Bankkunde::getNachname() {
  return this->nachname;
}
// Getter und Setter für Tagesgeldkonto
void Bankkunde::setTagesgeldKonto(Tagesgeldkonto* tagesgeldKonto) {
  this->tagesgeldKonto = tagesgeldKonto;
}
Tagesgeldkonto* Bankkunde::getTagesgeldKonto() {
  return this->tagesgeldKonto;
}

// Getter und Setter für FestgeldKonto
void Bankkunde::setFestgeldKonto(Festgeldkonto* festgeldKonto) {
  this->festgeldKonto = festgeldKonto;
}
Festgeldkonto* Bankkunde::getFestgeldKonto() {
  return this->festgeldKonto;
}

// Getter und Setter für Girokonto
void Bankkunde::setGiroKonto(Girokonto* giroKonto) {
  this->giroKonto = giroKonto;
}
Girokonto* Bankkunde::Bankkunde::grtGiroKonto() {
  return this->giroKonto;
}

// Getter und Setter für Kreditkartenkonto
void Bankkunde::setKreditkartenKonto(Kreditkartenkonto* kreditkartenKonto) {
  this->kreditkartenKonto = kreditkartenKonto;
}
Kreditkartenkonto* Bankkunde::Bankkunde::getKreditkartenKonto() {
  return this->kreditkartenKonto;
}
