#include "matrix.h"
#include <iostream>
#include <cassert>
#include <cstring>

// Constructors.
Matrix::Matrix(): nrows(3), ncols(3), data(nullptr), endpointer(nullptr) {}  // Default constructor.
Matrix :: Matrix(int nrows, int ncols):nrows(nrows),ncols(ncols)  // Constructor with parameter.
{
    int size = nrows * ncols;
    data = new double [size];   // Allocates memory dynamically using new.
    endpointer = data + size;
    memset(data, 0, sizeof(double) * size); // Initialise all members of array with value 0 using memset()
                                            // function which is optimised low level f'n faster than loop.
}
Matrix :: Matrix(const Matrix& other)   // Copy Constructor.
{
    nrows = other.nrows;
    ncols = other.ncols;
    int size = nrows * ncols;
    data = new double [size];  // Allocates memory for the new object we are creating.
    endpointer = data + size;
    for (int i=0; i<nrows; i++)
        for (int j=0; j<ncols; j++)
            {data[offset(i,j)] = other.data[offset(i,j)];}
}
// Destructor.
Matrix :: ~Matrix()
{
    delete [] data;
}

// Member Function.
int Matrix :: offset(int i, int j) const
{
    assert(i >= 0 && i < nrows && j >= 0 && j < ncols);
    return j * nrows + i; // Returns index of (i,j)th element. Uses column-major order.

}
void Matrix::print() const
{
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            std::cout << get(i, j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Accessor Functions getters and setters.
double Matrix :: get(int i, int j) const
{return data[offset(i,j)];} // Returns (i,j)th element of matrix.
void Matrix :: set(int i, int j, double value)
{data[offset(i,j)] = value;}    // Sets value at (i,j)th location.

// Member Operator Overloading.
Matrix& Matrix::operator = (const Matrix& other)
{
    if (this != &other) 
    {
        // Check for self-assignment.

        delete[] data; // Deallocate existing memory.

        nrows = other.nrows;
        ncols = other.ncols;

        int size = nrows * ncols;
        data = new double[size];

        endpointer = data + size;

        // Copy data from the other matrix.
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < ncols; j++)
                data[offset(i, j)] = other.data[offset(i, j)];
    }
    return *this;
}

double& Matrix::operator() (int i, int j) // Overloading subscript operator. Returnvalue can be changed as we returned reference.
{return data[offset(i,j)];}

const double Matrix::operator() (int i, int j) const // Overloading subscript. Returnvalue can't be changed. Can only be used with const object.
{return data[offset(i,j)];}

Matrix Matrix::add(const Matrix& other) const
{
    if (nrows != other.nrows || ncols != other.ncols) 
    {
        // Matrices must have the same dimensions for addition.
        throw std::invalid_argument("Matrices must have the same dimensions for addition");
    }

    Matrix result(nrows, ncols);

    for (int i = 0; i < nrows; i++)
        for (int j = 0; j < ncols; j++)
            result.set(i, j, get(i, j) + other.get(i, j));

    return result;
}

Matrix Matrix::subtract(const Matrix& other) const
{
    if (nrows != other.nrows || ncols != other.ncols) 
    {
        // Matrices must have the same dimensions for subtraction.
        throw std::invalid_argument("Matrices must have the same dimensions for subtraction");
    }

    Matrix result(nrows, ncols);

    for (int i = 0; i < nrows; i++)
        for (int j = 0; j < ncols; j++)
            result.set(i, j, get(i, j) - other.get(i, j));

    return result;
}

Matrix Matrix::multiply(const Matrix& other) const
{
    if (ncols != other.nrows) 
    {
        // The number of columns in the first matrix must be equal to the number of rows in the second matrix.
        throw std::invalid_argument("Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication");
    }

    Matrix result(nrows, other.ncols);

    for (int i = 0; i < nrows; i++)
        for (int j = 0; j < other.ncols; j++)
            for (int k = 0; k < ncols; k++)
                result.set(i, j, result.get(i, j) + get(i, k) * other.get(k, j));

    return result;
}