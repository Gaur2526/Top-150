Problem Statement Break Down : 

1. we have an array nums and an integer val 
2. we have to delete all the occurence of the val in nums in in-place manner
3. we have to return the length of the updated array the length will be the number of elements which are not equal to the val

Solution :

// Brute Force 

#include<bits/stdc++.h>
using namespace std;

void remove(vector<int> &nums,int val){
    
    sort(nums.begin(),nums.end());
    
    for(int i = 0;i<nums.size()-1;i++){
        
        if(nums[i] == val){
            for(int j = i+1;j<nums.size();j++){
                if(nums[j] != val){
                    swap(nums[i],nums[j]);
                    break;
                }
            }
        }
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
    
    int val;
    cin>>val;
    
    remove(nums,val);
    
    int cnt = 0;
    
    for(int i = 0;i<nums.size();i++){
        
        if(nums[i] != val) cnt++;
    }
    
    cout<<cnt<<endl;
    for(auto itr : nums){
        cout<<itr<<" ";
    }
    
}

Time complexity : O(n^2)
Space complexity : o(log n) because of the sort() function 

// Optimised approach

#include<bits/stdc++.h>
using namespace std;

int remove(vector<int> &nums,int val){
    
    int itr = 0;
    
    for(int i=0;i<nums.size();i++){
        
        if(nums[i] != val){
            nums[itr++] = nums[i];
        }
    }
    
    return itr;
    
}
int main(){
    
    int n;
    cin>>n;
    
    vector<int> nums;
    
    for(int i = 0;i<n;i++){
        
        int val;
        cin>>val;
        
        nums.push_back(val);
    }
    
    int val;
    cin>>val;
    
    int len = remove(nums,val);
    
    cout<<len<<endl;
    for(auto itr : nums){
        cout<<itr<<" ";
    } 
}

Time complexity : O(n)
Space complexity : O(1)
