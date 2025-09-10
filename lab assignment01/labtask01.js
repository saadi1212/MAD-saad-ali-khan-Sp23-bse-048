
function add(a, b) {
    if (a === undefined || b === undefined) {
        console.log("Error: Missing arguments for addition.");
        return;
    }
    return a + b;
}


function subtract(a = 0, b = 0) {
    return a - b;
}


function multiply(...numbers) {
    return numbers.reduce((product, num) => product * num, 1);
}


function divide() {
    if (arguments.length === 0) {
        console.log("Error: No arguments passed for division.");
        return;
    }

    let result = arguments[0];
    for (let i = 1; i < arguments.length; i++) {
        if (arguments[i] === 0) {
            console.log("Error: Division by zero is not allowed.");
            return;
        }
        result /= arguments[i];
    }
    return result;
}


console.log("Add(5, 3) =", add(5, 3));          
console.log("Add(5) =", add(5));                
console.log("Subtract(10, 4) =", subtract(10, 4)); 
console.log("Subtract(7) =", subtract(7));      
console.log("Multiply(2, 3, 4) =", multiply(2, 3, 4)); 
console.log("Divide(100, 2, 5) =", divide(100, 2, 5)); 
console.log("Divide(10, 0) =", divide(10, 0)); 
