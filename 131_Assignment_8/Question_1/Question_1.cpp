#include<iostream>
using namespace std;

int main()
{
	int a[4] = { 9,5,8,2 };
	int* p = a;  int* q = &a[3];
	while (q >= p)
	{
		cout << *q << " ";
		--q;
	}
}