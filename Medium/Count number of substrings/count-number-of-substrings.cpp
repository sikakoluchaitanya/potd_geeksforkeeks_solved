//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
   long atmost(string s, int k)
    {
        int arr[26] = {0};
        int diff = 0; // to store number of different character
        int left = 0; // left pointer which will get incremented if the there more different character then requiref
        int result = 0;
        
        for(int i=0; i<s.length(); i++)
        {
            arr[s[i] -'a']++;
            if(arr[s[i]- 'a']==1)
            {
                diff++;
            }
            
            while(diff>k)
            {
                arr[s[left]-'a']--;
                
                if(arr[s[left] -'a'] == 0)
                {
                    diff--;
                }
                
                left++;
            }
            result = result + (i - left + 1);
        }
        return result;
    }
  
    long long int substrCount (string s, int k) {
    	
    	return atmost(s,k) - atmost(s,k-1); 
    }
    
    
}; // have done this question using sliding window method 

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends
