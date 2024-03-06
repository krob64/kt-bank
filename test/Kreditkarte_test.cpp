#include <gtest/gtest.h>
#include "Karte.h"
class KartenTest : public ::testing::Test {
 protected:
  Karte k;
  void SetUp() { Karte k; }
};

TEST_F(KartenTest, getterKartentyp){
  //Karte k; // protected hat verhindert, dass Klasse instanziert wurde. Haben in der Karte.h erstmal public verwendet.
  bool typ = k.getKartenTyp();
  EXPECT_TRUE(typ);
};

TEST_F(KartenTest, gettervalidKarte) {
  //Karte k;
  bool valid = k.getValidKarte();
  EXPECT_TRUE(valid);
}