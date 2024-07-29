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
#include <string.h>

int	ft_strtoimax(const char *nptr, char **endptr, int base);

int main() {
    char *str;
    char *endptr;
	intmax_t	val;
    errno = 0;

    // Test 0: compare test
    str = "9223372036854775808"; // INTMAX_MAX + 1
    errno = 0;
    val = strtoimax(str, &endptr, 10);
    if (val != INTMAX_MAX || errno != ERANGE) {
        printf("Test 4 failed\n");
    }
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr );
	printf("strlen endptr: %lu\n", strlen(endptr));
	perror("current perror");
	printf("errno: %d\n", errno);
	printf("Test 0 success\n\n");

    // Test 1: Valid integer
    str = "123";
    val = ft_strtoimax(str, &endptr, 10);
    printf("Test 1 \n");
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr);
	perror("current perror");
	printf("errno: %d\n\n", errno);
    if (val != 123 || *endptr != '\0' || errno != 0) {
        printf("Test 1 failed\n\n");
        return 1;
    }

    // Test 2: Leading whitespace base 0 (makes base 10)
    str = "   123";
    val = ft_strtoimax(str, &endptr, 0);
    printf("Test 2 \n");
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr);
	perror("current perror");
	printf("errno: %d\n\n", errno);
    if (val != 123 || *endptr != '\0' || errno != 0) {
        printf("Test 2 failed\n\n");
        return 1;
    }

    // Test 3: Trailing whitespace
    str = "123   ";
    val = ft_strtoimax(str, &endptr, 10);
    printf("Test 3\n");
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr - 1);
	printf("strlen endptr: %lu\n", strlen(endptr));
	perror("current perror");
	printf("errno: %d\n\n", errno);
    if (val != 123 || *(endptr - 1) != '3' || errno != 0) {
        printf("Test 3 failed\n\n");
        return 1;
    }

	   // Test 4: Overflow
	   str = "9223372036854775808"; // INTMAX_MAX + 1
	   errno = 0;
	   val = ft_strtoimax(str, &endptr, 10);
	   printf("Test 4\n");
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr - 1);
	printf("strlen endptr: %lu\n", strlen(endptr));
	perror("current perror");
	printf("errno: %d\n\n", errno);
	   if (val != INT_MAX || errno != ERANGE) {
	       printf("Test 4 failed\n");
	       return 1;
	   }

	   // Test 5: Underflow
	   str = "-9223372036854775809"; // INTMAX_MIN - 1
	   errno = 0;
	   val = ft_strtoimax(str, &endptr, 10);
	   if (val != INT_MIN || errno != ERANGE) {
	       printf("Test 5 failed\n");
	       return 1;
	   }

    // Test 6: Invalid input
    str = "123abc";
    val = ft_strtoimax(str, &endptr, 10);
    printf("Test 6\n");
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr);
	printf("strlen endptr: %lu\n", strlen(endptr));
	perror("current perror");
	printf("errno: %d\n\n", errno);
    if (val != 123 || *endptr != 'a' || errno != 0) {
        printf("Test 6 failed\n\n");
        return 1;
    }

    // Test 7: Empty string
    str = "";
    val = ft_strtoimax(str, &endptr, 10);
    printf("Test 7\n");
	printf("val: %ld\n\n", val);
    if (val != 0 || *endptr != '\0' || errno != EINVAL) {
        printf("Test 7 failed\n");
        return 1;
    }

    // Test 8: NULL pointer
    str = NULL;
    val = ft_strtoimax(str, &endptr, 10);
    printf("Test 8\n");
	printf("val: %ld\n\n", val);
    if (val != 0 || errno != EINVAL) {
        printf("Test 8 failed\n");
        return 1;
    }

    // Test 9: INT_MAX
    str = "2147483647"; // INTMAX_MAX
    errno = 0;
    val = ft_strtoimax(str, &endptr, 10);
    printf("Test 9\n");
	printf("INT_MAX %d\n", INT_MAX);
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr);
	printf("strlen endptr: %lu\n", strlen(endptr));
	perror("current perror");
	printf("errno: %d\n\n", errno);
    if (val != INT_MAX || errno != 0) {
        printf("Test 9 failed\n");
        return 1;
    }

    // Test 10: INT_MAX Overflow
    str = "2147483648"; // INTMAX_MAX + 1
    errno = 0;
    val = ft_strtoimax(str, &endptr, 10);
    printf("Test 10\n");
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr);
	printf("strlen endptr: %lu\n", strlen(endptr));
	perror("current perror");
	printf("errno: %d\n\n", errno);
    if (val != INT_MAX || errno != ERANGE) {
        printf("Test 10 failed\n");
        return 1;
    }
    // Test 11: INT_MIN
    str = "-2147483648"; // INTMAX_MIN
    errno = 0;
    val = ft_strtoimax(str, &endptr, 10);
    if (val != INT_MIN || errno != 0) {
        printf("Test 11 failed\n");
        return 1;
    }

	// Test 12 base 16
    str = "123abc";
	val = ft_strtoimax(str, &endptr, 16);
    printf("Test 12\n");
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr);
	printf("strlen endptr: %lu\n", strlen(endptr));
	perror("current perror");
	printf("errno: %d\n\n", errno);
    if (val != 1194684 || errno != 0) {
        printf("Test 12 failed\n");
        return 1;
	}

	// test 13 base 16 0x
    str = "0x123abc";
	val = ft_strtoimax(str, &endptr, 16);
    printf("Test 13\n");
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr);
	printf("strlen endptr: %lu\n", strlen(endptr));
	perror("current perror");
	printf("errno: %d\n\n", errno);
    if (val != 1194684 || errno != 0) {
        printf("test 13 failed\n");
        return 1;
	}

	// test 14 base 0 0X
    str = "0X123abc";
	val = ft_strtoimax(str, &endptr, 0);
    if (val != 1194684 || errno != 0) {
        printf("test 14 failed\n");
        return 1;
	}

    // Test 15: Invalid input
    str = "	 ()";
    val = ft_strtoimax(str, &endptr, 10);
    printf("Test 15\n");
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr);
	printf("strlen endptr: %lu\n", strlen(endptr));
	perror("current perror");
	printf("errno: %d\n\n", errno);
    if (val != 0 || *endptr != '	' || errno != 0) {
        printf("Test 15 failed\n\n");
        return 1;
    }

    // Test 16: base 0 case octal
    str = "0743";
    val = ft_strtoimax(str, &endptr, 0);
    printf("Test 16\n");
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr);
	printf("strlen endptr: %lu\n", strlen(endptr));
	perror("current perror");
	printf("errno: %d\n\n", errno);
    if (val != 483 || errno != 0) {
        printf("Test 16 failed\n\n");
        return 1;
    }

    // Test 17: base 8
    str = "0743";
    val = ft_strtoimax(str, &endptr, 8);
    printf("Test 17\n");
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr);
	printf("strlen endptr: %lu\n", strlen(endptr));
	perror("current perror");
	printf("errno: %d\n\n", errno);
    if (val != 483 || errno != 0) {
        printf("Test 17 failed\n\n");
        return 1;
    }

	// Test 18 invalid octal input
    str = "983";
    val = ft_strtoimax(str, &endptr, 8);
    printf("Test 18\n");
	printf("val: %ld\n", val);
	printf("endptr: %s\n", endptr);
	printf("strlen endptr: %lu\n", strlen(endptr));
	perror("current perror");
	printf("errno: %d\n\n", errno);
    if (val != 0 || *endptr != '9' || errno != 0) {
        printf("Test 18 failed\n\n");
        return 1;
    }
    printf("All tests passed\n");
    return 0;
}

