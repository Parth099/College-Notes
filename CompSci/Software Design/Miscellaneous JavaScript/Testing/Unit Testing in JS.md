Recall that in TDD [[Unit Testing]], we write tests first.

# Testing Units Without any External Libraries

Suppose we have a unit `Func` we wish to test. In JavaScript we can write:
```js
if(Func(...args) != val){
  throw new Error("Fails if ... is present")
}
```
*val* is the correct output for this function. When tests are run if any errors exist, they will be displayed. Each test here will target a case of the unit, there is no use of tests testing the same thing. 

# Testing via Test Runners
## Why?
1. The test code is easier to read
2. The results of the test look nice
3. Great for team projects
4. Works well with Continuous Integration*
5. The tests will be automated and will run based on your preferences

## Testing Library: Jest

### Installing Jest
In the parent folder type:
```linux
npm init -y
npm install --save-dev jest
```

Jest is being used because its the most developed tool as if now. It is also bundled with CreateReactAPP from Facebook.  

### Using Jest
Before starting, this must be present in `package.json`
```js
"scripts": {"test":"jest"}
```

While testing with Jest, the testing Unit and Jest-Tests are in different files. So, if the unit is called `order-total.js`, its testing file contains all of its tests will be called  `order-total.test.js`. We must also link the 2 files via using imports.

Suppose `order-total.js` has a function called `orderTotal()`. Use: 
```js
module.exports = orderTotal
```
in `order-total.js` to mark `orderTotal()` to be exported.

Use
```js
const ordertotal = require("./order-total");
```
in the testing file.

### Running Jest
To run test files one by one we need: 
```linux
sudo npm i -g jest-cli
```
This installs *Jest* in the terminal

We can then simply type **jest** in any folder that has test or has subfolders with tests to run all tests. 

If we need to run individual tests we type: 
```linux
jest FILENAME
```
This FILENAME would be `order-total.test.js` from the above example.