Problem Statement Break Down : 

1. we have an integer array nums of length n
2. in which the value of the each element is the longest jump it can made from that particular index
3. we have to return the min number of jump needed to reach the last index of the array

Solution :

// Optimised approach

#include<bits/stdc++.h>
using namespace std;

int getcnt(vector<int> nums){
    

    if(nums.size() <= 1) return 0;

    int jmp_cnt = 0;
    int farthest = 0;
    int endpoint = 0;

    for(int i=0;i<nums.size()-1;i++){

        farthest = max(farthest,i + nums[i]);

        if(i == endpoint){

           jmp_cnt++;
           endpoint = farthest;

         if(endpoint >= nums.size()-1) break;
         
        }

    }

    return jmp_cnt;
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
    
    cout<<getcnt(nums);
}

Time complexity : O(n)
Space complexity : O(1)
