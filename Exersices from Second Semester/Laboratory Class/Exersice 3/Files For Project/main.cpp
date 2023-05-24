#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <fstream>
#include "student.h"
using namespace std;


ostream &operator<<(ostream &,student &);
ostream &operator<<(ostream &,subject &);

void delete_help_arr(char **);
void make_help_arr(char *&, const char *);

void increase_semester(student &,student &, student &);
void decrease_semester(student &,student &, student &);
void semester_after_exams(student &,student &,student &);
void compare_students_semester(student &,student &,student &,student &,ostream &);

//����������� ��� ��� �������� ���������

void make_subj_array(vector<subject>&);
void process_subj_array(vector <subject>&,ostream &);





int main(void)
{ 
	int m;
	string choice;
	bool t = false;
	char* help_arr = NULL;
	unsigned int hours1 = 0,hours2 = 0,hours3 = 0;
	
	system("chcp 1253");
	cout <<"----------------------" << endl;
	
	//���������� ��������� ���������
	
	vector<subject> arr_subj;
    make_subj_array(arr_subj);
    
    cout << "��������� ���������" << endl;
    cout << "-----------------------------------------------------" << endl;
	
	for(int i= 0;i< arr_subj.size();i++)
	{
		cout << i+1 << ")"  << arr_subj[i];
	}
	
	
	cout << "�� ������ �� ���������� ������ ������ ��� ��������� �� ������ ��� ��� �������� ���������;(���/���)" << endl;
	cin >> choice;
	while(choice != "���" && choice != "���")
	{
		cout << "���������� ����� (��� � ���)" << endl;
		cin >> choice;
	}
	
	while(choice == "���")
	{
		t = true;
		process_subj_array(arr_subj,cout);
		cout << "�� ������ �� �������������� ������ ������ ��� ��������� �� ������ ��� ��� �������� ���������;(���/���)" << endl;
		cin >> choice;
		while(choice != "���" && choice != "���")
			{
				cout << "���������� ����� (��� � ���)" << endl;
				cin >> choice;
			}		
	}
	
	if(t == true)
	{
		cout<< endl << endl << endl << endl << "����������� ��������� ���������" << endl;
		for(int i=0;i< arr_subj.size();i++)
		{
			cout<< i << ")" << arr_subj[i];
		}
	}
	
    //���������� �������� ���� constructors, accessors ��� copy constructors.

	cout<< endl << endl << endl<< endl <<"������ �������" << endl;
	cout<<"----------------" << endl;
    cout<< "���������� ��������"<< endl;
    cout << "-------------------" << endl << endl << endl << endl;
    cout << "|-------------------------|" << endl;
    cout << "|���������� ������ �������|" << endl;
	cout << "|-------------------------|" << endl;

	//���������� ������ �������

    make_help_arr(help_arr,"22390174");

    student panagiotis(help_arr,"������������� ����������");
    cout << panagiotis;
    
    if(panagiotis.get_student_semester() > 1)
	{
		do{
			m =	panagiotis.passed_subj(arr_subj,cout);
		}while(m != 0);
	}
    
    while(1)
	{
		int subj;
		cout << "��� �� �������� ������ ������ ����� ��� ��������;(���/���)" << endl;
		cin >> choice;
		while(choice != "���" && choice != "���")
		{
			cout << "���������� ����� (��� � ���)" << endl;
			cin >> choice;
		}
    	if(choice == "���")
		{
			break;
		}
		else
		{
			subj = panagiotis.sign_subj(arr_subj,cout);
		} 
		
		// ��������� �� ��� ����� �� ������� ������ ������

		
		if(subj == -2)
		{
			break;
		}
		
			//��� ����� ��� ���� �� ���� ��� �����������
		
		if(subj != -1)
		{
			panagiotis += arr_subj[subj];
			hours2 += arr_subj[subj].get_subject_hours();
		}
		if(hours2 > 38)
		{
			cout << "��� ������� �� �������� ��� 38 ����" << endl;
			break;
		}
	}
	
	cout << "������� ��� ������� " << panagiotis.get_student_name() << endl;
	cout << panagiotis;
	
	cout<< endl<< endl << endl << "|---------------------------|" << endl;
    cout << "|���������� �������� �������|" << endl;
	cout << "|---------------------------|" << endl;
    
    
    
    make_help_arr(help_arr,"22390052");
    
    student xarhs(help_arr,"����� ��������",2);
    cout << xarhs;
    
	if(xarhs.get_student_semester() > 1)
	{
		do{
			m =	xarhs.passed_subj(arr_subj,cout);
		}while(m != 0);
	}	
	
	
	while(1)
	{ 
		int subj;
		cout << "��� �� �������� ������ ������ ����� ��� ��������;(���/���)" << endl;
		cin >> choice;
		while(choice != "���" && choice != "���")
		{
			cout << "���������� ����� (��� � ���)" << endl;
			cin >> choice;
		}
    	if(choice == "���")
		{
			break;
		}
		else
		{
			subj = xarhs.sign_subj(arr_subj,cout);
		} 
		
		// ��������� �� ��� ����� �� ������� ������ ������
		
		if(subj == -2)
		{
			break;
		}
		
		//��� ����� ��� ���� �� ���� ��� �����������
		
		if(subj != -1)
		{
			xarhs += arr_subj[subj];
			hours1 += arr_subj[subj].get_subject_hours();
		}
		if(hours1 > 38)
		{
			cout << "��� ������� �� �������� ��� 38 ����" << endl;
			break;
		}	
	} 
	
	cout << "������� ��� ������� " << xarhs.get_student_name() << endl;
	cout << xarhs;
   
       
    //���������� ������ �������.   
       
    cout<< endl<< endl << endl << "|-------------------------|" << endl;
    cout << "|���������� ������ �������|" << endl;
	cout << "|-------------------------|" << endl;
	
    student nefeli = panagiotis;
    
    cout<< endl<< endl << endl << "|---------------------------|" << endl;
    cout << "|������ ����� ������ �������|" << endl;
	cout << "|---------------------------|" << endl;
    
    cout << nefeli;
    
    make_help_arr(help_arr,"22390131");
    
    nefeli.set_student_AM(help_arr);
    delete_help_arr(&help_arr);
    nefeli.set_student_name("������ ������������");
    nefeli.set_student_semester(3);
    
    cout<< endl<< endl << endl << "|---------------------------|" << endl;
    cout << "|������ ����� ������ �������|" << endl;
	cout << "|---------------------------|" << endl;
    
    cout << nefeli;
    
    if(nefeli.get_student_semester() > 1)
	{
		do{
			m = nefeli.passed_subj(arr_subj,cout);
		}while(m != 0);
	}
    
    while(1)
	{
		int subj;
		
		cout << "��� �� �������� ������ ������ ����� ��� ��������;(���/���)" << endl;
		cin >> choice;
		while(choice != "���" && choice != "���")
		{
			cout << "���������� ����� (��� � ���)" << endl;
			cin >> choice;
		}
    	if(choice == "���")
		{
			break;
		}
		else
		{
			subj = nefeli.sign_subj(arr_subj,cout);
		} 
	
		// ��������� �� ��� ����� �� ������� ������ ������

	
		if(subj == -2)
		{
			break;
		}
		
		//��� ����� ��� ���� �� ���� ��� �����������

		
		if(subj != -1)
		{
			nefeli += arr_subj[subj];
			hours3 += arr_subj[subj].get_subject_hours();
		}
		if(hours3 > 38)
		{
			cout << "��� ������� �� �������� ��� 38 ����" << endl;
			break;
		}
	}
	
	// ����� ������������ =
	
	cout<< endl<< endl << endl << "|---------------------------|" << endl;
    cout << "|���������� �������� �������|" << endl;
	cout << "|---------------------------|" << endl;

	
	make_help_arr(help_arr,"22390092");
	student stauros(help_arr,"������� ������",3);
	stauros = nefeli;
	
	cout << stauros << endl;
	
	compare_students_semester(panagiotis,xarhs,nefeli,stauros,cout );
	
	
	
	
	//���������� ��������� ��������� �� ������ ��������
	
	ofstream outputFile;
	outputFile.open("data.txt");
	if(outputFile.is_open())
	{
		outputFile << "----------------" << endl;
		outputFile << "�������� �������" << endl;
		outputFile << "----------------" << endl;
		
		outputFile << panagiotis << endl;
		outputFile << xarhs << endl;
		outputFile << nefeli << endl;
		outputFile << stauros << endl;
		
		compare_students_semester(panagiotis,xarhs,nefeli,stauros,outputFile );	
	}
	else
	{	
		cout << "Error Opening File" << endl;
		exit(1312);
	}
	return 0;
}


//��������� ������� �������� �� ��� ������� (+=)

void increase_semester(student &panagiotis,student &xarhs, student &nefeli)
{
    panagiotis += 1;
    xarhs += 1;
    nefeli += 1;
}

//��������� ������� �������� (-=)

void decrease_semester(student &panagiotis,student &xarhs, student &nefeli)
{
    panagiotis -= 1;
    xarhs -= 1;
    nefeli -= 1;
}

//��������� ������� �������� (++)

void semester_after_exams(student &panagiotis,student &xarhs,student &nefeli)
{
    panagiotis++;
    xarhs++;
    nefeli++;
}

//����������� ���������� ������

void delete_help_arr(char **help_arr)
{
    delete [] *help_arr;
}

//����������� ���������� ������

void make_help_arr(char *&help_arr,const char *AM)
{
  int len = strlen(AM);
  help_arr = new char [len + 1];
  strcpy (help_arr, AM);
}

//���������� ��������� ���������

void make_subj_array(vector<subject>& vec)
{
    int i;

    string names[] = {"������� �����", "���������� �������", "������������������ ���������������", "C", "����������� ��������� 1", "Assembly", "����� ���������", "������ ��������� 1", "������ ��������� 2",
                      "������", "������ 2", "�������� �������", "�������� ����������", "������� ��� �����������", "������������", "�������������", "����������� ��� ����������",
                      "���������", "������ ��� ���������","�������� ��� ������� ����������" , "������� ���������", "���������� ����������", "���������������� ���������",
                      "������������ ��������� ���������"};
    
    string password[] = {"ICE1-2005", "ICE1-1001", "ICE1-2004", "ICE1-1004", "ICE1-3005", "ICE1-3006", "ICE1-4001", "ICE1-3003", "ICE1-5001",
                         "ICE-3004", "ICE-4002", "ICE1-1002", "ICE-1005", "ICE1-740", "ICE1-7307", "ICE1-6003", "ICE-2002", "ICE1-7207", "ICE1-4006", "ICE1-2001",
                         "ICE1-5004", "CE1-6001", "ICE1-7308", "ICE1-4004"};

    int hours[] = {4, 5, 6, 6, 4, 5, 4, 4, 4, 4, 5, 4, 4, 4, 4, 5, 4, 4, 4, 4, 4, 4, 5, 5};

    bool season[] = {true, false, true, false, false, false, true, false, false, false, true, false, false, true, true, false, true, false, true, true, false, true, true, false};
    
    
    for (i = 0; i < 24; i++)
    {
        subject subj;
        subj.set_subject_lektiko(names[i]);
        subj.set_subject_password(password[i]);
        subj.set_subject_hours(hours[i]);
        subj.set_subject_season(season[i]);
        vec.push_back(subj);
    }
}

//��������� ����������� ��������� ���������

void process_subj_array(vector <subject>& vec,ostream &left) 
{
	string name,password;
	unsigned int hours;
	bool season;
    
	subject k;

    left << "���� ����� ���������: " << endl;
    cin >> name;

    left << "���� ������ ��������: " << endl;
    cin >> password;

    left << "���� ���� ����������� ��� ���������(0-7):" << endl;
    cin >> hours;
    
	while (k.get_subject_hours() < 0 && k.get_subject_hours() > 7) {
        left << "����� ����:�� ���� ����������� ����������� ������(0-7):" << endl;
        cin >> hours;
    }

    left << "���� ������� ���������(0 = ���������, 1 = ������):" << endl;
    cin >> season;
    while(k.get_subject_season() < 0 && k.get_subject_season() > 1)
	{
		left << "����� ����:�� ��������� ��� ��������� ������ �� �����(0 = ��������� ������� � 1 = ������ �������)" << endl;
	}
    
    k.set_subject_hours(hours);
    k.set_subject_lektiko(name);
    k.set_subject_password(password);
    k.set_subject_season(season);

    vec.push_back(k);
} 

void compare_students_semester(student &panagiotis,student &xarhs,student &nefeli,student &stauros,ostream &left)
{
	if(stauros != nefeli)
	{
		left << "�� ������� ��� " << stauros.get_student_name() << " ��� ��� " << nefeli.get_student_name() << " ����� �����������" << endl;
	}
	else
	{
		left << "�� ������� ��� " << stauros.get_student_name() << " ��� ��� " << nefeli.get_student_name() << " ����� ����" << endl;
	}
	
	
	if(panagiotis <= xarhs)
	{
		left << "�� ������� ��� " << panagiotis.get_student_name() << " ����� ��������� � ��� ��� ��� " << xarhs.get_student_name() << endl;
	}
	else
	{
		left << "�� ������� ��� " << panagiotis.get_student_name() << " ����� ���������� ��� ��� " << xarhs.get_student_name() << endl;
	}	
    
    
	if(xarhs == nefeli)
	{
		left << "�� ������� ��� " << xarhs.get_student_name() << " ��� ��� " << nefeli.get_student_name() << " ����� ����" << endl;
	}
	else
	{
		left << "�� ������� ��� " << xarhs.get_student_name() << " ��� ��� " <<  nefeli.get_student_name() << " ����� �����������" << endl;

	}
	
	if(panagiotis < stauros)
	{
		left << "�� ������� ��� " << panagiotis.get_student_name() << " ����� ��������� ��� ��� " << stauros.get_student_name() << endl;
	}
	else
	{
		left << "�� ������� ��� " << panagiotis.get_student_name() << " ����� ���������� � ��� ��� ��� " << stauros.get_student_name() << endl; 	
	}
}





