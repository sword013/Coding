class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size();
        int jumps = 0;
        int l=0,r=0;    //range
        while(r<n-1){
            //for this range from l to r, what is the farthest that i can go ? 
            int farthest = 0;
            for(int i=l;i<=r;i++){
                farthest = max(farthest,i+a[i]);
            }
            //new range : 
            l=r+1; r=farthest;
            jumps++;
        }
        return jumps;
        //O(N), O(1)
        //trying to reach the farthest so its under greedy
    }
};