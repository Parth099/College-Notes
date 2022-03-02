"use strict";
var Department = /** @class */ (function () {
    function Department(id, name) {
        this.employees = [];
        this.id = id;
        this.name = name;
    }
    Department.prototype.describe = function () {
        console.log("Department: " + this.name);
    };
    Department.prototype.addEmployee = function (emp) {
        this.employees.push(emp);
    };
    Department.prototype.printEmpInfo = function () {
        this.employees.forEach(function (emp, idx) {
            console.log("".concat(idx + 1, " - ").concat(emp));
        });
    };
    return Department;
}());
var dept = new Department("Medical");
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
