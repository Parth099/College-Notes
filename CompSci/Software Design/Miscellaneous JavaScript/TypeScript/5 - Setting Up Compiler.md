# Setting Up The TS Compiler
## Watch mode
```unix
tsc [FILENAME] -w
```
the `-w` or `--watch` will watch the file for changes and compile per change.

## Compiling Many Files
Suppose we have 
```
file1.ts
file2.ts
```
And we want to watch for all changes. 

We firstly create a config file with
```unix
tsc --init
```
This tells TSC that this is the project directory.

Then to compile all of our files we just run
```unix
tsc
```
This will compile all files in the folder. 
```ts
[FILE DIRECTORY AFTER tsc]

file1.ts
file1.js

file2.ts
file2.js
```

We can even watch the entire project. 

## `tsconfig.json` Basics
### Source Map
We can bridge `.ts` and `.js` files via a source-map. This can help trace bugs in the browser-based `.js` files to our input `.ts` files.

Trigger
```json
"sourceMap": true,
```

<!-- Wont be finishing this since all this can be looked up -->
