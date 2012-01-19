#include "tinytest.h"
#include "checkout.h"

void test_index()
{
    ASSERT_EQUALS(POMMES, indexPour("Pommes\n"));
    ASSERT_EQUALS(BANANES, indexPour("Bananes\n"));
    ASSERT_EQUALS(CERISES, indexPour("Cerises\n"));
}

void test_prix()
{
    ASSERT_EQUALS(100, prixPour(POMMES));
    ASSERT_EQUALS(150, prixPour(BANANES));
    ASSERT_EQUALS(75, prixPour(CERISES));
}

void test_reduction_vide()
{
    int etat[] = {
        0, // Pommes
        0, // Bananes
        0 // Cerises
    };
    ASSERT_EQUALS(0, reductionPour(etat));
}

void test_reduction_une_cerise()
{
    int etat[] = { 0, 0, 1 };
    ASSERT_EQUALS(0, reductionPour(etat));
}

void test_reduction_deux_cerises()
{
    int etat[] = { 0, 0, 2 };
    ASSERT_EQUALS(-20, reductionPour(etat));
}

void test_reduction_trois_cerises()
{
    int etat[] = { 0, 0, 3 };
    ASSERT_EQUALS(0, reductionPour(etat));
}

int main()
{
  RUN(test_index);
  RUN(test_prix);
  RUN(test_reduction_vide);
  RUN(test_reduction_une_cerise);
  RUN(test_reduction_deux_cerises);
  RUN(test_reduction_trois_cerises);
  return TEST_REPORT();
}
