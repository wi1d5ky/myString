#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>		// for istream, ostream, size_t

class String
{
public:

	// Constructor
	String();								// default
	String(char c);							// from char
	String(const char * s);					// from c-string
	String(const String & s);				// copy

	// Destructor
	~String();

	// Assign
	String & operator = (char c);			// character
	String & operator = (const char * s);	// c-string
	String & operator = (const String s);	// string

	// Get Item By Id
	char & operator [] (int i);				// non-const
	const char & operator [] (int i) const;	// const

	// compare
	bool operator > (const String & refs);
	bool operator < (const String & refs);
	bool operator >= (const String & refs);
	bool operator <= (const String & refs);
	bool operator == (const String & refs);

	// append
	String operator + (char c);
	String operator + (const char * s);
	String operator + (const String & s);
	String & operator += (char c);
	String & operator += (const char * s);
	String & operator += (const String & s);

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
	const char * c_str() const
	{
		return str_;
	}

	void clear();				// clear
	void swap (String & str);	// swap
private:
	char * str_;
	size_t size_;
	size_t capacity_;
};

String operator + (const char * lhs, const String & rhs);
String operator + (const char lhc, String rhs);
std::istream & operator >> (std::istream & is, String & rhs);
std::ostream & operator << (std::ostream & os, const String & rhs);

#endif // MYSTRING_H
