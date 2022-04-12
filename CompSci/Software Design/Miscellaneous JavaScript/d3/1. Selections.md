# Selections
> **Important**: The return value of selections is the selection it self. This enables chaining

To be Added:
1. `sort()`


## Basics
To select an element we must use the d3 inbuilt:
```js
d3.select(cssSelector); //selects the first element
d3.selectAll(cssSelector);
```

Once something is selected we can alter its attributes
```js
const selection = d3.selectAll(cssSelector);
selection.style("fill", "red");
selection.classed("item", true); //bool to make sure you want to add
```

There are a few more:
1. `property` - for altering the attrs of HTML elements
2. `text`
3. `html`
4. `attr` - used to alter AVG elements (**IMPORTANT**)

## Functional Selections
```html
<svg width="800" height="600">
	<g transform="translate(70, 70)">
		<circle/>
		<circle cx="120" />
		<circle cx="240" />
		<circle cx="360" />
		<circle cx="480" />
	</g>
</svg>
```
We can color and change the attributes of this via a functional selection. 
```js
d3.selectAll('circle')
    .attr("fill", "orange")
    .attr("r", function(datum, index){
        return index * 10 + 10
    })

```
We can generate dynamic shapes via functional attr assignment.  
**Output**:

![[d3_selection_ex1.png]]

We can also pass-in function. 

## Event Listening
We will use the same SVG as last time. 
```js
function updateSize(e, d) {
	//this is the DOM element
    const element = d3.select(this);
    element.attr("r", 40 * Math.random() + 5);
}

d3.selectAll("circle")
    .on("click", updateSize);
```

**Output** after a few clicks

![[d3_selection_ex2.png]]

## Insert and Removal 

| Action        | Method   |
| ------------- | -------- |
| insert before | `insert(_, cssSelector)` | 
| insert after  | `append` |
| remove        | `remove` |


We cannot use the same code as before as we cannot just add a text element into a circle. We need the `<g>` group tag:
```html
<svg width="800" height="600">
	<g transform="translate(70, 70)">
		<g class="item" transform="translate(0, 0)">
                    <circle r="40" />
                </g>
                <g class="item" transform="translate(120, 0)">
                    <circle r="40" />
                </g>
                <g class="item" transform="translate(240, 0)">
                    <circle r="40" />
                </g>
	</g>
</svg>
```

```css
.svg-text{
	font-weight: 900;
	font-family: Arial, Helvetica, sans-serif;
    fill: #395be7;
}

```

```js
d3.selectAll("g.item")
    .append("text") //create text element
    .text("A")
    .classed("svg-text", true)
    .style("font-size", function (d, i) {
        return `${(i + 1) * 16}px`; 
		//i+1 to enure element 0 isnt 0 font sz
    });
```

**Output**:

![[d3_selection_ex3.png]]

> **Note**: Since we wanted the text on top of the circle we needed `append` and not `insert` which would put the text below the circle.


## Chaining Callers
### .each`()`
Relevant CSS and JS
```css
.odd{
	fill: aquamarine;
	}

```
```js
d3.selectAll("circle")
    .each(function (d, i) {
		//binds this to 
        if(i % 2)
            d3.select(this).classed("odd", true);
});
```

![[d3_selection_ex4.png]]
### .filter `()`
This code will do the same as the code above:
```js
d3.selectAll("circle")
    .filter((d, i) => i % 2 == 0)
    .classed("odd", true);
```