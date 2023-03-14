# Day 1 Check
| Team                 |
| -------------------- |
| Devin, Jimson, Parth |

## Step 3
> This pasted text proves that I have access to the Cluster.

For this example $x=3$ meaning that 3 process should have been triggered.

```shell
tul13074@chinook:~/LabMatrix/matrix-05-devin-jimson-parth$ mpiexec -f ~/hosts -n 3 ./hello
Hello from chinook I am process 0 of 3
Call to MPI_Bcast n==12345 on chinook myid=0
Hello from wolf2 I am process 2 of 3
Call to MPI_Bcast n==0 on wolf2 myid=2
Return from MPI_Bcast n==12345 on wolf2 myid=2
Hello from wolf3 I am process 1 of 3
Call to MPI_Bcast n==0 on wolf3 myid=1
Return from MPI_Bcast n==12345 on chinook myid=0
Return from MPI_Bcast n==12345 on wolf3 myid=1
```

## Step 4
```shell
tul13074@chinook:~/LabMatrix/matrix-05-devin-jimson-parth$ make test_mmult 
gcc test_mmult.c mmult.c mat.c -lm -o test_mmult
tul13074@chinook:~/LabMatrix/matrix-05-devin-jimson-parth$ ./test_mmult 
Matrices are the same
All tests pass.
```

This was running the basic matrix multiplication algorithm.

<div style="page-break-after: always; visibility: hidden"> 
\pagebreak 
</div>

## Step 5
```c
int mmult_simd(double *c,
               double *a, int aRows, int aCols,
               double *b, int bRows, int bCols)
{
    // dim(c) = a_row * b_col
    for (size_t i = 0; i < aRows; i++)
    {
        for (size_t j = 0; j < bCols; j++)
            c[i * bCols + j] = 0;

        for (size_t k = 0; k < aCols; k++)
        {
            for (size_t l = 0; l < bCols; l++)
            {
                c[i * bCols + l] += a[i * aCols + k] * b[k * bCols + l];
            }
        }
    }

    return 0;
}
```

This implemented the SIMD (optimized) algorithm.

Here is what I did:
1. Created a new file to test this function: `test_mmult_simd.c`
	+ This was copied from `test_mmult.c`
2. Added the new function `int mmult_simd(...)` to `mat.h`
3. Then added the following to the *makefile* (see below) and ran it.

```shell
test_mmult_simd: test_mmult_simd.c mmult.c mat.c
	gcc test_mmult_simd.c mmult_simd.c mat.c -lm -o test_mmult_simd

test_mmult_simd-O3: test_mmult_simd.c mmult.c mat.c
	gcc -O3 test_mmult_simd.c mmult_simd.c mat.c -lm -o test_mmult_simd-O3
```


> The one below utilizes the `-O3` optimization.

Both of these executables report the following message:
```txt
Matrices are the same
All tests pass.
```