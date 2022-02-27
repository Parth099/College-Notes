const input1 = document.querySelector("#num1");
const input2 = document.querySelector("#num2");

const button = document.querySelector("#adder");

const add = (a, b) => a + b;

button.addEventListener("click", function () {
    console.log(add(input1.value, input2.value));
});
