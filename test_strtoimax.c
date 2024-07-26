/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtoimax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:44:31 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/26 17:06:14 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main() {
    char *str;
    char *endptr;
    errno = 0;

    // Test 1: Valid integer
    str = "123";
    intmax_t val = strtoimax(str, &endptr, 10);
    if (val != 123 || *endptr != '\0' || errno != 0) {
        printf("Test 1 failed\n");
        return 1;
    }

    // Test 2: Leading whitespace
    str = "   123";
    val = strtoimax(str, &endptr, 10);
    if (val != 123 || *endptr != '\0' || errno != 0) {
        printf("Test 2 failed\n");
        return 1;
    }

    // Test 3: Trailing whitespace
    str = "123   ";
    val = strtoimax(str, &endptr, 10);
    if (val != 123 || *(endptr - 1) != ' ' || errno != 0) {
        printf("Test 3 failed\n");
        return 1;
    }

    // Test 4: Overflow
    str = "9223372036854775808"; // INTMAX_MAX + 1
    errno = 0;
    val = strtoimax(str, &endptr, 10);
    if (val != INTMAX_MAX || errno != ERANGE) {
        printf("Test 4 failed\n");
        return 1;
    }

    // Test 5: Underflow
    str = "-9223372036854775809"; // INTMAX_MIN - 1
    errno = 0;
    val = strtoimax(str, &endptr, 10);
    if (val != INTMAX_MIN || errno != ERANGE) {
        printf("Test 5 failed\n");
        return 1;
    }

    // Test 6: Invalid input
    str = "123abc";
    val = strtoimax(str, &endptr, 10);
    if (val != 123 || *endptr != 'a' || errno != 0) {
        printf("Test 6 failed\n");
        return 1;
    }

    // Test 7: Empty string
    str = "";
    val = strtoimax(str, &endptr, 10);
    if (val != 0 || *endptr != '\0' || errno != EINVAL) {
        printf("Test 7 failed\n");
        return 1;
    }

    // Test 8: NULL pointer
    str = NULL;
    val = strtoimax(str, &endptr, 10);
    if (val != 0 || errno != EINVAL) {
        printf("Test 8 failed\n");
        return 1;
    }

    // Test 9: INT_MAX
    str = "2147483648"; // INTMAX_MAX
    errno = 0;
    val = strtoimax(str, &endptr, 10);
    if (val != INTMAX_MAX || errno != ERANGE) {
        printf("Test 9 failed\n");
        return 1;
    }

    // Test 10: INT_MAX Overflow
    str = "2147483649"; // INTMAX_MAX + 1
    errno = 0;
    val = strtoimax(str, &endptr, 10);
    if (val != INTMAX_MAX || errno != ERANGE) {
        printf("Test 10 failed\n");
        return 1;
    }
    // Test 11: INT_MIN
    str = "-2147483647"; // INTMAX_MIN
    errno = 0;
    val = strtoimax(str, &endptr, 10);
    if (val != INTMAX_MIN || errno != ERANGE) {
        printf("Test 11 failed\n");
        return 1;
    }

    // Test 11: INT_MIN Underflow
    str = "-2147483648"; // INTMAX_MIN - 1
    errno = 0;
    val = strtoimax(str, &endptr, 10);
    if (val != INTMAX_MIN || errno != ERANGE) {
        printf("Test 5 failed\n");
        return 1;
    }
    printf("All tests passed\n");
    return 0;
}

