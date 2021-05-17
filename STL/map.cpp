#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    string state_name;
    long long population;
    map<string, long long> States;

    while (true)
    {
        int option;
        cout << "\nEnter the operation to be Performed:\n1.Enter Data\n2.Search Data\n3.Display Database\n4.Exit\n>>>";
        cin >> option;
        if (option == 1)
        {
            pair<string, long long> state;
            cout << "Enter the Name of State: ";
            cin >> state_name;
            cout << "Enter the Population of State: ";
            cin >> population;
            state = { state_name, population };
            States.insert(state);
        }
        else if (option == 2)
        {
            cout << "Enter the Name of the State to be Searched: ";
            cin >> state_name;
            cout << "Population of the State is: " << States[state_name] << endl;
        }
        else if (option == 3)
        {
            cout << "Database: \n";
            for (auto it : States)
            {
                cout << "\nNAME: " << it.first << "\tPOPULATION: " << it.second << endl;
            }
        }
        else
        {
            cout << "Program Finished";
            break;
        }
    }
    return 0;
}
