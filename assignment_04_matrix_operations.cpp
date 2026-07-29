// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void transposeMatrix(int matrix[10][10], int rows, int cols);
void addMatrices(int matrixA[10][10], int matrixB[10][10], int result[10][10], int rows, int cols);
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int result[10][10], int rowsA, int colsA, int colsB);
void displayMatrix(int matrix[10][10], int rows, int cols);


int main()
{
    int rows, cols;

    int matrix[10][10];

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;


    // Read Matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }


    // PART A - Transpose
    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix, rows, cols);

    cout << "\nTransposed Matrix:\n";
    transposeMatrix(matrix, rows, cols);



    // PART B - Addition
    int matrixB[10][10];
    int sum[10][10];

    cout << "\nEnter second matrix for addition:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }

    cout << "\nMatrix Addition Result:\n";

    addMatrices(matrix, matrixB, sum, rows, cols);

    displayMatrix(sum, rows, cols);



    // PART C - Multiplication
    int rowsB, colsB;

    int matrixC[10][10];
    int product[10][10];

    cout << "\nEnter rows for multiplication matrix: ";
    cin >> rowsB;

    cout << "Enter columns for multiplication matrix: ";
    cin >> colsB;


    cout << "Enter second matrix:\n";

    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixC[i][j];
        }
    }


    if (cols != rowsB)
    {
        cout << "Error: Columns of first matrix must equal rows of second matrix." << endl;
    }
    else
    {
        cout << "\nMatrix Multiplication Result:\n";

        multiplyMatrices(matrix, matrixC, product, rows, cols, colsB);

        displayMatrix(product, rows, colsB);
    }


    return 0;
}



// Function A: Transpose Matrix
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << setw(5) << matrix[j][i];
        }

        cout << endl;
    }
}



// Function B: Add Two Matrices
void addMatrices(int matrixA[10][10], int matrixB[10][10], int result[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}



// Function C: Multiply Two Matrices
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int result[10][10], int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}



// Function to display matrices
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }

        cout << endl;
    }
}