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

** Archivo menu.cc: Funciones de menu
**
** Referencias:
**      Enlaces de interés

** Historial de revisiones:
**      01/02/2026 - Creación (primera versión) del código
**/

#include "menu.h"

#include <iostream>
#include <limits>
#include <chrono>

#ifdef _WIN32
  #include <conio.h>
#endif

#include "../generator/matrix_generator.h"
#include "../algorithm/multiply_by_rows.h"
#include "../algorithm/multiply_by_columns.h"
#include "../exceptions/exceptions.h"


/**
 * @brief function that waits for the user to press any key
 */
void Menu::PressAnyKey() { 
#ifdef _WIN32
  _getch(); 
#else
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get(); 
#endif
}


/**
 * @brief function to clear the standard ouput
 */
void Menu::clrscr() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}


/**
 * @brief Method to read an int from console
 * @param string input text
 * @return int written
 */
int Menu::ReadInt(const std::string& text) {
  int value;
  while (true) {
    std::cout << text;
    std::cin >> value;

    if (!std::cin.fail()) break;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << "Not valid input" << std::endl;
  }
  return value;
}


/**
 * @brief Print Main Menu options
 */
void Menu::ShowMainMenu() {
  clrscr();
  std::cout << "MATRIXES MULTIPLICATION" << std::endl;;
  std::cout << "1. Square Matrixes" << std::endl;;
  std::cout << "2. Custom Matrixes" << std::endl;;
  std::cout << "3. Quit" << std::endl;
}


/**
 * @brief Print Algorithm Menu options
 */
void Menu::ShowAlgorithmMenu() {
  std::cout << std::endl;
  std::cout << "Choose Algorithm:" << std::endl;
  std::cout << "1. Multiplication by Rows" << std::endl;;
  std::cout << "2. Multiplication by Columns" << std::endl;;
  std::cout << "3. Run both" << std::endl;
  std::cout << "0. Back" << std::endl;
}


/**
 * @brief Call Execute for Square Matrixes of n dimension
 */
void Menu::SquareMatrixes() {
  clrscr();
  int n = ReadInt("Dimension n: ");

  ShowAlgorithmMenu();
  int option = ReadInt("> ");

  if (option < 0 || option > 3) {
    std::cerr << "Not valid algorithm option" << std::endl;
    return;
  }

  if (option == 0) return;

  Execute(n, n, n, n, option);
  PressAnyKey();
}


/**
 * @brief Call Execute for Custom Matrixes
 */
void Menu::CustomMatrixes() {
  clrscr();

  std::cout << "A Matrix" << std::endl;;
  int rows_A = ReadInt("Rows: ");
  int columns_A = ReadInt("Columns: ");
  
  std::cout << std::endl;
  std::cout << "B Matrix" << std::endl;
  int rows_B = ReadInt("Rows: ");
  int columns_B = ReadInt("Columns: ");

  ShowAlgorithmMenu();
  int option = ReadInt("> ");

  if (option < 0 || option > 3) {
    std::cerr << "Not valid algorithm option" << std::endl;
    return;
  }

  if (option == 0) return;

  Execute(rows_A, columns_A, rows_B, columns_B, option);
  PressAnyKey();
}


/**
 * @brief Executes the chosen algorithm
 * @param int row dimensions - Matrix A
 * @param int column dimensions - Matrix A
 * @param int row dimensions - Matrix B
 * @param int column dimensions - Matrix B
 * @param int chosen option
 */
void Menu::Execute(int rows_A, int columns_A, int rows_B, int columns_B, int option) {
  try {
    MatrixGenerator generator;
    MatrixInstance instance = generator.GenerateMatrixes(rows_A, columns_A, rows_B, columns_B);
    std::cout << std::endl;
    std::cout << "Matrix Dimensions: " << instance.PrintDimensions() << std::endl;

    if (option == 1 || option == 3) {
      MultiplyByRows algorithm;
      auto start = std::chrono::high_resolution_clock::now();
       MatrixSolution result = algorithm.solve(instance);
      auto end = std::chrono::high_resolution_clock::now();
      auto micro_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
      auto second_time = std::chrono::duration<double>(end - start);

      std::cout << std::endl;
      std::cout << "Algorithm: " << algorithm.name() 
                << " -- Complexity: " << algorithm.complexity() << std::endl;
      std::cout << "Result Dimensions: " << result.PrintDimensions() << std::endl;
      std::cout << "Time: " << micro_time.count() << " µs -- " << second_time.count() << " s" << std::endl;
    }

    if (option == 2 || option == 3) {
      MultiplyByColumns algorithm;
      auto start = std::chrono::high_resolution_clock::now();
      MatrixSolution result = algorithm.solve(instance);
      auto end = std::chrono::high_resolution_clock::now();
      auto micro_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
      auto second_time = std::chrono::duration<double>(end - start);

      std::cout << std::endl;
      std::cout << "Algorithm: " << algorithm.name() 
                << " -- Complexity: " << algorithm.complexity() << std::endl;
      std::cout << "Result Dimensions: " << result.PrintDimensions() << std::endl;
      std::cout << "Time: " << micro_time.count() << " µs -- " << second_time.count() << " s" << std::endl;
    }
  } catch (const Exceptions& error) {
    std::cout << std::endl;
    std::cout << "ERROR: " << error.what()  << std::endl;
  }
}


/**
 * @brief Public Method to actually run the algorithm
 */
void Menu::Run() {
  while (true) {
    ShowMainMenu();
    int option = ReadInt("> ");

    switch (option) {
      case 1:
        SquareMatrixes();
        break;
      case 2:
        CustomMatrixes();
        break;
      case 3:
        return;
      default:
        std::cerr << "Not valid option" << std::endl;;
        PressAnyKey();
    }
  }
}