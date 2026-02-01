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

** Archivo matrix_instance.h: Implementacion de MatrixInstance
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      01/02/2026 - Creacion (primera version) del codigo
**/

#include "matrix_instance.h"
#include "../exceptions/exceptions.h"

/**
 * @brief Constructor for MatrixInstance class, checks if the input matrixes can be multiplied
 * @param Matrix A, first matrix to be multiplied
 * @param Matrix B, second matrix to be multiplied
 */
MatrixInstance::MatrixInstance(const Matrix& Matrix_A, const Matrix& Matrix_B) : MatrixA_(Matrix_A), MatrixB_(Matrix_B) {
  if (!CanBeMultiplied()) {
    throw MatrixMultiplicationException(MatrixA_.getColumns(), MatrixB_.getRows());
  }
}


/**
 * @brief Checks if two matrixes instantiated can be multiplied or not
 * @return Bool. True if they can be multiplied, false otherwise
 */
bool MatrixInstance::CanBeMultiplied() const {
  return MatrixA_.getColumns() == MatrixB_.getRows();
}


/**
 * @brief Method to print the dimensions of both instantiated matrixes
 * @return String
 */
std::string MatrixInstance::PrintDimensions() const {
  return "A: " + std::to_string(MatrixA_.getRows()) + "x" + std::to_string(MatrixA_.getColumns()) + 
         ", B: " + std::to_string(MatrixB_.getRows()) + "x" + std::to_string(MatrixB_.getColumns());
}