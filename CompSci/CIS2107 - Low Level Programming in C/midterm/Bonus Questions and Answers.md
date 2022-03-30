# Bonus Questions
## 1.01 Unix
1. What is the diff between exit/logout  
2. `who` vs `whoami` vs `logname` vs `users`
3. Difference between folder (*Windows* vs *Unix*)

## 2.01 C-Lang
1. Compiler VS Interpreter
2. What is GNU? Why isn't it like Unix.
3. Machine Code VS Object Code
4. Firmware

## 2.02 Intro to C programming
1. What is the difference between a function in C vs Method in Java.
2. What is undefined behavior (UB) in C?
3. C99 vs C11

## 2.03 Code Structure
1. Explain ASCII vs UTF
2. What is the longest possible identifier in C

## 2.05 Functions
1. Know the diffs between
	+ `#define`
	+ `static`
	+ global & local scope
	+ `const`

## 2.07 Pointers
1. How can we find the size of a function?

## 2.11.1 File Writing \[SEQ\]
1. When a file is deleted is it not *actually* deleted yet we cannot see it. What actually occurs? 
2. Diff between stream vs file \[Technical\]
	+	Which is good for what job?

## 2.11.2 File Writing \[RAF\]
1. How do file extensions work?
 
--- 
 # Answers
 
## 1.01 Unix
1. `logout` is an internal command of the shell which means that its action depends on the shell implementation. `logout` does what it says: terminates the session. `exit` is like a `c` function that kills processes. `exit` on a shell terminates the shell process which is bound to later restart. 
2. `who` vs `whoami` vs `logname` vs `users`
	+	`who`: displays all logged on users 
	+	`whoami`: displays the **effective** user. If you are root it will show that
	+	`logname`:prints **your** username 
	+   `users`

3. The main difference is that a folder is a logical concept that does not necessarily map to a physical directory. A directory is an file system object. A folder is a GUI object. This means that a directory **always** maps to a physical storage object while a folder may not map to a physical address (virtual folder). 

## 2.01 C-Lang
1. Compiler vs interpreter
	+ compiler reads the entire file while is line by line
	+ Compiler **does** produce intermediate object code
	+ Compiler is more efficient 

2. GNU is an extensive collection of free software, which can be used as an operating system or can be used in parts with other operating systems. Unlike Unix which is trademarked, GNU Linux is free to use by **anyone**
	+	Funny enough, the `U` stands for not Unix

3. Machine VS Object Code
	+	Machine Code is binary code to be executed by the compiler. 
	+	Object code is the part of machine code that is not linked to become a complete program yet. The linker will connect everything together.

4. Firmware is a type of software that is etched directly into a piece of hardware. It operates without going through APIs, the operating system, or device drivers. It is what allows cameras on phones to be used. 

## 2.02 Intro to C programming

1. The difference is that non static methods cannot be used without their parent class while functions **have no** class. Functions do not have privacy control like methods do. Functions are require all data be passed in while methods can access class data while running. 

2. Whenever the result of a program is unpredictable, it is said to have undefined behavior. This can be dividing by 0 or accessing array memory greater than its length. 
3. C11 is the latest ANSI C specification. 

## 2.03 Code Structure
1. ASCII is a subset of UTF. UTF-8 is an encoding scheme that uses 8-bytes to set up a `char` model. UTF is backwards comparable with ASCII. 
2. If you wish to be portable your var names must be less than 31 chars long. Otherwise there is **no** restriction. 

## 2.05 Functions
1. \_
	+ `#define` is a preprocessor directive. Any top level `#define` var is **global**
	+ `static` variables use bss data. This means they are only initialized once. They do not go out of scope in the scope they are defined in. If a static variable is defined in a function and the function ends, the next time the function is called the static variable will be recalled and **will** retain its value from last run. 

## 2.07 Pointers
1. ???

## 2.11.1 File Writing \[SEQ\]
1. Most operating systems keep track of files by keeping pointers to the start of file pointers and end of file pointers. When you delete these files their pointer gets removed but their data does not. Since the file pointers do not exists this space is freed for any other data to be over written there. 
2. Files are "persistent" and "non-volatile". Data in files do not require power to be maintained. A Stream is like a connection. An example of a Stream is reading integers from `stdin`. We are often unsure when the data will end the data is live. We process as we receive it while a file has data rewritten to it. 

## 2.11.2 File Writing \[RAF\]
The file extension is the protocol for reading the file at hand. 