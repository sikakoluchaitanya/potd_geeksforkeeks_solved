//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string answer ="";
        while( n> 0)
        {
            answer += ('A'+ (n-1)%26);
            n = (n-1)/26;
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends