#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int visited[1000][1000];

bool isValid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool backtrack(vector<vector<char>> &board, const string &word, int r, int c, int pos)
{
    if (pos == word.size())
        return true; // Reached the end of the word

    if (!isValid(r, c, board.size(), board[0].size()) || visited[r][c] || board[r][c] != word[pos])
        return false;

    visited[r][c] = 1;

    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for (int k = 0; k < 4; k++)
    {
        int i = dirs[k][0];
        int j = dirs[k][1];

        if (backtrack(board, word, r + i, c + j, pos + 1))
            return true;
    }
    visited[r][c] = 0;

    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size(), m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0])
            {
                memset(visited, 0, sizeof(visited));
                if (backtrack(board, word, i, j, 0))
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<char>> board = {{'a', 'b'},
                                  {'c', 'd'}};
    string word = "acdb";
    cout << exist(board, word) << endl;

    return 0;
}