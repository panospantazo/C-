#include <string>
#include <iostream>
#include "subject.h"
using namespace std;

void subject::set_subject_password(string new_password)
{
    password = new_password;
}
        
        
void subject::set_subject_lektiko(string new_lektiko)
{
    lektiko = new_lektiko;
}
        
        
void subject::set_subject_hours(unsigned int new_hours)
{
    hours = new_hours;
}
        
        
void subject::set_subject_season(bool new_season)
{
    season = new_season;
}



//Getters

string subject::get_subject_password() const
{
    return password;
}
        
string subject::get_subject_lektiko() const
{
    return lektiko;
}
        
unsigned int subject::get_subject_hours() const
{
    return hours;
}
        
bool subject::get_subject_season() const
{
    return season;
}

ostream &operator<<(ostream &left, subject &right)
{
    left << "����� ���������: " << right.get_subject_lektiko() << endl;
    left << "�������: " << right.get_subject_password() << endl;
    left << "���� �����������: " << right.get_subject_hours() << endl;
    if (right.get_subject_season())
    {
        left << "�������: ������" << endl;
    }
    else
    {
        left << "Season: ���������" << endl;
    }
    cout << "-----------------------------------------------------"<< endl;
    return left;
}



