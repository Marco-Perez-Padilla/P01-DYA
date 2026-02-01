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

** Archivo MatrixAlgorithm.h: Interfaz para algoritmos de multiplicación
**
** Referencias:
**      Enlaces de interés

** Historial de revisiones:
**      01/02/2026 - Creación (primera versión) del código
**/

#ifndef MATRIX_ALGORITHM_INTERFACE_H
#define MATRIX_ALGORITHM_INTERFACE_H

#include "../input_output/matrix_instance.h"
#include "../input_output/matrix_solution.h"

class MatrixAlgorithmInterface {
 public:
  virtual ~MatrixAlgorithmInterface() = default;

  // Algorithm
  virtual MatrixSolution solve(const MatrixInstance& instance) = 0;
  // Documentation
  virtual std::string name() const = 0;
  virtual std::string complexity() const = 0;
};

#endif  