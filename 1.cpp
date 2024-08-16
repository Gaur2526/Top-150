Problem statement Break down:
## Link to problem
[Click me](https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150)
1. we have two arrays nums1 and nums2 which are sorted in ascending order 
2. Two integers m and n where m is the size of nums1 and n is the size of nums2
3. The actual size of nums1 is m+n where n elements are zeroes we have provided extra size to accomodate final sorted array in nums1
4. We have to merge both the arrays in sorted manner

Solution : 

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1,vector<int> &nums2){
    
    vector<int> dummy;
    
    for(int i = 0;i<nums1.size() - nums2.size();i++){
        
        dummy.push_back(nums1[i]);
    }
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    while(i < dummy.size() && j < nums2.size()){
        
        if(dummy[i] <= nums2[j]){
            nums1[k++] = dummy[i++];
        }
        else{
            nums1[k++] = nums2[j++];
        }
    }
    
    while(i < dummy.size()){
         nums1[k++] = dummy[i++];
    }
    
    while(j < nums2.size()){
        nums1[k++] = nums2[j++];
    }
}
int main(){
    
    int m,n;
    cin>>m>>n;
    vector<int> nums1,nums2;

    for(int i=0;i<m+n;i++){
        int val;
        cin>>val;
        
        nums1.push_back(val);
    }
    
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        
        nums2.push_back(val);
    }
    
    merge(nums1,nums2);
    
    for(auto itr : nums1){
        cout<<itr<<" ";
    }
}

Time complexity : O(m)
Space complexity : O(m-n)
