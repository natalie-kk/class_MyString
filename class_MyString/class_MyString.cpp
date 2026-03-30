// class_MyString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "myString.h"
#include "Array.h"

using namespace std;

int main()
{
    myString me;
    me.Output();
    cout << myString::GetCount() << endl;
    myString me2(25);
    me2.Output();
    cout << myString::GetCount() << endl;
    char userText[] = "Bully";
    char userText2[] = "The king of Queens";
    myString userLine(userText);
    userLine.Output();
    cout << myString::GetCount() << endl;
    myString text(move(userText));
    cout << "Move construct:\n";
    cout << text << endl;
    text = move(userText2);
    cout << text << endl;
    cout << userText << endl;
    cout << userText2 << endl;
    if (userText > userText2)
        cout << "userText > userText2" << endl;
    else if (userText < userText2)
        cout << "userText < userText2" << endl;
    else
        cout << "userText == userText2" << endl;

    userText[0] = 'b';
    cout << userText << endl;
    int size = 5;
    Array<int> arr(size);
    Array<int> arr1(size);
    Array<int> arr2(size);
    cout << "Default array:\n";
    cout << arr;
    cout << "Array #2:\n";
    cout << arr1;
    cout << "Array #3:\n";
    cout << arr2;
    arr = arr1;
    cout << "Operator= (arr=arr1)" << endl;
    cout << "arr: " << arr;
    cout << "Copy(arr3=arr2): ";
    Array arr3(arr2);
    cout << arr3;

    srand(time(NULL));

}



