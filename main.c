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


static int handle_ones(int input, const char **output)
{
	if ((input > 10) || (input < 0)) {
		printf("%s invalid input %d", __FUNCTION__, input);
		return -1;
	}

	*output = ones[input];

	return 0;
}


static int handle_tens(int input, const char **output)
{
	if ((input > 10) || (input < 0)) {
		printf("%s invalid input %d", __FUNCTION__, input);
		return -1;
	}

	*output = tens[input];

	return 0;
}


int convert(int input, char *out_string)
{
	int ones;
	int tens;
	/* char build_str[MAX_CHARS]; */
	const char *ones_str = NULL;

	ones = input % 10;
	if (handle_ones(ones, &ones_str) != 0) {
		return -1;
	}
	
	/* get only the ones */
	tens = (input / 10) % 10;
	if (handle_tens(ones, &ones_str) != 0) {
		return -1;
	}

	memcpy(out_string, ones_str, MAX_CHARS);

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
	printf("Hello worlds");

	return 0;
}
