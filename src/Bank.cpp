#include "Bank.h"
#include <iostream>

Bank::Bank() {
  this->kundenID_gen = 0;

  // leere vector initialisierung
  this->kunden = std::vector<Bankkunde>();
  this->automaten = std::vector<Bankautomat>();
}

Bank::~Bank() {
  std::cout << "Bank zerstoert." << std::endl;
}

Bank Bank::instance() {
  static Bank tempBank = Bank();
  return tempBank;
}

void Bank::kundeAnlegen(std::string vorname, std::string nachname) {
  Bankkunde tempkunde = Bankkunde(vorname, nachname, 0);
  kunden.push_back(tempkunde);
  // this->kundenID_gen++;
}

void Bank::kundeLoeschen(unsigned int kundenID) {
  // durch den kunden vector loopen
  for (int i = 0; i < kunden.size(); i++) {
    if (kunden.at(i).getKundenID() == kundenID) {
      // wenn kundenID uebereinstimmt, loesche das element. (komisches iterator zeug muss hier gemacht werden?)
      this->kunden.erase(this->kunden.begin() + i);
      return;
    }
  }

  std::cout << "kundenID " << kundenID << " nicht gefunden.";
}

void Bank::automatAnlegen(double automat_bargeld) {
  Bankautomat tempautomat = Bankautomat(automat_bargeld);
  this->automaten.push_back(tempautomat);
}

void Bank::automatLoeschen(unsigned int automatID) {
  for (int i = 0; i < this->automaten.size(); i++) {
    if (this->automaten.at(i).getAutomatID() == automatID) {
      // wenn automatID uebereinstimmt, loesche das element. (komisches iterator zeug muss hier gemacht werden?)
      this->automaten.erase(this->automaten.begin() + i);
      return;
    }
  }

  std::cout << "automatID " << automatID << " nicht gefunden.";
}

// die returntypes von den gettern sind up for debate.
/*
 * szenario:    kundenID wird nicht gefunden.
 * frage:       wie soll man dem caller wissen lassen, dass kein kunde gefunden wurde?
 * antworten:   std::optional<T>, int return mit T* als parameter, exception werfen, leeren bankkunden returnen (wie es unten auch
 *              erstmals implementiert wurde)
 */
// Bankkunde Bank::getKunde(unsigned int kundenID) {
//   for (int i = 0; i < this->kunden.size(); i++) {
//     if (this->kunden.at(i).kundenID == kundenID) {
//       return this->kunden.at(i);
//     }
//   }
// }

int Bank::getKunde(unsigned int kundenID, Bankkunde** gefundenerKunde) {
  for (int i = 0; i < this->kunden.size(); i++) {
    if (this->kunden[i].getKundenID() == kundenID) {
      *gefundenerKunde = &this->kunden[i];
      return 0;
    }
  }
  std::cout << "kundenID [" << kundenID << "] koennte nicht gefunden werden." << std::endl;
  return ELEMENT_NOT_FOUND;
}

int Bank::getKunde(int index, Bankkunde** gefundenerKunde) {
  if (index > this->kunden.size() - 1) {
    std::cout << "index [" << index << "] in kunden is out of bounds" << std::endl;
    return VECTOR_INDEX_OOB;
  }

  *gefundenerKunde = &this->kunden[index];
  return 0;
}

int Bank::getAutomat(unsigned int automatID, Bankautomat** gefundenerAutomat) {
  for (int i = 0; i < this->automaten.size(); i++) {
    if (this->automaten[i].getAutomatID() == automatID) {
      *gefundenerAutomat = &this->automaten[i];
      return 0;
    }
  }
  std::cout << "automatID [" << automatID << "] koennte nicht gefunden werden." << std::endl;
  return ELEMENT_NOT_FOUND;
}

int Bank::getAutomat(int index, Bankautomat** gefundenerAutomat) {
  if (index > this->automaten.size() - 1) {
    std::cout << "index [" << index << "] in automaten is out of bounds" << std::endl;
    return VECTOR_INDEX_OOB;
  }

  *gefundenerAutomat = &this->automaten[index];
  return 0;
}

// std::optional implementation
/*
 * caller usage:
 *      optional<Bankkunde> gesuchter_kunde = getKunde(45);
 *      if(gesuchter_kunde.has_value()) {
 *          gesuchter_kunde.setKontostand(12);
 *      }
 *
 */
// std::optional<Bankkunde> Bank::getKunde(unsigned int kundenID) {
//   for (int i = 0; i < this->kunden.size(); i++) {
//     if (this->kunden.at(i).getKundenID() == kundenID) {
//       std::optional<Bankkunde> some_opt = std::nullopt;
//
//       return;
//     }
//   }
//   return {};
// }
