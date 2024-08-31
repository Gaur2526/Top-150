Problem Statement Break Down :

1. we have an integer array nums and a target value
2. we have to return two distinct indices such that :
   a) nums[i] == nums[j]
   b) abs(i-j)<=k


Solution :

// Optimised approach

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){

            if(mp.find(nums[i]) != mp.end() && i - mp[nums[i]]<=k) return true;

            mp[nums[i]] = i;

        }
        
        return false;
    }
};

Time complexity : O(n)
Space complexity : O(n)
  
