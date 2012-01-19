#include "tinytest.h"
#include "checkout.h"

void test_index()
{
    ASSERT_EQUALS(POMMES, indexPour("Pommes"));
    ASSERT_EQUALS(APPLES, indexPour("Apples"));
    ASSERT_EQUALS(MELE, indexPour("Mele"));
    ASSERT_EQUALS(BANANES, indexPour("Bananes"));
    ASSERT_EQUALS(CERISES, indexPour("Cerises"));
}

void test_prix()
{
    ASSERT_EQUALS(100, prixPour(POMMES));
    ASSERT_EQUALS(100, prixPour(MELE));
    ASSERT_EQUALS(100, prixPour(APPLES));
    ASSERT_EQUALS(200, prixPour(BANANES));
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
    ASSERT_EQUALS(-20, reductionPour(etat, CERISES));
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
    ASSERT_EQUALS(-200, reductionPour(etat, BANANES));
}

void test_reduction_apples()
{
    int etat[] = { 0, 0, 0, 2, 0 };
    ASSERT_EQUALS(-100, reductionPour(etat, APPLES));
}

void test_reduction_mele()
{
    int etat[] = { 0, 0, 0, 0, 1 };
    ASSERT_EQUALS(-50, reductionPour(etat, MELE));
}

void test_reduction_globale_pommes()
{
    int etat[] = { 4, 0, 0, 0, 0 };
    ASSERT_EQUALS(-100, reductionGlobalePour(etat, POMMES));
    ASSERT_EQUALS(-100, reductionGlobalePour(etat, APPLES));
    ASSERT_EQUALS(-100, reductionGlobalePour(etat, MELE));
    ASSERT_EQUALS(0, reductionGlobalePour(etat, BANANES));
}

void test_reduction_globale()
{
    int etat[] = { 1, 1, 1, 1, 1 };
    ASSERT_EQUALS(-200, reductionGlobalePour(etat, POMMES));
    ASSERT_EQUALS(-200, reductionGlobalePour(etat, BANANES));
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
  RUN(test_reduction_apples);
  RUN(test_reduction_mele);
  RUN(test_reduction_globale_pommes);
  RUN(test_reduction_globale);
  return TEST_REPORT();
}
