Problem Statement Break Down :

1. we have an array nums sorted in ascending order 
2. we have to delete the duplicates from the array such that no element can occur more than once
3. relative order of element should be preserved
4. we have to return the number of unique elements in the array and array such that first k elements are the once which are unique after k elements whatever is there it doesn't matter

Solution :

// Brute force 

#include<bits/stdc++.h>
using namespace std;

int remove(vector<int> &nums){
    
    set<int> st;
    
    for(int i = 0;i<nums.size();i++){
        st.insert(nums[i]);
    }
    
    
   int itr = 0;
   
   for(auto it : st){
       nums[itr++] = it;
   }
    
    return st.size();
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
    
    int len = remove(nums);
    
    cout<<len<<endl;
    
    for(auto itr : nums){
        cout<<itr<<" ";
    }
}

Time complexity : O(nlogn)
Space complexity : O(n)

// Optimised approach

#include<bits/stdc++.h>
using namespace std;

int remove(vector<int> &nums){
    
   int itr = 0;
   
   for(int i=0;i<nums.size()-1;i++){
       
       if(nums[i+1] > nums[i]){
           nums[itr++] = nums[i];
       }
   }
   
   if(nums[nums.size()-1] > nums[nums.size()-2]){
       nums[itr] = nums[nums.size()-1]; 
   }
   return itr+1;
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
    
    int len = remove(nums);
    
    cout<<len<<endl;
    
    for(auto itr : nums){
        cout<<itr<<" ";
    }
}

Time complexity : O(n)
Space complexity : O(1)
