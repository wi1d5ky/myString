#include "mystring.h"
#include <iostream>
#include <cstring>

constexpr int MaxStrLen = 1000;

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
	this->swap(rhs);
	return *this;
}

String & String::operator = (const char * s)
{
	String tmp(s);
	return *this = tmp;
}

String & String::operator = (char c)
{
	String tmp(c);
	return *this = tmp;
}

char & String::operator [] (int i)
{
	return const_cast<char &>(static_cast<const String &>(*this)[i]);
}

const char & String::operator [] (int i) const
{
	return str_[i];
}

bool String::operator > (const String & rhs)
{
	return strcmp(str_, rhs.str_) > 0;
}

bool String::operator >= (const String & rhs)
{
	return strcmp(str_, rhs.str_) >= 0;
}

bool String::operator == (const String & rhs)
{
	return strcmp(str_, rhs.str_) == 0;
}

bool String::operator <= (const String & rhs)
{
	return strcmp(str_, rhs.str_) <= 0;
}

bool String::operator < (const String & rhs)
{
	return strcmp(str_, rhs.str_) < 0;
}

String String::operator + (const String & rhs)
{
	char * c = new char[size_ + rhs.size_ + 1];	// incl. '\0'
	strcpy(c, "");
	strcat(c, str_);
	strcat(c, rhs.str_);
	String s(c);
	delete [] c;
	return s;
}

String String::operator + (const char * rhs)
{
	String srhs(rhs);
	return *this + srhs;
}

String String::operator + (char rc)
{
	String srhs(rc);
	return *this + srhs;
}

String operator + (const char * lhs, const String & rhs)
{
	String slhs(lhs);
	return slhs + rhs;
}

String operator + (char lhc, String rhs)
{
	String slhs(lhc);
	return slhs + rhs;
}

String & String::operator += (const String & rhs)
{
	char * c = new char[size_ + rhs.size_ + 1];	// incl. '\0'
	strcpy(c, "");
	strcat(c, str_);
	strcat(c, rhs.str_);
	*this = c;
	return *this;
}

String & String::operator += (const char* rhs)
{
	String srhs(rhs);
	return *this += srhs;
}

String & String::operator += (char rc)
{
	String srhs(rc);
	return *this += srhs;
}

void String::clear()
{
	if(capacity_ == 1)
		return;
	size_ = 0;
	capacity_ = 1;
	delete [] str_;
	str_ = new char[capacity_];
	str_[0] = '\0';
}

void String::swap (String & rhs)
{
	int tmp_size = size_,
		tmp_capa = capacity_;
	char * tmp_str = str_;

	size_ = rhs.size_;
	capacity_ = rhs.capacity_;
	str_ = rhs.str_;

	rhs.size_ = tmp_size;
	rhs.capacity_ = tmp_capa;
	rhs.str_ = tmp_str;

}

std::istream & operator >> (std::istream & is, String & rhs)
{
	char tmp[MaxStrLen];
	is >> tmp;
	rhs = tmp;
	return is;
}

std::ostream & operator << (std::ostream & os, const String & rhs)
{
	os << rhs.c_str();
	return os;
}
