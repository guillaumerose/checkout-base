#include "tinytest.h"
#include "checkout.h"

void test_index()
{
    ASSERT_EQUALS(POMMES, indexPour("Pommes"));
    ASSERT_EQUALS(BANANES, indexPour("Bananes"));
    ASSERT_EQUALS(CERISES, indexPour("Cerises"));
}

void test_prix()
{
    ASSERT_EQUALS(100, prixPour(POMMES));
    ASSERT_EQUALS(150, prixPour(BANANES));
    ASSERT_EQUALS(75, prixPour(CERISES));
}

void test_reduction_une_cerise()
{
    int etat[] = { 0, 0, 0 };
    ASSERT_EQUALS(0, reductionPour(etat, CERISES));
}

void test_reduction_deux_cerises()
{
    int etat[] = { 0, 0, 1 };
    ASSERT_EQUALS(-30, reductionPour(etat, CERISES));
}

void test_reduction_deux_cerises_une_pomme()
{
    int etat[] = { 0, 0, 2 };
    ASSERT_EQUALS(0, reductionPour(etat, POMMES));
}

void test_reduction_trois_cerises()
{
    int etat[] = { 0, 0, 2 };
    ASSERT_EQUALS(0, reductionPour(etat, CERISES));
}

void test_reduction_bananes()
{
    int etat[] = { 0, 1, 0 };
    ASSERT_EQUALS(-150, reductionPour(etat, BANANES));
}

int main()
{
  RUN(test_index);
  RUN(test_prix);
  RUN(test_reduction_une_cerise);
  RUN(test_reduction_deux_cerises);
  RUN(test_reduction_deux_cerises_une_pomme);
  RUN(test_reduction_trois_cerises);
  RUN(test_reduction_bananes);
  return TEST_REPORT();
}
