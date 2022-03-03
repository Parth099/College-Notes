//generics
const arr: Array<string> = ["lol"];

//sets promise state to sucess in 2000ms
const promise: Promise<string> = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve("Promise is completed");
    }, 2000); //2000ms
});

promise.then((v: string) => {
    console.log(v);
});

function merge<T extends object, S extends object>(ObjA: T, ObjB: S) {
    return Object.assign(ObjA, ObjB);
}

const merged = merge({ name: "Bobert" }, { job: "none" }); //error
merged.name; //valid

function getItem<T extends object, S extends keyof T>(obj: T, key: S) {
    return `Val: ${obj[key]}`;
}

console.log(getItem({ name: "Kris" }, "name"));
//generic classes
