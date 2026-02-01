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

** Archivo matrix_generator.h: Generador simple de matrices aleatorias
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      01/02/2026 - Creacion (primera version) del codigo
**/

#ifndef MATRIX_GENERATOR_H
#define MATRIX_GENERATOR_H

#include "../matrix/matrix.h"
#include "../input_output/matrix_instance.h"

struct MatrixGenerator {
  double RandomDouble(double min, double max) const;
  MatrixInstance GenerateSquareMatrixes(int size, double min_value = 0.0, double max_value = 10.0) const;
  MatrixInstance GenerateMatrixes(int rows_A, int columns_A, int rows_B, int columns_B, double min_value = 0.0, double max_value = 10.0) const;
  Matrix GenerateRandomMatrix(int rows, int columns, double min_value = 0.0, double max_value = 10.0) const;
};

#endif