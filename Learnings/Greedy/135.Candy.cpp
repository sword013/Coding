//https://leetcode.com/problems/candy/
//This was really hard to implement. Check both BF and optimal 
class Solution {
public:
    int bruteForce(vector<int> &ratings){
        int n = ratings.size();
        int left[n],right[n];
        
        //left array indicates that I only consider left neighbours
        left[0]=1; right[n-1]=1;

        //this only satisfies left neihgbours
        for(int i=1;i<n;i++) {
            if(ratings[i-1]<ratings[i]) 
                left[i] = left[i-1]+1;
            else left[i]=1; //it has less rating than left, thus greedily give it less candies
        }

        //this only satisfies right neighbors
        for(int i=n-2;i>=0;i--) {
            if(ratings[i]>ratings[i+1]) 
                right[i] = right[i+1]+1;
            else right[i]=1;
        }

        //if at "i", i have max of left and right, it will satisfy both left and right neighbors,
        //means if rating[i] is greater than both then max of both will ensure that at i, we have 
        //#candies better than both left and right neighbors

        int total=0;
        for(int i=0;i<n;i++){
            total += max(left[i],right[i]);
        }
        return total;
        //O(3n) time, O(2n) space (can easily be converted to O(n) space(watch striver for that))
        //Now we move towards optimal, which will take O(1) space
    }
    
    bool isFlat(int i,vector<int> &ratings){
        if(ratings[i]==ratings[i-1]) return true;
        return false;
    }

    bool isIncreasing(int i,vector<int> &ratings){
        if(ratings[i]>ratings[i-1]) return true;
        return false;
    }

    bool isDecreasing(int i,vector<int> &ratings){
        if(ratings[i]<ratings[i-1]) return true;
        return false;
    }
    
    int optimal(vector<int> &ratings){
        //Uses slope concept
        //Example : 0 2 4 7 6 5 4 3 2 1 1 1 2 3 4 2 1 1
        // logic: draw a slope grpah and you will get what to do
        //aim is to give candies to a mountain(flat,increasing,flat,dereasing) and repeat
        int n = ratings.size();
        int sum=1;  //1 candy given to first guy
        int i = 1;
        while(i<n){
            if(isFlat(i,ratings)) { 
                sum+=1; 
                i++;
                continue;
            } 
            int peak=1; //if next element is big, then curr element has already consumed this 1
            while(i<n and isIncreasing(i,ratings)) {
                peak++; //one who sits at top locally increases its height
                sum+=peak;
                i++;
            }

            int down=0; //cuz we dk if we have yet arrived at down or if next element is small, then curr element has already 
            //consumed this 0; draw graph
            while(i<n and isDecreasing(i,ratings)){
                down++;
                sum+=down;
                i++;
            }
            down++; //cuz we expect to give down+1 to the 
            if(down>peak) sum+= down-peak;
         
        }

        return sum;

    }

    int candy(vector<int>& ratings) {
        //return bruteForce(ratings);
        return optimal(ratings);
    }
};