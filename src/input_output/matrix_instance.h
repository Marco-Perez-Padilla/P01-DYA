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

** Archivo matrix_instance.h: Representa las instancias que son entradas del problema
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      01/02/2026 - Creacion (primera version) del codigo
**/

#ifndef MATRIX_INSTANCE_H
#define MATRIX_INSTANCE_H

#include <string>
#include "../matrix/matrix.h"

class MatrixInstance {
 private:
  Matrix MatrixA_;
  Matrix MatrixB_;

 public: 
  MatrixInstance(const Matrix& A, const Matrix& B);
  const Matrix& getMatrixA() {return MatrixA_;}
  const Matrix& getMatrixB() {return MatrixB_;}
  bool CanBeMultiplied() const;
  std::string PrintDimensions() const;
};

#endif