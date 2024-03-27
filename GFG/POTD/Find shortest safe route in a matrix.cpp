//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int deltax[4]={1,-1,0,0};
    int deltay[4]={0,0,1,-1};
    
    void preprocess(vector<vector<int>> &mat){
        int r=mat.size();
        int c=mat[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    //make all its neighbors as -1
                    mat[i][j]=-1;
                    for(int k=0;k<=3;k++){
                        int new_i=i+deltax[k];
                        int new_j=j+deltay[k];
                        if(new_i>=0 and new_i<r and new_j>=0 and new_j<c)
                            mat[new_i][new_j]=-1;
                    }
                }
            }
        }
    }
    
    int findShortestPath(vector<vector<int>> &mat)
    {
        int r=mat.size();
        int c=mat[0].size();
        
        preprocess(mat);
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        queue < pair< int,pair<int,int> > > q;
        for(int i=0;i<mat.size();i++){
            if(mat[i][0]!=-1) {
                q.push({1,{i,0}});
                vis[i][0]=true;
            }
        }
        
       
        while(!q.empty()){
            int dist = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            
            if(j==c-1) return dist;
            
            q.pop();
            for(int k=0;k<4;k++){
                 int new_i= i+deltax[k];
                 int new_j= j+deltay[k];
                
                 if(new_i>=0 and new_i<r and new_j>=0 and new_j<c and 
                    mat[new_i][new_j]!=-1 and !vis[new_i][new_j]){
                        vis[new_i][new_j]=true;
                        q.push({dist+1,{new_i,new_j}});
                    }
            }
            
        }
        return -1;
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
