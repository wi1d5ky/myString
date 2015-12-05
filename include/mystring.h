#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
public:

	// Constructor
	String();								// default
	String(const String & src);				// copy
	String(const char * src);				// from c-string
	String(char c);							// from char

	// Destructor
	~String();

	// Assign
	String & operator = (String rhs);		// string
	String & operator = (const char * s);	// c-string
	String & operator = (char c);			// character

	// get Item By Id
	char & operator [] (int i);
	const char & operator [] (int i) const;

	// compare
	bool operator > (const String & rhs);
	bool operator >= (const String & rhs);
	bool operator == (const String & rhs);
	bool operator <= (const String & rhs);
	bool operator < (const String & rhs);

	// append
	String operator + (const String & rhs);
	String operator + (const char * rhs);
	String operator + (char rc);

	// append then assign
	String & operator += (const String & str);
	String & operator += (const char* s);
	String & operator += (char c);

	// clear
	void clear();

	// swap
	void swap (String& str);

	// size
	size_t size() const
	{
		return size_;
	}
	size_t length() const
	{
		return size();
	}

	// c-api
	const char* c_str() const
	{
		return str_;
	}
private:
	char* str_;
	size_t size_;
	size_t capacity_;
};

String operator + (const char * lhs, const String & rhs);
String operator + (const char lhc, String rhs);
std::istream & operator >> (std::istream & is, String & rhs);
std::ostream & operator << (std::ostream & os, const String & rhs);

#endif // STRING_H
