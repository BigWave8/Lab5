#include <iostream>
#include <stdio.h>
#include <math.h>
#define SIZEOFMATRIX 5
using namespace std;

class ArrayColumnDown
{
    friend void sortColumnOfMatrixDescending(ArrayColumnDown matrix[]);
    friend void inputMatrix(ArrayColumnDown matrix[]);
    friend void outputMatrix(ArrayColumnDown matrix[]);
    friend void functions(ArrayColumnDown matrix[]);

private:
    int column[SIZEOFMATRIX];

public:
    void merge(int *initialArray, int leftElementNumber, int middleElementNumber, int rightElementNumber)
    {
        int leftVariableElementNumber = leftElementNumber, middleVariableElementNumber = middleElementNumber + 1, indexOfExtraArray = 0;
        int extraArray[rightElementNumber - leftElementNumber + 1];
        while (leftVariableElementNumber <= middleElementNumber && middleVariableElementNumber <= rightElementNumber)
        {
            if (initialArray[leftVariableElementNumber] > initialArray[middleVariableElementNumber])
            {
                extraArray[indexOfExtraArray] = initialArray[leftVariableElementNumber];
                leftVariableElementNumber++;
            }
            else
            {
                extraArray[indexOfExtraArray] = initialArray[middleVariableElementNumber];
                middleVariableElementNumber++;
            }
            indexOfExtraArray++;
        }
        while (leftVariableElementNumber <= middleElementNumber)
        {
            extraArray[indexOfExtraArray] = initialArray[leftVariableElementNumber];
            indexOfExtraArray++;
            leftVariableElementNumber++;
        }
        while (middleVariableElementNumber <= rightElementNumber)
        {
            extraArray[indexOfExtraArray] = initialArray[middleVariableElementNumber];
            indexOfExtraArray++;
            middleVariableElementNumber++;
        }
        for (leftVariableElementNumber = leftElementNumber; leftVariableElementNumber <= rightElementNumber; leftVariableElementNumber++)
        {
            initialArray[leftVariableElementNumber] = extraArray[leftVariableElementNumber - leftElementNumber];
        }    
    }
    void mergeSort(int *initialArray, int leftElementNumber, int rightElementNumber)
    {
        int middleElementNumber = (leftElementNumber + rightElementNumber) / 2;
        if ((rightElementNumber - leftElementNumber) > 0)
        {
            mergeSort(initialArray, leftElementNumber, middleElementNumber);
            mergeSort(initialArray, middleElementNumber + 1, rightElementNumber);
        }
        merge(initialArray, leftElementNumber, middleElementNumber, rightElementNumber);
    }
};
void inputMatrix(ArrayColumnDown matrix[])
{
    std::cout << "Enter your matrix:" << std::endl;
    for (int jCount = 0; jCount < SIZEOFMATRIX; jCount++)
    {
        for (int iCount = 0; iCount < SIZEOFMATRIX; iCount++)
        {
            std::cin >> matrix[iCount].column[jCount];
        }
    }
}
void outputMatrix(ArrayColumnDown matrix[])
{
    std::cout << "This is your matrix:" << std::endl;
    for (int jCount = 0; jCount < SIZEOFMATRIX; jCount++)
    {
        for (int iCount = 0; iCount < SIZEOFMATRIX; iCount++)
        {
            std::cout << matrix[iCount].column[jCount] << '\t';
        }
        std::cout << std::endl;
    }
}

void sortColumnOfMatrixDescending(ArrayColumnDown matrix[])
{
    for (int iCount = 0; iCount < SIZEOFMATRIX; iCount++)
    {
        matrix[iCount].mergeSort(matrix[iCount].column, 0, SIZEOFMATRIX-1);
    }
}

void functions(ArrayColumnDown matrix[])
{
    double average, sum = 0;
    for (int jCount = 1; jCount < SIZEOFMATRIX; jCount++)
    {
        average = 1;
        for (int iCount = 0; iCount < SIZEOFMATRIX-1; iCount++)
        {
            if (jCount > iCount)
            {
            average *= matrix[iCount].column[jCount];
            }
        }
        average = pow(abs(average),(float)  1 / jCount);
        sum += average;
        std::cout << "The average of geom " << jCount << " = " << average << std::endl;
    }
    std::cout << "Sum of function =" << sum << std::endl;
}

int main()
{
    ArrayColumnDown matrix[SIZEOFMATRIX];
    inputMatrix(matrix);
    outputMatrix(matrix);
    sortColumnOfMatrixDescending(matrix);
    outputMatrix(matrix);
    functions(matrix);
    return 0;
}