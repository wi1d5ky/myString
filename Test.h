#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <string>
#include <cstring>
#include "String.h"

class string_test : public ::testing::Test {};

TEST_F(string_test, Constructor)
{
	String s0("Initial string");

	String s1;
	String s2(s0);
	String s3("123");
	String s4('X');

	EXPECT_TRUE(strcmp(s1.c_str(), "\0") == 0);
	EXPECT_TRUE(strcmp(s2.c_str(), "Initial string\0") == 0);
	EXPECT_TRUE(strcmp(s3.c_str(), "123\0") == 0);
	EXPECT_TRUE(strcmp(s4.c_str(), "X\0") == 0);
}

TEST_F(string_test, Assign)
{
	String s1 = "Test";
	String s2 = s1;
	String s3 = 'X';
	EXPECT_TRUE(strcmp(s1.c_str(), "Test\0") == 0);
	EXPECT_TRUE(strcmp(s2.c_str(), "Test\0") == 0);
	EXPECT_TRUE(strcmp(s3.c_str(), "X\0") == 0);
}

TEST_F(string_test, size)
{
	String s1 = "Test";
	String s2 = "A";
	String s3 = "";
	EXPECT_EQ(s1.size(), (size_t) 4);
	EXPECT_EQ(s2.size(), (size_t) 1);
	EXPECT_EQ(s3.size(), (size_t) 0);
}

TEST_F(string_test, length)
{
	String s1 = "Test";
	String s2 = "A";
	String s3 = "";
	EXPECT_EQ(s1.length(), (size_t) 4);
	EXPECT_EQ(s2.length(), (size_t) 1);
	EXPECT_EQ(s3.length(), (size_t) 0);
}
