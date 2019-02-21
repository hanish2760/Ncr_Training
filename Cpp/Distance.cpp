
#include<iostream>
using namespace std;
class Centi;
class Feet {
	int inches;
	int feets;

public:
	Feet(int a, int b) {
		inches = b;
		feets = a;
		
	}
	friend class Centi;
	
	friend void add(Feet &f, Centi c);
	friend void add(Centi &c, Feet f);
		void dis() {
		cout << feets << " . " << inches;
	}
};
class Centi {
	int cm;
	int mt;
public :
	Centi(int a, int b) {
		cm = b;
		mt = a;
	}
	friend class Feet;
	friend void add(Feet &f, Centi c);
	friend void add(Centi &c, Feet f);
	
	void dis() {
		cout << cm << " . " << mt<<endl;
	}
};
void add(Feet &f,Centi c)
{
	f.inches = f.inches + c.cm;
	f.feets = f.feets + c.mt;
}
void add(Centi &c, Feet f)
{
	c.cm = f.inches + c.cm;
	c.mt = f.feets + c.mt;
}
int main() {
	
	Centi c(4, 5);
	Feet f(5, 4);
	add(f,c);
	add(c, f);
	getchar();

	return 1;
}