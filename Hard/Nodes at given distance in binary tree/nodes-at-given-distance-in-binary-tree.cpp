//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
public:
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        vector<int> result;
        findKDistanceNodes(root, target, k, result);
        sort(result.begin(), result.end()); // Sort the result in ascending order
        return result;
    }

private:
    int findKDistanceNodes(Node* root, int target, int k, vector<int>& result) {
        if (!root) return -1;

        if (root->data == target) {
            collectKDistanceNodes(root, k, result);
            return 0;
        }

        int leftDist = findKDistanceNodes(root->left, target, k, result);
        if (leftDist >= 0) {
            if (leftDist + 1 == k)
                result.push_back(root->data);
            else
                collectKDistanceNodes(root->right, k - leftDist - 2, result);
            return leftDist + 1;
        }

        int rightDist = findKDistanceNodes(root->right, target, k, result);
        if (rightDist >= 0) {
            if (rightDist + 1 == k)
                result.push_back(root->data);
            else
                collectKDistanceNodes(root->left, k - rightDist - 2, result);
            return rightDist + 1;
        }

        return -1;
    }

    void collectKDistanceNodes(Node* root, int k, vector<int>& result) {
        if (!root || k < 0) return;

        if (k == 0) {
            result.push_back(root->data);
            return;
        }

        collectKDistanceNodes(root->left, k - 1, result);
        collectKDistanceNodes(root->right, k - 1, result);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends