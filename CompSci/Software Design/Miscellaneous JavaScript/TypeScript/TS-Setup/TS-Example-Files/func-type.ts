function add(n1: number, n2: number): number {
    return n1 + n2;
}

function printResult(num: number): void {
    console.log("Result was: " + num);
}

let combiner: (a: number, b: number) => number;
combiner = add;
//combiner = printResult -> error
console.log(combiner(1, 110));

type printer = (a: number) => void;
function addAndCallBack(n1: number, n2: number, cb: printer) {
    cb(n1 + n2);
}
addAndCallBack(4, 56, printResult)

