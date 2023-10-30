#include <iostream>
#include <cmath>
using namespace std;

void TrapezoidalMethod(int n , double a, double b );
void SimpsonsRUleOdd(int n, double a, double b);
void SimpsonsRUleEven_4(int n, double a, double b);
void SimpsonsRUleEven(int n, double a, double b);

int integration_program()
{
    double a, b;
    int n;
newData:
    cout << "Enter the numbers of values <n>: ";
here:
    cin >> n;
    if (n < 3)
    {
        cout << endl
             << "Error! --> Enter a valid number of values: ";
        goto here;
    }
in:
    cout << "Enter the first value <a>: ";
    cin >> a;
    cout << "Enter the last value <b>: ";
    cin >> b;
    if (a > b)
    {
        cout << "\nError! --> Must be <<Last value>> greater than <<First value>>\n"
             << endl;
        goto in;
    }

    int Equation = 0;
    do
    {
    there:
        cout << "\n-----Chose number of equation----- " << endl;
        cout << "1- By trapezoidalMethod" << endl;
        cout << "2- By simpsonsRule" << endl;
        cout << "3- By trapezoidalMethod and simpsonsRule" << endl;
        cout << "4- site a new data" << endl;
        cout << "5- Exit" << endl;
        cout << "Enter the number you Choice: ";

        cin >> Equation;
        if (Equation != 5)
        {
            cout << endl
                 << "--------------------------------------------------------" << endl;
        }
        switch (Equation)
        {
        case 1:
            TrapezoidalMethod(n, a, b);
            break;

        case 2:
            if (n % 2 != 0)
            {
                SimpsonsRUleOdd(n, a, b);
            }
            else if (n == 4)
            {
                SimpsonsRUleEven_4(n, a, b);
            }
            else
            {
                SimpsonsRUleEven(n, a, b);
            }
            break;

        case 3:
            TrapezoidalMethod(n, a, b);
            cout << "\n\n----------------------------------------------------------------\n\n";
            if (n % 2 != 0)
            {
                SimpsonsRUleOdd(n, a, b);
            }
            else if (n == 4)
            {
                SimpsonsRUleEven_4(n, a, b);
            }
            else
            {
                SimpsonsRUleEven(n, a, b);
            }
            break;

        case 4:
            goto newData;

        case 5:
            break;
        default:
            cout << "\nError! --> Please enter available equation" << endl;
            cout << "----------------------------------------------\n";
            goto there;
        }
    } while (Equation != 5);

    return 0;
}

void set_x(double x[], int n, double h, double a)
{
    for (int i = 0; i < n; i++)
    {
        x[i] = a;
        a += h;
    }
}

void set_f_x(double x[], double f_x[], int n )
{
    again:
    int choose=0;
    cout<<"\n________choose function________\n"<< endl;
    cout<<"1- f(x)=x^4"<<endl;
    cout<<"2- f(x)=e^(-x^2)"<<endl;
    cout<<"enter function number: ";
    cin>>choose;
    switch(choose)
    {
        case 1:
            for (int i = 0; i < n; i++)
            {
                f_x[i] = pow(x[i], 4);
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                f_x[i] = exp(-1*pow(x[i],2));
            }
            break;
        default:
            cout<<"\nError! --> Enter a valid number\n";
            goto again;
    }

}

void TrapezoidalMethod(int n , double a , double b )
{
    double h = (b - a) / (n - 1); //.25
    double x[n];
    set_x(x, n, h, a);
    double f_x[n];
    set_f_x(x, f_x, n);
    double I = 0;
    double allValuesOfF_x = 0;
    for (int i = 1; i < n - 1; i++)
    {
        allValuesOfF_x += f_x[i];
    }
    I = h / 2 * (f_x[0] + f_x[n - 1] + 2 * allValuesOfF_x);
    cout << endl
         << "_________By Trapezoidal Method_________" << endl
         << endl;
    cout << "I = " << I << endl;
}

void SimpsonsRUleOdd(int n, double a, double b)
{
    double h = (b - a) / (n - 1);
    double x[n];
    set_x(x, n, h, a);
    double f_x[n];
    set_f_x(x, f_x, n);
    double I = 0;
    double ValuesEvenInF_x = 0;
    double ValuesOddInF_x = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (i % 2 == 0)
        {
            ValuesEvenInF_x += f_x[i];
        }
        else
        {
            ValuesOddInF_x += f_x[i];
        }
    }
    I = h / 3 * (f_x[0] + f_x[n - 1] + 4 * ValuesOddInF_x + 2 * ValuesEvenInF_x);
    cout << endl
         << "_________By Simpsons Rule_________" << endl
         << endl;
    cout << "I = " << I << endl;
}

void SimpsonsRUleEven_4(int n, double a, double b)
{
    double h = (b - a) / (n - 1);
    double x[n];
    set_x(x, n, h, a);
    double f_x[n];
    set_f_x(x, f_x, n);
    double I = 0;
    double allValuesOfF_x = 0;
    for (int i = 1; i < n - 1; i++)
    {
        allValuesOfF_x += f_x[i];
    }
    I = h * 3 / 8 * (f_x[0] + f_x[n - 1] + 3 * allValuesOfF_x);
    cout << endl
         << "_________By Simpsons Rule_________" << endl
         << endl;
    cout << "I = " << I << endl;
}

void SimpsonsRUleEven(int n, double a, double b)
{
    double h = (b - a) / (n - 1);
    double x[n];
    set_x(x, n, h, a);
    double f_x[n];
    set_f_x(x, f_x, n);
    double IOdd = 0;
    int LimitIndex = n - 3;
    double ValuesEvenInF_x = 0;
    double ValuesOddInF_x = 0;
    for (int i = 1; i < LimitIndex - 1; i++)
    {
        if (i % 2 == 0)
        {
            ValuesEvenInF_x += f_x[i];
        }
        else
        {
            ValuesOddInF_x += f_x[i];
        }
    }
    IOdd = h / 3 * (f_x[0] + f_x[LimitIndex - 1] + 4 * ValuesOddInF_x + 2 * ValuesEvenInF_x);
    double IEven = 0;
    double allValuesInF_x = 0;
    for (int i = n - 3; i < n - 1; i++)
    {
        allValuesInF_x += f_x[i];
    }
    IEven = h * 3 / 8 * (f_x[n - 4] + f_x[n - 1] + 3 * allValuesInF_x);
    double I = IEven + IOdd;
    cout << endl;
    cout << "_________By Simpsons Rule_________" << endl;
    cout << endl;
    cout << "I = " << I << endl;
}