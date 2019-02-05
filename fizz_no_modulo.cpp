#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    int next3=3, next5=5;
    for(i; i <= 100; i++)
    {
        if(i == next3)
        {
            cout << "P";
            next3 += 3;
        }
        if(i == next5)
        {
            cout << "R";
            next5 += 5;
        }
        if(i != next3 && i != next5)
        {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}
