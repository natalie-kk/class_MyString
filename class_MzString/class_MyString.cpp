
#include <iostream>
#include "myString.h"

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
    myString userLine(userText);
    userLine.Output();
    cout << myString::GetCount() << endl;
    
}



