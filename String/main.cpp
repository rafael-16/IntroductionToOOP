#include"String.h"



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