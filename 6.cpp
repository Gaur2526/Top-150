Problem Statement Break Down :

1. we have an integer array nums and an integer k
2. we have to rotate the array k time towards right
3. k>0

Solution : 

// Brute force
  
#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums,int k){
    
  while(k>0){
      
      for(int i=nums.size()-2;i>=0;i--){
         swap(nums[i] , nums[i+1]);
      }
      k--;
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
    
    int k;
    cin>>k;
    
    rotate(nums,k);
    
    for(auto itr : nums){
        cout<<itr<<" ";
    }
}

Time complexity : O(k*n)
Space complexity : O(1)

// Optimised approach

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums,int k){
  
  // if k>n so we normalize it 
  k = k%nums.size();
  
  // step1 : reverse the whole array
  reverse(nums.begin(),nums.end());

  // step 2 : reverse the first k elements  
  reverse(nums.begin(),nums.begin()+k);
  
  // step 3 : reverse the nums.size()-k elements
  reverse(nums.begin()+k,nums.end());
    
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
    
    int k;
    cin>>k;
    
    rotate(nums,k);
    
    for(auto itr : nums){
        cout<<itr<<" ";
    }
}

Time complexity : O(n)
Space complexity : O(1)
