#include "String.h"
#include <iostream>
#include <utility>
#include <cstring>

// ================================
// ========= Constructor ==========
// ================================

String::String()
{
	size_ = 0;
	capacity_ = 1;
	str_ = new char[capacity_];
	str_[0] = '\0';
}

String::String(const String& src):size_{src.size_}
{
	capacity_ = size_ + 1;
	str_ = new char[capacity_];
	for(size_t i = 0 ; i < capacity_ ; ++i)
		str_[i] = src.str_[i];
}

String::String(const char * src)
{
	size_ = strlen(src);
	capacity_ = size_ + 1;
	str_ = new char[capacity_];	// incl. '\0'
	for(size_t i = 0 ; i < capacity_ ; ++i)
		str_[i] = src[i];
}

String::String(char c)
{
	size_ = 1;
	capacity_ = size_ + 1;
	str_ = new char[capacity_];
	str_[0] = c;
	str_[1] = '\0';
}

// ========= Destructor ===========

String::~String()
{
	delete [] str_;
}

// ================================
// =========== Assign =============
// ================================

String & String::operator = (String rhs)
{
	std::swap(str_, rhs.str_);
	size_ = rhs.size_;
	capacity_ = rhs.capacity_;
	return *this;
}

String & String::operator= (const char * s)
{
	String tmp(s);
	return *this = tmp;
}

String & String::operator = (char c)
{
	String tmp(c);
	return *this = tmp;
}

std::ostream & operator << (std::ostream &os, const String &rhs)
{
	os << rhs.c_str();
	return os;
}
