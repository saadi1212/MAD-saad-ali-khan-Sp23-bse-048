// 1. ADD function (check for undefined arguments)
function add(a, b) {
    if (a === undefined || b === undefined) {
        console.log("Error: Missing arguments for addition.");
        return;
    }
    return a + b;
}

// 2. SUBTRACT function (using ES6 default parameters)
function subtract(a = 0, b = 0) {
    return a - b;
}

// 3. MULTIPLY function (using ES6 rest parameters)
function multiply(...numbers) {
    return numbers.reduce((product, num) => product * num, 1);
}

// 4. DIVIDE function (using the Arguments object)
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

// ---------- Test the functions ----------
console.log("Add(5, 3) =", add(5, 3));          // 8
console.log("Add(5) =", add(5));                // Error
console.log("Subtract(10, 4) =", subtract(10, 4)); // 6
console.log("Subtract(7) =", subtract(7));      // 7 - 0 = 7
console.log("Multiply(2, 3, 4) =", multiply(2, 3, 4)); // 24
console.log("Divide(100, 2, 5) =", divide(100, 2, 5)); // 10
console.log("Divide(10, 0) =", divide(10, 0));  // Error