function add(n1: number, n2: number = 1) {
    return n1 + n2;
}

console.log(add(12));

const person = {
    name: "Min",
    age: 56,
};

const person2 = { ...person };
console.log(person2, person === person2);

function add2(...args: number[]) {
    return args.reduce((prev: number, curr: number) => prev + curr, 0);
}

console.log(add2(1, 2, 3, 4, 5, 6)) //sum is 21