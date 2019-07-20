#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TestCode.h"

/*

Write a function bin_hex_StrToInt32 that receives a string containing either a binary or hex number. 
The function must return the string�s integer value. 

Note that a string that contains ONLY '1' and '0' can be considered as a binary or a hex string. 
For eaxmple, "10" can be a binary number equivalent to 2 or a hex number equivalent to 16.
If the string is containg ONLY '1' and '0', the default will be ***binary***.

If the input parameter is empty or invalid value, the function should return -2

Note: Do not call built-in library functions that accomplish these tasks automatically.
*/

/*



***REVIEWER COMMENTS/APPROVAL****







*/

int bin_hex_StrToInt32(const char * s)
{
    int length = strlen(s);
	if (length == 0)
		return -2;
	int base = 0; //this initial value will be used to indicate the base of the number

	int counter = 0;
	

	//check to see if it's a binary number
	for (int i = 0; i < length; i++)
		if (s[i] == '0' || s[i] == '1')
			counter++;
		else
			break;

	if(counter == length)
	   base = 2;

	if (base == 0) //check to see if it's hex number
	{
		counter = 0;

		for (int i = 0; i < length; i++)
			if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f'))
				counter++;
			else
				break;

		if (counter == length)
			base = 16;
	}

	if(base == 0) //the input string is neither binary nor hex
		return -2;

	int num = 0;

	for (int i = 0; i<length; i++)
	{
		if(base == 2)
		    num = num * 2 + s[i] - '0';
		else
		{
			if (s[i] >= '0' && s[i] <= '9')
				num = num * 16 + s[i] - '0';
			else if (s[i] >= 'A' && s[i] <= 'F')
				num = num * 16 + (s[i] - 'A' + 10);
			else if (s[i] >= 'a' && s[i] <= 'f')
				num = num * 16 + (s[i] - 'a' + 10);
		}
	}
	return num;
}

