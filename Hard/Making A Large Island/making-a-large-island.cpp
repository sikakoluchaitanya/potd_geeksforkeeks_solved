//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
           int n = grid.size();
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        auto is_valid = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < n;
        };
        
        function<int(int, int, int)> dfs = [&](int x, int y, int color) {
            if (!is_valid(x, y) || grid[x][y] != 1) {
                return 0;
            }
            grid[x][y] = color;
            int size = 1;
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                size += dfs(nx, ny, color);
            }
            return size;
        };
        
        unordered_map<int, int> island_sizes; // {color: size}
        int color = 2; // Start from color 2 (1 is already used for '1's)
        int max_island_size = 0;
        
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == 1) {
                    int size = dfs(x, y, color);
                    island_sizes[color] = size;
                    max_island_size = max(max_island_size, size);
                    color++;
                }
            }
        }
        
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == 0) {
                    set<int> neighbor_colors;
                    int potential_size = 1; // Change the '0' to '1'
                    for (auto& dir : directions) {
                        int nx = x + dir.first;
                        int ny = y + dir.second;
                        if (is_valid(nx, ny)) {
                            int neighbor_color = grid[nx][ny];
                            if (neighbor_color != 0 && neighbor_colors.find(neighbor_color) == neighbor_colors.end()) {
                                neighbor_colors.insert(neighbor_color);
                                potential_size += island_sizes[neighbor_color];
                            }
                        }
                    }
                    max_island_size = max(max_island_size, potential_size);
                }
            }
        }
        
        return max_island_size;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends