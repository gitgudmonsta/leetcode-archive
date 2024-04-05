class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int lo, hi, row, col;

        row = n, lo = 0, hi = n;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if(matrix[mid][m - 1] < target) 
                lo = mid + 1;
            else {
                row = min(row, mid);
                hi = mid;
            }
        }
        if(row == n) return false;

        col = m, lo = 0, hi = m;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if(matrix[row][mid] < target) {
                lo = mid + 1;
            }
            else {
                col = min(col, mid);
                hi = mid;
            }
        }
        if(col == m) return false;

        return (matrix[row][col] == target);
    }
};
