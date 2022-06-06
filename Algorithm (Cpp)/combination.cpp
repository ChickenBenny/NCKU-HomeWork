#include<iostream>
 
using namespace std;
 
// A function to print all combination of a given length from the given array.
void Combination(int a[], int reqLen, int start, int currLen, bool check[], int len) 
{
	// Return if the currLen is more than the required length.
	if(currLen > reqLen)
	return;
	// If currLen is equal to required length then print the sequence.
	else if (currLen == reqLen) 
	{
		cout<<"\t";
		for (int i = 0; i < len; i++) 
		{
			if (check[i] == true) 
			{
				cout<<a[i]<<" ";
			}
		}
		cout<<"\n";
		return;
	}
	// If start equals to len then return since no further element left.
	if (start == len) 
	{
		return;
	}
	// For every index we have two options.
	// First is, we select it, means put true in check[] and increment currLen and start.
	check[start] = true;
	Combination(a, reqLen, start + 1, currLen + 1, check, len);
	// Second is, we don't select it, means put false in check[] and only start incremented.
	check[start] = false;
	Combination(a, reqLen, start + 1, currLen, check, len);
}
 
int main()
{
	int i, n;
	bool check[n];
	cout<<"Enter the number of element array have: ";
	cin>>n;
 
	int arr[n];
	cout<<"\n";
 
	// Take the input of the array.
	for(i = 0; i < n; i++)
	{
		cout<<"Enter "<<i+1<<" element: ";
		cin>>arr[i];
		check[i] = false;
	}
 
	// For each length of sub-array, call the Combination().
	for(i = 1; i <= n; i++)
	{
		cout<<"\nThe combination of  length "<<i<<" for the given array set:\n";
		Combination(arr, i, 0, 0, check, n);
	}
	return 0;
}