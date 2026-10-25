/*
 * Day 1 - sum of two integers, done like an engineer (not like a tutorial).
 *
 * PREDICT FIRST. Write your answers down BEFORE you build:
 *   1. ./day01_sum 2 3                      -> ?
 *   2. ./day01_sum -10 4                    -> ?
 *   3. ./day01_sum 2 abc                    -> ?   (what exit code?)
 *   4. ./day01_sum 9223372036854775807 1    -> ?   (what IS LLONG_MAX + 1?)
 *
 * Only after writing predictions: build, run, compare. Where you were wrong
 * is the whole lesson. This is the predict -> build -> break -> explain loop
 * that the 180-day plan runs on every single task.
 */
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* Parse a full base-10 integer. Rejects junk, empty strings, and range errors. */
static int parse_ll(const char *text, long long *out) {
    if (text == NULL || text[0] == '\0') return 0;
    errno = 0;
    char *end = NULL;
    long long value = strtoll(text, &end, 10);
    if (errno == ERANGE) return 0;   /* outside long long range */
    if (*end != '\0') return 0;      /* trailing non-numeric characters */
    *out = value;
    return 1;
}

/* Checked addition: returns 0 on signed overflow instead of invoking UB. */
static int add_checked(long long a, long long b, long long *out) {
    if (b > 0 && a > LLONG_MAX - b) return 0;
    if (b < 0 && a < LLONG_MIN - b) return 0;
    *out = a + b;
    return 1;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <int> <int>\n", argv[0]);
        return 2;
    }
    long long a = 0, b = 0;
    if (!parse_ll(argv[1], &a) || !parse_ll(argv[2], &b)) {
        fprintf(stderr, "error: both arguments must be valid integers\n");
        return 1;
    }
    long long sum = 0;
    if (!add_checked(a, b, &sum)) {
        fprintf(stderr, "error: integer overflow\n");
        return 1;
    }
    printf("%lld\n", sum);
    return 0;
}
