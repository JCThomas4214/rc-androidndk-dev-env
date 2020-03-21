#define DEBUG

extern "C" {
	#include <template_module/template_module.h>
}
#include <gmock/gmock.h>

#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING  1

TEST(TestCase1, bin_hex_StrToInt32Test_cornerCases)
{   	                
	const char * stringlist[] = {"", " ", "00 11", ".0123", "0.", "+00", "0.1", "10+", "12fl", "abcdefg"};

	ASSERT_EQ(-2, bin_hex_StrToInt32(stringlist[0]));
	ASSERT_EQ(-2, bin_hex_StrToInt32(stringlist[1]));
	ASSERT_EQ(-2, bin_hex_StrToInt32(stringlist[2]));
	ASSERT_EQ(-2, bin_hex_StrToInt32(stringlist[3]));
	ASSERT_EQ(-2, bin_hex_StrToInt32(stringlist[4]));
	ASSERT_EQ(-2, bin_hex_StrToInt32(stringlist[5]));
	ASSERT_EQ(-2, bin_hex_StrToInt32(stringlist[6]));
	ASSERT_EQ(-2, bin_hex_StrToInt32(stringlist[7]));
	ASSERT_EQ(-2, bin_hex_StrToInt32(stringlist[8]));
	ASSERT_EQ(-2, bin_hex_StrToInt32(stringlist[9]));
	
	
}

TEST(TestCase2, bin_hex_StrToInt32Test_normalCases)
{   	
	const char * stringlist[] = {
						  "0", 
						  "0000",
						  "1",
						  "0001",
						  "101",
						  "1100",
						  "11100",
						  "10000000",
						  "11111001",
						  "0000111100001101",
						  "9",
						  "A",
						  "F",
						  "0123",
						  "abcdef",
						  "ABCDEF",
						  "abcDEF",
						  "aBcDeF",
						  "D1Ce",
						  "923FB5"
					     };

	ASSERT_EQ(0, bin_hex_StrToInt32(stringlist[0]));
	ASSERT_EQ(0, bin_hex_StrToInt32(stringlist[1]));
	ASSERT_EQ(1, bin_hex_StrToInt32(stringlist[2]));
	ASSERT_EQ(1, bin_hex_StrToInt32(stringlist[3]));
	ASSERT_EQ(5, bin_hex_StrToInt32(stringlist[4]));
	ASSERT_EQ(12, bin_hex_StrToInt32(stringlist[5]));
	ASSERT_EQ(28, bin_hex_StrToInt32(stringlist[6]));
	ASSERT_EQ(128, bin_hex_StrToInt32(stringlist[7]));
	ASSERT_EQ(249, bin_hex_StrToInt32(stringlist[8]));
	ASSERT_EQ(3853, bin_hex_StrToInt32(stringlist[9]));
	ASSERT_EQ(9, bin_hex_StrToInt32(stringlist[10]));
	ASSERT_EQ(10, bin_hex_StrToInt32(stringlist[11]));
	ASSERT_EQ(15, bin_hex_StrToInt32(stringlist[12]));
	ASSERT_EQ(291, bin_hex_StrToInt32(stringlist[13]));
	ASSERT_EQ(11259375, bin_hex_StrToInt32(stringlist[14]));
	ASSERT_EQ(11259375, bin_hex_StrToInt32(stringlist[15]));
	ASSERT_EQ(11259375, bin_hex_StrToInt32(stringlist[16]));
	ASSERT_EQ(11259375, bin_hex_StrToInt32(stringlist[17]));
	ASSERT_EQ(53710, bin_hex_StrToInt32(stringlist[18]));
	ASSERT_EQ(9584565, bin_hex_StrToInt32(stringlist[19]));
}

int main(int argc, char** argv, char** envp)
{
	// printf("Helloworld!! with some clang ;)\n");
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
} 
