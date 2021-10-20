#include <iomanip>
#include <iostream>

void print_ma(int m[][5], int dim1);  // ugly and not flexible

// void print_ma(
//     int m[][],
//     int dim1,
//     int dim2);  // error: second dimension must be knwon at compile time

void print_ma(int* p, int row, int col);  // the "best" solution

int main() {
  int ma[6][5];  // matrix: 6 rows, 5 columns each

  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 5; ++j)
      ma[i][j] = 10 * i + j;

  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j)
      std::cout << std::setw(3) << ma[i][j];
    std::cout << std::endl;
  }

  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j)
      std::cout << &ma[i][j] << " ";
    std::cout << std::endl;
  }

  // int* pma{ma};     // error
  // int* pma[5]{ma};  // error
  int* p{reinterpret_cast<int*>(ma)};
  // int* p{&ma[0][0]};

  // print_ma(ma, 6, 5);  // error
  print_ma(p, 6, 5);

  auto d_ma = new int[6 * 5]{};

  std::cout << std::endl;

  print_ma(d_ma, 6, 5);
  delete[] d_ma;

  return 0;
}

void print_ma(int* p, int row, int col) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j)
      std::cout << std::setw(2) << p[i * col + j] << " ";
    std::cout << std::endl;
  }
}
