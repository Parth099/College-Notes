# Typing
## Core Types
These are types that are predefined in `JS` and `TS`.

| Types     | `JS`                 | `TS`                                                |
| --------- | -------------------- | --------------------------------------------------- |
| `number`  | 1, 5.6, -90          | Same as JS                                          |
| `string`  | text                 | Same as JS                                          |
| `boolean` | `true`, `false`      | `TS` has no "truthy" and "falsy" values             |
| `object`  | `{age: 50}`          | Same as JS but TS can be made to be more *specific* |
| `Array`   | `[1, "56", [false]]` | Same as JS but TS can make array type strict                                                    |

## TS-Only Types
| Type    | `TS` Example      | Description                            |
| ------- | ----------------- | -------------------------------------- |
| `Tuple` | (1, 2)            | Fixed **type** and **length** array    |
| `Enum`  | `enum {NEW, OLD}` | enumerated global `const` identifiers  |
| `any`   | \*                | Variable can hold **any** type of data |

## Core Types in TS
### Adding Types of Functions and Variables
```ts
function addition(n1: number, n2: number) {
	const result =  n1 + n2;
	return result;
}
```
We do not need to assign type assignments to declared variables like `result` because `TS` can **infer** types of variables. However it is possible to do it yourself. 

```ts
const result: number =  n1 + n2;
```
This type of typesetting is frowned upon since `TypeScript` can always infer types *perfectly* by itself.

However using type annotations on uninitialized variables is valid and good practice. 
```ts
let prefectSquare: number;
//later in code
perfectSquare = 400; //valid
perfectSquare = '9'; //not valid
```

Something like this will let you assign any datatype for the first initialization. 
```ts
let result;
```

### Objects
Suppose we declare this in a `.ts` file.
```ts
const person = {
	name: "Tom",
	age: 56,
};
```
`TS` will infer our object types like so:
```ts
const person: {  
	name: string;  
	age: number;  
}
```
This is **not** our object, it is only what TS thinks our object is.

We can add a object annotation like so, and let TS know our `person` is an object
```ts
const person: object = {
	name: "Tom",
	age: 56,
};
```

However, the following line causes an error: 
```ts
console.log(person.name)
```
This is because now TS is not sure what is inside the object. We need to make our `object` annotation more specific. 

This is then valid: we use value-type pairing. 
```ts
const person: {
	name: string;
	age: number;
} = {
	name: "Tom",
	age: 56,
};

console.log(person.name);
```
This is not the most optimal way of doing object typing. 

### Arrays
We can declare *typed* arrays with
```ts
let favActivities: string[];
favActivities = ["running", "eating"];
```
Adding a `1` to `favActivities` will cause an error. 

To create regular `JS` un-typed arrays we can use
```ts
let arr: any[]
```
This `any` is a keyword in `TS` to make allow **any** datatype. 

#### Array Typing Benefit
```ts
for (let act of favActivities) {
	console.log(act.toUpperCase());
}
```
Since the array is type `string`, TS will know that `act: string`. Thus the autocomplete *will* offer string based methods, and conversely show errors when you attempt to use functions not available to the type.  

## New TS Types
### Tuple
```ts
let role: [number, string] = [1, "author"]; //id, decrip
console.log(role)
```

We define a 2-length array with element 1 being a number and 2 a string. The only flaw here is `.push(element: any)`. Sadly, we can push any element on to the array but it offers the regular protections. 

### Enum
Suppose we wanted a user access constant that defines what level of access someone has on a `person` object.
something like
```js
0 - no access
1 - read access
2 - admin access
```

#### Before ENUM
```ts
const person = {
	name: "Tom",
	age: 56,
	hobbies: ["cooking", "talking"],
	access : 2,
};
```
Now we see that `"Tom"` has admin access but this is unreadable.

We can do this too:
```ts
const NONE = 0;
const READ = 1;
const ADMIN = 2;

const person = {
	name: "Tom",
	age: 56,
	hobbies: ["cooking", "talking"],
	access : ADMIN,
};
```
This is more readable.
#### After ENUM
```ts
enum Access {NONE, READ, ADMIN}; //{0, 1, 2}

const employee = {
	name: "Tim",
	age: 56,
	hobbies: ["cooking", "talking"],
	access : Access.READ, //1
};
```
The enum much like in C (see, [[2.5 Functions]]) makes code more readable and shorter. Much like C, the uppercase is convention.

We are also not restricted to `{0, 1, 2, 3, ...}`
Here are some valid enums
```ts
enum Access {NONE = 15, READ, ADMIN}; //{15, 16, 17}
enum Access {NONE = 100, READ = "READ", ADMIN = "ADMIN"}; 
```
With enum we will not worry about the value only the constant var name.

### Any Type
```ts
let arr: any[]; //Regular JS array
let thing: any;
```
`any` removes all `TS` optimizations and should be used as a final measure or for types that can only be determined on runtime. 