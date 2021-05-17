#include<iostream>
#include<string>
using namespace std;
class student
{
	float roll_no;
	string name, Class, division, dob, bloodg, address;
	float license_no;
	float telephone_no;

	static int count;
public:
	inline void getdata()
	{
		cout << endl << "Enter roll no:";
		cin >> roll_no;
		cout << endl << "Enter name:";
		cin.ignore();
		getline(cin, name);
		cout << endl << "Enter class:";
		getline(cin, Class);
		cout << endl << "Enter division:";
		getline(cin, division);
		cout << endl << "Enter dob:";
		getline(cin, dob);
		cout << endl << "Enter blood group:";
		getline(cin, bloodg);
		cout << endl << "Enter address:";
		getline(cin, address);
		cout << endl << "Enter license number:";
		cin >> license_no;
		cout << endl << "Enter telephone number:";
		cin >> telephone_no;

	}
	inline void showdata()
	{
		cout << roll_no << "\t" << name << "\t" << Class << "\t" << division << "\t" << dob << "\t" << bloodg << "\t" << address << "\t" << license_no << "\t" << telephone_no << endl;
	}

	inline void update_name()
	{
		string new_name;
		cout << endl << "Enter the new name:";
		cin.ignore();
		getline(cin, new_name);
		name = new_name;

	}
	inline void update_class()
	{
		string new_class;
		cout << endl << "Enter the new class:";
		cin.ignore();
		getline(cin,new_class);
		Class = new_class;

	}
	inline void update_div()
	{
		string new_div;
		cout << endl << "Enter the new division:";
		cin.ignore();
		getline(cin,new_div);
		division = new_div;

	}
	inline void update_dob()
	{
		string new_dob;
		cout << endl << "Enter the new date of birth:";
		cin.ignore();
		getline(cin,new_dob);
		dob=new_dob;

	}
	inline void update_bg()
	{
		string new_bg;
		cout << endl << "Enter the new blood group:";
		cin.ignore();
		getline(cin,new_bg);
		bloodg = new_bg;

	}
	inline void update_address()
	{
		string new_address;
		cout << endl << "Enter the new address:";
		cin.ignore();
		getline(cin,new_address);
		address = new_address;

	}
	inline void update_lic()
	{
		float new_license;
		cout << endl << "Enter the new license number:";
		cin >> new_license;
		license_no = new_license;

	}
	inline void update_tele()
	{
		float new_tele;
		cout << endl << "Enter the new telephone number:";
		cin >> new_tele;
		telephone_no = new_tele;

	}
	student()
	{
		count += 1;
		cout << "Default constructor called:" << endl;
		roll_no = 0;
		name = "NULL";
		Class = "NULL";
		division = "NULL";
		dob = "NULL";
		bloodg = "NULL";
		address = "NULL";
		license_no = 0;
		telephone_no = 0;

		cout << "Roll no :" << roll_no << endl;
		cout << "Name:" << name << endl;
		cout << "Class:" << Class << endl;
		cout << "Division:" << division << endl;
		cout << "DOB:" << dob << endl;
		cout << "Blood group:" << bloodg << endl;
		cout << "Address:" << address << endl;
		cout << "License number:" << license_no << endl;
		cout << "Telephone number:" << telephone_no << endl;

	}
	student(float rno, string n, string c, string d, string dob, string bg, string ad, float lno, float tno)
	{
		count += 1;
		cout << "Parameterized constructor called:" << endl;
		roll_no = rno;
		name = n;
		Class = c;
		division = d;
		dob = dob;
		bloodg = bg;
		address = ad;
		license_no = lno;
		telephone_no = tno;

		cout << "Roll no:" << rno << endl;
		cout << "Name:" << n << endl;
		cout << "Class:" << c << endl;
		cout << "Division:" << d << endl;
		cout << "Dob:" << dob << endl;
		cout << "Blood group:" << bg << endl;
		cout << "Address:" << ad << endl;
		cout << "License number:" << lno << endl;
		cout << "Telephone number:" << tno << endl;

	}
	student(const student& p)
	{
		count += 1;
		cout << "Copy constructor called:" << endl;
		roll_no = p.roll_no;
		name = p.name;
		Class = p.Class;
		division = p.division;
		dob = p.dob;
		bloodg = p.bloodg;
		address = p.address;
		license_no = p.license_no;
		telephone_no = p.telephone_no;

		cout << "Roll no:" << roll_no << endl;
		cout << "Name:" << name << endl;
		cout << "Class:" << Class << endl;
		cout << "Division:" << division << endl;
		cout << "Dob:" << dob << endl;
		cout << "Blood group:" << bloodg << endl;
		cout << "Address:" << address << endl;
		cout << "License number:" << license_no << endl;
		cout << "Telephone number:" << telephone_no << endl;
	}
	~student()
	{

		count -= 1;
		cout << endl << "Destructor called:";

	}
	static void countf()
	{
		cout << endl << "Number of objects created:" << count;
	}
	int getrno()
	{
		return roll_no;
	}

	friend class teacher;

};
class teacher
{
public:
	int teach(student& obj, int x)
	{
		obj.roll_no = x;
		obj.showdata();
		return 0;
	}
};
int student::count = 0;
int main()
{

	student* s[30];
	int n = 0; char ans1;

	int choice;  char ans;
	do
	{
		cout << endl << "Menu: \n 1.Default constructor \n 2.Parameterized constructor \n 3.Copy constructor\n 4.Friend Class\n 5.Add student\n 6.Display all students\n 7.Search for a specific students \n 8.Delete a specific student\n 9.Delete all students\n 10.Update\n 11.Quit:";
		cout << endl << "Enter choice:";
		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				student s; //calls default constructor

			}break;
			case 2:
			{
				student s1(2.0, "abc", "fe", "a", "01/01", "a+", "pune", 1234.0, 321.0);			//calls parameterized constructor
			}break;
			case 3:
			{
				student s;
				student s2 = s;				//calls copy constructor
			}break;
			case 4:
			{
				student s;
				teacher t;
				t.teach(s, 14);
			}break;
			case 5:
			{
				do
				{
					s[n] = new student;
					s[n]->getdata();
					n++;

					cout << endl << "Want to add more students?(y/n)";
					cin >> ans1;
				} while (ans1 == 'y');
			}break;
			case 6:
			{

				for (int j = 0; j < n; j++)
				{
					if (s[j] != NULL)
					{
						s[j]->showdata();

					}
					else
					{
						cout << endl << "DATABASE OF" << " " << j + 1 << " " << "HAS BEEN DELETED!" << endl;
					}


				}
			}break;
			case 7:
			{
				int sno; char ans2;
				do
				{

					cout << endl << "Enter the roll number of the student to be searched:";
					cin >> sno;
					for (int i = 0; i < n; i++)
					{
						if (s[i]->getrno() == sno)
						{
							s[i]->showdata();
						}
					}

					cout << endl << "Want to search for more students?(y/n)";
					cin >> ans2;
				} while (ans2 == 'y');

			}break;
			case 8:
			{
				int rno; char ans3;
				do
				{
					cout << endl << "Enter roll no of the student to be deleted:";
					cin >> rno;
					for (int k = 0; k < n; k++)
					{
						if (s[k]->getrno() == rno)
						{
							delete s[k];
							s[k] = NULL;
						}
					}
					cout << endl << "Want to delete more students?(y/n)";
					cin >> ans3;
				} while (ans3 == 'y');

			}break;
			case 9:
			{
				for (int p = 0; p < n; p++)
				{
					delete s[p];
					s[p] = NULL;
				}

			}break;
			case 10:
			{
				char ans4; int sno1; int ch;
				cout << endl << "Update:";
				do
				{

					cout << endl << "Menu:\n 1.Name\n 2.Class\n 3.Division\n 4.Date of birth\n 5.Blood Group\n 6.Address\n 7.License Number\n 8.Telephone Number:" << endl;
					cout << endl << "Enter the choice:";
					cin >> ch;
					switch (ch)
					{

						case 1:
						{
							cout << endl << "Enter the roll number of the student whose name is to be updated:";
							cin >> sno1;

							for (int i = 0; i < n; i++)
							{
								if (s[i]->getrno() == sno1)
								{
									s[i]->update_name();
								}
							}
						}break;
						case 2:
						{
							cout << endl << "Enter the roll number of the student whose class is to be updated:";
							cin >> sno1;

							for (int i = 0; i < n; i++)
							{
								if (s[i]->getrno() == sno1)
								{
									s[i]->update_class();
								}
							}
						}break;
						case 3:
						{
							cout << endl << "Enter the roll number of the student whose division is to be updated:";
							cin >> sno1;

							for (int i = 0; i < n; i++)
							{
								if (s[i]->getrno() == sno1)
								{
									s[i]->update_div();
								}
							}
						}break;
						case 4:
						{
							cout << endl << "Enter the roll number of the student whose dob is to be updated:";
							cin >> sno1;

							for (int i = 0; i < n; i++)
							{
								if (s[i]->getrno() == sno1)
								{
									s[i]->update_dob();
								}
							}
						}break;
						case 5:
						{
							cout << endl << "Enter the roll number of the student whose blood group is to be updated:";
							cin >> sno1;

							for (int i = 0; i < n; i++)
							{
								if (s[i]->getrno() == sno1)
								{
									s[i]->update_bg();
								}
							}
						}break;
						case 6:
						{
							cout << endl << "Enter the roll number of the student whose address is to be updated:";
							cin >> sno1;

							for (int i = 0; i < n; i++)
							{
								if (s[i]->getrno() == sno1)
								{
									s[i]->update_address();
								}
							}
						}break;
						case 7:
						{
							cout << endl << "Enter the roll number of the student whose license no is to be updated:";
							cin >> sno1;

							for (int i = 0; i < n; i++)
							{
								if (s[i]->getrno() == sno1)
								{
									s[i]->update_lic();
								}
							}
						}break;
						case 8:
						{
							cout << endl << "Enter the roll number of the student whose telephone no is to be updated:";
							cin >> sno1;

							for (int i = 0; i < n; i++)
							{
								if (s[i]->getrno() == sno1)
								{
									s[i]->update_tele();
								}
							}
						}break;

					}

					cout << endl << "Want to update more students?(y/n)";
					cin >> ans4;
				} while (ans4 == 'y');



			}
			case 11:
			{
				break;
			}break;
			default:
				cout << endl << "Wrong choice!!!";

		}


		student::countf(); //counts the number of objects

		cout << endl << "Enter menu again?(y/n)";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}
