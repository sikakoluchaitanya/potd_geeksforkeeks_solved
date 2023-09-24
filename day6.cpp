/*Given an integer N and an integer D, rotate the binary representation of the integer N by D digits to the left as well as right and return the results in their decimal representation after each of the rotation.
Note: Integer N is stored using 16 bits. i.e. 12 will be stored as 0000000000001100.

Example 1:

Input:
N = 28, D = 2
Output:
112
7
Explanation: 
28 in Binary is: 0000000000011100
Rotating left by 2 positions, it becomes 0000000001110000 = 112 (in decimal).
Rotating right by 2 positions, it becomes 0000000000000111 = 7 (in decimal).
Example 2:

Input: 
N = 29, D = 2
Output: 
116
16391
Explanation: 
29 in Binary is: 0000000000011101
Rotating left by 2 positions, it becomes 0000000001110100 = 116 (in decimal).
Rotating right by 2 positions, it becomes 100000000000111 = 16391 (in decimal).
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
           vector<int> result(2);

        // Ensure d is within the range [0, 15]
        d %= 16;

        // Convert N to its binary representation
        bitset<16> binaryN(n);

        // Left Rotation
        bitset<16> leftRotated(binaryN);
        for (int i = 0; i < 16; i++) {
            int newIndex = (i + d) % 16;
            leftRotated[newIndex] = binaryN[i];
        }
        result[0] = leftRotated.to_ulong();

        // Right Rotation
        bitset<16> rightRotated(binaryN);
        for (int i = 0; i < 16; i++) {
            int newIndex = (i - d + 16) % 16;
            rightRotated[newIndex] = binaryN[i];
        }
        result[1] = rightRotated.to_ulong();

        return result; 
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
