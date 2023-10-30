// بسم الله
#include <fstream>
#include <iostream>

using namespace std;


int get_int(string s) {
    int n;
    do {
        cout << s ;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin >> n;
    } while (cin.fail());

    return n;
}
int get_float(string s) {
    float n;
    do {
        cout << s ;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin >> n;
    } while (cin.fail());

    return n;
}


float *y_from_file(string filename) {
    fstream file;
    file.open(filename, ios::in);
    if (!file.is_open()) {
        cout << "The file does not exist or you don't have permition to read it." << endl;
        exit(1);
    }

    string tmp;
    int lines;
    for (int i = 0; !file.eof(); i++) {
        getline(file, tmp);
        lines = i;
    } 
    // cout << "lines: " << lines << endl;
    float *y_buffer = new float[lines];
    file.seekg(0, ios::beg);
    getline(file, tmp);

    float x, y;
    for (int i = 0;i < lines; i++) {
        file >> x >> y;
        y_buffer[i] = y;
        // cout << "y " << y << endl;
    }
    return y_buffer;
}

float *x_from_file(string filename) {
    fstream file;
    file.open(filename, ios::in);
    if (!file.is_open()) {
        cout << "The file does not exist or you don't have permition to read it." << endl;
        exit(1);
    }

    string tmp;
    int lines;
    for (int i = 0; !file.eof(); i++) {
        getline(file, tmp);
        lines = i;
    } 
    // cout << "lines: " << lines << endl;
    float *x_buffer = new float[lines];
    file.seekg(0, ios::beg);
    getline(file, tmp);

    float x, y;
    for (int i = 0;i < lines; i++) {
        file >> x >> y;
        x_buffer[i] = x;
        // cout << "y " << y << endl;
    }
    return x_buffer;
}


void print_arr(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}