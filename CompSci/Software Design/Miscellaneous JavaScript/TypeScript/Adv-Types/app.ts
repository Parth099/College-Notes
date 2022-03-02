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
