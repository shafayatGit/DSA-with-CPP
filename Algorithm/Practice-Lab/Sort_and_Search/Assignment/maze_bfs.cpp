#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, int rows, int cols)
{
    vector<vector<int>> steps(rows, vector<int>(cols, -1));
    queue<pair<int, int>> bfsQueue;

    bfsQueue.push({0, 0});
    steps[0][0] = 0;

    int rowMove[4] = {-1, 1, 0, 0};
    int colMove[4] = {0, 0, -1, 1};

    while (!bfsQueue.empty())
    {
        auto [currentRow, currentCol] = bfsQueue.front();
        bfsQueue.pop();

        if (currentRow == rows - 1 && currentCol == cols - 1)
            return steps[currentRow][currentCol];

        for (int d = 0; d < 4; d++)
        {
            int nextRow = currentRow + rowMove[d];
            int nextCol = currentCol + colMove[d];

            if (nextRow >= 0 && nextRow < rows &&
                nextCol >= 0 && nextCol < cols &&
                steps[nextRow][nextCol] == -1 &&
                grid[nextRow][nextCol] == 0)
            {
                steps[nextRow][nextCol] = steps[currentRow][currentCol] + 1;
                bfsQueue.push({nextRow, nextCol});
            }
        }
    }

    return -1;
}

int main()
{
    int totalRows, totalCols;
    cin >> totalRows >> totalCols;

    vector<vector<int>> matrix(totalRows, vector<int>(totalCols));

    for (int i = 0; i < totalRows; i++)
    {
        for (int j = 0; j < totalCols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int answer = shortestPath(matrix, totalRows, totalCols);
    cout << "Minimum steps: " << answer << endl;

    return 0;
}
