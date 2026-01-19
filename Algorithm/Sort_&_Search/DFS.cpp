#include <iostream>
using namespace std;

void DFS(int G[8][8], int start, int n)
{
     int visited[8] = {0};
    if (visited[start] == 0)
    {
        cout << start << " ";
        visited[start] = 1;

        for (int j = 0; j < n; j++)
        {

            if (G[start][j] == 1 && visited[j] == 0)
            {
                DFS(G, j, n);
            }
        }
    }
}

int main()
{
    int G[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 0, 1, 0, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0}, {0, 1, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}};

    DFS(G, 4, 8);
}