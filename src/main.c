/* 
nome : Shop Da Antonio
versione : 2.0.0
descrizione : Simulazione di un negozio
FUNZIONALITA ATTUALI : 
	-Scelta quanti prodotti comprare
	-Scelta di comprare una bevanda, un cibo o un dolce
	-Counter di bevanda, cibo e dolce
	-Tot costo e Media costo finale
	-Media costo di bevanda, cibo e dolce
	-Costo totale di bevanda, cibo e dolce
	-Possibilita di ricevere resto se da piu del Tot costo
	-Array scontrino 
	-Implementazione grafica
	-Stampa scontrino 
FUNZIONALITA FUTURE : 
	-Ricevere sconto dopo X prodotti 
	-Array scorte e quantita 
CHANGELOG :
	V 1.2.0 
		Aggiunte :
		-Media costo di bevanda, cibo e dolce
		-Costo totale di bevanda, cibo e dolce
	V 1.2.1
		Modifiche : 
		-Miglioramento codice
		-Bug fix: il programma da errore se inserisce una lettera dove deve inserire un num
	V 1.3.0
		Aggiunte :
		-Aggiunta scorte max e scontrino max
		Modifiche :
		-Bug fix: il programma da errore se inserisce una lettera dove deve inserire un num
		Miglioramento :
		-Messaggi di errore piu descrittivi  
	V 1.4.0
		Aggiunte :
		-Pagamento e resto
	V 1.4.1
		Miglioramento : 
		-Implementazione suggerimenti all'utente
	V 1.5.0
		Aggiunte :
		-Array scontrino
		Modifiche : 
		-Rifactoring variabili
	V 1.5.1
		Modifiche :
		-Bug fix: il programma da errore se inserisce una lettera dove deve inserire un num
			-domanda di pagamento
			-domanda di pezzi comprati
			-domanda di prezzo
		Rimozioni:
		-Rimosso parte del codice riguardo:
			-mediaBevande, scontrinoBevande, totBevande
			-mediaCibo, scontrinoCibo, totCibo
			-mediaDolce, scontrinoDolce, totDolce
	V 2.0.0
		Implementanzioni:
		-Grafica
		-Stampa scontrino
		Rimozioni:
		-Variabili riguardanti le bevande, cibo e dolci

*/

#include <stdio.h>
#include <ctype.h>

/* Spesa.c: gestione carrello della spesa */

int main() {
	// Dichiarazione variabili
	int prodotti; // Numero di prodotti che vuole comprare l'utente
	int maxScontrino = 2000, scorte = 500, scontrinoLunghezza = 0, uscita = 0,
		scontrinoQuantita[scorte], scontrinoTot;
	float prezzo, totScontrino, pagamento, resto,  
		scontrinoMedia, scontrinoPrezzo[scorte];
	char risposta, scontrinoProdotto[scorte]; // Risposta utente se bevanda o cibo
	
	// Acquisizione dati e calcoli	
	do { 
		
		do {
			printf
			( 	"\n\n"
				"\t[ b = bevanda \t]\n"
				"\t[ c = cibo \t]\n"
				"\t[ d = dolce \t]\n"
				"\t[ e = ESCI \t]\n"
			);
			printf("\nVuoi una bevanda, un cibo o un dolce?\t");
			scanf(" %c",&risposta); // Risposta utente se bevanda, cibo o dolce
			risposta = ( tolower(risposta) );
			scontrinoProdotto[ scontrinoLunghezza ] = risposta; 
			if ( risposta != 'b' && risposta != 'c' && risposta != 'd' && risposta != 'e') printf("\nErrore\n"); 
		} while ( risposta != 'b' && risposta != 'c' && risposta != 'd' && risposta != 'e');
		
		if ( risposta == 'e' ) {
			uscita = 1;
			break;
		}
		
		do {
			printf("\nQuanti ne vuoi comprare?[ES. 4] \t");
			if ( 
				scanf("%d", &scontrinoQuantita[ scontrinoLunghezza ]) != 1 
				|| scontrinoQuantita[ scontrinoLunghezza ] < 0  
			) {
	        	printf("\nErrore: valore non valido");
				if ( scontrinoQuantita[ scontrinoLunghezza ] < 0 ) printf("\nErrore: numero minore di 0");
				
	        	// Pulire il buffer di input
	        	int c;
	        	while ((c = getchar()) != '\n' && c != EOF) { }
	        	scontrinoQuantita[ scontrinoLunghezza ] = -1; // Per ripetere il ciclo
	    	} else {
	        	continue;
	    	}
		} while ( scontrinoQuantita[ scontrinoLunghezza ] < 0);
		
		scontrinoTot += scontrinoQuantita[ scontrinoLunghezza ];
		
		do {          
			printf("\nQuanto costa?[ES. 3.54] \t\t");

			if ( 
				scanf("%f", &scontrinoPrezzo[ scontrinoLunghezza ]) != 1 
				|| scontrinoPrezzo[ scontrinoLunghezza ] < 0 
				|| scontrinoPrezzo[ scontrinoLunghezza ] > maxScontrino 
			) {
	        	if ( scontrinoPrezzo[ scontrinoLunghezza ] > maxScontrino ) printf("\nErrore: non puoi aver pagato piu di %d euro", maxScontrino );
				else printf("\nErrore: hai inserito un numero negativo o una lettera");
				
	        	// Pulire il buffer di input
	        	int c;
	        	while ((c = getchar()) != '\n' && c != EOF) { }
	        	scontrinoPrezzo[ scontrinoLunghezza ] = -1; // Per ripetere il ciclo
	    	} else {
	        	continue;
	    	}
			
		} while ( scontrinoPrezzo[ scontrinoLunghezza ] < 0 ); // Se l'utente da un valore minore di 0
		
		if ( scontrinoLunghezza == 0 ) {
			totScontrino = scontrinoPrezzo[ scontrinoLunghezza ] * scontrinoQuantita[ scontrinoLunghezza ];
		} else {
			totScontrino += ( scontrinoPrezzo[ scontrinoLunghezza ] * scontrinoQuantita[ scontrinoLunghezza ] ); 
		}
		
		printf("\nCARRELLO ATTUALE: \t\t\t%.2f EUR", totScontrino);
		
		scontrinoLunghezza++;
		
	} while ( uscita != 1 );
		
	scontrinoMedia = totScontrino / scontrinoTot; // Media del prezzo totale
	
	// Visualizzazione dati

	if ( scontrinoLunghezza > 0 ) {
		
		do {
			printf("\nTotale scontrino: %.2f ", totScontrino );
			printf("\nCome vuoi pagare il tutto?[ES. 3.54]\t");
			if ( scanf("%f", &pagamento) != 1 || pagamento < totScontrino) {
	        	if ( pagamento < totScontrino ) printf("\nErrore: valore non valido");
				
	        	// Pulire il buffer di input
	        	int c;
	        	while ((c = getchar()) != '\n' && c != EOF) { }
	        	pagamento = -1; // Per ripetere il ciclo
	    	} else {
	        	continue;
	    	}
			if ( pagamento > totScontrino ) resto = pagamento - totScontrino;
		} while ( pagamento < totScontrino);
		
		printf("\n========================================================");
		printf("\n                       SHOP                             ");
		printf("\n========================================================");
		printf(
		"\nProdotti comprati: \t %d"
		"\nPrezzo totale: \t\t %.2f EUR"
		"\nMedia prezzo totale: \t %.2f EUR"
		"\nPagamento: \t\t %.2f EUR"
		,scontrinoTot, totScontrino, scontrinoMedia, pagamento
		);
		
		if ( resto > 0 ) printf("\nResto: \t\t\t %.2f EUR", resto);
		printf("\n========================================================");
		
	}
	
	return 0;
}

/* 
entro dentro
scelgo i prodotti in base ai miei soldi
pago la somma totale al cassiere
ricevo lo scontrino
*/