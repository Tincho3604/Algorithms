// Constants
const btn = document.getElementsByClassName("btn");
const res = document.getElementById("res");
const btn0 = document.getElementById("btn0").value = 0;
const btn1 = document.getElementById("btn1").value = 1;
const btnClr = document.getElementById("btnClr").value = 'C';
const btnEql = document.getElementById("btnEql").value = '=';
const btnSum = document.getElementById("btnSum").value = '+';
const btnSub = document.getElementById("btnSub").value = '-';
const btnMul = document.getElementById("btnMul").value = '*';
const btnDiv = document.getElementById("btnDiv").value = '/';

let arr = []
let cont = 0

const operations = value => {
switch (value) {
    case '1':
        arr.push(1)
        res.innerHTML += '1'
        break;
    case '0':
        arr.push(0)
        res.innerHTML += '0'
        break;
    case 'C':
        cont++
          res.innerHTML = ''
          arr = []
        break;
    case '+':
        arr.push('+')
        res.innerHTML += '+'
        break;
    case '-':
        arr.push('-')
        res.innerHTML += '-'
        break;
    case '*':
        arr.push('*')
        res.innerHTML += '*'
        break;
    case '/':
        arr.push('/')
        res.innerHTML += '/'
        break;                       
    case '=':
        let sign;
        let index = arr.map(item => Number.isInteger(item) ? '' : sign = item).indexOf(sign)
        let half1 = arr.slice(0,index)
        let half2 = arr.slice(index+1, arr.length)
       switch (sign) {
            case '+':
                res.innerHTML = pass_int_to_Binary(sum(pass_binary_to_int(half1),pass_binary_to_int(half2)))
              break;

            case '-':
                res.innerHTML = pass_int_to_Binary(sub(pass_binary_to_int(half1),pass_binary_to_int(half2)))
                break;

            case '*':
                res.innerHTML = pass_int_to_Binary(mult(pass_binary_to_int(half1),pass_binary_to_int(half2)))
                break;
            
            case '/':
                res.innerHTML = pass_int_to_Binary(div(pass_binary_to_int(half1),pass_binary_to_int(half2)))
                break;
                default: 'Wrong Option'
       }
            default: 'Wrong Option'
  }
}

//Functions 
      
const pass_binary_to_int = value => {
    return value.reverse().map((item,index) => item === 1 ? Math.pow(2, index) : 0 ).reduce((accum, currentValue) => accum + currentValue)
}

const pass_int_to_Binary = value => {
    return value.toString(2)
  }

const sum = (part1, part2) => part1 + part2
const sub = (part1, part2) => part1 - part2
const mult = (part1, part2) => part1 * part2
const div = (part1, part2) => part1 / part2
