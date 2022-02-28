//obj
const person = {
    name: "Tom",
    age: 56,
    hobbies: ["cooking", "talking"],
    access : 2,
};

//arr
let favActivities: string[];
favActivities = ["running", "eating"];

console.log(person.name);
//console.log(person.nickname) error in TS

for (let act of favActivities) {
    console.log(act.toUpperCase());
}
//tup
let role: [number, string] = [1, "author"]; //id, decrip
console.log(role)

//enum
enum Access {NONE, READ, ADMIN}; 
const employee = {
    name: "Tim",
    age: 56,
    hobbies: ["cooking", "talking"],
    access : Access.READ, //1
};