//https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    class Item{
        public:
        double profit,weight;
        double pw;
    };
    
    static bool comp(Item i1,Item i2){
        return i1.pw>i2.pw;
    }
    
    double fractionalKnapsack(vector<int>& values, vector<int>& weights, int w) {
        // Your code here
        int n = values.size();
        vector<Item> item(n);
        for(int i=0;i<n;i++){
            item[i].profit = values[i];
            item[i].weight = weights[i];
            item[i].pw = (double)((double)values[i]/(double)weights[i]);
        }
        sort(item.begin(),item.end(),comp);
        
        int i=0;
        double rem=w,sum=0;
        while(i<n and item[i].weight<=rem){
            sum+=item[i].profit;
            rem-=item[i].weight;
            i++;
            
        }
        
        //cout<<"sum=" <<sum <<endl;
        if(i<n) sum+= rem * item[i].pw;
        
        return sum;
    }
};