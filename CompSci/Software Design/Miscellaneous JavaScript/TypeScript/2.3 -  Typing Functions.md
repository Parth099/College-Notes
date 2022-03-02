# Function Typing
## Function return type
```ts
function add(n1: number, n2: number): number {
	return n1 + n2;
}
```
The add function always returns a number. 
Setting function return type is not a good idea unless you have a reason for it. It is convention to let TS infer the rtype. 

## `void` rtype
```ts
function printResult(num: number): void{
	console.log("Result was: "+ num);
}
```
Self-explanatory, it returns `undefined` . We use `void` and not `undefined` because `void` is used when a function has no return statement. 

This is the valid alternate code, but the function above is far better.
```ts
function printResult(num: number): undefined{
	console.log("Result was: "+ num);
	return undefined;
}
```

## `Function` type
Setting a variable type to `function` , meaning storing pointers.
```ts
let combiner: Function;
combiner = add;
console.log(combiner(1, 1));
```

There is yet an issue. `combiner` can also be set to `printResult` shown above but it does not have 2 arguments. 

To avoid this issue, we can use this syntax
```ts
let combiner: (a: number, b: number) => number;
combiner = add;
//combiner = printResult --> error
console.log(combiner(1, 110));
```
`combiner` will only accept functions that have the same signature:
+ input as 2 numbers
+ output as a number

## Callback Typing
Nothing new here just the last few elements of the lesson
```ts
type printer = (a: number) => void;
function addAndCallBack(n1: number, n2: number, cb: printer) {
	cb(n1 + n2);
}
addAndCallBack(4, 56, printResult)
```
```js
[OUTPUT]
Result was: 60
```

Note: While `printer` has rtype void, the actual callback can return a value. The point of using `void` is to signal we are not going to do anything with the r-value of `cb` .

## `unknown` type
```ts
let userIn: unknown;
let userName: string;

userIn = 5;
userIn = "str";
userName = userIn;
```

This causes an error:
```c
app.ts:7:1 - error TS2322: Type 'unknown' is not assignable to type 'string'.
```

We can use unknown for type safety since it will always always force us to check typing.

### The fix
```ts
let userIn: unknown;
let userName: string;

userIn = 5;
userIn = "str";

if (typeof userIn === "string") {
	userName = userIn;
}
```

## `never` rtype
```ts
//function has no return value not even undefined
function genError(message: string, errorCode: number): never {
	throw { message, errorCode };
}
const result = genError("Threw Error on purpose", -1)
console.log(result)
```
For functions with no return value (crash or inf loops). 