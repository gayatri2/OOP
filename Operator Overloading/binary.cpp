

#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imaginary;
public:

    Complex() {
        real = 0.0;
        imaginary = 0.0;
    }
    Complex operator + (Complex const& c)
    {
        Complex ans;
        ans.real = real + c.real;
        ans.imaginary = imaginary + c.imaginary;
        return ans;
    }
    Complex operator * (Complex const& obj)
    {
        Complex ans1;
        ans1.real = real * (obj.real) - imaginary * (obj.imaginary);
        ans1.imaginary = real * (obj.imaginary) + imaginary * (obj.real);
        return ans1;
    }

    friend ostream& operator<<(ostream& output, const Complex& c) {
        if (c.imaginary >= 0)
        {
            output << c.real << "+" << c.imaginary << "i" << endl;
            return output;

        }
        else
        {
            output << c.real << c.imaginary << "i" << endl;
            return output;
        }

    }

    friend istream& operator>>(istream& input, Complex& c) {
        cout << endl << "Enter real and imaginary numbers:";
        input >> c.real >> c.imaginary;
        return input;
    }
};

int main() {
    Complex c1;
    Complex c2;
    cin >> c1;
    cin >> c2;
    cout << c1;
    cout << c2;
    char ans;
    int flag;
    do
    {
        cout << endl << "Menu:";
        cout << endl << "1.Addition:";
        cout << endl << "2.Multiplication:";
        cout << endl << "Enter choice:";
        cin >> flag;
        switch (flag)
        {
        case 1:
        {
            Complex c3 = c1 + c2;
            cout << endl << "Addition of the two numbers:" << c3;

        }break;
        case 2:
        {
            Complex c4 = c1 * c2;
            cout << endl << "Multiplication of the two numbers:" << c4;
        }break;
        default: cout << endl << "Wrong choice!";
        }
        cout << endl << "Enter again? (y/n)";
        cin >> ans;
    } while (ans == 'y');





    return 0;
}
