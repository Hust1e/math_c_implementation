#include <check.h>
#include "../s21_math.h"

// START ALL TESTS

START_TEST(s21_abs_test1) { ck_assert_int_eq(s21_abs(5), abs(5)); } END_TEST
START_TEST(s21_abs_test2) { ck_assert_int_eq(s21_abs(-3), abs(-3)); } END_TEST
START_TEST(s21_abs_test3) { ck_assert_int_eq(s21_abs(1007), abs(1007)); } END_TEST

// END ALL TESTS 
 
void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

Suite *abs_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("abs(x)");
  tc_core = tcase_create("core");

  // ADDING TEST IN CORE SUITE
  tcase_add_test(tc_core, s21_abs_test1);
  tcase_add_test(tc_core, s21_abs_test2);
  tcase_add_test(tc_core, s21_abs_test3);
  // CLOSE TEST IN CORE SUITE
  
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void)
{
    int fail = 0;
    case_test(abs_suite(), &fail);
    return fail;
}