#include "matrix.h"
#include "../exceptions/exceptions.h"

Matrix::Matrix(int rows, int columns) {
  if (rows < 0 || columns < 0) {
    throw MatrixNegativeSizeException();
  }
  
  if (rows == 0 && columns == 0) {
    throw MatrixBothZeroException();
  }
  
  rows_ = rows;
  columns_ = columns;
  values_.resize(rows * columns, 0.0);
}

double& Matrix::operator()(int i, int j) {
  if (!isValidIndex(i, j)) {
    throw MatrixIndexOutOfRangeException(i, j, rows_, columns_);
  }
  return values_[i * columns_ + j];
}

const double& Matrix::operator()(int i, int j) const {
  if (!isValidIndex(i, j)) {
    throw MatrixIndexOutOfRangeException(i, j, rows_, columns_);
  }
  return values_[i * columns_ + j];
}