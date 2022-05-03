#include "Header.h"
#include <iostream>
using namespace std;

int main() {
	Array one(5);
	cout << one << endl;

	Array two(4, 4.0);
	cout << two << endl;

	Array three (one);
	cout << three << endl;

	cout << three.Length() << endl;

	cout << three[3] << endl;

	three.resize(10);
	cout << three << endl;

	three = two;
	cout << three << endl;

	if (three == two) cout << " equals" << endl;
	
	Array four(4, 3.0);
	cout << " Arrays" << endl;
	cout << three << endl;
	cout << four << endl;
	if (three >= four) cout << " larger" << endl;

	Array five = one + two; cout << five;
	//cin >> five; cout << endl << five;




	cout << "Array length " << five.Length() << endl;
	cout << five.capacity() << "- memory cells reserved";
	five.reserve(10); // 10 ячеек памяти зарезервировано
	cout << endl << five.capacity() << "- Amount of reserved memory";
	five.pushBack(3);
	five.pushBack(10);
	five.pushBack(20);
	cout << five << " - Array  " << five.capacity(); 
	five.popBack();
	five.popBack();
	five.popBack();
	cout << endl <<  five << " - Array  " << five.capacity();
	Array six(4, 3.0);
	cout << endl << six.capacity();
	six.reserve(1);
	cout << endl << six.capacity();

	string zetta;
	zetta = "33234234324frfrfg";
	cout << zetta;







   /*
	Array one(5, 2.0);
	Array two(6, 5.0);

	Array third = two + one;
	cout << third;
	one[2] = 69;
	third.resize(7);
	cout << endl << third;
	cout << endl << one;
	third.reserve(5);
	cout << endl;
	third.resizeSecond(7);
	cout << two.Length();
	two.reserve(2);
	cout << endl << "cap" << two.capacity();
	two.pushBack(3);
	two.popBack();
	two.pushBack(7);
	cout << "taken" << two.popBack();
	two.popBack();
	cout << endl << "length" << two.Length() << " capacity" << two.capacity();




	cout << endl << third.capacity();

	Array ne(6, 4);
	cout << endl << ne.capacity();

	ne.pushBack(3);
	ne.pushBack(3);
	ne.pushBack(3);
	ne.pushBack(3);
	ne.popBack();
	ne.popBack();
	//ne.reserve(2);
	cout << ne.capacity();
	*/
}