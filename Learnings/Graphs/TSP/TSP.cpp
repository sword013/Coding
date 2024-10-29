//Try here: https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1
class Solution {
    public:
        int visited_all; //means all are visited
        
        int tsp(int city,int bit_mask,vector<vector<int>> &cost,vector<vector<int>> &dp){
            int n = cost.size();
            if(dp[city][bit_mask]!=-1) return dp[city][bit_mask];
            if(bit_mask == visited_all){
                //now try to go back to original city
                return cost[city][0];
            }
            
            int mini = INT_MAX;
            //go to the cities which are not visited yet
            for(int neigh=0;neigh<n;neigh++){
                if((bit_mask&(1<<neigh))==0){
                    //that city is not visited as ith bit is not set in bitmask
                    //mark it as visited and do recursion from that city
                    mini = min(mini,cost[city][neigh]+tsp(neigh,(bit_mask|(1<<neigh)),cost,dp));
                    
                }
            }
            return dp[city][bit_mask]=mini;
        }
        
        int total_cost(vector<vector<int>>cost){
            // Code here
            //1 <= cost[i][j] <= 103 means its a complete graph
            
            int n = cost.size();
            vector<vector<int>> dp(n,vector<int>((1<<n),-1));   //2^n
            int bit_mask = 1;   //marking 0th city as visited
            visited_all= (1<<n)-1;
            return tsp(0,bit_mask,cost,dp);
            
        }
};