#include <iostream>

using namespace std;

int main() {
    char alphabet = 'D';
    int count;
    do {
        cout << "Please enter an alphabet: ";
        cin >> alphabet;
        switch (alphabet) {
            case 'T' :
                count = 3;
                break;
            case 'S' :
                count = 6;
                break;
            case 'N':
                count = 9;
                break;
            case 'E':
                exit(0);
            default:
                count = 12;
                break;
        }
        for (int i = 0; i < count; i++)
        {
            cout << alphabet;
            for (int j = 0; j < count; j++)
                cout << alphabet;
            cout << endl;
        }
    } while (alphabet != 'E');
}