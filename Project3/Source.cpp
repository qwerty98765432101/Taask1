#include <iostream>
#include <stdlib.h>
#include "Header.h"


using namespace std;

	Array::Array() {
		Arr = new double[N];
	}
    Array::Array(size_t N) {
		this->N = N;
		Arr = new double[N];
		for (int i = 0; i < N; i++) {
			Arr[i] = 0;
		}
	}
    Array::Array(size_t N, double n) {
		this->N = N;
		Arr = new double[N];
		for (int i = 0; i < N; i++) {
			Arr[i] = n;
		}
	}
    Array::Array(const Array& obj) {
		this->N = obj.N;
		Arr = new double[N];
		for (int i = 0; i < N; i++) {
			Arr[i] = obj.Arr[i];
		}
	}
    Array::Array(Array&& obj) noexcept : Arr(nullptr), N(0)  {
		this->N = obj.N;
		Arr = obj.Arr;
		obj.N = 0;
		obj.Arr = nullptr;
	}

    Array::Array(size_t N, int res) {
	Arr = new double[N + res];
	}
    Array::~Array() = default;


	int Array::Length() {
		return N;
	}
    
	double& Array:: operator [](int index) {
	if (index < 0 || index > N) {
			throw exception("неверный индекс");
		}  return Arr[index];
	}
	void Array:: resize(int newSize) {
		double* Ar = new double[newSize];
		if(N >= newSize)
		for (int i = 0; i < newSize; i++) {
			Ar[i] = Arr[i];
		}  else
		{
			for (int i = 0; i < N; i++) {
				Ar[i] = Arr[i];
			}
			for (int i = N; i < newSize; i++) {
				Ar[i] = 0;
			}
		}
		N = newSize;
		delete[]Arr;
		Arr = Ar;
	}
	Array& Array:: operator=(const Array& obj) {
		N = obj.N;
		if (Arr != nullptr) {
			delete[] Arr;
		}
		Arr = new double[obj.N];
		for (int i = 0; i < obj.N; i++) {
			Arr[i] = obj.Arr[i];
		}
		return *this;
	}
	Array& Array:: operator =(Array && obj) noexcept {
		 if (this != &obj) {
			 delete[]Arr;
			 Arr = obj.Arr;
			 this->N = obj.N;
			 obj.N = 0;
			 obj.Arr = nullptr;
			 
		 }
		 return *this;
	 }
	bool Array:: operator ==(Array& obj) {
		if (this->N != obj.N) throw exception("Разные длины");
		for (int i = 0; i < N; i++) {
			if (Arr[i] != obj.Arr[i]) {
				return false;
			}
		}return true;
	}
	bool Array:: operator !=(Array& obj) {
		if (this->N != obj.N) throw exception("Разные длины");
		for (int i = 0; i < N; i++) {
			if (Arr[i] != obj.Arr[i]) {
				return true;
			}
		}return false;
	}
	 istream& operator >>(istream& is,Array& obj) {
		for (int i = 0; i < obj.N; i++) {
			is >> obj.Arr[i];
		}
		return is;
	}
     ostream& operator <<(ostream& os, const Array& obj) {
		for (int i = 0; i < obj.N; i++) {
			os << obj.Arr[i];
		}
		return os;
	}



	 void Array::reserve(int n) {
		double* Ar = new double[N + n + 1];                                                                                                                                                                                
		for (int i = 0; i < N; i++) {
			Ar[i] = Arr[i];
		}
		delete[]Arr;
		Arr = Ar;
	}


	 int Array::capacity() {
		int count = 1;
		double i = *(Arr + N);
		while (*(Arr + N + count) == i) {
			count++;
	
		}
		return count -1;
	}
	 void Array::resizeSecond(int newSize) {
		int n = capacity();
		if (newSize > N) {
			if (newSize - N <= n) { N = newSize; }
			else { throw exception("Overload"); }
		}
		else for (int i = N - 1; i > newSize - 1; i--) {
			Arr[i] = Arr[N];
		}
		N = newSize;
	}
	 void Array::pushBack(double x) {
		if (capacity() != 0) {
			N++;
			Arr[N - 1] = x;
		}
		else throw exception("Overload");
		
	}
	 double Array::popBack() {
		double temp;
		temp = Arr[N-1];
		Arr[N - 1] = Arr[N];
		N--;
		return temp;
	}
	

Array operator + (Array& obj_1, Array& obj_2) {
	Array Arrey(obj_1.N + obj_2.N);
	Arrey.N = obj_1.N + obj_2.N;
	int k = 0;
	for (int i = 0; i < obj_1.N; i++) {
		Arrey.Arr[i] = obj_1.Arr[i];
		k++;
	}

	for (int i = k; i < obj_1.N + obj_2.N; i++) {
		Arrey.Arr[i] = obj_2.Arr[i-k];
	}
	return Arrey;
}

double check(const Array& one, const Array& two) {
	int size;
	int k = 0;
	if (one.N >= two.N) { size = two.N; k++; }

	else size = one.N;
	for (int i = 0; i < size; i++) {
		if (one.Arr[i] > two.Arr[i])
			return 1;
		else if (one.Arr[i] < two.Arr[i]) return -1;
	}
	if (one.N == two.N) {
		return 0;
	}
	if (one.N > two.N) {
		return 1;
	}
	else return -1;
 }
	



bool operator >(const Array& one, const Array& two) {
	return(check(one, two) > 0);
}
bool operator <(const Array& one, const Array& two) {
	return(check(one, two) < 0);
}
bool operator <=(const Array& one, const Array& two) {
	return(check(one, two) <= 0);
}
bool operator >=(const Array& one, const Array& two) {
	return(check(one, two) >= 0);
}

