// https://leetcode.com/problems/set-matrix-zeroes
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool isRowHasZero = false;
        bool isColHasZero = false;

        // Check if first row and column has zero
        for (int i=0; i<m; i++)
            if (matrix[i][0] == 0)
                isColHasZero = true;
        for (int j=0; j<n; j++)
             if (matrix[0][j] == 0)
                isRowHasZero = true;

        // Store states of each row and column in the first row and column
        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
                if (matrix[i][j] == 0)
                    matrix[0][j] = matrix[i][0] = 0;

        // Set zeros except first row and column
        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        
        // Set first row and column to zero if they had zero
        if (isRowHasZero)
            for (int j=0; j<n; j++)
                matrix[0][j] = 0;
        if (isColHasZero)
            for (int i=0; i<m; i++)
                matrix[i][0] = 0;
        
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    s.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        cout << "[";
        for (int j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << " ";
        cout << "]" << endl;
    }
}
