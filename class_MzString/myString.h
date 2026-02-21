#pragma once
#include <iostream>

class myString {
	char* userString;
	int userLen;
	static int count;
public:
	myString();
	myString(int userLength);
	myString(const char* userStr);
	~myString();

	char* Input();
	void Output() const;
	void SetLength(int user);
	static int GetCount();
};
