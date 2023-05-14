#include<iostream>
using namespace std;

class String
{
	int size;
	char* str;
public:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Constuctor" << this << endl;
	}
	~String()
	{
		
	}
};

void main()
{
	setlocale(LC_ALL, "");


	cout << "Hello String" << endl;
}