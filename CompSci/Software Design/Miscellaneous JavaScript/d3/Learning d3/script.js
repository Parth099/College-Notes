//[40, 10, 20, 60, 30];
let myData = [
    { name: "Abe", grade: 40 },
    { name: "Bob", grade: 10 },
    { name: "Carl", grade: 20 },
    { name: "Dimmy", grade: 60 },
    { name: "Elaine", grade: 30 },
];
let maxInData = myData.reduce((prev, currObj) => {
    return Math.max(prev, currObj.grade);
}, myData[0].grade);

d3.select(".chart") //data container
    .selectAll("circle") //we want to bind to type:circle
    .data(myData) //with this data
    .join("circle") //does the join
    .attr("cx", function (d, i) {
        return i * 100;
    })
    .attr("cy", 100)
    .attr("r", (d) => d.grade) //datum usage
    .style("fill", "#395be7")
    .filter((d) => d.grade === maxInData) //no typecase
    .style("fill", "red");

//https://www.d3indepth.com/datajoins/
