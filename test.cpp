//test function file
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int arr[7][7];
int sumMatrix(int row, int col, int m)
{
    int sum = 0;
    for (int i = row; i <= row + m - 1; i++)
    {
        for (int j = col; j <= col + m - 1; j++)
            sum += arr[i][j];
    }
    return sum;
}
bool checkIncreasedCol(int startRow, int startCol, int m)
{   
    for(int i = startCol; i <= startCol + m - 1; i++)
    {
        for(int j = startRow + 1; j <= startRow + m - 1; j++)
        {
            if(arr[j][i] < arr[j - 1][i])
                return false;
        }
    }
    return true;   
}
int main()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
            cin >> arr[i][j];
    }
    int m = 0;
    m = (4 % 7) > 2 ? (4 % 7) : 2;
    int lowestSum = 1000000;
    int sumTemp;
    int firstRow, firstCol;
    for (int k = 0; k <= 7 - m; k++)
    {
        for (int h = k; h <= 7 - m; h++)
        {
            sumTemp = sumMatrix(k, h, m);
            if (sumTemp < lowestSum)
            {
                lowestSum = sumTemp;
                firstCol = h;
                firstRow = k;
            }
        }
    }
    if (checkIncreasedCol(firstRow, firstCol, m))
        cout << "thanh cong";
    else    
        cout << "that bai";
    return 0;
}


