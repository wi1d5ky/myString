#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <string>
#include <cstring>
#include <cctype>
#include "mystring.h"

bool same_str (const char * ls, const char * rs)
{
	return strcmp(ls, rs) == 0;
}

class string_test : public ::testing::Test {};

TEST_F(string_test, constructor)
{
	String s, t("CSIE106"), u(t), v('a');
	EXPECT_TRUE(same_str(s.c_str(), ""));
	EXPECT_TRUE(same_str(t.c_str(), "CSIE106"));
	EXPECT_TRUE(same_str(u.c_str(), "CSIE106"));
	EXPECT_TRUE(same_str(v.c_str(), "a"));
}

TEST_F(string_test, copy_assign)
{
	String s("NTU"), t("NTNU"), u, v;
	s = t;
	u = "NTNU";
	v = 'Y';

	EXPECT_TRUE(same_str(s.c_str(), "NTNU"));
	EXPECT_TRUE(same_str(t.c_str(), "NTNU"));
	EXPECT_TRUE(same_str(u.c_str(), "NTNU"));
	EXPECT_TRUE(same_str(v.c_str(), "Y"));
}

TEST_F(string_test, size_and_length)
{
	String s = "NTNU";
	String t = "Y";
	String u = "";
	EXPECT_EQ(s.size(), (size_t) 4);
	EXPECT_EQ(t.size(), (size_t) 1);
	EXPECT_EQ(u.size(), (size_t) 0);

	EXPECT_EQ(s.length(), (size_t) 4);
	EXPECT_EQ(t.length(), (size_t) 1);
	EXPECT_EQ(u.length(), (size_t) 0);
}

void read_write(String & str) {str[2] = 'T';}
void read_only(const String &str) { char c = str[1];}

TEST_F(string_test, get_item_by_id)
{
	String s("NTNU");
	read_write(s);
	EXPECT_TRUE(same_str(s.c_str(), "NTTU" ));
	read_only(s);
	EXPECT_TRUE(same_str(s.c_str(), "NTTU" ));
}

TEST_F(string_test, append)
{
	char c[] = "12";
	String	s1 = "ab", s2 = "cd", s3 = "ef",
			s4 = s1 + s2 + s3,
			s5 = s1 + c + s2,
			s6 = s1 + "gh",
			s7 = "ij" + s2,
			s8 = c + s3,
			s9 = s1 + 'k',
			s10 = 'l' + s1;
	EXPECT_TRUE(same_str(s1.c_str(), "ab" ));
	EXPECT_TRUE(same_str(s2.c_str(), "cd" ));
	EXPECT_TRUE(same_str(s3.c_str(), "ef" ));
	EXPECT_TRUE(same_str(s4.c_str(), "abcdef" ));
	EXPECT_TRUE(same_str(s5.c_str(), "ab12cd" ));
	EXPECT_TRUE(same_str(s6.c_str(), "abgh" ));
	EXPECT_TRUE(same_str(s7.c_str(), "ijcd" ));
	EXPECT_TRUE(same_str(s8.c_str(), "12ef" ));
	EXPECT_TRUE(same_str(s9.c_str(), "abk" ));
	EXPECT_TRUE(same_str(s10.c_str(), "lab" ));
	// s11 = 'l' + c + s1 can't work

	s1 += s2;
	EXPECT_TRUE(same_str(s1.c_str(), "abcd" ));
	EXPECT_TRUE(same_str(s2.c_str(), "cd" ));

	s2 += s3 + s4;
	EXPECT_TRUE(same_str(s2.c_str(), "cdefabcdef" ));
	EXPECT_TRUE(same_str(s3.c_str(), "ef" ));
	EXPECT_TRUE(same_str(s4.c_str(), "abcdef" ));


	s1 += s3 += s1;
	EXPECT_TRUE(same_str(s1.c_str(), "abcdefabcd" ));
	EXPECT_TRUE(same_str(s3.c_str(), "efabcd" ));

	s3 += "zz";
	EXPECT_TRUE(same_str(s3.c_str(), "efabcdzz" ));

	s3 += 'r';
	EXPECT_TRUE(same_str(s3.c_str(), "efabcdzzr" ));
}

TEST_F(string_test, compare)
{
	String	s1 = "bbc", s2 = "bbc",
			s3 = "bbb", s4 = "abc";
	EXPECT_TRUE(s1 == s2);
	EXPECT_TRUE(s1 >= s2);
	EXPECT_TRUE(s1 <= s2);
	EXPECT_TRUE(s2 >  s3);
	EXPECT_TRUE(s4 <  s1);
}

TEST_F(string_test, clear)
{
	String s("This should not appear!"), t, u(s);
	t = "This should not appear, too.";
	s.clear();
	t.clear();
	u.clear();
	EXPECT_TRUE(same_str(s.c_str(), "" ));
	EXPECT_TRUE(same_str(t.c_str(), "" ));
	EXPECT_TRUE(same_str(u.c_str(), "" ));
}

TEST_F(string_test, swap)
{
	String ntu("NTU"), ntnu("NTNU");
	ntu.swap(ntnu);
	EXPECT_TRUE(same_str(ntu.c_str(), "NTNU" ));
	EXPECT_TRUE(same_str(ntnu.c_str(), "NTU" ));
}


//TEST_F(string_test, CinAndCout)
//{
//	std::cout << "What you input, should be outputed below." << std::endl;
//	String s;
//	std::cin >> s;
//	std::cout << s << std::endl;
//}


