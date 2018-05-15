#include "stdafx.h"
#include "Template.h"
#include <iostream> 
#include <string> 
using namespace std;

template <class T>
TestTemp<T>::TestTemp()
{
}

template <class T>
void TestTemp<T>::SetValue(T obj_i)
{
}

template <class T>
T TestTemp<T>::Getalue()
{
	return m_Obj;
}

// No need to call this TemporaryFunction() function,
// it's just to avoid link error.
void TemporaryFunction()
{
	TestTemp<int> TempObj;
}