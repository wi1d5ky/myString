#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring.h"

using namespace std;

bool same_str (const char * ls, const char * rs)
{
	return strcmp(ls, rs) == 0;
}

// For Test 4 : get item by id
void read_write(String & str)
{
	str[2] = 'T';
}
void read_only(const String &str)
{
	char c = str[1];
	assert(c == 'T');
}

int main()
{
	cout << "[Constructor]\t\tTest Running... ";

    String t1s, t1t("CSIE106"), t1u(t1t), t1v('a');
	assert(same_str(t1s.c_str(), ""));
	assert(same_str(t1t.c_str(), "CSIE106"));
	assert(same_str(t1u.c_str(), "CSIE106"));
	assert(same_str(t1v.c_str(), "a"));

	cout << "Done!" << endl << endl;

	// ========================

	cout << "[Copy Assign]\t\tTest Running... ";

	String t2s("NTU"), t2t("NTNU"), t2u, t2v;
	t2s = t2t;
	t2u = "NTNU";
	t2v = 'Y';

	assert(same_str(t2s.c_str(), "NTNU"));
	assert(same_str(t2t.c_str(), "NTNU"));
	assert(same_str(t2u.c_str(), "NTNU"));
	assert(same_str(t2v.c_str(), "Y"));

	cout << "Done!" << endl << endl;

	// ========================

	cout << "[Size and Length]\tTest Running... ";

	String t3s = "NTNU";
	String t3t = "Y";
	String t3u = "";

	assert(t3s.size() == (size_t) 4);
	assert(t3t.size() == (size_t) 1);
	assert(t3u.size() == (size_t) 0);

	assert(t3s.length() == (size_t) 4);
	assert(t3t.length() == (size_t) 1);
	assert(t3u.length() == (size_t) 0);

	cout << "Done!" << endl << endl;

	// ========================

	cout << "[Get item by id]\tTest Running... ";

	String t4s("NTNU");
	read_write(t4s);
	assert(same_str(t4s.c_str(), "NTTU" ));
	read_only(t4s);
	assert(same_str(t4s.c_str(), "NTTU" ));

	cout << "Done!" << endl << endl;

	// ========================

	cout << "[Append]\t\tTest Running... ";

	char t5c[] = "12";
	String	t5s1 = "ab", t5s2 = "cd", t5s3 = "ef",
					t5s4 = t5s1 + t5s2 + t5s3,
					t5s5 = t5s1 + t5c + t5s2,
					t5s6 = t5s1 + "gh",
					t5s7 = "ij" + t5s2,
					t5s8 = t5c + t5s3,
					t5s9 = t5s1 + 'k',
					t5s10 = 'l' + t5s1;
	assert(same_str(t5s1.c_str(), "ab" ));
	assert(same_str(t5s2.c_str(), "cd" ));
	assert(same_str(t5s3.c_str(), "ef" ));
	assert(same_str(t5s4.c_str(), "abcdef" ));
	assert(same_str(t5s5.c_str(), "ab12cd" ));
	assert(same_str(t5s6.c_str(), "abgh" ));
	assert(same_str(t5s7.c_str(), "ijcd" ));
	assert(same_str(t5s8.c_str(), "12ef" ));
	assert(same_str(t5s9.c_str(), "abk" ));
	assert(same_str(t5s10.c_str(), "lab" ));
	// s11 = 'l' + c + s1 can't work

	t5s1 += t5s2;
	assert(same_str(t5s1.c_str(), "abcd" ));
	assert(same_str(t5s2.c_str(), "cd" ));

	t5s2 += t5s3 + t5s4;
	assert(same_str(t5s2.c_str(), "cdefabcdef" ));
	assert(same_str(t5s3.c_str(), "ef" ));
	assert(same_str(t5s4.c_str(), "abcdef" ));


	t5s1 += t5s3 += t5s1;
	assert(same_str(t5s1.c_str(), "abcdefabcd" ));
	assert(same_str(t5s3.c_str(), "efabcd" ));

	t5s3 += "zz";
	assert(same_str(t5s3.c_str(), "efabcdzz" ));

	t5s3 += 'r';
	assert(same_str(t5s3.c_str(), "efabcdzzr" ));

	t5s3 += t5s3;
	assert(same_str(t5s3.c_str(), "efabcdzzrefabcdzzr" ));

	cout << "Done!" << endl << endl;

	// ========================

	cout << "[Compare]\t\tTest Running... ";

	String	t6s1 = "bbc", t6s2 = "bbc",
					t6s3 = "bbb", t6s4 = "abc";
	assert(t6s1 == t6s2);
	assert(t6s1 >= t6s2);
	assert(t6s1 <= t6s2);
	assert(t6s2 >  t6s3);
	assert(t6s4 <  t6s1);

	cout << "Done!" << endl << endl;

	// ========================

	cout << "[Clear]\t\t\tTest Running... ";

	String t7s("This should not appear!"), t7t, t7u(t7s);
	t7t = "This should not appear, too.";
	t7s.clear();
	t7t.clear();
	t7u.clear();
	assert(same_str(t7s.c_str(), "" ));
	assert(same_str(t7t.c_str(), "" ));
	assert(same_str(t7u.c_str(), "" ));

	cout << "Done!" << endl << endl;

	// ========================

	cout << "[Swap]\t\t\tTest Running... ";

	String t8ntu("NTU"), t8ntnu("NTNU");
	t8ntu.swap(t8ntnu);
	assert(same_str(t8ntu.c_str(), "NTNU" ));
	assert(same_str(t8ntnu.c_str(), "NTU" ));

	cout << "Done!" << endl << endl;

	// ========================

	cout << "[CinAndCout]\t\tTest Running... " << endl << endl;

	cout << "What you input should be outputed below." << endl;
	String t9s;
	cin >> t9s;
	cout << t9s << endl;

	cout << "\t\t\t\t\tDone!" << endl << endl;

	// ========================

	cout << endl << "All Test Passed." << endl;
	return 0;
}
