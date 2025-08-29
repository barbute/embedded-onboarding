
# Code to be improved:

```c
matrix_t matrix_transpose(matrix_t m) {
  matrix_t mt = create_matrix(m.cols, m.rows); //<- assume this has been implemented

  for (int i = 0; i < m.rows; ++i) {
    for (int j = 0; j < m.cols; ++j) {
      mt.data[j * m.rows + i] = m.data[i * m.cols + j];
    }
  }

  return mt;
}
```

## Improvements:

Lowk didn't really know what was so bad about the code (I also do not know much about matrices or linear algebra), so I asked ChatGPT for advice. Only thing bro told me that was relevant was to make it more clear what was happening by using better naming conventions and splitting up the code so I used a macro to define what's going on when the array is being transposed.

Also I didn't even know that C doesn't really have `<ArrayList>` like Java, so I didn't understand that you have to essentially treat a 1D array like a 2D by skipping over the first couple of "rows" by multiplying `r` when indexing and then adding `c` to access the correct "column" (Since the array size needs to be known at compile time).

### My own notes:

General formula for 2D arrays in C:

$$
i(r,c)=r\times m..{cols}+c
$$

### "Improved" code:

```c
#define MATRIX_AT(m, r, c) (m).data[(r) * (m).cols + (c)]

matrix_t matrix_transpose(matrix_t m) {
  matrix_t mt = create_matrix(m.cols, m.rows); //<- assume this has been implemented

  for (int r = 0; r < m.rows; ++r) {
    for (int c = 0; c < m.cols; ++c) {
      MATRIX_AT(mt, c, r) = MATRIX_AT(m, r, c);
    }
  }

  return mt;
}
```
