/*
https://leetcode.com/problems/insert-interval/
Strivrs is not that intuitive. will try that later
My logic overview : 
    1) Push all before
    2) Find newstart and new End
    3) Push all after

    1) while(Your start is greater  than the endpoint of interval i)
        This is a previous interval thus push it in answer. 
    2) If you reached till end means this interval starts after everyone ends. Thus push this as last interval and exit
    3) You got a start which is less than endpoint. Means you got newStart = min (start,currStart);
    4) Now if end is before currEnd means the interval is a sandwhich, doesnt overlap. thus add start,end and then push all later and exit
    5) interval overlaps. you got newStart. time to find newEnd. While(your end is greater than currEnd) go ahead
    6) now your end <= currEnd. if this end is even less than currStart, means it doesnt overlap with ith interval. push newStart,end.
    else it overlaps with ith interval in which case take max(end,currEnd);
    7) Push remaining
    Take care of edge case: i==n after you do i++ anywhere

*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;
        int start = newInterval[0];
        int end = newInterval[1];

        while(i<n and start>intervals[i][1]){
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        if(i==n) {
             ans.push_back({newInterval[0],newInterval[1]});
             return ans;
        }
        //start>=currStart
        if(end<intervals[i][0]) {
            //this is completely new
            ans.push_back({newInterval[0],newInterval[1]});
            //push rest else here and done !
             while(i<n){
                ans.push_back({intervals[i][0],intervals[i][1]});
                i++;
            }
            return ans;
        }
        int newStart = min(intervals[i][0],start);
       
        //find newEnd;
        while(i<n and end>intervals[i][1]) i++;
        if(i==n) {
             ans.push_back({newStart,newInterval[1]});
             return ans;
        }
        //end<=intervals[i][1]
        if(end<intervals[i][0])
            ans.push_back({newStart,end});
        else{
            ans.push_back({newStart,max(end,intervals[i][1])});
            i++;
        }
        //push rest others
        while(i<n){
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }

        return ans;
    }
};