#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

#define N 400   //matrix size
#define N2 16000 //array size
#define value 2.00001 //matrix value

double seconds()
{
  return double(clock())/CLOCKS_PER_SEC;
}

//matrix inversion for float performance evaluation
void matrixMul(float mat1[N][N], float mat2[N][N], float result[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      result[i][j] = 0;
      for (int k = 0; k < N; k++)
        result[i][j] += mat1[i][k] * mat2[k][j];
    }
  }
}

//bubble sort for integer operation performance evaluation
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int array[], int n)
{
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (array[j] > array[j + 1])
        swap(&array[j], &array[j + 1]);
} 

int main() { 
    float res[N][N]; // To store result 
    float mat1[N][N];
    float mat2[N][N];
    fill(*mat1, *mat1 + N*N, value);
    fill(*mat2, *mat2 + N*N, value);
    double start1 = seconds();
    int count1 = 0;
    while(seconds() < start1 + 10)
    {
      matrixMul(mat1, mat2, res);
      count1++;
    }
    double end1 = seconds();
    double vcount1 = count1 * 60 / (end1 - start1);
    cout << "Number of matrix inversion operations: " << vcount1 << " in " << (end1 - start1) << " seconds." << endl;

    int arr[N2];
    for (int i = 0; i < N2; i++)
    {
      arr[i] = N2 - i;
    }
    int n = sizeof(arr)/sizeof(arr[0]); 
    int count2 = 0;
    double start2 = seconds();
    while(seconds() < start2 + 10)
    {
      bubbleSort(arr, n);
      count2 ++;
    }
    double end2 = seconds();
    double vcount2 = count2 * 60 / (end2 - start2);
    cout << "Number of bubble sort operations: " << vcount2 << " in " << (end2 - start2) << " seconds." << endl;

    double average = (2 * vcount1 * vcount2) / (vcount1 + vcount2);
    cout << "Average speed is: " << average << endl;

    char key;
    cout << "Close the window with any key.";
    cin >> key;

    return 0; 
}