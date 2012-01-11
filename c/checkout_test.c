#include "tinytest.h"
#include "checkout.h"

void test_upper_case()
{
    char input[1024] = "aBc";
    process(input);
    ASSERT_STRING_EQUALS("ABC", input);
}

int main()
{
  RUN(test_upper_case);
  return TEST_REPORT();
}
