// بسم الله
#include <iostream>
#include <sstream>
#include <cmath>
#include <numeric>

#include "../libs/getlib.h"

void fill_arr(float arr[], int size);
double sum_arr(float arr[], int size);
double sum_arr2(float arr[], int size);
double sum_arr3(float arr[], int size);
double sum_arr4(float arr[], int size);
double sum_arr_mul_arr(float arr1[], float arr2[], int size);
double sum__arr2_mul_arr(float arr1[], float arr2[], int size);
double sum_ln_arr(float arr[], int size);
double sum_arr_mul_ln_arr(float arr1[], float arr2[], int size);
double sum_ln_arr_mul_ln_arr(float arr1[], float arr2[], int size);
double sum_ln_arr2(float arr[], int size);

void equation1(float arr1[], float arr2[], int size);
void equation2(float arr1[], float arr2[], int size);
void equation3(float arr1[], float arr2[], int size);
void equation4(float arr1[], float arr2[], int size);

using namespace std;


void fill_arr(float arr[], int size)
{
    ostringstream sosa;
    for (int i=0; i<size; i++)
    {
        sosa << i+1;
        // cout << "no." << i+1 << " = ";
        arr[i] = get_float("no."+sosa.str() + " = ");
        sosa.str("");
        sosa.clear();
        // cin >> arr[i];
    }
}

double sum_arr(float arr[], int size)
{
    double sum = 0;
    for (int i=0; i<size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

double sum_arr2(float arr[], int size)
{
    double sum = 0;
    for (int i=0; i<size; i++)
    {
        sum += arr[i]*arr[i];
    }
    return sum;
}

double sum_arr3(float arr[], int size)
{
    double sum = 0;
    for (int i=0; i<size; i++)
    {
        sum += arr[i]*arr[i]*arr[i];
    }
    return sum;
}

double sum_arr4(float arr[], int size)
{
    double sum = 0;
    for (int i=0; i<size; i++)
    {
        sum += arr[i]*arr[i]*arr[i]*arr[i];
    }
    return sum;
}

double sum_arr_mul_arr(float arr1[], float arr2[], int size)
{
    double sum = 0;
    for (int i=0; i<size; i++)
    {
        sum += arr1[i] * arr2[i];
    }
    return sum;
}

double sum__arr2_mul_arr(float arr1[], float arr2[], int size)
{
    double sum = 0;
    for (int i=0; i<size; i++)
    {
        sum += arr1[i] * arr1[i] * arr2[i];
    }
    return sum;
}

double sum_ln_arr(float arr[], int size)
{
    double sum = 0;
    for (int i=0; i<size; i++)
    {
        sum += log(arr[i]);
    }
    return sum;
}

double sum_arr_mul_ln_arr(float arr1[], float arr2[], int size)
{
    double sum = 0;
    for (int i=0; i<size; i++)
    {
        sum += arr1[i] * log(arr2[i]);
    }
    return sum;
}

double sum_ln_arr_mul_ln_arr(float arr1[], float arr2[], int size)
{
    double sum = 0;
    for (int i=0; i<size; i++)
    {
        sum += log(arr1[i]) * log(arr2[i]);
    }
    return sum;
}

double sum_ln_arr2(float arr[], int size)
{
    double sum = 0;
    for (int i=0; i<size; i++)
    {
        sum += log(arr[i]) * log(arr[i]);
    }
    return sum;
}

void equation1(float arr1[], float arr2[], int size)
{
    double sum_x = sum_arr(arr1, size);
    double sum_y = sum_arr(arr2, size);
    double sum_x2 = sum_arr2(arr1, size);
    double sum_x_mul_y = sum_arr_mul_arr(arr1, arr2, size);

    double a = (sum_x2 * sum_y - sum_x * sum_x_mul_y) / (sum_x2 * size - sum_x * sum_x);
    double b = (size * sum_x_mul_y - sum_x * sum_y) / (size * sum_x2 - sum_x * sum_x);

    cout << "The equation is ( y = " << a << " + " << b << " x )\n";
}

void equation2(float arr1[], float arr2[], int size)
{
    double sum_x = sum_arr(arr1, size);
    double sum_y = sum_arr(arr2, size);
    double sum_x2 = sum_arr2(arr1, size);
    double sum_x3 = sum_arr3(arr1, size);
    double sum_x4 = sum_arr4(arr1, size);
    double sum_x_mul_y = sum_arr_mul_arr(arr1, arr2, size);
    double sum_x2_mul_y = sum__arr2_mul_arr(arr1, arr2, size);

    double det = size * (sum_x2 * sum_x4 - sum_x3 * sum_x3) - sum_x * (sum_x * sum_x4 - sum_x2 * sum_x3) + sum_x2 * (sum_x * sum_x3 - sum_x2 * sum_x2);
    double a = (sum_y * (sum_x2 * sum_x4 - sum_x3 * sum_x3) - sum_x * (sum_x_mul_y * sum_x4 - sum_x2_mul_y * sum_x3) + sum_x2 * (sum_x_mul_y * sum_x3 - sum_x2_mul_y * sum_x2)) / det;
    double b = (size * (sum_x_mul_y * sum_x4 - sum_x2_mul_y * sum_x3) - sum_y * (sum_x * sum_x4 - sum_x2 * sum_x3) + sum_x2 * (sum_x * sum_x2_mul_y - sum_x2 * sum_x_mul_y)) / det;
    double c = (size * (sum_x2 * sum_x2_mul_y - sum_x3 * sum_x_mul_y) - sum_x * (sum_x * sum_x2_mul_y - sum_x2 * sum_x_mul_y) + sum_y * (sum_x * sum_x3 - sum_x2 * sum_x2)) / det;

    cout << "The equation is ( y = " << a << " + " << b << " x + " << c << " x^2 )\n";
}

void equation3(float arr1[], float arr2[], int size)
{
    double sum_x = sum_arr(arr1, size);
    double sum_y = sum_arr(arr2, size);
    double sum_Y = sum_ln_arr(arr2, size);
    double sum_x2 = sum_arr2(arr1, size);
    double sum_x_mul_Y = sum_arr_mul_ln_arr(arr1, arr2, size);

    double A = (sum_x2 * sum_Y - sum_x * sum_x_mul_Y) / (sum_x2 * size - sum_x * sum_x);
    double b = (size * sum_x_mul_Y - sum_x * sum_Y) / (size * sum_x2 - sum_x * sum_x);

    double a = exp(A);

    cout << "The equation is ( y = " << a << " e^" << b << " x )\n";
}

void equation4(float arr1[], float arr2[], int size)
{
    double sum_ln_x = sum_ln_arr(arr1, size);
    double sum_ln_y = sum_ln_arr(arr2, size);
    double sum_ln_x2 = sum_ln_arr2(arr1, size);
    double sum_ln_x_mul_ln_y = sum_ln_arr_mul_ln_arr(arr1, arr2, size);

    double A = (sum_ln_x2 * sum_ln_y - sum_ln_x * sum_ln_x_mul_ln_y) / (sum_ln_x2 * size - sum_ln_x * sum_ln_x);
    double b = (size * sum_ln_x_mul_ln_y - sum_ln_x * sum_ln_y) / (size * sum_ln_x2 - sum_ln_x * sum_ln_x);

    double a = exp(A);

    cout << "The equation is ( y = " << a << " x^" << b << " )\n";
}

int fit_data_program(string filename="") {
    short eq, n;
    char again;
    
    float *x_values = NULL;
    float *y_values = NULL;
    do {
        int refill = 0;
        cout << "============================================\n";
        cout << "Choose the equation number you want : \n";
        cout << "1) y = a + bx \n";
        cout << "2) y = a + bx + cx^2 \n";
        cout << "3) y = a e^bx \n";
        cout << "4) y = a x^b \n";
        cout << "5) Exit\n";

        eq = get_int("\nYour choice : ");

        if (eq==5) exit(0);
        if (eq < 1 || eq > 5)
        {
            cout << "The equation number is incorrect.\n";
            cout << "Do you want to do another process? [y/n] ";
            cin >> again;
            continue;
        }

        if (x_values) {
            cout << "\n1) Refill the data (x, y)\n";
            cout << "2) Continue \n";

            refill = get_int("Your choice : ");
            if (refill == 1) {
                delete x_values;
                delete y_values;
                x_values = NULL;
                y_values = NULL;
            }

        }

        if ((filename==""  && !x_values) || refill == 1) {
            cout << "\nYOU NEED TO ENTER A POSTIVE NUMBER FOR n.\n";
            do {
                n = get_int("Enter n : ");
            } while (n < 1);

            x_values = new float[n];
            y_values = new float[n];

            cout << "Enter x values : \n";
            fill_arr(x_values, n);
            cout << "Enter y values : \n";
            fill_arr(y_values, n);

        } else if (!x_values) {
            x_values = x_from_file(filename);
            y_values = y_from_file(filename);

            n = sizeof(x_values) / sizeof(x_values[0]);
            n++;
        } 

        switch (eq)
        {
        case 1 :
            {
                equation1(x_values, y_values, n);
            }
            break;
        case 2 :
            {
                equation2(x_values, y_values, n);
            }
            break;
        case 3 :
            {
                equation3(x_values, y_values, n);
            } 
            break;
        case 4 :
            {
                equation4(x_values, y_values, n);
            } 
            break;
        default:
            break;
        }

        cout << "============================================\n";

        cout << "Do you want to do another process? [y/n] ";
        cin >> again;
        if (!again == 'y' ||!again == 'Y') {
            delete x_values;
            delete y_values;
        }
        system("clear");
    }
    while (again == 'y' || again == 'Y');

    cout << "\nThank you for using our program.\nHave a nice day.\n";
    cout << "############################################\n";

    return 0;
}

void display_help(void) {
    cout << "Usage: calc [-I|f] [-f [file.tsv]]\n";

    cout << "Calculate the numerical integration values for given equation.\n";
    cout << "Fit data table into an equation.\n\n";

    cout << "Opations:\n";
    cout << "\t-f\t\t fit these data into an equation.\n";
    cout << "\t-f file.tsv\t fit data in file into an equation.\n";
    cout << "\t-I\t\t get the numercal integration.\n";
    cout << "\t-h\t\t isplay this help and exit\n";

    cout << "\nExamples:\n";
    cout << "To get data from file\n";
    cout << "\t$ clac -f data.tcv\n";
    cout << "To use the intract mode just use the default\n";
    cout << "\t$ clac -f\n";
    cout << "To solve the integration equation\n";
    cout << "\t$ clac -I\n";

    cout << "\nAuthor: \n";
    cout << "\tFREE PALSTINE TEAM: \n\t-Fouad 22036\n\t-Ammar 22071\n\t-Mohamed 22229\n\t-Moumen 22339\n\t-Ahmed 22249\n\t-عبد الله 22256\n";
    cout << "\nLicense: \n";
    cout << "\tGPLv3+:  GNU  GPL  version  3  or <https://gnu.org/licenses/gpl.html\n";
    cout << "\tThis  is  free  software:  you are free to change and redistribute it.\n";
}