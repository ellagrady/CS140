/*
 * Ella Grady
 * CS 140
 * May 2, 2022
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function has a prototype of the form:
 *
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * Each function is evaluated by counting the number of misses 
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. The REQUIRES and ENSURES from 15-122 are included
 *     for your convenience. They can be removed if you like.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N]){
    int rowblock, colblock;
    int row, col;
    int temp = 0, diag = 0;
    if(N== 32 && M ==32) {

            /* Diagonal entries in diagonal blocks force cache miss
             *  In this case the cache has B_i,..,B_{i-1},A_i,B_{i+1},..,B_{i+7}
             *  so writing into B_i will evict A_i. But we need to read A_i again
             *  so we get another miss while moving A_i back in
             *  To alleviate this problem we set B_i at the end, so (1) we
             *  won't need to read A_i again and (2) we have B_i when i <- i+1
             * That is, handle B[i][i] = A[i][i] after the inner most loop
             * and skip it in the inner most loop (if(y == x && i == j))
             */
        for (colblock = 0; colblock < N; colblock += 8)  { // blocks size of 8
            for (rowblock = 0; rowblock < N; rowblock += 8) {
                for (row = rowblock; row < rowblock +8 ; row++) {
                    for (col = colblock; col < colblock + 8; col++) {
                        // row and column not equal
                        if (row != col) {
                            B[col][row] = A[row][col];
                        }
                        else {
                            temp = A[row][col];
                            diag = row;
                        }
                    }
                    if (rowblock == colblock) {
                        B[diag][diag] = temp;
                    }
                }
            }
        }
    }
   
    else if(N == 64 && M == 64)
        {
            return;
        }
            /* // Blocking with block size 8x8 and subblocks 4x4
            // Overview of an 8x8 block and its subblock:
            // A = ---------  B = ---------
            //     | W | X |      | W'| Y'|
            //     ---------      ---------
            //     | Y | Z |      | X'| Z'|
            //     ---------      ---------
            // 1) Move X^t into X', W^t into Z'
            // 2) Move Z into Z' while moving W^t from Z' to W' 
            //      3) Move Y^t into Y'
			//
			// Notice in the steps above, the cache lines in rows can be re-used:
			//
			// 1) A:  rows WX written into B: rows X'Z'
			// 2-3) A: rows YZ are written into B: rows W'Y'
			// 3 is a nested loop inside 2.

			// When you know a group of 4 ints is about to be evicted that you will need "soon",
			//store them in registers by using local temp variables.
			
			
            int x,y,i,j;
            // Temporary storage for step 2. 
            int tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
            
                                    // Save diagonal transpose for later
            
                    // Step 2           
                    // A line will be evicted from cache so store it in tmp vars
                                          
                            // Loading B line evicts A, so get A's vals from tmp vars
                            // Also store in B's old vals to move up in the tmp vars
                    
                            // B's old val that need to be moved up have been evicted,
                            // but we had them stored in tmp vars
                    
                            // Step 3
                    
        } */
    else
        {
            return;
           //  int i, j, k;
            // int MAX_INTS_IN_CACHE = 32*8;
            /* increment - Estimated number of integers which can be used from cache
             * without causing a miss
             */
            /* int increment;

            if(M < 32 || MAX_INTS_IN_CACHE % M)
                increment = 8;
            else
                increment = MAX_INTS_IN_CACHE / M;


            for(i = 0; i < M; i+= increment){
                for(j = 0; j < N; j++){
                    B[i][j] = A[j][i];

                    for(k = 1; k < increment && i + k < M; k++)
                        B[i + k][j] = A[j][i + k]; 
                }
            } */
        }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    
}

/*
 * trans_cheat - cheating by using a temporary array on the stack
 */
char trans_cheat_desc[] = "Illegal version that uses stack array";
void trans_cheat(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;
    int C[68][68]; /* Illegal! */
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            C[i][j] = A[i][j];
        }
    }    
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            B[i][j] = C[j][i];
        }
    }    
}

char trans_col_desc[] = "column-wise scan transpose";
void trans_col(int M, int N, int A[N][M], int B[M][N]){
    int i, j, tmp;
    for (j = 0; j < M; j++){
        for (i = 0; i < N; i++){
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    
}

char zig_zag_desc[] = "using a zig-zag access pattern";
void zig_zag(int M, int N, int A[N][M], int B[M][N]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            if(i % 2 == 0){
                B[j][i] = A[i][j];
            }else{
                B[M-1-j][i] = A[i][M-1-j];
            }
        }
    }  
}

char trans_blocking_desc[] = "Better locality via blocking";
void trans_blocking(int M, int N, int A[N][M], int B[M][N]){
    int x,y,i,j;
    for(x=0; x<N; x+=8){
        for(y=0; y<M; y+=8){

            for(i=x; (i<x+8) && (i<N) ; i++){
                for(j=y; (j<y+8) && (j<M); j++ ){
                    B[j][i] = A[i][j];
                }
            }

        }
    }
}

char smaller_blocking_desc[] = "Using smaller blocks";
void smaller_blocking(int M, int N, int A[N][M], int B[M][N]){
    int x,y,i,j;
    for(x=0; x<N; x+=4){
        for(y=0; y<M; y+=4){

            for(i=x; (i<x+4) && (i<N) ; i++){
                for(j=y; (j<y+4) && (j<M); j++ ){
                    B[j][i] = A[i][j];
                }
            }

        }
    }

}

// Via experiment, I found that smaller blocking performs better when 
// M=N=64 than M=N=32. Hence we use a variable block size
char variable_blocking_desc[] = "Using variable block size";
void variable_blocking(int M, int N, int A[N][M], int B[M][N]){
    int x,y,i,j,step;
    step = 2*64*64/M/N;
    if (step < 2)
        step=2;
    for(x=0; x<N; x+=step){
        for(y=0; y<M; y+=step){

            for(i=x; (i<x+step) && (i<N) ; i++){
                for(j=y; (j<y+step) && (j<M); j++ ){
                    B[j][i] = A[i][j];
                }
            }

        }
    }

}

// Blocking with zig-zagging access pattern
char zigzag_blocking_desc[] = "variable blocking + zigzag";
void zigzag_blocking(int M, int N, int A[N][M], int B[M][N]){
    int x,y,i,j,step,min;
    step = 2*64*64/M/N;
    if (step < 2)
        step=2;

    for(x=0; x<N; x+=step){
        for(y=0; y<M; y+=step){
            min = y+step < M ? y+step : M;
            for(i=x; (i<x+step) && (i<N) ; i++){
                for(j=y; (j<y+step) && (j<M); j++ ){
                    if(i % 2 == 0){
                        B[j][i] = A[i][j];
                    }else{
                        B[min-1-j+y][i] = A[i][min-1-j+y];
                    }
                }
            }

        }
    }
}

char smaller_blocking_zz_desc[] = "smaller blocks with zig zag";
void smaller_blocking_zz(int M, int N, int A[N][M], int B[M][N]){
    int x,y,i,j,min;
    for(x=0; x<N; x+=4){
        for(y=0; y<M; y+=4){
            min = y+4 < M ? y+4 : M;
            for(i=x; (i<x+4) && (i<N) ; i++){
                for(j=y; (j<y+4) && (j<M); j++ ){
                    if(i % 2 == 0)
                        B[j][i] = A[i][j];
                    else
                        B[min-1-j+y][i] = A[i][min-1-j+y];
                }
            }

        }
    }

}

// This one avoids post diagnal misses
// ONLY WORKS FOR SQUARE MATRICES
char post_diag_desc[] = "avoid post diag miss (requires square)";
void post_diag(int M, int N, int A[N][M], int B[M][N]){
    int i,j,ii,jj;
    int bsize = 4;

    /* if we should start at the front */

    for (ii=0; ii<N; ii+=bsize) { 
        /* copy the items above the diagonal in the block
         * containing the diagonal */
        for (i=ii; i<ii+bsize; i++)
            for (j=i+1; j<ii+bsize; j++)
                B[j][i] = A[i][j];
        /* copy the items below and including the diagonal
         * in the block containing the diagonal */
        for (i=ii; i<ii+bsize; i++)
            for (j=ii; j<i+1; j++)
                B[j][i] = A[i][j];
        /* copy every other block in the row of blocks
         * */
        for (jj=ii+bsize; jj<M+ii; jj+=bsize)  
            for (i=ii; i<ii+bsize; i++)  
                for (j=jj; j<jj+bsize; j++)   
                    B[j % M][i] = A[i][j % M];
    }

}

// This one uses non-square blocks
char nonsquare_blocking_desc[] = "using nonsquare blocks 8*4";
void nonsquare_blocking(int M, int N, int A[N][M], int B[M][N]){
    int x,y,i,j;
    for(x=0; x<N; x+=8){
        for(y=0; y<M; y+=4){

            for(i=x; (i<x+8) && (i<N) ; i++){
                for(j=y; (j<y+4) && (j<M); j++ ){
                    B[j][i] = A[i][j];
                }
            }

        }
    }
}

// non-squre blocks, version 2 using 4*8 blocks
char nonsquare_blocking2_desc[] = "using nonsquare blocks 4*8";
void nonsquare_blocking2(int M, int N, int A[N][M], int B[M][N]){
    int x,y,i,j;
    for(x=0; x<N; x+=4){
        for(y=0; y<M; y+=8){

            for(i=x; (i<x+4) && (i<N) ; i++){
                for(j=y; (j<y+8) && (j<M); j++ ){
                    B[j][i] = A[i][j];
                }
            }

        }
    }
}


/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);
    registerTransFunction(trans_cheat, trans_cheat_desc);
    registerTransFunction(trans_col, trans_col_desc);
    registerTransFunction(zig_zag, zig_zag_desc);
    registerTransFunction(trans_blocking, trans_blocking_desc);
      registerTransFunction(smaller_blocking, smaller_blocking_desc);
      registerTransFunction(variable_blocking, variable_blocking_desc);
      registerTransFunction(zigzag_blocking, zigzag_blocking_desc);
      registerTransFunction(smaller_blocking_zz, smaller_blocking_zz_desc);
      registerTransFunction(post_diag, post_diag_desc);
    registerTransFunction(nonsquare_blocking, nonsquare_blocking_desc);
    registerTransFunction(nonsquare_blocking2, nonsquare_blocking2_desc);
    // registerTransFunction(pranav_test, pranav_test_desc);
}


/* 
 * is_transpose - This optional helper function checks if B is the
 * transpose of A. You can check the correctness of your transpose by
 * calling it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N]){
    int i, j;

    for (i = 0; i < N; i++){
        for(j = 0; j < M; ++j){
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

