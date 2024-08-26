/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoimax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:58:52 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/26 15:33:23 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include <stdlib.h>

/*
DESCRIPTION
These  functions  are similar tostrtol(3) and strtoul(3).
The function converts the initial part of the string in nptr to a long integer
value according to the given base, which must be between 2 and 36 inclusive, 
or be the special value 0.

The  string  may  begin  with an arbitrary amount of white space 
(as determined by isspace(3)) followed by a single optional '+' or '-' sign.
If base is zero or 16, the string may then include a "0x" or "0X" prefix, and
the number will be read in base 16; 
otherwise, a zero base is taken as 10 (decimal) unless the next character 
is '0', in which case it is taken  as  8  (octal).

The  remainder  of  the string is converted to a long value in the obvious 
manner, stopping at the first character which is not a valid digit in the given
base. (In  bases  above  10,  the letter  'A'  in  either uppercase or
lowercase represents 10, 'B' represents 11, and so forth, with 'Z' representing
35.)

If endptr is not NULL, strtol() stores the address of the first invalid
character in  *endptr. If there were no digits at all, strtol() stores the
original value of nptr in *endptr (and returns 0).  In particular, if *nptr is
not '\0' but **endptr is  '\0'  on  return,  the  entire string is valid.

RETURN VALUE
On success, the converted value is returned.  If nothing was found to  convert,
zero  is  returned.  On overflow or underflow INTMAX_MAX or INTMAX_MIN or 
UINTMAX_MAX is returned, and errno is set to ERANGE.
*/

//really cool way to get the absolute value:
	//i += (sign ^ (sign >> 31)) - (sign >> 31);

int	ft_strtoimax(const char *nptr, char **endptr, int base);
int	skip_whitespace(const char *str);
int	ft_atoi_base_e(const char *nptr, char ***endptr, int base, int sign);
int	determine_sign(const char *nptr);
int	check_base(const char *nptr, char ***endprt, int base, int sign);

int	ft_strtoimax(const char *nptr, char **endptr, int base)
{
	int	i;
	int	sign;
	int	nb;

	errno = 0;
	*endptr = (char *) nptr;
	if (!(base >= 0 && base <= 36) || (nptr == NULL || *nptr == '\0'))
	{
		errno = EINVAL;
		return (0);
	}
	i = skip_whitespace(nptr);
	sign = determine_sign(&nptr[i]);
	if (sign)
		i++;
	else
		sign = 1;
	nptr = nptr + i;
	nb = check_base(nptr, &endptr, base, sign);
	return (nb);
}

int	check_base(const char *nptr, char ***endptr, int base, int sign)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (base == 0)
	{
		if (nptr[i] == '0' && (nptr[i + 1] == 'x' || nptr[i + 1] == 'X'))
			nb = ft_atoi_base_e(&nptr[i + 2], endptr, 16, sign);
		else if (nptr[i] == '0')
			nb = ft_atoi_base_e(&nptr[i++], endptr, 8, sign);
		else
			nb = ft_atoi_base_e(&nptr[i], endptr, 10, sign);
	}
	else if (base == 16)
	{
		if (nptr[i] == '0' && (nptr[i + 1] == 'x' || nptr[i + 1] == 'X'))
			i += 2;
		nb = ft_atoi_base_e(&nptr[i], endptr, 16, sign);
	}
	else if (base >= 2 && base <= 32)
		nb = ft_atoi_base_e(&nptr[i], endptr, base, sign);
	return (nb);
}

//to be implemented (too long for norminette, not needed for current usecase)
int	ft_atoi_base_e(const char *nptr, char ***endptr, int base, int sign)
{
	return (0);
}

// returns the amount of spaces that need to be skipped (according to isspace)
int	skip_whitespace(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	return (i);
}

// if next char is -, returns -1, + returns 1, 
int	determine_sign(const char *nptr)
{
	if (*nptr == '+')
		return (1);
	if (*nptr == '-')
		return (-1);
	return (0);
}
