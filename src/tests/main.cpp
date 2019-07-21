// #include <stdio.h>
#include <gmock/gmock.h>
#include "../TestCode.h"

int main(int argc, char** argv, char** envp)
{
	// printf("Helloworld!! with some clang ;)\n");
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
} 