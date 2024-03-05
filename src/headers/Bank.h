#pragma once
#include <iostream>
#include <vector>
#include "Bankautomat.h"
#include "Bankkunde.h"
#include "Konto.h"
#include "Kreditkarte.h"

#define ELEMENT_NOT_FOUND -1
#define VECTOR_INDEX_OOB -1

class Bank {
 private:
  unsigned int kundenID_gen;
  std::vector<Bankkunde> kunden;
  std::vector<Bankautomat> automaten;
  Bank();

 public:
  static Bank instance();
  ~Bank();
  void kundeAnlegen(std::string vorname, std::string nachname);
  void kundeLoeschen(unsigned int kundenID);
  void automatAnlegen(unsigned int automatenID);
  void automatLoeschen(unsigned int automatenID);
  int getKunde(unsigned int kundenID, Bankkunde* gefundenerKunde);
  int getKunde(int index, Bankkunde* gefundenerKunde);
  int getAutomat(unsigned int automatID, Bankautomat* gefundenerAutomat);
  int getAutomat(int index, Bankautomat* gefundenerAutomat);
};
