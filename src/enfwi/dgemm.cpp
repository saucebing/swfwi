/*
 * dgemm.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: rice
 */

#include "Matrix.h"
extern "C" {
#include <rsf.h>
}

static void alpha_A_B_plus_beta_C(
  char transA, char transB,
  double alpha, Matrix &A, Matrix &B,
  double beta, Matrix &C) {
  int k = A.getNumCol();
  if (transA == 't' || transA == 'T') {
    k = A.getNumRow();
  }

  int m = C.getNumRow();
  int n = C.getNumCol();
  int lda = A.getNumRow();
  int ldb = B.getNumRow();
  int ldc = C.getNumRow();
  dgemm_(&transA, &transB,
              &m, &n, &k,
              &alpha, // alpha
              A.getData(), &lda,
              B.getData(), &ldb,
              &beta, // beta
              C.getData(), &ldc);

}

void alpha_A_B_plus_beta_C(double alpha, Matrix &A, Matrix &B, double beta, Matrix &C) {
  alpha_A_B_plus_beta_C('n', 'n', alpha, A, B, beta, C);
}

void alpha_ATrans_B_plus_beta_C(double alpha, Matrix& A, Matrix& B, double beta, Matrix& C) {
  alpha_A_B_plus_beta_C('t', 'n', alpha, A, B, beta, C);
}
