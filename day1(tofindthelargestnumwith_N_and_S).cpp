/*Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'. Return -1 if it is not possible.

Example 1:

Input: N = 2, S = 9
Output: 90
Explaination: It is the biggest number 
with sum of digits equals to 9.
Example 2:

Input: N = 3, S = 20
Output: 992
Explaination: It is the biggest number 
with sum of digits equals to 20.
Your Task:
You do not need to read input or print anything. Your task is to complete the function findLargest() which takes N and S as input parameters and returns the largest possible number. Return -1 if no such number is possible.

Expected Time Complexity: O(N)
Exepcted Auxiliary Space: O(1)*/

#include <iostream>
#include <string>
using namespace std;

string findLargest(int N, int S) {
    // If it's not possible to create such a number, return "-1"
    if (S > 9 * N || (S == 0 && N > 1)) {
        return "-1";
    }
    
    // Initialize an array to store the digits of the result number
    int result[N];
    
    // Start with the leftmost (most significant) digit
    int i = 0;
    
    // Fill the digits from left to right
    while (i < N) {
        // If S is greater than 9, set the current digit to 9
        if (S >= 9) {
            result[i] = 9;
            S -= 9;
        }
        // If S is less than 9, set the current digit to S
        else {
            result[i] = S;
            S = 0;
        }
        i++;
    }
    
    // Convert the array of digits to a string
    string largestNumber = "";
    for (int j = 0; j < N; j++) {
        largestNumber += to_string(result[j]);
    }
    
    return largestNumber;
}

int main() {
    int N1 = 2, S1 = 9;
    cout << findLargest(N1, S1) << endl; // Output: "90"

    int N2 = 3, S2 = 20;
    cout << findLargest(N2, S2) << endl; // Output: "992"

    return 0;
}

