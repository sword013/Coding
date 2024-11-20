//https://leetcode.com/problems/burst-balloons/description/

class Solution {
public:
    int f(int l,int r,vector<int> &a){
        //base:
        if(l>r){
            //no more subproblems left
            return 0;
        }

        //i>=j means subproblems exists

        int max_cost = 0;
        for(int i=l+1;i<=r-1;i++){
            int left  = f(l,i,a); 
            int right = f(i,r,a);
            max_cost = max(max_cost,left+right+a[l]*a[i]*a[r]);
        }
       
        return max_cost;
    }
    int maxCoins(vector<int>& a) {
        a.insert(a.begin(),1);
        a.push_back(1);
        int n = a.size();
        // return f(0,n-1,a);

        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int l=n-1;l>=0;l--){
            for(int r=0;r<n;r++){
                 int max_cost = 0;
                for(int i=l+1;i<=r-1;i++){
                    int left  = dp[l][i]; 
                    int right = dp[i][r];
                    max_cost = max(max_cost,left+right+a[l]*a[i]*a[r]);
                }
       
            dp[l][r]=max_cost;
            }
        }

        return dp[0][n-1];
    }
};