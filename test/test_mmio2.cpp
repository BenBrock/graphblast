#define GRB_USE_APSPIE

#include <cstdio>
#include <cstdlib>

#include <graphblas/mmio.hpp>
#include <graphblas/util.hpp>
#include <graphblas/graphblas.hpp>

int main(int argc, char **argv)
{
  std::vector<graphblas::Index> row_indices;
  std::vector<graphblas::Index> col_indices;
  std::vector<float> values;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s [matrix-market-filename]\n", argv[0]);
    exit(1);
  } else { 
	readMtx( argv[1], row_indices, col_indices, values );
  }

  return 0;
}
