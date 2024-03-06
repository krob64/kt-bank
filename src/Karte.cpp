#include "Karte.h"

Karte::Karte() {
  validKarte = true;
  kartenTyp = true;

};
bool Karte::getKartenTyp(){
  return this->kartenTyp;
};
bool Karte::getValidKarte() {
  return this->validKarte;
}
    //class Karte {
// protected:
//  Karte() {}
//
// private:
//  bool kartenTyp = true;  // Kreditkarte: true, Girokarte: false
//
//  bool validKarte = false;  // Check erfolgreich - Kreditkarte: PZ, Girokarte: Pin
//
// public:
//  bool getKartenTyp() { return kartenTyp; }
//
//  bool getValidKarte() { return validKarte; }
//
//  bool checkKarte(bool kartentyp) {
//    if (kartentyp) {
//      //Kreditkarte::checkKarte();
//    }
//
//    else {
//      //Girokarte::checkKarte();
//    }
//  }
//};