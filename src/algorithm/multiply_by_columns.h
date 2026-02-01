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

** Archivo multiply_by_columns.h: Algoritmo de multiplicación por columnas (j-k-i)
**
** Referencias:
**      Enlaces de interés

** Historial de revisiones:
**      01/02/2026 - Creación (primera versión) del código
**/

#ifndef MULTIPLY_BY_COLUMNS_H
#define MULTIPLY_BY_COLUMNS_H

#include "matrix_algorithm_interface.h"

class MultiplyByColumns : public MatrixAlgorithmInterface {
 public:
  MatrixSolution solve(const MatrixInstance& instance) override;
  std::string name() const override { return "Multiplication by Columns"; }
  std::string complexity() const override { return "O(m x n x l)"; }
};

#endif