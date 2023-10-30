let display = document.getElementById("calculator-screen");
let btnWrapper = document.getElementById('noBtnContainer');

document.querySelector(".all-clear").addEventListener('click', resetCalculator());
// allClear

const operators = ["+", "-", "*", "/"];
const numbers = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"];


var arg1;
var arg2;
var op;
var result;

//variable storing value currently displayed
var displayed;

// normal calculation with onyl 2 numbers 
function add(arg1, arg2) {
    return arg1+arg2;
}

function subtract(arg1, arg2) {
    return arg1-arg2;
}

function multiply(arg1, arg2) {
    return arg1*arg2;
}

function divide(arg1, arg2) {
    return arg1/arg2;
}

//operate 
function operate(no1, no2, op){
    if (op==="+"){
        return add(no1, no2);
    }

    else if (op==="-"){
        return subtract(no1, no2);
    }

    else if (op==="*"){
        return multiply(no1, no2);
    }

    else if (op==="/"){
        return divide(no1, no2);
    }
}

function buttonPress() {
    btnWrapper.addEventListener('click', (event)=> {
        const isButton = event.target.nodeName === 'BUTTON';
        if (!isButton) {
            return;
        }

        let val = event.target.value;

        if (operators.includes(val) || numbers.includes(val) || val === "="){
            // return event.target.value;
            updateDisplay(event.target.value);
        }

        // reset cal through AC button 
        if (val==="all-clear"){
            resetCalculator();
        }
    })
}

function updateDisplay(button){

    if(button !== "="){
        // update no1 or put operator 
        if ((arg1=="" || op === "" ) && numbers.includes(button)){
            display.value += button;
            arg1 += button;
            arg1 = parseFloat(arg1);
        }
        //entering operator and making sure it does not duplicate 
        else if (operators.includes(button) && op=="" && (arg1!=="" || (displayed !== "" && arg2==""))){
            display.value += button;
            op = button; 
        }
        //entering no2 (after operator second number starts)
        else if (op!=="" && arg1!="" && numbers.includes(button)){
            display.value += button;
            arg2 += button;
            arg2 = parseFloat(arg2)
        }
    }
    else{
        if (arg1=="" && arg2 == "" && op === ""){
            alert("kindly enter a valid equation");
        }
        else if (arg1 == "" || arg2 === ""){
            alert("Enter both numbers first !");
        }
        else if (op==="") {
            alert("enter a operator and second number");
        }

        // once the operation is done, the result becomes the new argument 1 and the argument 2 is reset so that new number is entered instead 
        result = operate(arg1, arg2, op);
        display.value = result;
        displayed = result;
        arg1 = displayed;
        arg2 = ""; 
        op = "";
    }
}

function resetCalculator(){
    arg1 = "";
    arg2 = "";
    op = "";
    result = 0;
    display.value = "";
    displayed = "";
}


    
function startCalculator(){
    buttonPress();
}

startCalculator();