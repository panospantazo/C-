#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s("0123456789");
    string f("345");

    s += s;

    cout << "str- find-345c:pos: " << s.find("345") << endl;
    cout << "str-  find-345-c:pos: " << s.find(f) << endl;
    cout << "str-  find-1c: pos: " << s.find('1') << endl;
    cout << "str-  rfind-345 : pos: " << s.rfind("345") << endl;
    cout << "str-firstof-345 : pos: " << s.find_first_of("345") << endl;
    cout << "str-lastof-345:  pos: " << s.find_last_of("345") << endl;

    return 0;
}