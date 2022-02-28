//this was app.js for our first example


function addition(n1: number, n2: number, printResult: boolean, resultPhrase: string) {
    if (printResult) {
        console.log(resultPhrase + (n1 + n2));
    } else {
        return n1 + n2;
    }
}

const number1 = 67;
const number2 = 17;

const printResult = true;
let resultPhrase = "Result is ";

const result = addition(number1, number2, printResult, resultPhrase);
console.log(result);
