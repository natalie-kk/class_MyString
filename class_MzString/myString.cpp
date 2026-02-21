#include "myString.h"
#include <cstring>
#include <iostream>
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

void myString::SetLength(int user)
{
	userLen = user;
}

int myString::GetCount()
{
	return count;
}
