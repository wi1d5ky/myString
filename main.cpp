#include <stdio.h>

#define TEST_MODE 1
#if TEST_MODE
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Test.h"
#endif // TEST_MODE

#if TEST_MODE
int main(int argc,char **argv)
	{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
#else
int main()
{
	printf("Run Test!\n");
	return 0;
}
#endif // TEST_MODE
