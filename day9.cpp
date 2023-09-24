/*Given an array A of n positive numbers. The task is to find the first equilibrium point in an array. Equilibrium point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 

Example 1:

Input: 
n = 5 
A[] = {1,3,5,2,2} 
Output: 
3 
Explanation:  
equilibrium point is at position 3 as sum of elements before it (1+3) = sum of elements after it (2+2). 
Example 2:

Input:
n = 1
A[] = {1}
Output: 
1
Explanation:
Since there's only element hence its only the equilibrium point.*/

//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
          if (n == 1) {
        return 1;  // There's only one element, so it's the equilibrium point
    }

    int leftPointer = 0;
    int rightPointer = n - 1;
    long long leftSum = 0;
    long long rightSum = 0;

    while (leftPointer <= rightPointer) {
        if (leftSum < rightSum) {
            leftSum += a[leftPointer];
            leftPointer++;
        }
        else if (leftSum > rightSum) {
            rightSum += a[rightPointer];
            rightPointer--;
        }
        else {
            if (leftPointer == rightPointer) {
                return leftPointer + 1;  // Return 1-based index of the equilibrium point
            }
            leftSum += a[leftPointer];
            rightSum += a[rightPointer];
            leftPointer++;
            rightPointer--;
        }
    }

    return -1;  // If no equilibrium point is found
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
