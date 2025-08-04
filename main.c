// To compare original functions with mine.
// compile ft_*.c main.c *.h && ./a.out
// make bonus && compile main_bonus.c libft.a && ./a.out'
#include <ctype.h> // isalpha...
#include <string.h> // str-cosa, mem-cosa,
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

#include <stdio.h>

void	free_str_arr(char **str_arr, int n)
{
	for (int i = 0; i < n; i++)
		free(str_arr[i]);
	free(str_arr);
}

char	main_sgn(int n)
{
	if (n < 0)
		return('-');
	if (n > 0)
		return ('+');
	return ('0');
}

char	alternate_case_val(unsigned int i, char c)
{
	if (i % 2 == 0)
	{
		if ('a' <= c && c <= 'z')
			return (c - 'a' + 'A');
	}
	else
	{
		if ('A' <= c && c <= 'Z')
			return (c - 'A' + 'a');
	}
	return (c);
}

void	alternate_case_ref(unsigned int i, char *c)
{
	if (i % 2 == 0)
	{
		if ('a' <= *c && *c <= 'z')
			*c += (- 'a' + 'A');
	}
	else
	{
		if ('A' <= *c && *c <= 'Z')
			*c += (- 'A' + 'a');
	}
}


int	main(int argc, char** argv)
{
	int		c;
	int		n;
	int		m;
	int		k;
	int		s;
	char	**strings;
	char	**str_arr;
	int		*integers;
	int		*integers2;
	int		n_int;
	char	*string;
	char	*string2;
	char	*str_aux;
	char	*str_aux2;

	// "is something" functions and toupper/tolower:
	c = 0;
	while (c < 200)
	{
		if (!!ft_isalpha(c) != !!isalpha(c))
			printf("Error: ft_isalpha(%i) = ft_isalpha(%c) = %i != %i\n", c, c, ft_isalpha(c), isalpha(c));
		if (!!ft_isdigit(c) != !!isdigit(c))
			printf("Error: ft_isdigit(%i) = ft_isdigit(%c) = %i != %i\n", c, c, ft_isdigit(c), isdigit(c));
		if (!!ft_isalnum(c) != !!isalnum(c))
			printf("Error: ft_isalnum(%i) = ft_isalnum(%c) = %i != %i\n", c, c, ft_isalnum(c), isalnum(c));
		if (!!ft_isascii(c) != !!isascii(c))
			printf("Error: ft_isascii(%i) = ft_isascii(%c) = %i != %i\n", c, c, ft_isascii(c), isascii(c));
		if (!!ft_isprint(c) != !!isprint(c))
			printf("Error: ft_isprint(%i) = ft_isprint(%c) = %i != %i\n", c, c, ft_isprint(c), isprint(c));
		if (toupper(c) != ft_toupper(c))
			printf("Error: toupper failed with c=%i\n", c);
		if (tolower(c) != ft_tolower(c))
			printf("Error: tolower failed with c=%i\n", c);
		c++;
	}
	// strlen
	n = 3;
	m = 30;
	strings = malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++)
		strings[i] = malloc(m * sizeof(char));
	strcpy(strings[0], "0123456789");
	strcpy(strings[1], "");
	strcpy(strings[2], "qué coño");
	for (int i = 0; i < n; i++)
	{
		ft_strlen(strings[i]);
		if (ft_strlen(strings[i]) != strlen(strings[i]))
			printf("Error: ft_strlen(%s) = %li != %li\n", strings[i], ft_strlen(strings[i]), strlen(strings[i]));
	}
	free_str_arr(strings, n);
	n = 10;
	string = calloc(n, sizeof(char));
	string2 = calloc(n, sizeof(char));
	// memset / bzero
	strncpy(string, "aaaaaaaaaaaa", n);
	strncpy(string2, "aaaaaaaaaaaa", n);
	k = 5;
	if (strncmp(ft_memset(string, 'b', k), memset(string2, 'b', k), n) != 0)
			printf("Error: memset failed with k=%i\n", k);
	k = 0;
	if (strncmp(ft_memset(string, 'c', k), memset(string2, 'c', k), n) != 0)
			printf("Error: memset failed with k=%i\n", k);
	k = 3;
	ft_bzero(string, k);
	bzero(string2, k);
	if (strncmp(string, string2, n) != 0)
		printf("Error: bzero failed with k=%d\n", k);
	k = 7;
	ft_bzero(string, k);
	bzero(string2, k);
	if (strncmp(string, string2, n) != 0)
		printf("Error: bzero failed with k=%d\n", k);
	free(string);
	free(string2);
	// strncmp / memcmp
	n = 8;
	m = 20;
	strings = malloc(n * sizeof(char*));
	strings[0] = calloc(m, sizeof(char));
	strcpy(strings[0], "hola");
	strings[1] = calloc(m, sizeof(char));
	strcpy(strings[1], "hola que tal");
	strings[2] = calloc(m, sizeof(char));
	strcpy(strings[2], "holi");
	strings[3] = calloc(m, sizeof(char));
	strcpy(strings[3], "hola");
	strings[4] = calloc(m, sizeof(char));
	strcpy(strings[4], "");
	strings[5] = calloc(m, sizeof(char));
	strcpy(strings[5], "Hola");
	strings[6] = calloc(m, sizeof(char));
	strcpy(strings[6], "ab");
	strings[7] = calloc(m, sizeof(char));
	strcpy(strings[7], "ba");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				if (main_sgn(ft_strncmp(strings[i], strings[j], k)) != main_sgn(strncmp(strings[i], strings[j], k)))
				{
					printf("Error: strncmp with i=%i, j=%i, k=%i\n", i, j, k);
					printf("\tExpected value: %c\n\tValue obteained: %c\n", main_sgn(strncmp(strings[i], strings[j], k)), main_sgn(ft_strncmp(strings[i], strings[j], k)));
				}
				if (main_sgn(ft_memcmp(strings[i], strings[j], k)) != main_sgn(memcmp(strings[i], strings[j], k)))
				{
					printf("Error: memcmp with i=%i, j=%i, k=%i\n", i, j, k);
					printf("\tExpected value: %c\n\tValue obteained: %c\n", main_sgn(memcmp(strings[i], strings[j], k)), main_sgn(ft_memcmp(strings[i], strings[j], k)));
				}
			}
	free_str_arr(strings, n);
	// itoa
	n_int = 5;
	integers = malloc(n_int * sizeof(int));
	integers[0] = 0;
	integers[1] = 123;
	integers[2] = -123;
	integers[0] = INT_MIN;
	integers[0] = INT_MAX;
	str_aux2 = malloc(20 * sizeof(char));
	for (int i = 0; i < n_int; i++)
	{
		str_aux = ft_itoa(integers[i]);
		sprintf(str_aux2, "%d", integers[i]);
		if (strcmp(str_aux, str_aux2) != 0)
			printf("Error: itoa failed with n = %i\n", integers[i]);
		free(str_aux);
	}
	free(str_aux2);
	free(integers);
	// memcpy
	n = 20;
	m = 7;
	string = calloc(n, sizeof(char));
	string2 = calloc(n, sizeof(char));
	ft_memcpy(string, "hola que tal", m * sizeof(char));
	memcpy(string2, "hola que tal", m * sizeof(char));
	if (strcmp(string, string2))
		printf("Error: memcpy failed with strings");
	free(string);
	free(string2);
	integers = calloc(n, sizeof(int));
	integers2 = calloc(n, sizeof(int));
	int	ints_aux_memcpy[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	ft_memcpy(integers, ints_aux_memcpy, m * sizeof(int));
	memcpy(integers2, ints_aux_memcpy, m * sizeof(int));
	if (memcmp(integers, integers2, (m+3) * sizeof(int)))
		printf("Error: memcpy failed with integres");
	free(integers);
	free(integers2);
	// memmove test 1
	n = 20;
	m = 7;
	string = calloc(n, sizeof(char));
	string2 = calloc(n, sizeof(char));
	ft_memmove(string, "hola que tal", m * sizeof(char));
	memmove(string2, "hola que tal", m * sizeof(char));
	if (memcmp(string, string2, n))
		printf("Error: memmove failed with strings (test 1)");
	free(string);
	free(string2);
	integers = calloc(n, sizeof(int));
	integers2 = calloc(n, sizeof(int));
	int	ints_aux_memmove[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	ft_memmove(integers, ints_aux_memmove, m * sizeof(int));
	memmove(integers2, ints_aux_memmove, m * sizeof(int));
	if (memcmp(integers, integers2, n * sizeof(int)))
		printf("Error: memmove failed with integres (test 1)");
	free(integers);
	free(integers2);
	// memmove test 2
	string = calloc(n, sizeof(char));
	string2 = calloc(n, sizeof(char));
	strcpy(string, "hola que tal estas");
	strcpy(string2, "hola que tal estas");
	ft_memmove(string, string + 1, m * sizeof(char));
	memmove(string2, string2 + 1, m * sizeof(char));
	if (memcmp(string, string2, n))
		printf("Error: memmove failed with strings (test 2)");
	free(string);
	free(string2);
	integers = calloc(n, sizeof(int));
	integers2 = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		integers[i] = i;
		integers2[i] = i;
	}
	ft_memmove(integers, integers + 1, m * sizeof(int));
	memmove(integers2, integers2 + 1, m * sizeof(int));
	if (memcmp(integers, integers2, n * sizeof(int)))
		printf("Error: memmove failed with integres (test 2)");
	free(integers);
	free(integers2);
	// memmove test 3
	string = calloc(n, sizeof(char));
	string2 = calloc(n, sizeof(char));
	strcpy(string, "hola que tal estas");
	strcpy(string2, "hola que tal estas");
	ft_memmove(string + 1, string, m * sizeof(char));
	memmove(string2 + 1, string2, m * sizeof(char));
	if (memcmp(string, string2, n))
		printf("Error: memmove failed with strings (test 3)");
	free(string);
	free(string2);
	integers = calloc(n, sizeof(int));
	integers2 = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		integers[i] = i;
		integers2[i] = i;
	}
	ft_memmove(integers + 1, integers, m * sizeof(int));
	memmove(integers2 + 1, integers2, m * sizeof(int));
	if (memcmp(integers, integers2, n * sizeof(int)))
		printf("Error: memmove failed with integres (test 3)");
	free(integers);
	free(integers2);
	// strlcpy
	s = 10;
	k = 7;
	string = calloc(s, sizeof(char));
	string2 = calloc(s, sizeof(char));
	memset(string, 'u', s);
	memset(string2, 'u', s);
	n = ft_strlcpy(string, "hola", k);
	m = strlcpy(string2, "hola", k);
	if (n != m)
		printf("Error: Wrong return in strlcpy when k=%d. ft_strlcpy = %d != %d\n", k, n , m);
	if (strncmp(string, string2, s) != 0)
		printf ("Error: strlcpy failed when k=%d\n", k);
	k = 3;
	memset(string, 'u', s);
	memset(string2, 'u', s);
	n = ft_strlcpy(string, "hola", k);
	m = strlcpy(string2, "hola", k);
	if (n != m)
		printf("Error: Wrong return in strlcpy when k=%d. ft_strlcpy = %d != %d\n", k, n , m);
	if (strncmp(string, string2, s) != 0)
		printf ("Error: strlcpy failed when k=%d\n", k);
	k = 1;
	memset(string, 'u', s);
	memset(string2, 'u', s);
	n = ft_strlcpy(string, "hola", k);
	m = strlcpy(string2, "hola", k);
	if (n != m)
		printf("Error: Wrong return in strlcpy when k=%d. ft_strlcpy = %d != %d\n", k, n , m);
	if (strncmp(string, string2, s) != 0)
		printf ("Error: strlcpy failed when k=%d\n", k);
	k = 0;
	memset(string, 'u', s);
	memset(string2, 'u', s);
	n = ft_strlcpy(string, "hola", k);
	m = strlcpy(string2, "hola", k);
	if (n != m)
		printf("Error: Wrong return in strlcpy when k=%d. ft_strlcpy = %d != %d\n", k, n , m);
	if (strncmp(string, string2, s) != 0)
		printf ("Error: strlcpy failed when k=%d\n\tExpected: %s\n\tObtained: %s\n", k, string2, string);
	free(string);
	free(string2);
	// strlcat
	s = 20;
	string = calloc(s, sizeof(char));
	string2 = calloc(s, sizeof(char));
	str_aux = calloc(s, sizeof(char));
	k = 15;
	memset(string, 'u', s);
	memset(string2, 'u', s);
	memset(str_aux, 'u', s);
	strcpy(string, "hola");
	strcpy(string2, "hola");
	strcpy(str_aux, " que tal");
	n = ft_strlcat(string, str_aux, k);
	m = strlcat(string2, str_aux, k);
	if (n != m)
		printf("Error: Wrong return in strlcat when k=%d. ft_strlcpy = %d != %d\n", k, n , m);
	if (strncmp(string, string2, s) != 0)
		printf("Error: strlcat failed when k=%d\n\tExpected: %s\n\tObtained: %s\n", k, string2, string);
	k = 7;
	memset(string, 'u', s);
	memset(string2, 'u', s);
	memset(str_aux, 'u', s);
	strcpy(string, "hola");
	strcpy(string2, "hola");
	strcpy(str_aux, " que tal");
	n = ft_strlcat(string, str_aux, k);
	m = strlcat(string2, str_aux, k);
	if (n != m)
		printf("Error: Wrong return in strlcat when k=%d. ft_strlcpy = %d != %d\n", k, n , m);
	if (strncmp(string, string2, s) != 0)
		printf("Error: strlcat failed when k=%d\n\tExpected: %s\n\tObtained: %s\n", k, string2, string);
	k = 3;
	memset(string, 'u', s);
	memset(string2, 'u', s);
	memset(str_aux, 'u', s);
	strcpy(string, "hola");
	strcpy(string2, "hola");
	strcpy(str_aux, " que tal");
	n = ft_strlcat(string, str_aux, k);
	m = strlcat(string2, str_aux, k);
	if (n != m)
		printf("Error: Wrong return in strlcat when k=%d. ft_strlcpy = %d != %d\n", k, n , m);
	if (strncmp(string, string2, s) != 0)
		printf("Error: strlcat failed when k=%d\n\tExpected: %s\n\tObtained: %s\n", k, string2, string);
	k = 0;
	memset(string, 'u', s);
	memset(string2, 'u', s);
	memset(str_aux, 'u', s);
	strcpy(string, "hola");
	strcpy(string2, "hola");
	strcpy(str_aux, " que tal");
	n = ft_strlcat(string, str_aux, k);
	m = strlcat(string2, str_aux, k);
	if (n != m)
		printf("Error: Wrong return in strlcat when k=%d. ft_strlcpy = %d != %d\n", k, n , m);
	if (strncmp(string, string2, s) != 0)
		printf("Error: strlcat failed when k=%d\n\tExpected: %s\n\tObtained: %s\n", k, string2, string);
	free(string);
	free(string2);
	free(str_aux);
	// strchr
	n = 130 * 5;
	string = calloc(n, sizeof(char));
	c = 0;
	while (c < n - 5)
	{
		string[c] = c % 128;
		c++;
	}
	c = 0;
	while (c < 210)
	{
		if (ft_strchr(string, c) != strchr(string, c))
			printf("Error: strchr failed with c=%d\n", c);
		if (ft_strrchr(string, c) != strrchr(string, c))
			printf("Error: strrchr failed with c=%d\n", c);
		m = 0;
		while (m < 10)
		{
			k = 0;
			while (k < n - 12)
			{
				if(ft_memchr(string + k, c, m) != memchr(string + k, c, m))
					printf("Error: memchr failed with c=%d, m=%d, k=%d\n", c, m, k);
				k++;
			}
			m++;
		}
		c++;
	}
	free(string);
	// strnstr
	string = calloc(20, sizeof(char));
	strcpy(string, "hola que tal");
	if (ft_strnstr(string, "hola", 4) != string)
		printf("Error: strnstr failed at test 1\n");
	if (ft_strnstr(string, "holi", 4) != NULL)
		printf("Error: strnstr failed at test 2\n");
	if (ft_strnstr(string, "que", 4) != string + 5)
		printf("Error: strnstr failed at test 3\n");
	if (ft_strnstr(string, "ques", 3) != string + 5)
		printf("Error: strnstr failed at test 4\n");
	if (ft_strnstr(string, "ques", 4) != NULL)
		printf("Error: strnstr failed at test 5\n");
	if (ft_strnstr(string, "holas", 4) != string)
		printf("Error: strnstr failed at test 6\n");
	if (ft_strnstr(string, "tal", 3) != string + 9)
		printf("Error: strnstr failed at test 7\n");
	if (ft_strnstr(string, "tal que", 3) != string + 9)
		printf("Error: strnstr failed at test 8\n");
	if (ft_strnstr(string, "tal que", 4) != NULL)
		printf("Error: strnstr failed at test 9\n");
	free(string);
	// strdup
	string = ft_strdup("hola");
	string2 = strdup("hola");
	if (strcmp(string, string2) != 0)
		printf("Error: strdup");
	free(string);
	free(string2);
	// atoi
	n = 14;
	strings = malloc(n * sizeof(char *));
	strings[0] = ft_itoa(0);
	strings[1] = ft_itoa(123);
	strings[2] = ft_itoa(-123);
	strings[3] = ft_itoa(INT_MAX);
	strings[4] = ft_itoa(INT_MIN);
	for (int i = 5; i < n; i++)
		strings[i] = malloc(30 * sizeof(char));
	strcpy(strings[5], "+123");
	strcpy(strings[6], "++123");
	strcpy(strings[7], "--123");
	strcpy(strings[8], "-0");
	strcpy(strings[9], "+0");
	strcpy(strings[10], "asdf");
	strcpy(strings[11], "-123asdf123");
	strcpy(strings[12], "00123");
	// strcpy(strings[13], "214748364800009000000");
	for(int i = 0; i < n; i++)
		if (ft_atoi(strings[i]) != atoi(strings[i]))
		printf("Error: atoi failed at test %i\n\tExpected: %i\n\tObteined: %i\n", i, atoi(strings[i]), ft_atoi(strings[i]));
	free_str_arr(strings, n);
	// split
	n = 30;
	string = calloc(n, sizeof(char));
	strncpy(string, "hola que tal",n);
	str_arr = ft_split(string, ' ');
	free(string);
	if (strcmp(str_arr[0], "hola") != 0)
		printf("Error: split failed on test 1.1\n");
	if (strcmp(str_arr[1], "que") != 0)
		printf("Error: split failed on test 1.2\n");
	if (strcmp(str_arr[2], "tal") != 0)
		printf("Error: split failed on test 1.3\n");
	if (str_arr[3] != NULL)
		printf("Error: split failed on test 1.4\n");
	k = 0;
	while (str_arr[k] != NULL)
	{
		free(str_arr[k]);
		k++;
	}
	free(str_arr);
	string = calloc(n, sizeof(char));
	strncpy(string, "...hola....que..tal..estas?....",n);
	str_arr = ft_split(string, '.');
	free(string);
	if (strcmp(str_arr[0], "hola") != 0)
		printf("Error: split failed on test 2.1\n");
	if (strcmp(str_arr[1], "que") != 0)
		printf("Error: split failed on test 2.2\n");
	if (strcmp(str_arr[2], "tal") != 0)
		printf("Error: split failed on test 2.3\n");
	if (strcmp(str_arr[3], "estas?") != 0)
		printf("Error: split failed on test 2.4\n");
	if (str_arr[4] != NULL)
		printf("Error: split failed on test 2.5\n");
	k = 0;
	while (str_arr[k] != NULL)
	{
		free(str_arr[k]);
		k++;
	}
	free(str_arr);
	// strmapi
	n = 20;
	string = calloc(n, sizeof(char));
	strncpy(string,"abcdefghijk", n);
	string2 = ft_strmapi(string, alternate_case_val);
	if (strncmp(string2, "AbCdEfGhIjK",n))
		printf("Error: strmapi failed with alternate_case_val");
	free(string2);
	ft_striteri(string, alternate_case_ref);
	if (strncmp(string, "AbCdEfGhIjK",n))
		printf("Error: strmapi failed with alternate_case_ref");
	free(string);
	ft_putstr_fd("hola que tal", 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("muy bien", 1);
	
	(void) argc;
	printf("Use 'valgrind %s' for testing memory leaks.\n", argv[0]);
}
