#include "stdafx.h"
#include<iostream>
#include<string>
#include<conio.h>
#include "Template.h"
using namespace std;

template <class T>
class Holder {
private:
	T obj;                                        // embedded object inside Holder<T> (uses default constructor)
	int count;                                    // private data inside Holder<T>
public:
	Holder() : count(1) {}                        // template Constructor: default count = 1
	Holder(int count) : count(count) {}           // template Constructor: initialize count

	void demo() { cout << "Holder<T> demo() default" << endl; };    // this function is shared by all classes

																	// overload << and >> for the template class, which has type "Holder<T>"
	friend istream &operator >> (istream  &input, Holder<T> &o) {
		cout << "   (Holder template) Please enter " << o.count << " data items" << endl;
		input >> o.obj;       // here we use the >> overload funtion inside the class of obj 
		return input;
	}
	friend ostream &operator<< (ostream &output, const Holder<T> &o) {
		output << endl << "   (Holder template) Calling cout << for object" << endl;
		output << o.obj;      // here we use the << overload funtion inside the class of obj 
		return output;
	}

};



template <class T, int N>
class mysequence {
	T memblock[N];
public:
	void setmember(int x, T value);
	T getmember(int x);
};

template <class T, int N>
void mysequence<T, N>::setmember(int x, T value) {
	memblock[x] = value;
}

template <class T, int N>
T mysequence<T, N>::getmember(int x) {
	return memblock[x];
}

int main() {
	mysequence <int, 5> myints;
	mysequence <double, 5> myfloats;
	myints.setmember(0, 100);
	myfloats.setmember(3, 3.1416);
	cout << myints.getmember(0) << '\n';
	cout << myfloats.getmember(3) << '\n';


	cout << endl;
	system("pause");
	return 0;
}



