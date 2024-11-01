/*
https://leetcode.com/problems/non-overlapping-intervals/description/
Same as N meetings in one room
*/

class Solution {
public:
    static bool comp(vector<int> a,vector<int> b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n = intervals.size();
        int end = intervals[0][1],cnt=1;    //1st meeting ter karuch shakto
        for(int i=1;i<n;i++){
            if(intervals[i][0]<end){
                //delete this meeting
            } else {
                //this meeting can be done
                end = intervals[i][1];
                cnt++;
            }
        }
        return n-cnt;
    }
};