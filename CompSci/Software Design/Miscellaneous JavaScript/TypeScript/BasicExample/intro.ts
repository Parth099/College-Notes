const num1 = document.querySelector("#num1")! as HTMLInputElement;
const num2 = document.querySelector("#num2")! as HTMLInputElement;

const btn = document.querySelector("#adder");

const addFunc = (a: number, b: number) => a + b;

//num1.value cases an error as TS wont know if QuerySelc will work
//
btn.addEventListener("click", function () {
    console.log(addFunc(+num1.value, +num2.value));
});
