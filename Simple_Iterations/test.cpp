#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "math.h"

// prints matrix A | B
void print(double **matrix, double *array, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << array[i] << "\n";
    }
}

// prints a matrix
void print(double **matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << "\n";
    }
}

// prints an array
void print(double *array, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << array[i];
    std::cout << "\n";
}

// modifies matrix
void modify(double **matrix, double *array, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        int modifier = matrix[i][i];
        array[i] /= modifier;
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] /= modifier;
        }
    }
}

// returns norm of the matrix
double norm(double **matrix, int rows, int columns)
{
    double *x = new double[rows];
    double n;
    for (int i = 0; i < rows; i++)
    {
        n = 0;
        for (int j = 0; j < columns; j++)
            n += fabs(matrix[i][j]);
        x[i] = n;
    }

    double max = 0;
    for (int i = 0; i < rows; i++)
        if (x[i] >= max)
            max = x[i];

    delete[] x;

    return max;
}

// return norm of the array
double norm(double *array, int rows)
{
    double max = 0;
    for (int i = 0; i < rows; i++)
        if (fabs(array[i]) >= max)
            max = fabs(array[i]);

    return max;
}

// multiplies two matrices
// C = A * B
void multiplication(int rows, int columns, double **A, double *B, double *C)
{
    for (int i = 0; i < rows; i++)
        C[i] = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            C[i] += A[i][j] * B[j];
        }
    }
}

// subtract array A from array B
// array C is a result
void subtraction(int N, double *A, double *B, double *C)
{
    for (int i = 0; i < N; i++)
    {
        C[i] = A[i] - B[i];
    }
}

// the method of simple iterations
void SIM(int rows, int columns, double *B, double **C)
{
    // counting x0
    double *xPrev = new double[rows];
    for (int i = 0; i < rows; i++)
        xPrev[i] = 0;

    // preparing new array for the future
    double *xNext = new double[rows];
    for (int i = 0; i < rows; i++)
        xNext[i] = 0;

    // counting x^(k+1)
    for (int i = 1; i <= rows; i++)
    {
        // std::cout << "\ni = " << i << std::endl;
        for (int j = 0; j <= rows; j++)
        {
            // C * x^k
            multiplication(rows, columns, C, xPrev, xNext);
        }
        /*
        std::cout << "\nC * x^k:" << std::endl;
        for (int l = 0; l < rows; l++)
        {
            std::cout << xNext[l] << std::endl;
        }
        */
        // B - C * x^k
        subtraction(rows, B, xNext, xPrev);
        /*
        std::cout << "\nB - C * x^k:" << std::endl;
        for (int i = 0; i < rows; i++)
        {
            std::cout << xPrev[i] << std::endl;
        }
        */
    }

    std::cout << "\nSimple iteratyions method:" << std::endl;
    for (int i = 0; i < rows; i++)
    {
        std::cout << xPrev[i] << std::endl;
    }

    delete[] xPrev;
    delete[] xNext;
}

// the Seidel Method
void Seidel(int rows, double **A, double *B)
{
    // an array of unknown values in the previous step
    // setting to "0" according to the method
    double *xPrevious = new double[rows];
    for (int i = 0; i < rows; i++)
        xPrevious[i] = 0;

    // setting the accuracy of calculations
    double epsilon = 0.001;

    while (true)
    {
        // an array of unknown values in the current step
        double *xCurrent = new double[rows];

        // calculating the values of the unknowns at the current
        // iteration according to the theoretical formulas
        for (int i = 0; i < rows; i++)
        {
            // initialize the i-th unknown with the value of the
            // free term of the i-th row of the matrix
            xCurrent[i] = B[i];

            // subtracting the sum for all unknowns other than the i-th
            for (int j = 0; j < rows; j++)
            {
                // with j < i, we can use the values of the unknowns
                // already calculated at this iteration
                if (j < i)
                    xCurrent[i] -= A[i][j] * xCurrent[j];
                // for j > i, we use the values from the last iteration
                if (j > i)
                    xCurrent[i] -= A[i][j] * xPrevious[j];
            }
            // dividing by the coefficient for the i-th unknown
            xCurrent[i] /= A[i][i];
        }
        // Calculating the current error relative to the
        // previous iteration
        double error = 0.0;

        for (int i = 0; i < rows; i++)
            error += abs(xCurrent[i] - xPrevious[i]);

        // if the required accuracy is achieved,
        // then we complete the process
        if (error < epsilon)
        {
            delete[] xCurrent;
            break;
        }

        // moving on to the next iteration, so
        // that the current values are unknown
        // become values in the previous iteration
        for (int i = 0; i < rows; i++)
            xPrevious[i] = xCurrent[i];

        delete[] xCurrent;
    }

    std::cout << "\nSeidel method:" << std::endl;
    for (int i = 0; i < rows; i++)
        std::cout << xPrevious[i] << std::endl;

    delete[] xPrevious;
}

int main()
{
    int rows, columns;

    // open the file to create an "A" matrix
    std::ifstream A_file("C:/Users/latsu/GitHub_projects/Computational_Mathematics/Simple_Iterations/A.txt");
    if (!A_file)
    {
        std::cout << "File 'A.txt' could not be open.\n";
        return -1;
    }

    // read number of rows and columns
    A_file >> rows;
    A_file >> columns;

    // create an "A" matrix
    double **A = new double *[rows];
    for (int i = 0; i < rows; i++)
        A[i] = new double[columns];

    // fill the "A" matrix
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            A_file >> A[i][j];

    // close the file
    A_file.close();

    // open the file to create a "B" array
    std::ifstream B_file("C:/Users/latsu/GitHub_projects/Computational_Mathematics/Simple_Iterations/B.txt");
    if (!B_file)
    {
        std::cout << "File 'B.txt' could not be open.\n";
        return -1;
    }

    // create the "B" array
    double *B = new double[rows];

    // fill the "B" array
    for (int i = 0; i < rows; i++)
        B_file >> B[i];

    // close the file
    B_file.close();

    std::cout << "\nMatrix:" << std::endl;
    print(A, B, rows, columns);

    modify(A, B, rows, columns);

    /*
    std::cout << "\nModified matrix:" << std::endl;
    print(A, B, rows, columns);
    */

    // creating matrix "C"
    double **C = new double *[rows];
    for (int i = 0; i < rows; ++i)
        C[i] = new double[columns];

    // fill matrix "C"
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            C[i][j] = A[i][j];
        C[i][i] = 0;
    }

    // std::cout << "\nNorm of 'C' = " << norm(C, rows, columns) << std::endl;
    // std::cout << "Norm of 'B' = " << norm(B, rows) << std::endl;

    SIM(rows, columns, B, C);

    Seidel(rows, A, B);

    // freeing up the memory
    for (int i = 0; i < rows; i++)
        delete[] A[i];
    delete[] A;

    delete[] B;

    for (int i = 0; i < rows; i++)
        delete[] C[i];
    delete[] C;

    return 0;
}