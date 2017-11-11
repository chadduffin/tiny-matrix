#include "tiny_matrix.h"

TinyMatrix::TinyMatrix(unsigned int p_row, unsigned int p_col) {
  unsigned int len = ((p_row*p_col) >> 1)+((p_row*p_col) & 0x1);

  row = p_row;
  col = p_col;

  matrix = new unsigned char[len];

  memset(matrix, 0, len);
}

TinyMatrix::~TinyMatrix(void) {
  if (matrix) { delete matrix; }
}

void TinyMatrix::Set(unsigned int p_row, unsigned int p_col, unsigned char p_val) {
  if ((p_row < row) && (p_col < col) && (p_val <= 0xF)) {
    unsigned int i = (p_col+p_row*col) >> 1;

    if ((p_col+p_row*col) & 0x1) {
      *(matrix+i) = (*(matrix+i) & 0xF) | ((p_val << 4) & 0xF0);
    } else {
      *(matrix+i) = (*(matrix+i) & 0xF0) | (p_val & 0xF);
    }
  }
}

unsigned char TinyMatrix::Get(unsigned int p_row, unsigned int p_col) {
  if ((p_row < row) && (p_col < col)) {
    unsigned int i = (p_col+p_row*col) >> 1;

    if ((p_col+p_row*col) & 0x1) {
      return (*(matrix+i) & 0xF0) >> 4;
    } else {
      return *(matrix+i) & 0xF;
    }
  }

  return 0xFF;
}
