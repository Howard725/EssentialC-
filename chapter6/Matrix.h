//
// Created by Administrator on 2016/3/4.
//

#ifndef CHAPTER6_MATRIX_H
#define CHAPTER6_MATRIX_H


#include <stdlib.h>
#include <iosfwd>

using namespace std;

template <typename valType>
class Matrix {

    friend Matrix<valType>& operator+( const Matrix<valType>& matrix1, const Matrix<valType>& matrix2 );
    friend Matrix<valType>& operator*( const Matrix<valType>& matrix1, const Matrix<valType>& matrix2 );

public:
    Matrix( int rows = 1, int columns = 1 );
    Matrix( valType *array, int rows, int columns );
    Matrix( const Matrix& matrix );
    ~Matrix();
    Matrix& operator=( const Matrix & matrix1 );
    Matrix& operator+=( const Matrix& matrix1 );

    ostream& print( ostream &os ) const;

    valType& operator()( int row, int column )
    {
        return _matrix[row][column];
    };
    valType& operator()( int row, int column ) const
    {
        return _matrix[row][column];
    };

private:
    int _rows;
    int _columns;
    valType *_matrix;
};

template <typename valType>
ostream& operator<<( ostream &os, Matrix<valType> matrix )
{
    return matrix.print( os );
}

template <typename valType>
Matrix<valType>::Matrix(int rows, int columns)
    : _rows( rows ), _columns( columns )
{
    if ( rows < 1 || columns < 1 )
        throw "Invalid input.";
    int size = rows * columns;
    _matrix = new valType[ size ];
    for( int i = 0; i < size; ++i )
        _matrix[i] = valType();
}

template <typename valType>
Matrix<valType>::Matrix(valType *array, int rows, int columns)
    : _rows(rows), _columns(columns)
{
    if ( rows < 1 || columns < 1 || array == NULL )
        throw "Invalid input.";
    int size = rows * columns;
    _matrix = new valType[size];
    for ( int i = 0; i < size; ++i )
        _matrix[i] = array[i];
}

template <typename valType>
Matrix<valType>::Matrix(const Matrix<valType> &matrix)
{
    _rows = matrix._rows;
    _columns = matrix._columns;
    int size = _rows * _columns;
    _matrix = new valType[size];
    for ( int i = 0; i < size; ++i )
        _matrix[i] = matrix._matrix[i];
}

template <typename valType>
Matrix<valType>::~Matrix() { delete [] _matrix; }

template <typename valType>
Matrix<valType>& Matrix<valType>::operator=(const Matrix<valType> &matrix)
{
    if ( this != &matrix )
    {
        Matrix temp(matrix);
        valType* temPtr = temp._matrix;
        temp._matrix = _matrix;
        _matrix = temPtr;

        _rows = temp._rows;
        _columns = temp._columns;
    }
    return *this;
}

#endif //CHAPTER6_MATRIX_H




















