// C++ implementation to find
// minimum number of deletions
// to make a string palindromic

#include <bits/stdc++.h>
using namespace std;

// Returns the length of
// the longest palindromic
// subsequence in 'str'
int lps(string str)
{
	int n = str.size();
	
	// array to store computation
	// of subproblems
	int L[n];
	
	// iterate over subproblems to get the current
	// value from previous computation
	for (int i = n - 1; i >= 0; i--)
	{
		// to store previous values
		int back_up = 0;
		for (int j = i; j < n; j++)
		{
			if (j == i)
				L[j] = 1;
			else if (str[i] == str[j])
			{
				int temp = L[j];
				L[j] = back_up + 2;
				back_up = temp;
			}
			else
			{
				back_up = L[j];
				L[j] = max(L[j], L[j - 1]);
			}
		}
	}
	
	// return final answer
	return L[n - 1];
}
	
// function to calculate
// minimum number of deletions
int minimumNumberOfDeletions(string str)
{

	int n = str.size();
	
	// Find longest palindromic
	// subsequence
	int len = lps(str);

	// After removing characters
	// other than the lps, we
	// get palindrome.
	return (n - len);
}

// Driver Code
int main()
{
	string str = "geeksforgeeks";
	cout << "Minimum number of deletions = " << minimumNumberOfDeletions(str);
	return 0;
}

