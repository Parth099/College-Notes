//not the same as type (typedef)
interface Named {
    readonly name: string;
    outputName?: string; //optional prop
}

//we can extand from many classes
interface Greetable extends Named {
    age: number;

    greet(phrase: string): void;
}

//using interface as type to typecheck `objects`
//NOTE: this is before we took name and created Interface Named
let usr1: Greetable;
usr1 = {
    name: "Max",
    age: 12,
    greet: function greet(s: string) {
        console.log(s + this.name);
    },
};
usr1.greet("Hi I am ");

//interfaces with class
class Person implements Greetable {
    //name is readonly outside of class
    outputName?: string;
    constructor(public name: string, public age: number, outName?: string) {
        this.name = name;
        this.age = age;

        if (outName) {
            this.outputName = outName;
        }
    }

    greet(phrase: string): void {
        if (this.outputName) {
            console.log("<Person> Hi I am " + this.outputName);
        } else {
            console.log("<Person> Hi I am " + this.name);
        }
    }
}

let usr2 = new Person("Jen", 49, "robot");
usr2.greet("Hi, I am ");

//function Interface Types
interface AddFn {
    (a: number, b: number): number;
}
let add: AddFn;
add = (n1: number, n2: number) => n1 + n2;
