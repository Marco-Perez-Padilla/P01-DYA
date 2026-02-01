/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Diseño y Analisis de Algoritmos
** Curso: 3º
** Practica 1: Complejidad Computacional
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 31/01/2026

** Archivo matrix.cc: Implementacion de la clase Matrix siguiendo los principios SOLID y el patron estrategia
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      31/01/2025 - Creacion (primera version) del codigo
**/

#include "matrix.h"
#include "../exceptions/exceptions.h"

/**
 * @brief Constructor for Matrix class
 * @param int rows, number of matrix's rows
 * @param int columns, number of matrix's columns
 */
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

/**
 * @brief Overload of non-constant operator () to be used as setter
 * @param int i, row index
 * @param int j, column index
 */
double& Matrix::operator()(int i, int j) {
  if (!isValidIndex(i, j)) {
    throw MatrixIndexOutOfRangeException(i, j, rows_, columns_);
  }
  return values_[i * columns_ + j];
}

/**
 * @brief Overload of constant operator () to be used as getter
 * @param int i, row index
 * @param int j, column index
 */
const double& Matrix::operator()(int i, int j) const {
  if (!isValidIndex(i, j)) {
    throw MatrixIndexOutOfRangeException(i, j, rows_, columns_);
  }
  return values_[i * columns_ + j];
}