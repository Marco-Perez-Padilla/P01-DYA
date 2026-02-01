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

** Archivo help.h: Funciones de ayuda
**
** Referencias:
**      Enlaces de interés

** Historial de revisiones:
**      01/02/2026 - Creación (primera versión) del código
**/

#include <iostream>
#include "help_functions.h"

/**
 * @brief Prints Help to the user
 */
void Help() {
    std::cout << "MATRIXES MULTIPLIER" << std::endl;
    std::cout << "Generates matrices and multiplies them using different algorithms.\n" << std::endl;

    std::cout << "Options:" << std::endl;
    std::cout << "  --help        Show this help message" << std::endl;
    std::cout << "  Run the program without arguments to start the interactive menu." << std::endl;
    std::cout << std::endl;

    std::cout << "Interactive Menu:" << std::endl;
    std::cout << "  1. Square matrices  -> Choose size n x n and multiplication algorithm." << std::endl;
    std::cout << "  2. Custom matrices  -> Specify rows and columns for matrices A and B, then choose algorithm." << std::endl;
    std::cout << "  3. Quit             -> Exit the program." << std::endl;
    std::cout << std::endl;

    std::cout << "Algorithm Options:" << std::endl;
    std::cout << "  1. Multiplication by Rows" << std::endl;
    std::cout << "  2. Multiplication by Columns" << std::endl;
    std::cout << "  3. Run both algorithms" << std::endl;
    std::cout << "  0. Back to main menu" << std::endl;
    std::cout << std::endl;
}


/**
 * @brief Prints how to use the program
 */
void Usage() {
    std::cout << "How to use: ./matrixes_multiplier [--help]" << std::endl;
    std::cout << "Try './matrixes_multiplier --help' for more information." << std::endl;
}


/**
 * @brief Validates arguments given in CLI
 * @param argc
 * @param argv
 */
int ValidateArguments(int argc, char* argv[]) {
  if (argc == 1) return -1;
  if (argc == 2) {
    std::string arg1 = argv[1];
    if (arg1 == "--help" || arg1 == "-h") {
      Help();
      return 0;
    } else {
      Usage();
      return 1;
    }
  } else {
    Usage();
    return 1;
  }
}