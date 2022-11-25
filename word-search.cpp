//https://leetcode.com/problems/word-search/

int MX = 7;
bool isFound = false;
int dx[4] = { +1, +0, +0, -1};
int dy[4] = { +0, -1, +1, +0};
int row = 0, col = 0;

bool dfs(vector<vector<char>>& board, string &word, vector<vector<bool>>& vis, int r, int c, int pos) {
	vis[r][c] = 1;
	pos += 1;
	if (pos == word.size()) {
		return true;
	}

	for (int i = 0; i < 4; i++) {
		int xx = r + dx[i];
		int yy = c + dy[i];
		if (xx >= 0 && xx < row && yy >= 0 && yy < col && !vis[xx][yy]) {
			if (board[xx][yy] == word[pos]) {
				if (dfs(board, word, vis, xx, yy, pos)) return true;
			}
		}
	}





	vis[r][c] = 0;

	return false;
}

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		row = board.size();
		col = board[0].size();
		vector<vector<bool>> vis(row, vector<bool>(col, false));

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (board[i][j] == word[0]) {

					bool isOk = dfs(board, word, vis, i, j, 0);
					if (isOk) return true;
				}
			}
		}


		return false;
	}
};