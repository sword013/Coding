//https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

class Solution {
public:
    long long sumBetween(long long a,long long b){
       return (b*(b+1))/2 - ((a-1)*(a))/2;
    }

    int isPossible( long long index, long long n, long long maxSum, long long val){
        long long left = index;
        long long right = n-1-index;
        long long lsum;
        long long rsum;

        if(left>=val){
            lsum = left-val+1 + sumBetween(1,val-1);
        } else{
            lsum = sumBetween(val-left,val-1);
        }

        if(right>=val){
            rsum = right-val+1 + sumBetween(1,val-1);
        } else{
            rsum = sumBetween(val-right,val-1);
        }

        long long sum = lsum + rsum+val;
        if(sum==maxSum) return 0;
        else if(sum<maxSum) return -1;  //you can try to increase sum
        else return +1; //you have to decrease sum !

    }

    int maxValue(int n, int index, int maxSum) {
        long long low = 1,high=maxSum,mid;
        long long ans;

        while(low<=high){
            long long mid = (low+high)/2;
            int ret = isPossible(index,n,maxSum,mid);
            if(ret==0){
                return mid;
            }else if(ret==-1){
                //good,satsified ; you  can increase sum
                low=mid+1;
                ans=mid;
            }else{
                //ret == 1
                high = mid-1;
            }
        }
        return ans;
        // int ans;
        // for(int i=1;i<maxSum;i++){
        //     int ret = isPossible(index,n,maxSum,i);
        //     if(ret==0) return i;
        //     else if(ret==-1){
        //         ans=i;
        //     }else break;
        // }
        // return ans;
    }
};