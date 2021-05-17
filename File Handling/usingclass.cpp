#include<iostream>
#include<fstream>
using namespace std;
class student
{
	char name[20];
	int roll_no;
public:
	void getdata();
	void showdata();
	int getrno()
	{
		return roll_no;
	}
};
void student::getdata()
{
	cout << "Enter name:" << endl;
	//cin.ignore();
	cin >> name;
	cout << "Enter roll no:" << endl;
	cin >> roll_no;
}
void student::showdata()
{
	
	cout << "Name:" << name << endl;
	cout << "Roll no:" << roll_no << endl;
}
int main()
{
	student s; char ans = 'y';
	cout << endl << "Writing into the file:" << endl;
	ofstream fout;
	fout.open("studentdetails.dat", ios::out | ios::binary);
	while (ans == 'y')
	{
		s.getdata();
		fout.write((char*)&s, sizeof(s));

		cout << endl << "Enter more records?" << endl;
		cin >> ans;
	}
	fout.close();

	cout << endl << "Reading from file:" << endl;
	ifstream fin;
	fin.open("studentdetails.dat", ios::in | ios::binary);
	while (fin.read((char*)&s, sizeof(s)))
	{
		s.showdata();
	}
	
	ifstream fin1;
	fin1.open("studentdetails.dat", ios::in | ios::binary);
	int no;
	cout << endl << "Searching from file:" << endl;
	cout <<"Enter the roll no of the student to be searched for:" << endl;
	cin >> no;
	student s1;
	int flag=1;
	while (fin1.read((char*)&s1, sizeof(s)))
	{
		if (no == s1.getrno())
		{
			flag = 1;
			cout << "Record found:" << endl;
			s1.showdata();
			cout << endl;

		}
		else
		{
			flag = 0;
		}
	}
	if (flag == 0)
	{
		cout << "Record not found:" << endl;
	}
	fin.close();

	
	return 0;
}