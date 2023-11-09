//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int columnWithMaxZeros(vector<vector<int>>arr,int N){
        vector<int> result(N,0);
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(arr[i][j] == 0)
                {
                    result[j]++;
                }
            }
        }
        
        int maxzero = 0;
        int index = 0;
    
        for(int i=0;i<N;i++)
        {
            if(result[i]>maxzero)
            {
                maxzero = result[i];
                index = i;
            }
        }
        
        if(maxzero == 0)
        {
            return -1;
        }
        else
        {
            return index; 
        }
    }
};

//{ Driver Code Starts.
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    vector<vector<int>>arr(N,vector<int>(N));
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	        for(int j = 0;j<N;j++){
	            int x;
	            cin >> x; 
	            arr[i][j]=x;
	        }
	    }
	    Solution ob;
	    cout << ob.columnWithMaxZeros(arr,N) << endl;
	}
	
	return 0;
}
// } Driver Code Ends