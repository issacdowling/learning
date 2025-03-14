#include "../munit/munit.h"

#include "exercise.h"
#include <stdint.h>

typedef struct CoffeeShop {
  uint64_t quality;
  uint64_t taste;
  uint64_t branding;
} coffee_shop_t;

int main() {
    {
      int i1 = 1234;
      int i2 = 5678;

      swap(&i1, &i2, sizeof(int));

      munit_assert_int(i1, ==, 5678);
      munit_assert_int(i2, ==, 1234);
    }
    {
    coffee_shop_t sbucks = {2, 3, 4};
    coffee_shop_t terminalshop = {10, 10, 10};

    swap(&sbucks, &terminalshop, sizeof(coffee_shop_t));

    munit_assert_int(sbucks.quality, ==, 10);
    munit_assert_int(sbucks.taste, ==, 10);
    munit_assert_int(sbucks.branding, ==, 10);

    munit_assert_int(terminalshop.quality, ==, 2);
    munit_assert_int(terminalshop.taste, ==, 3);
    munit_assert_int(terminalshop.branding, ==, 4);
    }
    {
      char *s1 = "dax";
      char *s2 = "adam";

      swap(&s1, &s2, sizeof(char *));
      munit_assert_string_equal(s1, "adam");
      munit_assert_string_equal(s2, "dax");
    }
}
