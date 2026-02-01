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

** Archivo menu.h: Funciones de menu
**
** Referencias:
**      Enlaces de interés

** Historial de revisiones:
**      01/02/2026 - Creación (primera versión) del código
**/

#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
 private:
  void PressAnyKey();
  void clrscr();
  int ReadInt(const std::string& text);

  void ShowMainMenu();
  void ShowAlgorithmMenu();

  void SquareMatrixes();
  void CustomMatrixes();
  void Execute(int rows_A, int columns_A, int rows_B, int columns_B, int option);

 public:
  void Run();
};

#endif
