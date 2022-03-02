class Department {
    protected employees: string[] = [];
    static expireYear = 2023; //static var Department.expireYear
    constructor(public readonly id: number, public name: string) {
        this.id = id;
        this.name = name;

        //readonly id --> cannot alter id
        //private disallows var access outside class
    }

    describe(this: Department) {
        console.log("Department: " + this.name);
    }

    addEmployee(emp: string) {
        this.employees.push(emp);
    }

    printEmpInfo() {
        this.employees.forEach((emp, idx) => {
            console.log(`${idx + 1} - ${emp}`);
        });
    }

    //accessed w/o creating the class via CLASSNAME.createEmployee
    static createEmployee(name: string) {
        return { name };
    }
}

const dept = new Department(1, "Medical");
dept.describe(); //valid

dept.addEmployee("Emp 1");
dept.addEmployee("Emp 2");
dept.addEmployee("Emp 3");
/*
dept.employees[2] = "Emp 4"; //we dont want this
So we mark employee as private
*/
dept.printEmpInfo();

//let acc: any = { describe: dept.describe };
//acc.describe(); //invalid since it is not a Department Type

//since the object matches Department this works well
//BEFORE WE ADDED employee
// acc = { name: "Accounting", describe: dept.describe };
// acc.describe();

//sub class

class ITDepartment extends Department {
    //if no constructor is given the base class constructor is used.
    constructor(id: number, public admins: string[]) {
        super(id, "ID");
        //props only after supercalls
    }
}

//more examples
class AccDepartment extends Department {
    private lastReport: string = "";

    constructor(id: number, private reports: string[]) {
        super(id, "Accounting");
    }

    //override of default var
    addEmployee(emp: string): void {
        if (emp != "Max") {
            this.employees.push(emp);
        }
        //employee is protected since we need to access outside
        //of parent class
    }

    addReport(report: string) {
        this.reports.push(report);
        this.lastReport = report;
    }

    get mostRecentReport() {
        return this.lastReport;
    }

    set mostRecentReport(value: string) {
        if (!value) {
            console.log("Empty String not allowed");
        }
    }

    //print report goes here
}

const ITD = new ITDepartment(1, ["DBA Jimmy"]);
ITD.addEmployee("Sam");
ITD.addEmployee("Jen");

console.log(ITD);

const ATD = new AccDepartment(2, ["report 1", "report 2"]);
ATD.addReport("report 6");
ATD.addEmployee("Max");
ATD.addEmployee("Dan");

console.log(`Last Report Added: "${ATD.mostRecentReport}"`);

ATD.mostRecentReport = "Pizza Boy Robbed";
console.log(`Last Report Added: "${ATD.mostRecentReport}"`);

console.log(ATD);
