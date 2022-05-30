#include <bits/stdc++.h>
using namespace std;
int n;

bool safe(vector<vector<int>> &board, int r, int c) {
    for (int i = 0; i < c; i++) if (board[r][i] == 1) return false;
    for (int i = r, j = c; i >= 0 && j >= 0; i--,j--) if (board[i][j] == 1) return false;
    for (int i = r, j = c; i < n && j >= 0; i++,j--) if (board[i][j] == 1) return false;
    return true;
}

bool solve(vector<vector<int>> &board, int c) {
    if (c >= n) return true;
    else {
        for (int i = 0; i < n; i++)
        {
            if (safe(board, i,c)) {
                board[i][c] = 1;
                if (solve(board, c+1)) return true;
                board[i][c] = 0;
            }
        }
        return false;
    }
}

signed main()
{
    cout << "Enter the value of N\n";
    cin >> n;
    vector<vector<int>> board(100, vector<int> (100, 0));
    if (!solve(board, 0)) cout << "No Solution exists!\n";
    else {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        
    }
    return 0;
}