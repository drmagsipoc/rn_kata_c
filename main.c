#include <stdio.h>
#include "rn.h"
#include "string.h"


static const char *ones[] =
{
	"",
	"I",
	"II",
	"III",
	"IV",
	"V",
	"VI",
	"VII",
	"VIII",
	"IX",
};


static const char *tens[] =
{
	"",
	"X",
	"XX",
	"XXX",
	"XL",
	"L",
	"LX",
	"LXX",
	"LXXX",
	"XC",
};


static const char *hundreds[] =
{
	"",
	"C",
	"CC",
	"CCC",
	"CD",
	"D",
	"DC",
	"DCC",
	"DCCC",
	"CM",
};


static const char *thousands[] =
{
	"",
	"M",
	"MM",
	"MMM",
	"",
	"",
	"",
	"",
	"",
	"",
};


static const char **digits_table[] =
{
	ones,
	tens,
	hundreds,
	thousands
};


static int handle_digits(enum digits_enum digit, int input, const char **output)
{
	const char **table = NULL;
	if ((input > 10) || (input < 0)) {
		printf("%s invalid input %d\n", __FUNCTION__, input);
		return -1;
	}

	table = digits_table[digit];
	*output = table[input];

	return 0;
}


int convert(int input, char *out_string)
{
	int num;
	/* char build_str[MAX_CHARS]; */
	const char *ones_str = NULL;
	const char *tens_str = NULL;
	const char *hundreds_str = NULL;
	const char *thousands_str = NULL;

	if (input >= 4000) {
		/* upper limit for roman numerals */
		return -2;
	}
	if (input < 1) {
		/* lower limit for roman numerals */
		return -3;
	}
	num = input % 10;
	if (handle_digits(ONES, num, &ones_str) != 0) {
		return -1;
	}
	
	/* get only the ones */
	num = (input / 10) % 10;
	if (handle_digits(TENS, num, &tens_str) != 0) {
		return -1;
	}

	num = (input /100) % 10;
	if (handle_digits(HUNDREDS, num, &hundreds_str) != 0) {
		return -1;
	}

	num = (input /1000) % 10;
	if (handle_digits(THOUSANDS, num, &thousands_str) != 0) {
		return -1;
	}

	strncpy_s(out_string, MAX_CHARS, thousands_str, MAX_CHARS);
	strncat_s(out_string, MAX_CHARS, hundreds_str, MAX_CHARS);
	strncat_s(out_string, MAX_CHARS, tens_str, MAX_CHARS);
	strncat_s(out_string, MAX_CHARS, ones_str, MAX_CHARS);

	return 0;
}


static void run_test(void)
{
	test_all();

	return;
}

int main(int argc, char *argv[])
{
	run_test();

	return 0;
}
