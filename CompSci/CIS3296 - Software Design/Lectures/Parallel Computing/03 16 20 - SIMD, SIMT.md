# SIMD - Single instruction, multiple data

Each single instruction is performed on multiple streams of data simultaneously.  

## Matrix Multiplication
```java
for (i = 0; i < N; i++) {
  for (j = 0; j < N; j++)
    c[i][j] = 0;
  for (k = 0; k < N; k++)
    for (l = 0; l < N; l++)
      c[i][l] += a[i][k] * b[k][l];
}
```

## `-O3` and SIMD
For example, the Pentium IV and later processors can perform 4 floating point operations simultaneously. 

So the innermost loop runs like:
```java
for (l = 0; l < N; l+=4)
      c[i][l:l+3] += a[i][k] * b[k][l:l+3];
```


# SIMT - Single Instruction Multiple Threads 
Multiple threads execute the same instruction concurrently. 

A warp executes one common instruction at a time where a warp is a group of 32 threads. 
