Problem Statement Break Down :

1. we have an array nums of size n
2. we have to find the element which occurse more than [n/2] times

Solution :

// Brute force

#include<bits/stdc++.h>
using namespace std;

int majority(vector<int> nums){
    
    if(nums.size() == 1) return nums[0];
  
    sort(nums.begin(),nums.end());
    
    int cnt = 1;
    
    for(int i=0;i<nums.size()-1;i++){
        
        if(nums[i] == nums[i+1]){
            cnt++;
            
            if(cnt > nums.size()/2) return nums[i];
        }
        else{
            cnt = 1;
        }
    }
   
   return -1;
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
    
    cout<<majority(nums)<<endl;
}

Time complexity : O(nlogn)
Space complexity : O(logn)

// Optimised approach

#include<bits/stdc++.h>
using namespace std;

int majority(vector<int> nums){
    
    int test_element = nums[0];
    int cnt = 1;
    
    for(int i = 1;i<nums.size();i++){
        
        if(nums[i] == test_element){
            cnt++;
        }
        else{
            cnt--;
            
            if(cnt == 0){
                test_element = nums[i];
                cnt = 1;
            }
        }
    }
    
    cnt = 0;
    
    for(int num : nums){
        if(test_element == num) cnt++;
    }
    
    return (cnt > nums.size()/2) ? test_element : -1; 
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
    
    cout<<majority(nums)<<endl;
}

Time complexity : O(n)
Space complexity : O(1)

  
