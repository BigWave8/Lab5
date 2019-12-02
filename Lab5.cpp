#include <iostream>
#include <stdio.h>
#include <math.h>

class ArrayColumnDown
{
    friend void sortMatrix(ArrayColumnDown matrix[]);
    friend void inputMatrix(ArrayColumnDown matrix[]);
    friend void outputMatrix(ArrayColumnDown matrix[]);
    friend void Functions(ArrayColumnDown matrix[]);

private:
    int column[5];

public:
    void merge(int *A, int left, int middle, int right)
    {
        int i = left, j = middle + 1, k = 0;
        int T[right - left + 1];
        while (i <= middle && j <= right)
        {
            if (A[i] > A[j])
            {
                T[k] = A[i];
                i++;
            }
            else
            {
                T[k] = A[j];
                j++;
            }
            k++;
        }
        while (i <= middle)
        {
            T[k] = A[i];
            k++;
            i++;
        }
        while (j <= right)
        {
            T[k] = A[j];
            k++;
            j++;
        }
        for (i = left; i <= right; i++)
            A[i] = T[i - left];
    }
    void mergesort(int *A, int left, int right)
    {
        int middle = (left + right) / 2;
        if ((right - left) > 0)
        {
            mergesort(A, left, middle);
            mergesort(A, middle + 1, right);
        }
        merge(A, left, middle, right);
    }
};
void inputMatrix(ArrayColumnDown matrix[])
{
    std::cout << "Enter your matrix:" << std::endl;
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            std::cin >> matrix[i].column[j];
        }
    }
}
void outputMatrix(ArrayColumnDown matrix[])
{
    std::cout << "This is your matrix:" << std::endl;
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            std::cout << matrix[i].column[j] << '\t';
        }
        std::cout << std::endl;
    }
}

void sortMatrix(ArrayColumnDown matrix[])
{
    for (int i = 0; i < 5; i++)
    {
        matrix[i].mergesort(matrix[i].column, 0, 4);
    }
}

void Functions(ArrayColumnDown matrix[])
{
    double average, sum = 0;
    for (int j = 1; j < 5; j++)
    {
        average = 1;
        for (int i = 0; i < 4; i++)
        {
            if (j > i)
            {
            average *= matrix[i].column[j];
            }
        }
        average = pow(abs(average),(float)  1 / j);
        sum += average;
        std::cout << "The average of geom " << j << " = " << average << std::endl;
    }
    std::cout << "Sum of function =" << sum << std::endl;
}

/*float Functions(int arr[n][n]) {
  int i, j, multiply = 1;
  double geom=0, sum=0;
  for (i = 0; i < n - 1; i++) {
    for (j = 1; j < n; j++) {
      if (j > i)
        multiply *= arr[i][j];
    }
    geom = pow(abs(multiply),(float)  1 / (n - 1 - i));
    multiply = 1;
    printf("%lf   ", geom);
    sum += geom;
  }
  printf("\n%lf", sum);
  return 0;
}*/

int main()
{
    ArrayColumnDown matrix[5];
    inputMatrix(matrix);
    outputMatrix(matrix);
    sortMatrix(matrix);
    outputMatrix(matrix);
    Functions(matrix);
    return 0;
}