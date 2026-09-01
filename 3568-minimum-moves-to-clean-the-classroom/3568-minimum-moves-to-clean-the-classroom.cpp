class Solution {
public:
    int minMoves(vector<string>& g, int E) {
        int m = g.size(), n = g[0].size();
        int sr, sc, k = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        // Find S and give IDs to L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (g[i][j] == 'L') {
                    id[i][j] = k++;
                }
            }
        }

        // No litter
        if (k == 0) return 0;

        int masks = 1 << k;

        // visited[row][col][energy][mask]
        int total = m * n * (E + 1) * masks;
        vector<char> visited(total, 0);

        auto getId = [&](int r, int c, int e, int mask) {
            return (((r * n + c) * (E + 1) + e) * masks + mask);
        };

        // r, c, energy, mask
        queue<array<int, 4>> q;

        q.push({sr, sc, E, 0});
        visited[getId(sr, sc, E, 0)] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto cur = q.front();
                q.pop();

                int r = cur[0];
                int c = cur[1];
                int e = cur[2];
                int mask = cur[3];

                if (mask == masks - 1)
                    return moves;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        g[nr][nc] == 'X')
                        continue;

                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nm = mask;

                    // Collect litter
                    if (g[nr][nc] == 'L') {
                        nm |= (1 << id[nr][nc]);
                    }

                    // Recharge
                    if (g[nr][nc] == 'R') {
                        ne = E;
                    }

                    int state = getId(nr, nc, ne, nm);

                    if (!visited[state]) {
                        visited[state] = 1;
                        q.push({nr, nc, ne, nm});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};