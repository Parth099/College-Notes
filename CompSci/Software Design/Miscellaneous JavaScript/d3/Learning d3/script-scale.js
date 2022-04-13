let LinearScale = d3.scaleLinear()
    .domain([0, 10])
    .range([0, 600]);

datum = [0, 2, 3, 5, 7.5, 9, 10];

d3.select(".chart")
    .selectAll("circle")
    .data(datum)
    .join("g")
    .classed("item", true)
    .append("circle")
    .attr("cx", function (d) {
        return LinearScale(d);
    })
    .attr("r", 4)
    .attr("cy", 20);

d3.select(".chart")
    .selectAll("g.item")
    .append("text")
    .classed("text", true)
    .text((d) => d)
    .attr("x", function (d) {
        return LinearScale(d);
    })
    .attr("y", 40);
