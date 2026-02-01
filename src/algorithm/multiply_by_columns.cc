/**
** Universidad de La Laguna
** Escuela Superior de Ingeniería y Tecnología
** Grado en Ingeniería Informática
** Asignatura: Diseño y Análisis de Algoritmos
** Curso: 3º
** Práctica 1: Complejidad Computacional
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 01/02/2026

** Archivo multiply_by_columns.cc: Implementación del algoritmo por columnas
**
** Referencias:
**      Enlaces de interés

** Historial de revisiones:
**      01/02/2026 - Creación (primera versión) del código
**/

#include "multiply_by_columns.h"

/**
 * @brief Method solve, implemented as multiplication with columns first
 * @param MatrixInstance instance of the problem
 * @return MatrixSolution, matrix resulted by the multiplication
 */
MatrixSolution MultiplyByColumns::solve(const MatrixInstance& instance) {
  const Matrix& MatrixA = instance.getMatrixA();
  const Matrix& MatrixB = instance.getMatrixB();
  
  unsigned int rows_A = MatrixA.getRows();
  unsigned int columns_A = MatrixA.getColumns();
  unsigned int columns_B = MatrixB.getColumns();
  
  Matrix MatrixC(rows_A, columns_B);

  for (unsigned int j = 0; j < columns_B; ++j) {
    for (unsigned int i = 0; i < rows_A; ++i) {
      double sum = 0.0;  
      for (unsigned int k = 0; k < columns_A; ++k) {
        sum += MatrixA(i, k) * MatrixB(k, j);
      }
      MatrixC(i, j) = sum;  
    }
  }
  
  return MatrixSolution(MatrixC);
}