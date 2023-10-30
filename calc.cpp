// بسم الله
#include <iostream>
#include <cstring>

#include "libs/mylib.h"
#include "libs/integration.h"

using namespace std;

int main(int argc, char *argv[])
{
    system("clear");

    if (argc == 1) 
        display_help();

    if (argc > 1) {
        switch (argv[1][1])
        {
        case 'f':
            if (argc == 3)
                fit_data_program(argv[2]);
            else
                fit_data_program();
            break;
        case 'I':
            integration_program();
            break;
        case 'h':
            display_help();
            break;

        default:
            cout << argv[0] << ": invalid option '" << argv[1] << "'" << endl;
            cout <<"Try '" << argv[0] <<" -h' for more information.\n";
            break;
        }
    } 


    return 0;
}

