let m = prompt("Inserisci il coefficiente m");
let c = prompt("Inserisci il coefficiente c");

let x1 = -1;
let y1 = m * x1 + c;

let x2 = 10;
let y2 = m * x2 + c;

console.log("Le coordinate del punto con x" + x1 + "sono: " + x1 + ", " + y1);
console.log("Le coordinate del punto con x" + x2 + "sono: " + x2 + ", " + y2);


let intersezioneY = c;
console.log("Il punto di intersezione con  y è"  + intersezioneY);

let intersezioneX = -(c / m);
console.log("Il punto di intersezione con x è" + intersezioneX);
