//
// Created by Administrator on 2016/1/5.
//

#ifndef CHAPTER4_MATRIX_H
#define CHAPTER4_MATRIX_H

#include <vector>
#include <iostream>

using namespace std;

typedef float elemType;

class Matrix {
public:
    Matrix &operator+(const Matrix &) const;

    Matrix &operator*(const Matrix &) const;

    Matrix &operator+=(const Matrix &);

    void print() const;

    elemType &operator()(int row, int column) {
        return _matrix[row][column];
    }

    elemType operator()(int row, int column) const
    {
        return _matrix[row][column];
    }

    Matrix(elemType=0., elemType=0., elemType=0., elemType=0.,
           elemType=0., elemType=0., elemType=0., elemType=0.,
           elemType=0., elemType=0., elemType=0., elemType=0.,
           elemType=0., elemType=0., elemType=0., elemType=0.);
    Matrix(const elemType* );

private:
    static const int _rows = 4;
    static const int _columns = 4;
    elemType _matrix[_rows][_columns];
};


#endif //CHAPTER4_MATRIX_H
