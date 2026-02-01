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

** Archivo matrix_solution.h: Representa la salida del problema
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      01/02/2026 - Creacion (primera version) del codigo
**/

#ifndef MATRIX_SOLUTION_H
#define MATRIX_SOLUTION_H

#include <string>
#include "../matrix/matrix.h"

class MatrixSolution {
 private:
  Matrix result_;

 public: 
  MatrixSolution(const Matrix& result) : result_(result) {}
  const Matrix& getResult() {return result_;}
  bool CheckResultDimensions(const Matrix& Matrix_A, const Matrix& Matrix_B) const;
  std::string PrintDimensions() const;
};

#endif