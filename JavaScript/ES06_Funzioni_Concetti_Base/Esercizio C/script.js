function triangoloTartaglia(numRighe) {
    if (numRighe < 1) {
        return "Errore: Il numero di righe deve essere almeno 1";
    }
    
    // inizio col generare una matrice per il triangolo
    const triangolo = [];
    
    for (let riga = 0; riga < numRighe; riga++) {
        triangolo[riga] = [];
        
        for (let colonna = 0; colonna <= riga; colonna++) {
            if (colonna === 0 || colonna === riga) {
                // I bordi del triangolo sono sempre 1
                triangolo[riga][colonna] = 1;
            } else {
                // Ogni altro numero è la somma dei due numeri sopra
                triangolo[riga][colonna] = triangolo[riga-1][colonna-1] + triangolo[riga-1][colonna];
            }
        }
    }
    
    return formattaTriangolo(triangolo, numRighe);
}

function formattaTriangolo(triangolo, numRighe) {
    let output = "";
    
    // Trova la larghezza massima dei numeri nell'ultima riga
    const ultimaRiga = triangolo[numRighe - 1];
    let maxLarghezza = 0;
    
    for (let num of ultimaRiga) {
        if (num.toString().length > maxLarghezza) {
            maxLarghezza = num.toString().length;
        }
    }
    
    // almeno 3 caratteri di spazio per numero
    const larghezzaNumero = Math.max(3, maxLarghezza + 1);
    
    // lunghezza totale dell'ultima riga
    const larghezzaTotale = ultimaRiga.length * larghezzaNumero;
    
    // formatto ogni riga
    for (let i = 0; i < numRighe; i++) {
        const riga = triangolo[i];
        
        // lunghezza della riga corrente
        const larghezzaRigaCorrente = riga.length * larghezzaNumero;
        
        // padding per centrare la riga
        const padding = Math.floor((larghezzaTotale - larghezzaRigaCorrente) / 2);
        
        // aggiungo gli spazi di padding
        let rigaFormattata = " ".repeat(padding);
        
        // aggiungo i numeri della riga
        for (let j = 0; j < riga.length; j++) {
            const numeroStr = riga[j].toString();
            // Centra il numero nel suo spazio allocato
            const spazioPrima = Math.floor((larghezzaNumero - numeroStr.length) / 2);
            const spazioDopo = larghezzaNumero - numeroStr.length - spazioPrima;
            
            rigaFormattata += " ".repeat(spazioPrima) + numeroStr + " ".repeat(spazioDopo);
        }
        
        output += rigaFormattata.trimEnd() + "\n";
    }
    
    return output;
}

function generaTriangolo() {
    const righeInput = document.getElementById('righe');
    const triangoloDiv = document.getElementById('triangolo');
    
    const numRighe = parseInt(righeInput.value);
    
    if (isNaN(numRighe) || numRighe < 1) {
        triangoloDiv.textContent = "Errore: Inserisci un numero valido maggiore di 0";
        return;
    }
    
    if (numRighe > 20) {
        triangoloDiv.textContent = "Errore: Massimo 20 righe per una visualizzazione ottimale";
        return;
    }
    
    const risultato = triangoloTartaglia(numRighe);
    triangoloDiv.textContent = risultato;
    
    console.log(`\nTriangolo di Tartaglia con ${numRighe} righe:`);
    console.log(risultato);
}

// funzioni heper
function setRighe(num) {
    document.getElementById('righe').value = num;
    generaTriangolo();
}