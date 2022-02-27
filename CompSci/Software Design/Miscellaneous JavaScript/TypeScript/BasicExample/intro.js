var num1 = document.querySelector("#num1");
var num2 = document.querySelector("#num2");
var btn = document.querySelector("#adder");
var addFunc = function (a, b) { return a + b; };
//num1.value cases an error as TS wont know if QuerySelc will work
//
btn.addEventListener("click", function () {
    console.log(addFunc(+num1.value, +num2.value));
});
