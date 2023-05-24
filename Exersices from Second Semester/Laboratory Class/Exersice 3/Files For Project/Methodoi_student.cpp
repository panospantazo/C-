#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include "student.h"
using namespace std;


student::student(char *in_AM,string in_name)
{
    AM = new char[strlen(in_AM) + 1];
    strcpy(AM,in_AM);
    name = in_name;
    semester = 1;    
}

//Constructor with AM,Name and semester as parametres

student::student(char *in_AM,string in_name,int in_semester)
{
    AM = new char[strlen(in_AM) + 1];
    strcpy(AM,in_AM);
    name = in_name;
    semester = in_semester;
}

//Copy Constructor

student::student(const student &in_student)
{
    AM = new char [strlen(in_student.AM + 1)];
    strcpy(AM,in_student.AM);
    name = in_student.name;
    semester = in_student.semester;
}

//Semester getter

unsigned int student::get_student_semester()
{
    return semester;
}

//Name getter

string student::get_student_name()
{
    return name;
}

//AM getter

const char* student::get_student_AM()
{
    return AM;
}

//Destructor

student::~student()
{
    delete [] AM;
}

//Setter of student's semester

void student::set_student_semester(int in_semester)
{
    semester = in_semester;
}

//Setter of student's name

void student::set_student_name(string in_name)
{
    name = in_name;
}

//Setter of AM

void student::set_student_AM(char * in_AM)
{
    if(AM != NULL)
    {
        delete [] AM;
    }

    AM = new char [strlen(in_AM) + 1];
    if(!AM)
    {
        cout << "�������� ��������� ������" << endl;
        exit(1312);
    }
    strcpy(AM,in_AM);
}

//Overloading +=

student &student::operator+=(const int right)
{
    semester = semester + right;
    return *this;
}

//Overloading -=

student &student::operator-=(const int right)
{
    semester = semester - right;
    return *this;
}

//Overloading ++

student &student::operator++(const int b) 
{
    semester = semester + 1;
    return *this;
}

//Overloading <<

ostream &operator<<(ostream &left, student &right) {
    int i;
    float sum = 0;
    
    left << endl << endl<<"� �����: " << right.get_student_name() <<" "<< "��: " << right.get_student_AM() <<" "<< "�������: " << right.get_student_semester() <<" "<< endl << endl;

    left << "|--------------------|" << endl;
    left << "|YOUR CURRENT CLASSES|" << endl;
    left << "|--------------------|" << endl;
    for (i = 0; i < right.classes.size(); i++) 
    {
        left << "Your " << i + 1 << "st class is: " << right.classes[i].get_subject_lektiko() << endl << endl;
    }

    left << endl << "|------------------|" << endl;
    left << "|THE PASSED CLASSES|" << endl;
    left << "|------------------|" << endl;
    
    for (i = 0; i <right.grades.size(); i++) 
    {
        left << "You passed " << right.classes_passed[i].get_subject_lektiko() << " class with grade " << right.grades[i] << endl << endl;
    }

    left << endl << "|------------------|" << endl;
    left << "|YOUR AVERAGE GRADE|" << endl;
    left << "|------------------|" << endl;
    
    for (i = 0; i <right.grades.size(); i++) 
    {
       sum += right.grades[i];
    }
    if(sum == 0)
    {
         left << endl <<"You haven't passed any subject yet" << endl;
         left << "-------------------------------------" << endl;
    }
    else
    {
        left << endl <<"Your average grade is " << roundNumber(sum/right.grades.size()) << endl;
        left << "--------------------------------------" << endl;
    }

    return left;
}

student &student::operator+=(subject &right)
{	
    this->classes.push_back(right);

    return *this;
}

int student::sign_subj(vector<subject>& vec, ostream& left)
{
    int i, lesson = -1;
    string sub_name,choice;
    bool toggle = false, F = false, K = false;
    


    left << "���� �� ������ ��� ��� �� ��������: ";

    cin.ignore();
    getline(cin, sub_name);
    
    
	for (i = 0; i < vec.size(); i++)
    {
        if (sub_name == vec[i].get_subject_lektiko())
        {
            lesson = i;
            toggle = true;
            break;
        }
    }
    
	if(!toggle)
	{
		left << endl<< "��� ������� �� ������ ��� ������� ���� �������� ��� ���������" << endl;
        return -1;
	}
    
	if(vec[lesson].get_subject_season() == false)
	{
		cout <<  endl <<"������� �� ��������� ���� �������� ������� ��������" << endl;
		return -1;
	}
    

    if (toggle)
    {
		for (i = 0; i < this->classes.size(); i++)
        {
            if (this->classes[i].get_subject_lektiko() == sub_name)
        	{
                F = true;
                break;
    		}
        }
        if (F)
        {
            left << endl <<"����� ��� ������� ��� ������������ ������" << endl;
            return -1;
        }

        for (i = 0; i < this->classes_passed.size(); i++)
        {
            if (this->classes_passed[i].get_subject_lektiko() == sub_name)
            {
                K = true;
                break;
        	}
        }
        if (K)
        {
            left << endl <<"����� ��� ������� �� ������������ ������" << endl;
            return -1;
        }
    }
   
    
    if (K == false && F == false)
    {
    	return lesson;
    }
    else
	{
    	return -1;	
	}
}

student& student::operator=(const student& right)
{
    if (this == &right) 
	{
        return *this;
    }

    semester = right.semester;

    grades = right.grades;

    classes_passed = right.classes_passed;

    classes = right.classes;

    return *this;
}

int student::passed_subj(vector <subject>& vec,ostream & left)
{
	int i,lesson;
	float grade = 0.0;
	string sub_name;
	bool toggle,K;
	
	while(1)
	{
		string choice2;
		choice2 = " ";
		
		left << endl <<"����� ������� ������ ������;(���/���)" << endl;
		cin >> choice2;
		while(choice2 != "���" && choice2 != "���")
		{
			cout << "���������� ����� (��� � ���)" << endl;
			cin >> choice2;
		}
		if(choice2 == "���")
		{
			break;
		}
		
		cout << "���� ������ ����� �������; " << endl; 
		cin.ignore();
		getline(cin, sub_name);
    
    
		for (i = 0; i < vec.size(); i++)
    	{
        	if (sub_name == vec[i].get_subject_lektiko())
        	{
            	lesson = i;
            	toggle = true;
            	break;
        	}
    	}
    	if(toggle == false)
		{
			left << endl <<"��� ������� �� ������ ��� ������� ���� �������� ��� ���������" << endl;
        	return -1;
		}
    
   
        for (i = 0; i < this->classes_passed.size(); i++)
        {
            if (this->classes_passed[i].get_subject_lektiko() == sub_name)
            {
                K = true;
                break;
        	}
        }
        if (K)
        {
            left << endl <<"����� ��� ������� �� ������������ ������!" << endl;
        }
        
        
        
		if(K == false && toggle == true)
		{
			left << endl << "�� �� ����� ������� �� " << vec[lesson].get_subject_lektiko() << ": " << endl;
			cin >> grade;
			if(grade >= 5)
			{
				grades.push_back(grade);
				classes_passed.push_back(vec[lesson]);
			}
			else if(grade >= 0)
			{
				left << endl <<"����� ����� ��� ������ " << vec[lesson].get_subject_lektiko() << endl;
				return -1;
			}
			else
			{
				left << endl << "��� ������� �� ������� �������� ����������" << endl;
				return -1;
			}	
		}
    }
    return 0;
}

bool student::operator==(const student &right)
{
	return this->semester == right.semester;
}

bool student::operator!=(const student &right)
{
	return this->semester != right.semester;
}

bool student::operator>=(const student &right)
{
	return this->semester >= right.semester;
}

bool student::operator<=(const student &right)
{
	return this->semester <= right.semester;
}

bool student::operator>(const student &right)
{
	return this->semester > right.semester;
}

bool student::operator<(const student &right)
{
	return this->semester < right.semester;
}


float roundNumber(float num) 
{
    float roundedNum = floor(num); 
    float decimalPart = num - roundedNum; 
    
    if (decimalPart > 0.35 && decimalPart < 0.8) 
	{
        roundedNum += 0.5; 
    } else if (decimalPart >= 0.8) 
	{
        roundedNum += 1.0;
    }
    
    return roundedNum;
}



