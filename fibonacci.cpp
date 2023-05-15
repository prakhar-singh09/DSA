//Printing fibonacci series upto n
#include <iostream>
using namespace std;
int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    for (int i = 1; i <= n; ++i) {
        // Prints the first two terms.
        if(i == 1) {
            cout << t1 << ", ";
            continue;
        }
        if(i == 2) {
            cout << t2 << ", ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        cout << nextTerm << ", ";
    }
    return 0;
}
// Output
// Enter the number of terms: 10
// Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 


//Using Recursion  
#include <iostream>
using namespace std;
int fib(int x) {
   if((x==1)||(x==0)) {
      return(x);
   }else {
      return(fib(x-1)+fib(x-2));
   }
}
int main() {
   int x , i=0;
   cout << "Enter the number of terms of series : ";
   cin >> x;
   cout << "\nFibonnaci Series : ";
   while(i < x) {
      cout << " " << fib(i);
      i++;
   }
   return 0;
}
// Output
// Enter the number of terms of series : 15
// Fibonnaci Series : 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377


//nth fibonacci series using recursion
//Time Complexity: Exponential
#include <bits/stdc++.h>
using namespace std;
 
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
 
int main()
{
    int n = 9;
    cout << fib(n);
    getchar();
    return 0;
}

// Output
// 34


//Using Dynamic Programming
// Time complexity: O(n) for given n

#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
	// Declare an array to store Fibonacci numbers. 1 extra to handle case, n = 0
	int f[n + 2];
	int i;
	// 0th and 1st number of the
	// series are 0 and 1
	f[0] = 0;
	f[1] = 1;
	for(i = 2; i <= n; i++)
	{
	//Add the previous 2 numbers in the series and store it
	f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
	}
};
int main ()
{
	int n = 9;
	
	cout <<fib(n);
	return 0;
}


//Using Binet's Formula
// Time Complexity: O(logn), this is because calculating phi^n takes logn time
// Auxiliary Space: O(1)

#include<iostream>
#include<cmath>
int fib(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}

int main ()
{
  int n = 9;
  std::cout << fib(n) << std::endl;
  return 0;
}
