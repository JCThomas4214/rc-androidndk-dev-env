#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <templateProject.h>
#include <template_module/template_module.h>

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

int init(int argc, char** argv)
{
	printf("the val: %d\n", bin_hex_StrToInt32("100011110"));
    printf("Hello World with Clang\n");

	return 0;
}