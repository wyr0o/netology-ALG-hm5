#include <iostream>
#include <fstream>

using namespace std;

void dfs(int** graph, int vertex, bool* visited, int* order, int& pos, int N)
{
    visited[vertex] = true;

    for (int v = 0; v < N; v++)
    {
        if (graph[vertex][v] == 1 && !visited[v])
        {
            dfs(graph, v, visited, order, pos, N);
        }
    }

    order[pos] = vertex + 1;
    pos--;
}

int main()
{
    ifstream file("C://ForInput//input.txt");

    if (!file.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    int N;
    file >> N;

    int** graph = new int* [N];
    for (int i = 0; i < N; i++)
        graph[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            file >> graph[i][j];

    file.close();

    bool* visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    int* order = new int[N];
    int pos = N - 1;

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            dfs(graph, i, visited, order, pos, N);
        }
    }

    cout << "Топологический порядок вершин: ";
    for (int i = 0; i < N; i++)
        cout << order[i] << " ";

    cout << endl;

    for (int i = 0; i < N; i++)
        delete[] graph[i];

    delete[] graph;
    delete[] visited;
    delete[] order;

    return 0;
}