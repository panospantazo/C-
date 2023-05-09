#include <iostream>
using namespace std;

class man
{
    public:
        friend void good_weather(man &);
        man(int in_mood);
        void report_mood();
    private:
        int mood;
};

void good_weather(man &);

int main(void)
{
    man bob(5);

    bob.report_mood();
    good_weather(bob);
    bob.report_mood();

    return 0;
}

man::man(int in_mood)
{
    mood = in_mood;
}

void man::report_mood()
{
    if(mood < 10)
    {
        cout << "I am okay..." << endl;    
    }
    else
    {
        cout << "I feel good!" << endl;
    }
}

void good_weather(man &ob)
{
    ob.mood += 10;
}