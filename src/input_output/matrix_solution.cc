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

** Archivo matrix_instance.h: Implementacion de MatrixSolution
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      01/02/2026 - Creacion (primera version) del codigo
**/

#include "matrix_solution.h"

/**
 * @brief Checks if the result matrix has the correct dimensions
 * @return Bool. True if the dimensions are correct, false otherwise
 */
bool MatrixSolution::CheckResultDimensions(const Matrix& A, const Matrix& B) const {
  return result_.getRows() == A.getRows() && result_.getColumns() == B.getColumns();
}


/**
 * @brief Method to print the dimensions of the result matrix
 * @return String
 */
std::string MatrixSolution::PrintDimensions() const {
  return std::to_string(result_.getRows()) + "x" + std::to_string(result_.getColumns());
}