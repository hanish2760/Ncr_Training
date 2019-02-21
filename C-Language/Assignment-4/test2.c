#include<iostream>
using namespace std;
int main()
{

	int a, b, n;
	cout << "enter " << endl << "1 for swap by value" << endl << "2 for swap by reference" << endl;
	cin >> n;
	cout << "enter a b" << endl;
	cin >> a >> b;
	void swap_value(int, int);
	void swap_reference(int &x, int &y);

	switch (n) {
	case 1: {

		swap_value(a, b);
		cout << a << b; break; }
	case 2: {

		swap_reference(a, b);
		cout << a << b; break; }
	}

}
void swap_value(int a1, int b1) {
	b1 = a1 + b1;
	a1 = b1 - a1;
	b1 = b1 - a1;
	cout << "call by value" << endl << a1 << b1 << endl;
}
void swap_reference(int &a1, int &b1) {
	b1 = a1 + b1;
	a1 = b1 - a1;
	b1 = b1 - a1;
	cout << "call by reference" << endl << a1 << b1 << endl;
}
