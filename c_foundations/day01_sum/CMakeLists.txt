add_executable(day01_sum sum.c)

# Each test asserts an outcome you predicted BEFORE running (predict-first).
add_test(NAME sum_valid COMMAND day01_sum 2 3)
set_tests_properties(sum_valid PROPERTIES PASS_REGULAR_EXPRESSION "^5")

add_test(NAME sum_negative COMMAND day01_sum -10 4)
set_tests_properties(sum_negative PROPERTIES PASS_REGULAR_EXPRESSION "-6")

# Bad input and overflow must exit non-zero: WILL_FAIL passes on a non-zero exit.
add_test(NAME sum_bad_input COMMAND day01_sum 2 abc)
set_tests_properties(sum_bad_input PROPERTIES WILL_FAIL TRUE)

add_test(NAME sum_overflow COMMAND day01_sum 9223372036854775807 1)
set_tests_properties(sum_overflow PROPERTIES WILL_FAIL TRUE)
