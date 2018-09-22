#ifndef __RN_H__
#define __RN_H__

#define MAX_CHARS		(512)
#define PASSED			(0)
#define FAILED			(!(PASSED))
#define TRUE			(1)
#define FALSE			(!TRUE)



int convert(int decimal_in, char *out_string);

void test_all(void);

#endiff