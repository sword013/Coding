//https://leetcode.com/problems/couples-holding-hands/description/
/*
logic:
i=0,2,4,...
At each index i, you should expect that its couple element should be present at i+1;
if not, find its couple's posi and swap it->swaps++;
next go to next couple making.
*/
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n =row.size();
        vector<int> posi(n);
        for(int i =0;i<n;i++) posi[row[i]]= i;

        int swaps=0;
        for(int i=0;i<row.size();i=i+2){
            int first = row[i];
            int expectedToItsRight = (row[i]%2==0)? row[i]+1 : row[i]-1;
          
            //2 _ look for 3, 5 _ look for 4
            if(row[i+1]==expectedToItsRight) {
                //its already there no need to swap
            }else{
                int val1=row[i+1],val2=expectedToItsRight;
                row[i+1] = val2; row[posi[val2]] = val1;    //swapping values
                swap(posi[val1],posi[val2]);        //swapping their positions as well
                
                swaps++;
            }
        }
        return swaps;
        //O(n),O(n)
    }
};