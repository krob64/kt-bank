#include <gtest/gtest.h>
#include "Kreditkarte.h"
class KartenTest : public ::testing::Test {
 protected:
  Kreditkarte k;
  void SetUp() { Kreditkarte k; }
};

TEST_F(KartenTest, checkKartentest){
  //Karte k; // protected hat verhindert, dass Klasse instanziert wurde. Haben in der Karte.h erstmal public verwendet.
  bool typ = k.checkKarte();
  EXPECT_TRUE(typ);
};

TEST_F(KartenTest, gettervalidKarte) {
  //Karte k;
  std::vector<unsigned long long> Klabusterbaeren{3333444433334444};
  bool valid = k.checkUnique(3333444433334444, Klabusterbaeren);
  EXPECT_TRUE(valid);
}