Problem Statement Break Down :

1. we have a sorted unique integers nums
2. a range [a,b] is the set of all integers from a to b (inclusive)
3. we have to return the list of consecutives 
4. Each range [a,b] in the list should be output as:
    a) "a->b" if a != b
    b) "a" if a == b


Solution :

// Optimised approach

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> res;

        for(int i=0;i<nums.size();i++){

            int start = nums[i];

            while(i+1 < nums.size() && nums[i+1] == nums[i] + 1){
                i++;
            }

            int end = nums[i];

            if(start == end) res.push_back(to_string(start));
            else res.push_back(to_string(start) + "->" + to_string(end));
        }

        return res;
    }
};

Time complexity : O(n)
Space complexity : O(1)
