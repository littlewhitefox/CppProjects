#include <iostream>

using namespace std;

void Swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a = 50;
	int *b;
	b = &a;
	*b = 500;

	int **c;
	c = &b;
	**c = 1000;

	cout << &a << endl;
	cout << "b = " << b << endl; 
	cout << &b << endl;
	cout << "c = " << c << endl;
	cout << &c << endl;

	cin.ignore();
}