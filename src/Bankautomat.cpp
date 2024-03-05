#include "Bankautomat.h"
#include <iostream>
#include "Bankkunde.h"



Bankautomat::Bankautomat(double startBetrag)
{
	this->bargeld = startBetrag; 
}

int Bankautomat::auszahlung(Konto* konto, int CARD_FLAG, int auszahlungsBetrag, unsigned int pin) {
    if (CARD_FLAG == GIROKARTE) { 
            
        if (!konto->getGirokarte()->kartenCheck(pin, CARD_FLAG)) {
            std::cout << "Diese Karte oder der PIN ist ungültig. Der Vorgang wird abgebrochen" << std::endl;
            return -1;
        }

        if ((double)auszahlungsBetrag > this->bargeld) {
            std::cout << "Sie möchten mehr Geld abheben, als momentan im Bankautomat vorhanden ist. Sie können momentan maximal: " << getBargeld() << "Euro abheben."
            << std::endl;
            return -1;
        }

        if (konto->getKontoStand() < auszahlungsBetrag) {
            std::cout << "Es ist nicht genug Geld auf dem Konto! Sie können momentan maximal :" << kunde.giroKonto.getKontostand() << std::endl;
            return -1;
        }

      this->bargeld -= auszahlungsBetrag;

      konto->setKontoStand(konto->getKontoStand() - auszahlungsBetrag);
      std::cout << auszahlungsbetrag << " Euro wurden abgehoben!" << std::endl;

      return auszahlungsBetrag;


    } else if (CARD_FLAG == KREDITKARTE) {

        if (!konto->getKreditkarte()->kartenCheck(pin, CARD_FLAG)) {
            std::cout << "Diese Karte oder der PIN ist ungültig. Der Vorgang wird abgebrochen" << std::endl;
            return -1;
        }

        if ((double)auszahlungsBetrag > this->bargeld) {
            std::cout << "Sie möchten mehr Geld abheben, als momentan im Bankautomat vorhanden ist. Sie können momentan maximal: " << getBargeld() << "Euro abheben."
            << std::endl;
            return -1;
        }

        if (konto->getKontostand() < auszahlungsBetrag) {
            std::cout << "Es ist nicht genug Geld auf dem Konto! Sie können momentan maximal :" << kunde.giroKonto.getKontostand() << std::endl;
            return -1;
        }

        this->bargeld -= auszahlungsBetrag;

        konto->setKontoStand(konto->getKontoStand() - auszahlungsBetrag);
        std::cout << auszahlungsbetrag << " Euro wurden abgehoben!" << std::endl;

        return auszahlungsBetrag;



    } else {
        std::cout << "Sie nutzen keine genehemigte Karte" << std::endl;
        return -1;
    }

    
        
  
}
    
	
// Getter und Setter für Bargeld
double Bankautomat::getBargeld() 
{
  return this->bargeld;
}


void Bankautomat::setBargeld(double betrag) 
{
  this->bargeld += betrag; 
}

// Getter und Setter für AutomatID
unsigned int Bankautomat::getAutomatID() 
{
  return this->automatID;
}

void Bankautomat::setAutomatID(unsigned int nummer) 
{ 
    automatID = nummer;
        
}
