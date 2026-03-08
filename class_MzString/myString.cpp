#include "myString.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
//Розробити клас String, який надалі буде використовуватися для роботи з рядками.
//Клас повинен містити :
//
//Конструктор за замовчуванням, що дозволяє створити рядок довжиною 80 символів;
//Конструктор, що дозволяє створювати рядок довільного розміру;
//Конструктор, який створює рядок та ініціалізує його рядком, отриманим від користувача.
//Необхідно створити деструктор, а також використовувати механізми делегування конструкторів, якщо це можливо.
//Клас має містити методи для введення рядків із клавіатури та виведення рядків на екран.Також потрібно 
//реалізувати статичну функцію - член, яка повертатиме кількість створених об'єктів рядків.
int myString::count = 0;
myString::myString()
{
	userLen = 80;
	userString = new char[userLen];
	strcpy_s(userString, userLen, "Default text in MyString");
	count++;
}

myString::myString(int userLength)
{
	char text[] = "Sized text in MyString";
	userLen = userLength +1 ;
	userString = new char[userLen];
	if (userLength < strlen(text))
		cout << "Too small user buffer suggestet!\n";
	else {
		strcpy_s(userString, userLen, text);
		count++;
	}
	
}

myString::myString(const char* userStr)
{
	userLen = strlen(userStr) + 1;
	userString = new char[userLen];
	strcpy_s(userString, userLen, userStr);
	count++;
}



char* myString::Input()
{
	const int size = 50;
	char userText[size];
	for (int i = 0; (userText[i] != 27)&&(i<size); i++) {
		userText[i] = getchar();
	}
	return userText;
}

void myString::Output() const
{
	cout << userString << endl;
	cout << "The size: " << userLen << endl;
}

myString::~myString()
{
	cout << "Destructor worked!\n";
	delete[] userString;
	userLen = 0;
	count--;
}

myString::myString(const myString& obj)
{
	cout << "Copy construct\n";
	userLen = obj.userLen;
	int size = strlen(obj.userString) + 1;
	userString = new char[size];
	strcpy_s(userString, size, obj.userString);
	count++;
}

myString::myString(myString&& obj)
{
	cout << "Move construct\n";
	userLen = obj.userLen;
	userString = obj.userString;

	obj.userLen = 0;
	obj.userString = nullptr;
	count++;
}

myString& myString::operator=(const myString& obj)
{
	if (this == &obj) 
		return *this;
	delete[] userString;
	cout << "Copy operator=\n";
	userLen = obj.userLen;
	int size = strlen(obj.userString) + 1;
	userString = new char[size];
	strcpy_s(userString, size, obj.userString);
	return *this;
}

myString& myString::operator=(myString&& obj)
{
	if (this == &obj)
		return *this;
	delete[] userString;
	cout << "Move operator=\n";
	userLen = obj.userLen;
	userString = obj.userString;

	obj.userLen = 0;
	obj.userString = nullptr;
	return *this;
}

void myString::SetLength(int user)
{
	userLen = user;
}

int myString::GetCount()
{
	return count;
}

ostream& operator<<(ostream& os, const myString& obj)
{
	os << "UserString: " << obj.userString << endl;
	os << "String's length: " << obj.userLen << endl;
	return os;
}

istream& operator>>(istream& is, myString& obj)
{
	string s;
	cout << "Input your String: ";
	is >> s; 

	delete[] obj.userString;
	obj.userLen = static_cast<int>(s.size()) + 1;
	obj.userString = new char[obj.userLen];
	strcpy_s(obj.userString, obj.userLen, s.c_str());
	return is;
}