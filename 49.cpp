Problem Statement Break Down :

1. we have an 2d array intervals
2. we have to merged those intervals which overlaps means ones ending value is lesser or equal to the ones starting value
3. we have to return the merged array


Solution : 


// Optimised approach

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.empty()) return {};

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> merged;

        for(auto interval : intervals){

            if(merged.empty() || merged.back()[1] < interval[0]){
                merged.push_back(interval);
            }
            else{

                merged.back()[1] = max(merged.back()[1],interval[1]);
            }
        }
        return merged;
        
    }
};

Time complexity : O(nlogn)
Space complexity : O(n)
