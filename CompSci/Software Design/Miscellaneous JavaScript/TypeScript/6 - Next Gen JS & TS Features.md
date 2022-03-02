## Next Gen JS & TS Features
### Default Arguments
```ts
function add(n1: number, n2: number = 1){
	return n1+n2;
}
console.log(add(12))
```
Default arguments must be last in parameter order.  
### Object Spread
> Array Spread not included because it is trivial

Copying `person` object
```ts
const person = {
	name: "Min",
	age: 56,
};

const person2 = { ...person };

console.log(person2, person === person2);
```

```ts
[OUTPUT]
Object { name: "Min", age: 56 } false
```

### Rest Parameters 
Creating functions with variable length parameters
```ts
function add2(...args: number[]) {
	return args.reduce((prev: number, curr: number) => prev + curr, 0);
}

console.log(add2(1, 2, 3, 4, 5, 6)) //sum is 21
```

`add2` will accept any number of `args` . 