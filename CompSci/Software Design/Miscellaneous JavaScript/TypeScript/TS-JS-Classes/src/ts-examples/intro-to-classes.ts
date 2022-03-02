export {};

class Department {
    private id: number;
    private name: string; //public not required
    private employees: string[] = [];

    constructor(id: number, name: string) {
        this.id = id;
        this.name = name;
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
