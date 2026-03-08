
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
    char userText[]  = "Bully";
    char userText2[] = "The king of Queens";
    myString userLine(userText);
    userLine.Output();
    cout << myString::GetCount() << endl;
    myString text(move(userText));
    cout << "Move construct:\n";
    cout << text << endl;
    text = move(userText2);
    cout << text << endl;
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
    cout << "Operator= (arr=arr1)" << endl;
    cout << "arr: " << arr;
    cout << "Copy(arr3=arr2): ";
    Array arr3(arr2);

    srand(time(NULL));

}



