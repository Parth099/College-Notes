"use strict";
const superEmp = {
    name: "Sim",
    privileges: ["elevator"],
    startDate: new Date(),
};
let p;
// p = "5"; -> error
// p = false; -> error
p = 5; //valid
function printEmpInfo(emp) {
    console.log(`Name: ${emp.name}`);
    if ("privileges" in emp) {
        console.log(`Privs: ${emp.privileges}`);
    }
}
