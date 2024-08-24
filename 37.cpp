Problem Statement Break Down :

1. we have an m * n integer matrix 
2. we have to set an entire row and col equals to zero if any of the element is zero
3. we have to do this in in-place manner

Solution : 

// Optimised approach

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        bool firstrowzero = false;
        bool firstcolzero = false;

        for(int i=0;i<matrix[0].size();i++){

            if(matrix[0][i] == 0) firstrowzero = true;
        }

        for(int j = 0;j<matrix.size();j++){

            if(matrix[j][0] == 0) firstcolzero = true;
        }

        for(int i=1;i<matrix.size();i++){

            for(int j=1;j<matrix[0].size();j++){

                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){

                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(firstrowzero){

            for(int i=0;i<matrix[0].size();i++){
                matrix[0][i] = 0;
            }
        }

        if(firstcolzero){

            for(int i=0;i<matrix.size();i++){

                matrix[i][0] = 0;
            }
        }
    }
};

Time complexity : O(n * m)
Space complexity : O(1)
