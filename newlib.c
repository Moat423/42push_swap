/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:11:26 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/01 16:47:23 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newlib.h"
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

//free an array of string (future: elemnbr isn't neccessary because NULL-term)
void	free_str_array(char **str_array, size_t elemnbr)
{
	size_t	i;

	if (str_array == NULL)
		return ;
	i = 0;
	while (i < elemnbr)
	{
		if (str_array[i])
			free(str_array[i]);
		i++;
	}
	free(str_array);
	return ;
}

//creates (with malloc) new string and copies str1 and then str2 inside
char	*ft_newstrjoin(char *str1, char *str2)
{
	int		len1;
	int		len2;
	char	*res;

	if (!str1 || !str2)
		return (NULL);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, str1, len1 + 1);
	ft_strlcpy(res + len1, str2, len2 + 1);
	return (res);
}

/*
#include <assert.h>
#include <string.h>
// Test ft_newstrjoin
void test_ft_newstrjoin(void)
{
    char *result;

    // Test case 1: Basic joining of two strings
    result = ft_newstrjoin("Hello, ", "World!");
    assert(strcmp(result, "Hello, World!") == 0);
    free(result);
    printf("Test case 1 passed\n");

    // Test case 2: Joining with an empty string
    result = ft_newstrjoin("Hello", "");
    assert(strcmp(result, "Hello") == 0);
    free(result);
    printf("Test case 2 passed\n");

    // Test case 3: Joining an empty string with a non-empty string
    result = ft_newstrjoin("", "World");
    assert(strcmp(result, "World") == 0);
    free(result);
    printf("Test case 3 passed\n");

    // Test case 4: Joining two empty strings
    result = ft_newstrjoin("", "");
    assert(strcmp(result, "") == 0);
    free(result);
    printf("Test case 4 passed\n");

    // Test case 5: Joining strings with special characters
    result = ft_newstrjoin("Hello\n", "World\t!");
    assert(strcmp(result, "Hello\nWorld\t!") == 0);
    free(result);
    printf("Test case 5 passed\n");

    // Test case 6: Joining long strings
    char *long_str1 = "This is a very long string that goes on and on and on...";
    char *long_str2 = "And this is another very long string that keeps going...";
    result = ft_newstrjoin(long_str1, long_str2);
    assert(strcmp(result, "This is a very long string that goes on and on and on...And this is another very long string that keeps going...") == 0);
    free(result);
    printf("Test case 6 passed\n");

    // Test case 7: NULL handling (assuming the function should return NULL for NULL inputs)
    result = ft_newstrjoin(NULL, "World");
    assert(result == NULL);
    printf("Test case 7 passed\n");

    result = ft_newstrjoin("Hello", NULL);
    assert(result == NULL);
    printf("Test case 8 passed\n");

    printf("All test cases passed!\n");
}

int main(void)
{
    test_ft_newstrjoin();
    return 0;
}
*/
/*
// test for free_str_array
void	test_free_str_array(void)
{
	char	**charray;
	size_t	size;
	size_t	i;

	size = 5;
	charray = (char **) malloc((size + 1) * sizeof(char *));
	if (charray == NULL)
	{
		printf("Memory allocation of charray failed");
		return (1);
	}
	i = 0;
	while (i < size)
	{
		charray[i] = ft_strdup("Hello");
		i++;
	}
	charray[size] = NULL;
	i = 0;
	printf("original strings:\n");
	while (i < size)
	{
		printf("i: %lu in array: %s\n", i, charray[i]);
		i++;
	}
	free_str_array(charray, size);
	charray = NULL;
	return (0);
}
*/
