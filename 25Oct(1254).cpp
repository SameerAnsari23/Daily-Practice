class Solution {
public:
    int m, n;

    bool clo(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;

        if (grid[i][j]) return true;

        grid[i][j] = 1;

        return clo(grid, i+1, j) & clo(grid, i-1, j) & clo(grid, i, j+1) & clo(grid, i, j-1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) cnt += clo(grid, i, j);
            }
        }

        return cnt;
    }
};
