# pragma once
#include <vector>

class Matrix 
{
    private:
        int nrows;  // Number of rows.
        int ncols;  // Number of columns.
        double * data;  // A pointer to first cell/element.
        double * endpointer;    // A pointer after the last cell/element.
    public:
        Matrix();     // Default constructor.
        Matrix(int nrows, int ncols);   // Constructor with parameter.
        Matrix(const Matrix& other);    // Copy Constructor.
        ~Matrix();  // Destructor.

        // Accessor Functions to get number of rows and number of columns.
        int nRows() const;
        int nCols() const;

        int offset(int i, int j) const;  // Function that returns index of (i,j)th element.

        // Accessor Functions getters and setters.
        double get(int i, int j) const; // Returns (i,j)th element of matrix .
        void set(int i, int j, double value);   // Sets (i,j)th element of matrix .
        
        // Member Operator Overloading.
        Matrix& operator = (const Matrix& other);   // Overloading Assignment Operator.
        double& operator() (int i, int j); // Overloading subscript operator. Returnvalue can be changed.
        const double operator() (int i, int j) const;// Overloading subscript. Returnvalue can't be changed.
        Matrix add(const Matrix& other) const;
        Matrix subtract(const Matrix& other) const;
        Matrix multiply(const Matrix& other) const;

        void print() const;
};

// Inline functions definitions.
inline int Matrix :: nRows() const
{return nrows;}
inline int Matrix :: nCols() const
{return ncols;}