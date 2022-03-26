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

Based on the GDB output we notice that `arr[n]` will move the array pointer (from address initial) forward $n$ spaces **and** dereference the pointer to get the value out. Since the array name (alias) points to the first element much like `arr[0]` which is a 0 shift forward we **do** expect the same value. 

<br>
<br>
<br>
<br>
<br>
<br>
<br>

<br>
<br>
<br>


> 5. In `Blowfish_Init( )`, what is the value of key?

The address and value:
```c
(gdb) break 383

Breakpoint 1, main () at GDBassign.c:383
(gdb) p key
$1 = 0x400ce0 "LAME_KEY"
(gdb)

```
The answer to **\#6** is also here. 
*Note:* Line 383 is when the function is called.

> 7. In Blowfish_Init( ), what are the values of i and j after the nested for loops have finished? i.e., after:
>```c
>for (i = 0; i < 4; i++) {
>	for (j = 0; j < 256; j++)
>		ctx->S[i][j] = ORIG_S[i][j];
>}
>```
>the code above is run

Given that both $i, j$ are declared outside of loop. Their scope is larger than the loop's context. Thus, $i = 4$, $j = 256$

> 8. What command(s) did you type in order to learn this?

```c
(gdb) break Blowfish_Init
Breakpoint 1 at 0x400986: file blowfish.c, line 704.
(gdb) next
The program is not being run.
(gdb) run

(gdb) break blowfish.c:718
Breakpoint 2 at 0x4009f6: file blowfish.c, line 718.
(gdb) c
Continuing.

Breakpoint 2, Blowfish_Init (ctx=0x7fffffffd8e0, key=0x400ce0 "LAME_KEY", keyLen=8) at blowfish.c:722
(gdb) p i
$1 = 4
(gdb) p j
$2 = 256
```

> 9. Before the `Blowfish_Encrypt` function is called, what is the value of `stuff[3]` (for each, print the value, and the command used to obtain the value):

| format | code            | value                            |
| ------ | --------------- | -------------------------------- |
| hex    | `p /x stuff[3]` | `0x20656874`                     |
| bin    | `p /t stuff[3]` | `100000011001010110100001110100` |
| float  | `p /f stuff[3]` | `1.94316151e-19`                 |

Four char:
```c
(gdb) x /4c &stuff[3]
0x7fffffffc26c: 116 't' 104 'h' 101 'e' 32 ' '
```

> 10. Before the Blowfish_Encrypt function is called, what is the value of stuff if we treat it as a string?

Command:
```unix
(gdb) x /s stuff
```

Output
```c
0x7fffffffc260: "Oh, who are the people in your neighborhood?\nIn your neighborhood? \n In your neighborhood? \n Say, who are the people in your neighborhood? \n The people that you meet ea
ch day \n \n [Anything Muppet #1: "...
```


> 11. What is the value of x the first time that the function F() in Blowfish.c is called?

```unix
(gdb) break F

Breakpoint 1, F (ctx=0x7fffffffd8e0, x=1753098189) at blowfish.c:550
(gdb) p x
$1 = 1753098189
```

The value is `1753098189`

<br>
<br>
<br>
<br>
<br>
<br>
<br>

> 12. What is the output if we run GDB's backtrace (abbreviated "`bt`") command inside the function `F()` in `Blowfish.c` the first time `F()` is called? Briefly explain the output of the command in your own words.

Command output:
```c
(gdb) bt
#0  F (ctx=0x7fffffffd8e0, x=1753098189) at blowfish.c:550

#1  0x0000000000400860 in Blowfish_Encrypt (ctx=0x7fffffffd8e0, xl=0x7fffffffc210, xr=0x7fffffffc214) at blowfish.c:602

#2  0x0000000000400aa9 in Blowfish_Init (ctx=0x7fffffffd8e0, key=0x400ce0 "LAME_KEY", keyLen=8) at blowfish.c:754

#3  0x000000000040066d in main () at GDBassign.c:383
```

`bt` is the steps it took to be where are are in the execution frame now. We started from `main` which called, `Blowfish_Init`, which then called `Blowfish_Encrypt` and now we are at `F`.

`bt` serves to display the call stack where the most recent function called is at the top.