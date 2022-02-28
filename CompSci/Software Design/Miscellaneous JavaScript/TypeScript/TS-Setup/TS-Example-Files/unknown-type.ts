let userIn: unknown;
let userName: string;

userIn = 5;
userIn = "str";

if (typeof userIn === "string") {
    userName = userIn;
}

//function has no return value not even undefined
function genError(message: string, errorCode: number): never {
    throw { message, errorCode };
}

const result = genError("Threw Error on purpose", -1)
console.log(result)