# More Types
## Union Type
```ts
function combine(n1: number | string, n2: number | string){
	let result;
	if (typeof n1 === "number" && typeof n2 === "number") {
		result = n1 + n2;
	} 
	else {
		result = n1.toString() + n2.toString();
	}
	return result;
}
```

Notice how the parameters are catching possible input *types*

## Literal Type
Instead of a variable being `number, string, bool, ...` we are instead being very specific on what value it should be.
```ts
const number1 = 56;
```
The type inferred here is `56` and not number, but `56` is a number. 

We can employ Literal Types in function params to get less error prone code. 

## Type Aliasing 
This is like `typedef` in C. 
Here is the syntax where we use aliasing with `union` types.
```ts
type Combinable = number | string;
function combine(n1: Combinable, n2: Combinable) {
	//code...
}
```

Literal Type Example:
```ts
type ConversionOutputter = "as-text" | "as-number";
```