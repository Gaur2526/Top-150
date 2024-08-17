Problem Statement Break Down : 

1. we have an array prices where prices[i] is the price of the stock on the i-th day
2. we have to find the total profit we gained by buy & selling the stock
3. we can buy and sell on the same day

Solution :

// Optimised approach

#include<bits/stdc++.h>
using namespace std;

int maxprofit(vector<int> prices){
    
    int total_profit = 0;
    
    for(int i=0;i<prices.size()-1;i++){
        
        if(prices[i+1] > prices[i]){
            
            total_profit = total_profit + prices[i+1] - prices[i];
        }
        
    }
    
    return total_profit;
}
int main(){
    
    int n;
    cin>>n;
    
    vector<int> prices;
    
    for(int i=0;i<n;i++){
        
        int val;
        cin>>val;
        
        prices.push_back(val);
    }
    
  cout<<maxprofit(prices);
}

Time complexity : O(n)
Space complexity : O(1)
