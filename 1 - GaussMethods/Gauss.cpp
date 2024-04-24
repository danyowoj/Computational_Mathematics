#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

// prints the matrix
void print(double **matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << "\n";
    }
}

// changes matrix via Gauss method
void Gauss(double **matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int k = i + 1; k < rows; k++)
        {
            double ratio = matrix[k][i] / matrix[i][i];
            for (int j = i; j < columns; j++)
            {
                matrix[k][j] -= ratio * matrix[i][j];
            }
        }
    }
}

// changes matrix via Modified Gauss method
void ModifiedGauss(double **matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        int id_max = i;
        double max_value = abs(matrix[i][i]);
        for (int k = i + 1; k < rows; k++)
        {
            double value = abs(matrix[k][i]);
            if (value > max_value)
            {
                id_max = k;
                max_value = value;
            }
        }
        std::swap(matrix[i], matrix[id_max]);

        for (int k = i + 1; k < rows; k++)
        {
            double ratio = matrix[k][i] / matrix[i][i];
            for (int j = i; j < columns; j++)
            {
                matrix[k][j] -= ratio * matrix[i][j];
            }
        }
    }
}

// solve the system of equalations
void solve(double **matrix, int rows, int columns)
{
    double *solution = new double[rows];

    for (int i = rows - 1; i >= 0; i--)
    {
        solution[i] = matrix[i][columns - 1];
        for (int j = i + 1; j < columns; j++)
        {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    for (int i = 0; i < rows; i++)
    {
        std::cout.precision(2);
        std::cout << i + 1 << " : " << solution[i] << std::endl;
    }
}

int main()
{
    int rows, columns;

    // open the file
    std::ifstream G("C:/Users/latsu/GitHub_projects/Computational_Mathematics/Gauss_methods/input.txt");
    if (!G)
    {
        std::cout << "File could not be open.\n";
        return -1;
    }

    // read number of rows and columns
    G >> rows;
    G >> columns;

    // create a Gauss Matrix matrix
    double **GaussMatrix = new double *[rows];
    for (int i = 0; i < rows; ++i)
        GaussMatrix[i] = new double[columns];

    // fill the GaussMatrix matrix
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            G >> GaussMatrix[i][j];

    // close the file
    G.close();

    std::cout << "\nGauss matrix:" << std::endl;
    print(GaussMatrix, rows, columns);

    std::cout << "\nGauss matrix changed:" << std::endl;
    Gauss(GaussMatrix, rows, columns);
    print(GaussMatrix, rows, columns);

    std::cout << "\nGauss matrix solution:" << std::endl;
    solve(GaussMatrix, rows, columns);

    std::cout << "\n------------------------------" << std::endl;

    // open the file
    std::ifstream MG("C:/Users/latsu/GitHub_projects/Computational_Mathematics/Gauss_methods/input.txt");
    if (!MG)
    {
        std::cout << "File could not be open.\n";
        return -1;
    }

    // read number of rows and columns
    MG >> rows;
    MG >> columns;

    // create a Modified Gauss Matrix matrix
    double **ModifiedGaussMatrix = new double *[rows];
    for (int i = 0; i < rows; ++i)
        ModifiedGaussMatrix[i] = new double[columns];

    // fill the Modified Gauss matrix
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            MG >> ModifiedGaussMatrix[i][j];

    // close the file
    MG.close();

    std::cout << "\nModified Gauss matrix:" << std::endl;
    print(ModifiedGaussMatrix, rows, columns);

    std::cout << "\nModified Gauss matrix changed:" << std::endl;
    ModifiedGauss(ModifiedGaussMatrix, rows, columns);
    print(ModifiedGaussMatrix, rows, columns);

    std::cout << "\nModified Gauss matrix solution:" << std::endl;
    solve(ModifiedGaussMatrix, rows, columns);

    // free up the memory
    for (int i = 0; i < rows; i++)
        delete[] GaussMatrix[i];
    delete[] GaussMatrix;

    for (int i = 0; i < rows; i++)
        delete[] ModifiedGaussMatrix[i];
    delete[] ModifiedGaussMatrix;

    return 0;
}