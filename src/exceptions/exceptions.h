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

** Archivo exceptions.h: 
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      31/01/2025 - Creacion (primera version) del codigo
**/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

/**
 * @brief Class Exceptions that inheritages from std:exception, it has a protected member which is the message to be thrown if an error occurs
 * 
 */
class Exceptions : public std::exception {
 protected:
  std::string error_message_;
  
 public:

  explicit Exceptions(const std::string& error_message) : error_message_(error_message) {}
  const char* what() const throw() {return error_message_.c_str();}
};

/**
 * @brief Class MatrixNegativeSizeException. Throws an exception if any index is negative
 */
class MatrixNegativeSizeException : public Exceptions {
 public:
  MatrixNegativeSizeException() : Exceptions("Error: Ninguna dimension puede ser negativas.") {}
};

/**
 * @brief Class MatrixNegativeSizeException. Throws an exception if both indexes are 0
 */
class MatrixBothZeroException : public Exceptions {
 public:
  MatrixBothZeroException() : Exceptions("Error: Ambas dimensiones de matriz son 0. Al menos una debe ser positiva.") {}
};

/**
 * @brief Class MatrixIndexOutOfRangeException. Throws an exception if any index is out of range
 */
class MatrixIndexOutOfRangeException : public Exceptions {
 public:
  MatrixIndexOutOfRangeException(int i, int j, int rows, int columns)
    : Exceptions(
      "Error: index out of range [" + std::to_string(i) + 
      "][" + std::to_string(j) + "]. " +
      "La matriz es de " + std::to_string(rows) + "x" + 
      std::to_string(columns) + "."
    ) {}
};

#endif