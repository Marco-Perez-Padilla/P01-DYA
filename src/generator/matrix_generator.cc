/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Diseño y Analisis de Algoritmos
** Curso: 3º
** Practica 1: Complejidad Computacional
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 01/02/2026

** Archivo matrix_generator.cc: Implementación de generador simple de matrices aleatorias
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      01/02/2026 - Creacion (primera version) del codigo
**/

#include "matrix_generator.h"
#include <cstdlib>

/**
 * @brief Method to generate random double numbers in a range [min, max]
 * @param double min value of the range
 * @param double max value of the range
 * @return double random double
 */
double MatrixGenerator::RandomDouble(double min, double max) const {
  if (max < min) std::swap(min, max);
    
  double random = std::rand() / (double)RAND_MAX;  
  return min + random * (max - min);
}


/**
 * @brief Generates a random matrix of dimensions rows x columns
 * @param int row dimensions
 * @param int column dimensions
 * @param double min value of the range
 * @param double max value of the range
 * @return Random Matrix
 */
Matrix MatrixGenerator::GenerateRandomMatrix(int rows, int columns, double min_value, double max_value) const {
  Matrix matrix(rows, columns);
  for (unsigned int i = 0; i < rows; ++i) {
    for (unsigned int j = 0; j < columns; ++j) {
      matrix(i, j) = RandomDouble(min_value, max_value);
    }
  }
    
  return matrix;
}


/**
 * @brief Generates an instance for the problem with two Square Matrixes
 * @param int size dimension of the square matrixes
 * @param double min value of the range
 * @param double max value of the range
 * @return MatrixInstance of the problem
 */
MatrixInstance MatrixGenerator::GenerateSquareMatrixes(int size, double min_value, double max_value) const {
  return GenerateMatrixes(size, size, size, size, min_value, max_value);
}


/**
 * @brief Generates an instance of two random matrixes with specified dimensions
 * @param int row dimensions - Matrix A
 * @param int column dimensions - Matrix A
 * @param int row dimensions - Matrix B
 * @param int column dimensions - Matrix B
 * @param double min value of the range
 * @param double max value of the range
 * @return MatrixInstance of the problem
 */
MatrixInstance MatrixGenerator::GenerateMatrixes(int rows_A, int columns_A, int rows_B, int columns_B, double min_value, double max_value) const {
  Matrix A = GenerateRandomMatrix(rows_A, columns_A);
  Matrix B = GenerateRandomMatrix(rows_B, columns_B);

  return MatrixInstance(A, B);
}