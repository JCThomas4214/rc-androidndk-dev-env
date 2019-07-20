#include <gmock/gmock.h>
#include "../TestCode.h"

int main(int argc, char** argv, char** envp)
{
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
} 