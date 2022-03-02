"use strict";
//using interface as type to typecheck `objects`
//NOTE: this is before we took name and created Interface Named
var usr1;
usr1 = {
    name: "Max",
    age: 12,
    greet: function greet(s) {
        console.log(s + this.name);
    },
};
usr1.greet("Hi I am ");
//interfaces with class
var Person = /** @class */ (function () {
    function Person(name, age, outName) {
        this.name = name;
        this.age = age;
        this.name = name;
        this.age = age;
        if (outName) {
            this.outputName = outName;
        }
    }
    Person.prototype.greet = function (phrase) {
        if (this.outputName) {
            console.log("<Person> Hi I am " + this.outputName);
        }
        else {
            console.log("<Person> Hi I am " + this.name);
        }
    };
    return Person;
}());
var usr2 = new Person("Jen", 49, "robot");
usr2.greet("Hi, I am ");
var add;
add = function (n1, n2) { return n1 + n2; };
