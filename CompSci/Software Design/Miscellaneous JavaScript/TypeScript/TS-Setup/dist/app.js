"use strict";
function add(n1, n2 = 1) {
    return n1 + n2;
}
console.log(add(12));
const person = {
    name: "Min",
    age: 56,
};
const person2 = Object.assign({}, person);
console.log(person2, person === person2);
function add2(...args) {
    return args.reduce((prev, curr) => prev + curr, 0);
}
console.log(add2(1, 2, 3, 4, 5, 6)); //sum is 21
