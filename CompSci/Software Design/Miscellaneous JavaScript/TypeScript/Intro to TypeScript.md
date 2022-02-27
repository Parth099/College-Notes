# Intro to TypeScript (TS)
Course: [Youtube - Acedemind](https://www.youtube.com/watch?v=BwuLxPH8IDs) 
<!--
	@TIME: 18:55
-->
## What is Typescript
TS is a superset of JS, it is built on top of JavaScript adding new features and advantages. However, browsers and `node` cannot run TS code. We need TS code to be **complied** into JS code to then be ran by the browser. TS is a tool to build clear code.

Since it is compiled, errors are thrown. 
Given its name, *Type*Script adds typing to JS making it easier to debug and foresee errors. With TS we don't need type sanitize via if guards.


## Things to learn from Example 1
### `const` keyword
```
path: ./BasicExample
```
`TS` does not allow two files to share any `const` names. In other words two `const` vars in different files cannot have the same name

### Letting TS know about Nullity
We can let TS know that an function will not return null via an `!` after the function call.
```js
const num1 = document.querySelector("#num1")!;
```
We can even inform TS on what the function will return like so:
```js
const num1 = document.querySelector("#num1")! as HTMLInputElement;
```

With this we are forced to check about what we are really returning/receiving.

### Adding Types to `functions`
```js
const addFunc = (a: number, b: number) => a + b;
```
To specify a type we just add a `:` and then the type.
