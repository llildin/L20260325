#include <iostream>
#include <vector>
#include "DynamicArray.h"
using namespace std;

class FVector2D
{
public:
	FVector2D(int InX = 0, int InY = 0) : X(InX), Y(InY)
	{

	}
	int X;
	int Y;

	// operator overloading
	FVector2D operator + (FVector2D RHS)
	{
		FVector2D New;
		New.X = X + RHS.X;
		New.Y = Y + RHS.Y;
		return New;
	}
};

int main()
{
	DynamicArray<int> IntArray;
	IntArray.PushBack(1);
	IntArray.PushBack(2);
	IntArray.PushBack(3);
	IntArray.PushBack(4);

	for (DynamicArray<int>::Iterator iter = IntArray.begin();
		iter != IntArray.end(); iter++)
	{
		cout << *iter << endl;
	}

	for (auto Data : IntArray)
	{
		cout << Data << endl;
	}

	/*
	vector<int> IntVector;

	IntVector.begin();
	IntVector.end();

	vector<int>::iterator iter;

	for (auto i : IntVector)
	{

	}
	*/

	return 0;
}