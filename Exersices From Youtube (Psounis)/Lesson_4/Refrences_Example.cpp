#include <iostream>
using namespace std;

int main(void)
{
    int x = 3;
    int &r = x;

    cout << "x = " << x << " r = " << r << endl;
    
    x = 4;
    cout << "x = " << x  << " r = " << r << endl;

    r = 5;
    cout << "x = " << x << " r = " << r << endl;

    return 0;
}