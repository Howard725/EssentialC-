//
// Created by Administrator on 2016/1/5.
//

#include "Matrix.h"

Matrix& Matrix::operator+(const Matrix &rhs) const
{
    Matrix result;
    for ( int ix = 0; ix < _rows; ++ix )
    {
        for ( int jx = 0; jx < _columns; ++jx )
        {
//            result._matrix[ix][jx] = _matrix[ix][jx] + rhs._matrix[ix][jx];
            result(ix, jx) = (*this)(ix, jx) + rhs(ix, jx);
        }
    }
    return result;
}

Matrix& Matrix::operator*(const Matrix & rhs) const
{
    Matrix result;
    for ( int ix = 0; ix < _rows; ++ix )
    {
        for ( int jx = 0; jx < _columns; ++jx )
        {
//            result._matrix[ix][jx] = 0;
            result(ix, jx) = 0;
            for ( int kx = 0; kx < _columns; ++kx )
            {
//                result._matrix[ix][jx] += _matrix[ix][kx] * rhs._matrix[kx][jx];
                result(ix, jx) += (*this)(ix, kx) * rhs(kx, jx);
            }
        }
    }
    return result;
}

Matrix& Matrix::operator+=(const Matrix & rhs)
{
    for ( int ix = 0; ix < _rows; ++ix )
    {
        for ( int jx = 0; jx < _columns; ++jx )
        {
//            _matrix[ix][jx] += rhs._matrix[ix][jx];
            (*this)(ix, jx) += rhs(ix, jx);
        }
    }
    return *this;
}

void Matrix::print() const {
    cout << "{";
    for ( int ix = 0; ix < _rows; ++ix )
    {
        for ( int jx = 0; jx < _columns; ++jx )
        {
            cout << "\t" << _matrix[ix][jx] ;
        }
        cout << ( ix == _rows - 1 ? "\t}" : "" ) << "\n";
    }
    cout << endl;
}

Matrix::Matrix(elemType elem00, elemType elem01, elemType elem02, elemType elem03,
               elemType elem10, elemType elem11, elemType elem12, elemType elem13,
               elemType elem20, elemType elem21, elemType elem22, elemType elem23,
               elemType elem30, elemType elem31, elemType elem32, elemType elem33)
{
    _matrix[0][0] = elem00; _matrix[0][1] = elem01; _matrix[0][2] = elem02; _matrix[0][3] = elem03;
    _matrix[1][0] = elem10; _matrix[1][1] = elem11; _matrix[1][2] = elem12; _matrix[1][3] = elem13;
    _matrix[2][0] = elem20; _matrix[2][1] = elem21; _matrix[2][2] = elem22; _matrix[2][3] = elem23;
    _matrix[3][0] = elem30; _matrix[3][1] = elem31; _matrix[3][2] = elem32; _matrix[3][3] = elem33;
}

Matrix::Matrix(const elemType* ptr)
{
    for ( int ix = 0; ix < _rows; ++ix )
    {
        for ( int jx = 0; jx < _columns; ++jx )
        {
            _matrix[ix][jx] = *(ptr++);
        }
    }
}
