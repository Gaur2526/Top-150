Problem Break Down : 

1. we have an integer array nums 
2. we have to return an integer array which stores the product of numbers means it will the product of the numbers except nums[i]
3. it will be guaranteed that the product is in the range of 32-bit
4. we have to done it in O(n)

Solution :

// Brute force 

#include<bits/stdc++.h>
using namespace std;

void product(vector<int> nums){
    
    vector<int> ans;
    
    for(int i=0;i<nums.size();i++){
        
        int prod = 1;
        
        for(int j=0;j<nums.size();j++){
            
            if(j != i){
                prod = prod * nums[j];
            }
        }
        
        
        ans.push_back(prod);
    }
    
    for(int num : ans){
        cout<<num<<" ";
    }
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
    
   product(nums);
}

Time complexity : O(n^2)
Space complexity : O(n)

// Optimised approach

#include<bits/stdc++.h>
using namespace std;

void product(vector<int> nums){
    
    vector<int> ans(nums.size(),1);

    int prefix = 1;

    for(int i=0;i<nums.size();i++){

        ans[i] = prefix;
        prefix = prefix * nums[i];
    }
        
    int suffix = 1;

    for(int i=nums.size()-1;i>=0;i--){
        ans[i] = ans[i] * suffix;
        suffix = suffix * nums[i];
    }
     
    
    for(int num : ans){
        cout<<num<<" ";
    }
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
    
   product(nums);
}

Time complexity : O(n)
Space complexity : O(1)
