//
// Created by Administrator on 2016/3/4.
//

#include <ostream>
#include "Matrix.h"

template <typename valType>
Matrix<valType>& Matrix<valType>::operator+=(const Matrix &matrix)
{
    if ( matrix._matrix == NULL )
        throw "Invalid input.";
    if ( matrix._rows != _rows || matrix._columns != _columns )
        throw "dimesion must be equal.";

    int size = _rows * _columns;
    for ( int i = 0; i < size; ++i )
        _matrix[i] += matrix._matrix[i];

    return *this;
}

template <typename valType>
ostream& Matrix<valType>::print(ostream &os) const
{
    for ( int i = 0; i < _rows; ++i )
    {
        for ( int j = 0; j < _columns; ++j )
            os << _matrix[ i * _columns + j ] << '\t';
        os << endl;
    }
    return os;
}

template <typename valType>
Matrix<valType>& operator+( const Matrix<valType> &matrix1, const Matrix<valType> &matrix2 )
{
    Matrix<valType> temp( matrix1 );
    temp += matrix2;
    return temp;
}

template <typename valType>
Matrix<valType>& operator*( const Matrix<valType> &matrix1, const Matrix<valType> &matrix2 )
{
    if ( matrix1._columns != matrix2._rows || matrix1._rows != matrix2._columns )
        throw "Invalid input.";
    Matrix<valType> result( matrix1._rows, matrix2._columns );
    for ( int i = 0; i < result._rows; ++i )
    {
        for ( int j = 0; j < result._columns; ++j )
        {
            valType sum = 0;
            for ( int k = 0; k < matrix1._columns; ++k )
                sum += matrix1._matrix[ i * matrix1._columns + k ] * matrix2._matrix[ j + matrix2._columns * k ];
            result._matrix[ i * result._columns + j ] = sum;
        }
    }
    return result;
}
