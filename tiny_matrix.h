#ifndef __TINY_MATRIX__
#define __TINY_MATRIX__

#include <cstring>

class TinyMatrix {
  public:
    TinyMatrix(unsigned int p_row, unsigned int p_col);
    ~TinyMatrix(void);

    void Set(unsigned int p_row, unsigned int p_col, unsigned char p_val);
    unsigned char Get(unsigned int p_row, unsigned int p_col);

  private:
    unsigned int col, row, llen;
    unsigned char *matrix;
};

#endif /* __TINY_MATRIX__ */
