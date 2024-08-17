Problem Statement Break Down :

1. we have an array nums in which we are initially at the position 0 
2. Each index value is the longest jump we can made from that particular index
3. we have to find whether we can reach the end of the array or not 
4. if yes then return true otherwise false

Solution : 

// Optimised approach

#include<bits/stdc++.h>
using namespace std;

bool isreached(vector<int> nums){
    
      int dist = 0;

      for(int i=0;i<nums.size();i++){

            if(i > dist) return false;

            dist = max(dist,i + nums[i]);

            if(dist >= nums.size()-1) return true;
      }

    return false;
}

int main(){
    
    int n;
    cin>>n;
    
    vector<int> nums;
    
    for(int i=0;i<n;i++){
        
        int val;
        cin>>val;
        
        nums.push_back(val);
    }
    
    cout<<isreached(nums);
}

Time complexity : O(n)
Space complexity : O(1)
