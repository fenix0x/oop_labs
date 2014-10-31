#include "stdafx.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[]) 
{
    int i;
    for (i = 100; i > 0; i -= 2) 
	{
        cout << i;
        if (i != 2) 
		{
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}