Problem Statement Break Down : 

1. we have an array prices where prices[i] is the price of the stock on the i'th day
2. we have to sell stock in such a way we will get max profit
3. NOTE : we will buy stock on different day and sell it on the other day such that buying_day < selling_day

Solution : 

// Optimised approach

#include<bits/stdc++.h>
using namespace std;

int profit_max(vector<int> prices){

    // we will make a variable to store max profit
    int max_profit = 0;

    // Here we will consider to buy the stock on the first day
    int price_firstday = prices[0];

    // Iterate on the days except the first day
    for(int i=1;i<prices.size()-1;i++){
        
        if(prices[i] < price_firstday){
            price_firstday = prices[i];
        }
        else{
            int profit = prices[i] - price_firstday;
            max_profit = max(max_profit,profit);
        }
    }
    
    return max_profit;
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
    
    cout<<profit_max(prices);
}

Time complexity : O(n)
Space complexity : O(1)
