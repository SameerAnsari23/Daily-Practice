class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0 && !vis[i][j]) {
                    long long island = 0;
                    queue<pair<int, int>>q;
                    q.push({i, j}) ;
                    vis[i][j] = true;
                    while(!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();
                        int r = curr.first;
                        int c = curr.second;

                        island += grid[r][c];

                        for(int move = 0; move < 4; move++) {
                            int nr = r + dr[move];
                            int nc = c + dc[move];
                            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] > 0) {
                                vis[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                    if(island % k == 0) cnt++;
                }
            }
        }
        return cnt;
        
    }
};
