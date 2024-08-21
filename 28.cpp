Problem Statement Break Down :

1. You are given an integer array height of length n.
2. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
3. Find two lines that together with the x-axis form a container, such that the container contains the most water.
4. Return the maximum amount of water a container can store.

Solution : 

// Brute force

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int area = INT_MIN;
    
        for(int i=0;i<height.size()-1;i++){
        
             for(int j=i+1;j<height.size();j++){
            
                int len = min(height[i],height[j]);
                int width = j-i;
                area = max(area, len * width );
            }
        }
    
    return area;
    }
};

Time complexity : O(n^2)
Space complexity : O(1)

// Optimised approach

class Solution {
public:
    int maxArea(vector<int>& height) {

        int area = INT_MIN;

        int left = 0;
        int right = height.size()-1;

        while(left < right){

            int length = min(height[left],height[right]);
            int width = abs(right - left);

            area = max(area, length * width);

            if(height[left] < height[right]) left++;
            else right--;
        }

        return area;
        
    }
};

Time complexity : O(n)
Space complexity : O(1)
