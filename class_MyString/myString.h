#pragma once
#include <iostream>
using namespace std;
class myString {
	char* userString;
	int userLen;
	static int count;
public:
	myString();
	myString(int userLength);
	myString(const char* userStr);
	~myString();

	myString(const myString& obj);
	myString(myString&& obj);

	myString& operator=(const myString& obj);
	myString& operator=(myString&& obj);

	friend ostream& operator<<(ostream& os, const myString& obj);
	friend istream& operator>>(istream& is, myString& obj);

	char* Input();
	void Output() const;
	void SetLength(int user);
	static int GetCount();

	//new hw methods
	void MyStrcpy(myString& obj);// копирование строк затираем предідущее значение
	int MyFindStr(const char* str) const;// 
	int MyFindChr(char c); // поиск символа в строке(индекс найденного символа, либо -1)
	int MyStrLen();// возвращает длину строки

	myString operator+(const myString& obj) const;
	myString& operator+=(char ch);
	char& operator[](const int& index);
	const char& operator[](int index) const;
	bool operator>(const myString& obj) const;
	bool operator<(const myString& obj) const;
	bool operator==(const myString& obj) const;
	//operator+	Конкатенация  const не Змінює значення строки
	//operator+=	Appends characters to a string.Змінює значення строки
	//operator=	Assigns new character values to the contents of a string.
	//operator[]	Provides a reference to the character with a specified index in a string.
	//operator  >, < , ==

};


