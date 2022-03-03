"use strict";
//generics
const arr = ["lol"];
//sets promise state to sucess in 2000ms
const promise = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve("Promise is completed");
    }, 2000); //2000ms
});
promise.then((v) => {
    console.log(v);
});
function merge(ObjA, ObjB) {
    return Object.assign(ObjA, ObjB);
}
const merged = merge({ name: "Bobert" }, { job: "none" }); //error
merged.name; //valid
function getItem(obj, key) {
    return `Val: ${obj[key]}`;
}
console.log(getItem({ name: "Kris" }, "name"));
//generic classes
