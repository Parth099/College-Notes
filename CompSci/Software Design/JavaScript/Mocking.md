Associated with: [[Unit Testing]]
# Mocking Functions
Recall the explanation of _tightly coupled_ functions from [[Pure Functions]]
One of the solutions is the conversion to a Pure Function

A secondary solution is a Mock Function. A Mock function used when you simply cannot create a Pure function. You can create a mock function that does exactly what you want it to do, a test double. This is great for *async functions*. We can *mock* the API call and then use the data for testing. This is because Testing is supposed to be fast, calling an API in test calls will slow down testing.  

# Tight Coupling(TC) & Mocking
We already know that TC makes it harder for you to change your code down the line. Coupling can occur in:
- Subclasses: The dependence on Parent implementation is *very* high
- Mutable State: Code that shares the mutable state with other code. Something like race conditions. 
- Message/Event: Code that communicates with other units via passing events & messages. 

Mocking is required when [[Pure Functions]] are not possible or create too much overhaul. Moreover, the requirement of Mocking arises when a unit of code can never function without another unit. 

## Mocking Examples 
From: [MPJ](https://www.youtube.com/watch?v=3PjdxjWK0F0)

Imagine we had an order total function with proper tests which ensured its proper output. For now this function was working. 

Function Body Example: 
```js
function orderTotal(){
	return order.items.reduce((prev, cur) => {
		cur.price * (cur.quantity || 1) + prev, 0)) 
	};
}
```
Now the issue presented in that video is [VAT tax](https://www.investopedia.com/terms/v/valueaddedtax.asp). We need to call an API to ensure its proper price calculation now. How can we test this API?

Here we run into an issue, we cannot call the API to test it. And what do we even test?!

We have 3 parts:
1. Calling the API
2. Extracting the VAT Value
3. Using the VAT value
### 1. Calling The API
Assume `orderTotal` is now a promise-based API caller.

Since we cannot call the API for real, we need to mock it!

```js
it('calls vatapi.com correctly', () => {
	let isFakeFetchCalled = false
	const fakeFetch = (url) => {
		expect(url).toBe('https://vatapi.com/v1/country-code-check?code=DE')
		isFakeFetchCalled = true
	}
	orderTotal(fakeFetch, {
		country: 'DE',
		items: [
		{ 'name': 'Dragon waffles', price: 20, quantity: 2 }
		]
	}).then(result => {
	expect(isFakeFetchCalled).toBe(true)
	})
})
```
We need to **edit** the orderTotal code, to accept a functional arg for `fetch()`. This is a simple test to see whether or not the API is being really called.   

We need to go further to see if the correct call is made. 
This can be done by *expecting* the URL of the call to be correct, like making sure the QueryString is correct.

Passing the `fetch()` ref into `orderTotal()` is known as **dependency injection**. This is common in applications.