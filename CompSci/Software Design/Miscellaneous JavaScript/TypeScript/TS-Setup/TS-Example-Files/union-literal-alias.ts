//alias
type Combinable = number | string;
type ConversionOutputter = "as-text" | "as-number"; 

//recall both strings and numbers have '+' op
//union type
function combine(n1: Combinable, n2: Combinable) {
    let result;
    if (typeof n1 === "number" && typeof n2 === "number") {
        result = n1 + n2;
    } else {
        result = n1.toString() + n2.toString();
    }
    return result;
}

const out_1 = combine(1, 2);
const out_2 = combine("Alpha", "Psi");

console.log({ out_1, out_2 });
