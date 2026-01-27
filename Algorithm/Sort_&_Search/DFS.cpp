#include <iostream>
using namespace std;

int visited[7] = {0}; // this visited array must be outside of the function so that it cant call more than once
void DFS(int G[7][7], int start, int n)
{
    int j;
    if (visited[start] == 0)
    {

        cout << start << " ";
        visited[start] = 1;

        for (j = 0; j < n; j++)
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
    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 1, 0}};

    DFS(G, 4, 7);
}