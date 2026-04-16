#include <vector>
#include <queue>

using namespace std;

bool checkWin(int player, int n, const vector<vector<int>>& board) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // For Player 1 (Top to Bottom), start from any P1 cell in row 0
    for (int j = 0; j < n; j++) {
        if (board[0][j] == player) {
            q.push({0, j});
            visited[0][j] = true;
        }
    }

    int dx[] = {-1, -1, 0, 0, 1, 1};
    int dy[] = {0, 1, -1, 1, -1, 0};

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        if (r == n - 1) return true; // Reached the opposite side!

        for (int i = 0; i < 6; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && 
                board[nr][nc] == player && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    return false;
}