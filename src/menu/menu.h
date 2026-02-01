#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
 public:
  void Run();

 private:
  // Menús
  void ShowMainMenu();
  void ShowAlgorithmMenu();

  // Flujo
  void ProcessSquareMatrix();
  void ProcessCustomMatrix();
  void ExecuteMultiplication(int rowsA, int colsA,
                             int rowsB, int colsB,
                             int option);

  // Utilidades
  int ReadInt(const std::string& text);
  void Wait();
  void Clear();
};

#endif
