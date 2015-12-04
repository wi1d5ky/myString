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

	size_t size() const
	{
		return size_;
	}
	size_t length() const
	{
		return size();
	}
	const char* c_str() const
	{
		return str_;
	}
private:
	char* str_;
	size_t size_;
	size_t capacity_;
};

std::ostream & operator << (std::ostream &os, const String &rhs);

#endif // STRING_H
