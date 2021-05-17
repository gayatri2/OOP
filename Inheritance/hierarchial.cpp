#include<iostream>
#include<string>
using namespace std;
class publications
{
	string title;
	float price;
public:
	string gettitle()
	{
		cout << endl << "Enter title of publication:";
		cin.ignore();
		getline(cin,title);
		return title;
	}
	float getprice()
	{
		cout << endl << "Enter price per unit:";
		cin >> price;
		return price;
	}
	string showtitle()
	{
		return title;
	}
	float showprice()
	{
		return price;
	}
};
//hierarchial inheritance
class book : public publications
{
	int page_count;
public:
	void getdata1()
	{

		cout << endl << "Enter page count:";
		cin >> page_count;
		publications::gettitle();
		publications::getprice();

	}
	void showdata1()
	{

		cout << "Publication title:" << " " << publications::showtitle() << endl;
		cout << "Price per page:"<< " " << publications::showprice() << endl;
		cout << endl << "Page count:" << " " << page_count << endl;


	}
	void totbook_price()
	{
		cout << "Total price of the book(depends on number of pages): $" << page_count * publications::showprice() << endl;
	}

};
class tape : public publications
{

	float play_time;
public:
	void getdata2()
	{

		cout << endl << "Enter playing time:";
		cin >> play_time;
		publications::gettitle();
		publications::getprice();
	}
	void showdata2()
	{

		cout << "Publication Title:"<< " " << publications::showtitle() << endl;
		cout << "Price per unit:" << " "<< publications::showprice() << endl;
		cout << endl << "Playing time:" << play_time << endl;

	}
	void tottape_price()
	{
		cout << "Total price of the tape(depends on playing time): $" << play_time * publications::showprice() << endl;
		cout << endl;
	}

};
int main()
{
	book* b[20];	//array of pointers
	tape* t[20];
	int n1 = 0; int n2 = 0;
	int ch; char ans; char ans1; char ans2;
	do
	{

		cout << endl << "Menu:\n 1.Input Books 2.Show Books \n 3.Input Tapes \n 4.Show Tapes:";

		cout << endl << "Enter choice:";
		cin >> ch;

		switch (ch)
		{
			case 1:
			{
				cout << endl << "Books:";
				do
				{
					b[n1] = new book;
					b[n1]->getdata1();
					n1++;

					cout << endl << "Want to add more books?(y/n)";
					cin >> ans1;
				} while (ans1 == 'y');



			}break;
			case 2:
			{

				for (int j = 0; j < n1; j++)
				{
					if (b[j] != NULL)
					{
						b[j]->showdata1();
						b[j]->totbook_price();

					}
					else
					{
						cout << endl << "DATABASE OF" << " " << j + 1 << " " << "NOT AVAILABLE!" << endl;
					}


				}


			}break;
			case 3:
			{
				cout << endl << "Tapes:";
				do
				{
					t[n2] = new tape;
					t[n2]->getdata2();
					n2++;

					cout << endl << "Want to add more tapes?(y/n)";
					cin >> ans2;
				} while (ans2 == 'y');

			}break;
			case 4:
			{

				for (int j = 0; j < n2; j++)
				{
					if (b[j] != NULL)
					{
						t[j]->showdata2();
						t[j]->tottape_price();

					}
					else
					{
						cout << endl << "DATABASE OF" << " " << j + 1 << " " << "NOT AVAILABLE!" << endl;
					}


				}



			}break;
			default: cout << endl << "Wrong choice!!!";

		}

		cout << endl << "Enter menu again? (y/n)";
		cin >> ans;
	}while (ans == 'y');

	return 0;
}
