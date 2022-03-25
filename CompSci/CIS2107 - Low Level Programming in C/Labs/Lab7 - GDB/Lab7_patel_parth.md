# GDB - Mini Lab
## Questions
> 1. What is the command to compile the files with extra symbols that are useful for GDB?

We must run 
```unix
gcc -g GDBassign.c blowfish.c -o GDBassign
```

> 2. What's the address of `stuff` ? 

GDB input (Line 1) and output (Line 2)
```c
(gdb) x stuff
0x7fffffffc260: 0x00000000
```

> 3. What's the address of `stuff[0]`?
```c
(gdb) x stuff[0]
0x0:    Cannot access memory at address 0x0
(gdb) x &stuff[0]
0x7fffffffc260: 0x00000000
```

> 4. Do we expect these to be the same?Why? Explain what the `[]` operator does in C.

Based on the GDB output we notice that `arr[n]` will move the array pointer (from address initial) forward $n$ spaces **and** dereference the pointer to get the value out. 

> 5. In `Blowfish_Init( )`, what is the value of key?

The address and value:
```c
(gdb) x key
0x400ce0:       0x454d414c
(gdb) p key
$3 = 0x400ce0 "LAME_KEY"
```