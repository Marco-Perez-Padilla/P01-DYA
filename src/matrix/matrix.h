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

** Archivo matrix.h: Declaracion de la clase Matrix siguiendo los principios SOLID y el patron estrategia
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      31/01/2026 - Creacion (primera version) del codigo
**/

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
 private:
  int rows_, columns_;
  std::vector<double> values_;

 public:
  Matrix(int rows = 0, int columns = 0);
    
  int getRows() const { return rows_; }
  int getColumns() const { return columns_; }
    
  double& operator()(int i, int j);
  const double& operator()(int i, int j) const;

  bool isValidIndex(int i, int j) const {
    return i >= 0 && i < rows_ && j >= 0 && j < columns_;
  }
};

#endif