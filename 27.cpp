Problem Statement Break Down :

1. we have an integer array numbers and an integer target
2. we have to return indices of two numbers which will on adding equal to the target
3. we have to return index+1 if 0-based indexing is used 
4. any number can't be used twice 
5. the array is sorted in ascending order

Solution :

// Brute force  

#include<bits/stdc++.h>
using namespace std;

void getindices(vector<int> nums,int target){
    
    vector<int> index;
    
    for(int i=0;i<nums.size()-1;i++){
        
        for(int j=i+1;j<nums.size();j++){
            
            if(nums[i] + nums[j] == target){
                index.push_back(i + 1);
                index.push_back(j  + 1);
            }
        }
    }
    
    for(auto itr : index){
        cout<<itr<<" ";
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
    
    int target;
    cin>>target;
    
   getindices(nums,target);
}

Time complexity : O(n^2)
Space complexity : O(k) where k is the size of the index vector
Note : It will provide TLE but it's an approach you can use where code constraints are not large

// Optimised approach

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
           int left = 0;
           int right = numbers.size()-1;
      
           vector<int> res;
      
           while(left < right){
          
             if(numbers[left] + numbers[right] == target){
                    res.push_back(left + 1);
                    res.push_back(right + 1);
                    break;
                }

             else if(numbers[left] + numbers[right] < target){
                  left++;
                }

             else{
                  right--;
                }
            }

        return res;
    }
};

Time complexity : O(n)
Space complexity : O(1) we will not count space consumed by the res vector because it is the part of the function and consumes minimal space
