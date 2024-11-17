/*
https://leetcode.com/problems/swim-in-rising-water/
This problem can be solved in various ways :
    1) BFS/DFS
    2) Binary Search
    3) Disjoint Set (Hint given in my notes)
    4) Dijsktra's (The code is given below): This is the most intuitional. Plain Dij Implementation.
       Only take care that you take distance as max of distance till current and neighbor node's value and not weight.
*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        //distance, (row,col): we will choose minimum always
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> d(n,vector<int>(m,1e9));
        d[0][0]=0;
        pq.push({grid[0][0],0,0});
        
        while(!pq.empty()){
            int du = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();
            if(r==n-1 and c==m-1) return du;
            //traverse neighbors or r,c:
            int deltar[]={0,-1,1,0};
            int deltac[]={1,0,0,-1};
            for(int i=0;i<4;i++){
                int nr = r+deltar[i];
                int nc = c+deltac[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m and max(du,grid[nr][nc])<d[nr][nc]){
                    d[nr][nc] = max(du,grid[nr][nc]);
                    pq.push({d[nr][nc],nr,nc});
                }
            }
        }

        return INT_MAX;

    }
};