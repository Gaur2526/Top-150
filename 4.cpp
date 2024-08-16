Problem Statement Break Down : 

1. we have an integer array nums sorted in ascending order
2. we have to modify the array in the way such that no element occurs more than twice in the array and we have to done this in in-place manner
3. we have to return k which is the first k elements which occurs twice in the modified array

Solution :

// Brute force

#include<bits/stdc++.h>
using namespace std;

int remove(vector<int> &nums){
    
    int itr = 0;
    nums[itr++] = nums[0];
    for(int i=1;i<nums.size();i++){
        
        int cnt = 0;
        
        for(int j=0;j<itr;j++){
            if(nums[j] == nums[i]) cnt++;
        }
        
        if(cnt < 2){
            nums[itr++] = nums[i];    
        }
    }
    
    return itr;
}
int main(){
    
    int n;
    cin>>n;
    
    vector<int> nums;
    
    for(int i =0;i<n;i++){
        
        int val;
        cin>>val;
        
        nums.push_back(val);
    }
    
    int len = remove(nums);
    
    cout<<len<<endl;
    
    for(auto itr : nums){
        cout<<itr<<' ';
    }
}

Time complexity : O(n^2)
space complexity : O(1)

// Optimised approach

#include<bits/stdc++.h>
using namespace std;

int remove(vector<int> &nums){
    
   int cnt = 1;
   int itr = 1;
   
   for(int i = 1;i<nums.size();i++){
       
       if(nums[i-1] == nums[i]){
           cnt++;
       }
       else{
           cnt = 1;
       }
       
       if(cnt<=2){
           nums[itr++] = nums[i];
       }
   }
   
   return itr;
}
int main(){
    
    int n;
    cin>>n;
    
    vector<int> nums;
    
    for(int i =0;i<n;i++){
        
        int val;
        cin>>val;
        
        nums.push_back(val);
    }
    
    int len = remove(nums);
    
    cout<<len<<endl;
    
    for(auto itr : nums){
        cout<<itr<<' ';
    }
}

Time complexity : O(n)
Space complexity : O(1)
  
