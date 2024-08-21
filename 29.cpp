Problem Statement Break Down :

1. we have an integer array nums
2. return all the triplets [nums[i], nums[j], nums[k]]
3. such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
4. Notice that the solution set must not contain duplicate triplets.

// Solution :

// Optimised approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        vector<vector<int>> res;

        for(int i=0;i<nums.size()-2;i++){

            if(i>0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = nums.size()-1;

            while(left < right){

                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0){

                    res.push_back( {nums[i],nums[left],nums[right]});

                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;

                }
                else if(sum < 0) left++;
                else right--;
            }
        }

        return res;
    }
};

Time complexity : O(n^2)
Space complexity : O(1)
