d3.selectAll("circle")
    .attr("fill", "orange")
    .attr("r", function (datum, index) {
        return index * 10 + 10;
    });

//ignore e, d for now
function updateSize(e, d) {
    const element = d3.select(this);
    element.attr("r", 40 * Math.random() + 5);
}

d3.selectAll("circle").on("click", updateSize);

d3.selectAll("g.item")
    .append("text")
    .text("A")
    .classed("svg-text", true)
    .style("font-size", function (d, i) {
        return `${(i + 1) * 16}px`;
    });

d3.selectAll("circle")
    .filter((d, i) => i % 2 == 0)
    .classed("odd", true);
