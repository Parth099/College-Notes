We introduced Jest in the [[Unit Testing in JS]] note.

## Jest Basics
The [getting-started](https://jestjs.io/docs/getting-started) from jest docs is great.

## Matchers
Most of this will be from [Jest Docs](https://jestjs.io/docs/using-matchers)

Code:
```js
test('two plus two is four', () => {
	expect(2 + 2).toBe(4);
});
```
This test uses the `expect()`, or an "expectation" object. This object is what a matcher is called on. In this case, `toBe(4)` is the matcher. Here it is testing for exact value. 

**Notice:** `toBe()` uses `Object.is(v1, v2)` to test for equality, and thus 2 objects are only equal if there share the same memory address.  

If we wish to test for equality based on value, we use the `toEqual(obj)` matcher.

More Advanced Matchers like using Truthiness, Iterables, and Numbers are on the docs.