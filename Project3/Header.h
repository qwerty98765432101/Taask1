#include <iostream>
#include <stdlib.h>


using namespace std;

class Array {
public:
	double* Arr;
	size_t N = 5;
public:
	Array();
	
	Array(size_t N);

	Array(size_t N, double n);

	Array(const Array& obj);

	Array(Array&& obj) noexcept;


	Array(size_t N, int res);


	~Array();


	int Length();

	double& operator [](int index);


	void resize(int newSize);


	Array& operator=(const Array& v);


	Array& operator =(Array&& obj) noexcept;


	bool operator ==(Array& obj);

	bool operator !=(Array& obj);


	friend istream& operator >>(istream& is, Array& obj);


	friend ostream& operator <<(ostream& os, const Array& obj);





	void reserve(int n);


	int capacity();

	void resizeSecond(int newSize);

	void pushBack(double x);

	double popBack();

};
Array operator + (Array& obj_1, Array& obj_2);

double check(const Array& one, const Array& two);




bool operator >(const Array& one, const Array& two);


bool operator <(const Array& one, const Array& two);

bool operator <=(const Array& one, const Array& two);

bool operator >=(const Array& one, const Array& two);
 