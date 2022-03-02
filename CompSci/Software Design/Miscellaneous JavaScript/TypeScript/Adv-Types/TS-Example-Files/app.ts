type Admin = {
    name: string;
    privileges: string[];
};

type Employee = {
    name: string;
    startDate: Date;
};

type ElevatedEmployee = Admin & Employee;

const superEmp: ElevatedEmployee = {
    name: "Sim",
    privileges: ["elevator"],
    startDate: new Date(),
};

type Combinable = string | number;
type Numeric = number | boolean;

type Universal = Combinable & Numeric;

let p: Universal;
// p = "5"; -> error
// p = false; -> error
p = 5; //valid

//mployee and Admin are Object Types
type JobDoer = Employee | Admin;
function printEmpInfo(emp: JobDoer) {
    console.log(`Name: ${emp.name}`);
    if ("privileges" in emp) {
        console.log(`Privs: ${emp.privileges}`);
    }
}

interface Bird {
    kind: "flier"; //Literal Type, this is a constant
    flyingSpeed: number;
}

interface Cow {
    kind: "walker";
    walkingSpeed: number;
}

type Animal = Bird | Cow;

function showSpeed(animal: Animal) {
    let speed: number; //only numbers are valid speeds
    switch (animal.kind) {
        case "flier":
            speed = animal.flyingSpeed;
            break;
        case "walker":
            speed = animal.walkingSpeed;
            break;
    }

    console.log({ speed });
}

//showSpeed({ kind: "flier", walkingSpeed: 5 }); //error
//showSpeed({ kind: "flier", flyingSpeed: 5 }); //valid

//casting
const usrIn = document.querySelector("#user-input");
if (usrIn) {
    (usrIn as HTMLInputElement).value = "Type in this Field";
}

//index types
interface ErrorObj {
    id: string;
    [prop: string]: string;
}

let formErrors: ErrorObj;
formErrors = {
    id: "news-letter-form", //id of our dom element
    email: "not a valid email",
    zip: "not a valid zip code",
    //...
};

//overloading
//type Combinable = string | number;
function add(a: string, b: string): string;
function add(a: Combinable, b: Combinable) {
    if (typeof a === "string" || typeof b === "string") {
        return a.toString() + b.toString(); //string concat
    }
    return a + b; //demorgans --> both are ints
}

const out = add("Expo", "Marker");
console.log(out.slice(4)); //Marker


