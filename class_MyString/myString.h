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
};


