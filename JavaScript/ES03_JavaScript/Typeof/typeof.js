// Dichiarazione delle variabili
let val1 = 42;
let val2 = "Ciao, mondo!";
let val3 = null; 
let val4 = { 
    nome: "Mario",
     età: 30 
}; 
let val5 = function() { 
    return "Ciao!"; 
}; 

function determinaTipo(val) {
    if (val === null) {
        return " null";
    }
    switch (typeof val) {
        case 'number':
            return "È un numero";
        case 'string':
            return "È una stringa";
        case 'object':
            return "È un oggetto";
        case 'function':
            return "È una funzione";
        default:
            return "Tipo sconosciuto";
    }
}

console.log(determinaTipo(val1)); 
console.log(determinaTipo(val2)); 
console.log(determinaTipo(val3));
console.log(determinaTipo(val4));
console.log(determinaTipo(val5));
