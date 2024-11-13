/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, upper_and_lower_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Zz");
	ASSERT_EQ(1, actual);
}


TEST(PasswordTest, sandwich_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZzZ");
	ASSERT_EQ(1, actual);
}


TEST(PasswordTest, has_mixed_case_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("ZzZ");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, false_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("bbb");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, mixed_empty_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("");
	ASSERT_EQ(0, actual);
}