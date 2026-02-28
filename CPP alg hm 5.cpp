#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleOutputCP(1251);
    ifstream file("C://ForInput//input.txt");

    if (!file.is_open()) 
    {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }
    int N;
    file >> N;

    int** matrix = new int* [N];
    for (int i = 0; i < N; i++) 
    {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            file >> matrix[i][j];
        }
    }

    file.close();
    cout << "Текстовый вид орграфа:" << endl;

    for (int i = 0; i < N; i++) 
    {
        cout << i + 1 << ": ";

        bool hasEdge = false;

        for (int j = 0; j < N; j++) 
        {
            if (matrix[i][j] == 1) 
            {
                cout << j + 1 << " ";
                hasEdge = true;
            }
        }

        if (!hasEdge) 
        {
            cout << "нет";
        }

        cout << endl;
    }
    for (int i = 0; i < N; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}