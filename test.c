#include "rn.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


static char *roman_buff = NULL;

static int result_cmp(int decimal_in, const char *exp_str)
{
	int result = FAILED;

	convert(decimal_in, roman_buff);
	if (strncmp(roman_buff, exp_str, MAX_CHARS) == 0) {
		result = PASSED;
	}

	return result;
}


static void my_assert(int cond, char *err_str)
{
	if (cond == FALSE) {
		printf(err_str);
		exit(1);
	}
}


void test_all(void)
{
	roman_buff = malloc(sizeof(*roman_buff) * MAX_CHARS);
	memcpy_s(roman_buff, MAX_CHARS, "", MAX_CHARS);
	if (roman_buff == NULL) {
		printf("out of memory");
		exit(2);
	}
	my_assert((result_cmp(1, "I") == PASSED), "Failed to convert 1");
	my_assert((result_cmp(4, "IV") == PASSED), "Failed to convert 4");
	my_assert((result_cmp(5, "V") == PASSED), "Failed to convert 5");
	my_assert((result_cmp(9, "IX") == PASSED), "Failed to convert 9");
	my_assert((result_cmp(10, "X") == PASSED), "Failed to convert 10");
	my_assert((result_cmp(11, "XI") == PASSED), "Failed to convert 11");
	my_assert((result_cmp(18, "XVIII") == PASSED), "Failed to convert 18");
	my_assert((result_cmp(50, "L") == PASSED), "Failed to convert 50");
	my_assert((result_cmp(100, "C") == PASSED), "Failed to convert 100");
	my_assert((result_cmp(500, "D") == PASSED), "Failed to convert 500");
	my_assert((result_cmp(1000, "M") == PASSED), "Failed to convert 1000");


	free(roman_buff);

	return;
}