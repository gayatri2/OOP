#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class student
{
public:
	int rollno;
	string name;
	char dob[15];

	bool operator==(const student& student1)
	{
		return(rollno == student1.rollno);
	}
	bool operator<(const student& student1)
	{
		return(rollno < student1.rollno);
	}

	friend ostream& operator << (ostream& out, const student& k);
	friend istream& operator >> (istream& in, student& k);
};

ostream& operator << (ostream& out, const student& k)
{
	out << k.rollno << k.name << k.dob;
	return out;
}

istream& operator >> (istream& in, student& k)
{
	cout << "Enter Roll No : " << endl;
	in >> k.rollno;
	cout << "Enter Name : " << endl;
	in >> k.name;
	cout << "Enter DOB  : " << endl;
	in >> k.dob;
	return in;
}

bool myfunc(const student& k, const student& i2)
{
	return(k.rollno < i2.rollno);
}

vector<student> read()
{
	int n;
	student k;
	vector<student> j;
	cout << "Enter no. of students : " << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		j.push_back(k);
	}
	return j;
}

void printfunction(const student& k)
{
	cout << k.rollno << " " << k.name << " " << k.dob << endl;
}

void print(const vector<student>& j)
{
	cout << "ROLL NO NAME DATE OF BIRTH" << endl;
	for_each(j.begin(), j.end(), printfunction);
}

void insert(vector<student>& j)
{
	student k;
	cin >> k;
	j.push_back(k);
}

void delet(vector<student>& j)
{
	student k;
	cout << "Enter Student Roll No To Delete his data : " << endl;
	cin >> k.rollno;
	vector<student>::iterator p;
	p = find(j.begin(), j.end(), k);
	if (p != j.end())
	{
		j.erase(p);
		cout << "Student record deleted" << endl;
	}
	else
		cout << "Student Not found with given roll no !!" << endl;
}

void search(vector<student>& j)
{
	student k;
	cout << "Enter Student Roll No to Search  : " << endl;
	cin >> k.rollno;
	cout << "ROLL NO NAME DATE OF BIRTH" << endl;
	vector<student>::iterator p;
	p = find(j.begin(), j.end(), k);
	if (p != j.end())
		cout << *p;
	else
		cout << "\nStuden Not found with the given roll no !! ";
}


void sort(vector<student>& j)
{
	sort(j.begin(), j.end(), myfunc);
	cout << "Data sorted successfully." << endl;
}

int main()
{
	vector<student> j;
	int choice;
	do
	{
		cout << "\n-------<< MENU >>---------" << endl;
		cout << "1.Create " << endl;
		cout << "2.Display " << endl;
		cout << "3.Insert  " << endl;
		cout << "4.Delete " << endl;
		cout << "5.Search " << endl;
		cout << "6.Sort" << endl;
		cout << "7.Quit" << endl;
		cout << "Enter your choice : " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:j = read(); break;
		case 2:print(j); break;
		case 3:insert(j); break;
		case 4:delet(j); break;
		case 5:search(j); break;
		case 6:
			sort(j);
			print(j);
			break;
		case 7:cout << "Your choice to EXIT" << endl; break;
		default: cout << "Enter correct choice " << endl;
		}
	} while (choice != 7);
}