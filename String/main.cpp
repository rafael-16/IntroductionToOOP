#include<iostream>

using namespace std;

class String
{
	int size;
	char* str;
public:
	//			Getters:
	int get_size()const
	{
		return size;
	}
	char* get_str()const
	{
		return str;
	}
	//			Setters:
	void set_size(int size)
	{
		this->size = size;
	}
	void set_str(char* str)
	{
		this->str = str;
	}
	//			Constructors:

	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size + 1] {};
		cout << "Constructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
			this->str[i] = str[i];
		this->str[size] = '\0';
		cout << "1WordConstructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size+1];
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		str[size] = '\0';
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Operators:

	String& operator=(const String& others)
	{
		this->size = others.size;
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
			this->str[i] = others.str[i];
		this->str[size] = '\0';
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//			Methods:

	void print()const
	{
		cout << "size: " << size << endl;
		cout << "str: " << str << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	os << obj.get_str();
	return os;
}

String operator+(String left, String right)
{
	int new_size = left.get_size() + right.get_size();
	char* new_str = new char[new_size + 1];
	new_str[new_size] = '\0';
	for (int i = 0; left.get_str()[i] != '\0'; i++)
	{
		new_str[i] = left.get_str()[i];
	}
	for (int i = 0; right.get_str()[i] != '\0'; i++)
	{
		new_str[left.get_size() + i] = right.get_str()[i];
	}

	return new_str;
}

//#define HOME_WORK

void main()
{
	setlocale(LC_ALL, "");

	//cout << "Hello, String!" << endl;
	//String str;
	//str.print();


#ifdef HOME_WORK
	String str1 = "Hello";
	cout << "str1: " << str1 << endl;

	String str2 = "World";
	cout << "str2: " << str2 << endl;

	String str3 = str1 + str2;
	cout << "str3: " << str3 << endl;

#endif // HOME_WORK
	String str = "Hello";

}