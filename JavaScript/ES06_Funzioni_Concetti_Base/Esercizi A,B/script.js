
function calcolatrice() {
    const num1Input = document.getElementById('num1');
    const num2Input = document.getElementById('num2');
    const operazioneSelect = document.getElementById('operazione');
    const risultatoDiv = document.getElementById('risultato-calc');
    
    // input dei valori
    const num1 = parseFloat(num1Input.value);
    const num2 = parseFloat(num2Input.value);
    const operazione = operazioneSelect.value;
    
    // check dell'input
    if (isNaN(num1) || isNaN(num2)) {
        mostraRisultato(risultatoDiv, "Errore: Inserisci numeri validi!", false);
        return;
    }
    
    if (!operazione) {
        mostraRisultato(risultatoDiv, "Errore: Seleziona un'operazione!", false);
        return;
    }
    
    if (operazione === "/" && num2 === 0) {
        mostraRisultato(risultatoDiv, "Errore: Divisione per zero non consentita!", false);
        return;
    }
    
    let risultato;
    
    // calcolo il risultato
    try {
        switch (operazione) {
            case "+":
                risultato = num1 + num2;
                break;
            case "-":
                risultato = num1 - num2;
                break;
            case "*":
                risultato = num1 * num2;
                break;
            case "/":
                risultato = num1 / num2;
                break;
            case "**":
                risultato = Math.pow(num1, num2);
                break;
            default:
                throw new Error("Operazione non valida");
        }
        
        mostraRisultato(risultatoDiv, `Risultato: ${num1} ${operazione} ${num2} = ${risultato}`, true);
        
    } catch (error) {
        mostraRisultato(risultatoDiv, "Errore: Si è verificato un errore nel calcolo!", false);
    }
}

function inverti_cifre(numero) {
    // prima di tutto, convertire il numero in una stringa.
    const isNegativo = numero < 0;
    let numeroStr = Math.abs(numero).toString();

    let numeroInvertito = numeroStr.split('').reverse().join('');
    



    let risultato = parseInt(numeroInvertito);
    
    return isNegativo ? -risultato : risultato;
}

function testInvertiCifre() {
    const numeroInput = document.getElementById('numero');
    const risultatoDiv = document.getElementById('risultato-inverti');
    
    const numero = parseInt(numeroInput.value);
    
    if (isNaN(numero)) {
        mostraRisultato(risultatoDiv, "Errore: Inserisci un numero intero valido!", false);
        return;
    }
    
    const numeroInvertito = inverti_cifre(numero);
    mostraRisultato(risultatoDiv, `Numero originale: ${numero}<br>Numero invertito: ${numeroInvertito}`, true);
}

function mostraRisultato(elemento, messaggio, successo) {
    elemento.innerHTML = messaggio;
    elemento.className = successo ? 'result success' : 'result error';
    elemento.classList.remove('hidden');
}

