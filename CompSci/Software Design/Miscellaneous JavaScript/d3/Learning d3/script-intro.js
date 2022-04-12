/*
Select the div
Select all of its CHILD p tags
bind data from the array
enter() returns all the missing binds
If we have no p and we have the full [1,2,3] it will return all the elements we need to bind still
*/

const div = d3.select("div").selectAll("p").data([1, 2, 3]).enter();

/*
append will take whats missing from enter() and create+append it
*/
div.append("p").text((data) => data); //data is a single entry per each 'p'


console.log("DONE");
