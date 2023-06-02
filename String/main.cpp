#include<iostream>
using namespace std;


class String;
String operator+(const String& left, const String& right);

class String
{
	int size;
	char* str;
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//			Constructors:

	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//			Operators:

	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	char operator[](int i)const;
	char& operator[](int i);

	//			Methods:

	void print()const;
};

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//			Constructors:

String::String(int size) :size(size), str(new char[size] {})
{
	cout << "DefConstructor:\t\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}

//			Operators:

String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	delete[] str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//			Methods:

void String::print()const
{
	cout << "SIZE: " << size << endl;
	cout << "STR: " << str << endl;
}

String   operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

#define HOME_WORK
//#define CONSTRUCTORS_CALLING


void main()
{
	setlocale(LC_ALL, "");

#ifdef HOME_WORK
	String str1 = "Hello";
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	String str3 = str1 + str2;

	//String str3;
	//str3 = str1 + str2;
	cout << str3 << endl;

	String str5 = str2;
	cout << str5 << endl;

#endif // HOME_WORK

#ifdef CONSTRUCTORS_CALLING
	String str1;
	str1.print();

	String str2{ "Привет" };
	str2.print();
#endif // CONSTRUCTORS_CALLING


}