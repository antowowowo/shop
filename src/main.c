/*
nome : Shop
versione : 3.0.0
descrizione : Simulazione di un negozio
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lib.h"

/*
- Pulisce una variabile char nel caso si metta un numero -
*/
int pulisciBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
	{
	}
}

/*
- Confronta la risposta con l'utente con il tipo di scorta -
- risposta sta per la risposta dell'utente -
- scorta sono definite all'inizio del codice -
*/
int cercaProdotto(char risposta[], char scorta[][MAXSTRINGA])
{
	printf("\nRicerca prodotto . . .");
	int segnaposto = -1;
	for (int i = 0; i < 3; i++)
	{
		if (strcmp(risposta, scorta[i]) == 0)
		{
			printf("\nTrovato.\n");
			segnaposto = i;
		}
	}
	if (segnaposto == -1)
		printf("\nNon trovato.\n");

	return segnaposto;
}

/*
- Ordina gli array in base a scontrinoPrezzo in ordine decrescente -
- size sta per la dimensione -
- scontrinoPrezzo[] sta per il prezzo -
- scontrinoQuantita[] sta per la quantita acquistata del prodotto -
- scontrinoProdotto[][MAXSTRINGA] sta per il prodotto acquistato -
*/
void scontrinoSorting(int size, float scontrinoPrezzo[], int scontrinoQuantita[], char scontrinoProdotto[][MAXSTRINGA])
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			// Se scontrinoPrezzo[j + 1] e' maggiore di scontrinoPrezzo[j] avviene il bubble sorting
			if (scontrinoPrezzo[j] < scontrinoPrezzo[j + 1])
			{
				// Scambio di valori della variabile scontrinoPrezzo
				float temp1 = scontrinoPrezzo[j];
				scontrinoPrezzo[j] = scontrinoPrezzo[j + 1];
				scontrinoPrezzo[j + 1] = temp1;

				// Scambio di valori della variabile scontrinoQuantita
				int temp2 = scontrinoQuantita[j];
				scontrinoQuantita[j] = scontrinoQuantita[j + 1];
				scontrinoQuantita[j + 1] = temp2;

				// Scambio di valori della variabile scontrinoProdotto
				char temp3[MAXSTRINGA];
				strcpy(temp3, scontrinoProdotto[j]);
				strcpy(scontrinoProdotto[j], scontrinoProdotto[j + 1]);
				strcpy(scontrinoProdotto[j + 1], temp3);
			}
		}
	}
}

/*
- Stampa lo scontrino -
- size sta per la dimensione -
- prodotto sono il tipo di scorta scelto dall'utente -
- quantita e' il numero di scorte prese dall'utente -
- quantitatot e' la somma di tutte le quantita -
- prezzo e' il valore di un prodotto -
- prezzotot e' la somma di tutti i prezzi -
- sconto e' la percentuale di sconto -
- pagamento e' il numero con cui l'utente paga -
- resto e' il possibile di soldi in piu che torna all'utente -
*/
void stampaScontrino(
	int size,
	char prodotto[][MAXSTRINGA],
	int quantita[],
	int quantitaTot,
	float prezzo[],
	float pagamento,
	float resto,
	float prezzoProdottiScontrino[],
	char fraseSconto[],
	float mediaScontrino,
	char fraseResto[],
	float subtotale,
	float iva,
	float totale)
{
	
	printf("\n========================================================");
	printf("\n                       SHOP                             ");
	printf("\n========================================================");
	for (int i = 0; i < size; i++)
	{
		printf(
			"\n%s x%d  %.2f = %.2f", prodotto[i], quantita[i], prezzo[i], prezzoProdottiScontrino[i]);
	}
	printf("\n--------------------------------------------------------");
	printf("\nProdotti comprati: \t %d", quantitaTot);
	
	printf("\nMedia prezzo unitario: \t %.2f EUR", mediaScontrino); // Calcolo della media prezzo unitario
	printf("\nSubtotale: \t %.2f", subtotale);
	printf("\nIVA: %.2f", iva);
	printf("\n%s", fraseSconto);
	printf("\nTotale: %.2f", totale);
	printf("\nPagamento: \t\t %.2f EUR", pagamento);

	printf("\n%s", fraseResto);
	printf("\n========================================================");
}


void inizializzaScontrino(
	int size,
	char prodotto[][MAXSTRINGA],
	int quantita[],
	int quantitaTot,
	float prezzo[],
	float prezzoTot,
	float sconto,
	float pagamento,
	float resto)
{
	float prezzoProdottiScontrino[100];
	for (int i = 0; i < size; i++)
	{
		prezzoProdottiScontrino[i] = prezzo[i] * quantita[i];
	}
	float valoreSconto = prezzoTot * sconto;
    char fraseSconto[100];

    // Assegnazione condizionale con snprintf
    if (valoreSconto == 0) {
        strcpy(fraseSconto, "\0"); // Stringa vuota
    } else {
        snprintf(fraseSconto, sizeof(fraseSconto), "\nSconto:\t\t\t -%.2f", valoreSconto);
    }

	float subtotale = prezzoTot, 
		  totale = prezzoTot,
		  iva = calcolaIva(prezzoTot);

	totale = totale + iva - valoreSconto;

	float mediaScontrino = calcolaMedia(totale, quantitaTot);

	char fraseResto[100];
	if ( resto == 0 ) {
		strcpy(fraseResto, "\0");
	} else {
		snprintf(fraseResto, sizeof(fraseResto), "\nResto: \t\t\t %.2f EUR", resto);
	}
	stampaScontrino( 
		 size,
		 prodotto,
		 quantita,
		 quantitaTot,
		 prezzo,
		 pagamento,
		 resto,
		 prezzoProdottiScontrino,
		 fraseSconto,
		 mediaScontrino,
		 fraseResto,
		 subtotale,
		 iva,
		 totale
	);
}

/*
- Sostituisce lo \n con il terminatore \0 -
*/
char *pulisciStringa(char stringa[])
{
	int posizione = strcspn(stringa, "\n"); // Si segna la posizione dello \n
	stringa[posizione] = '\0';				// \n viene sostituito con \0

	return stringa;
}

/*
- Inizializza i prodotti delle scorte -
*/
void inizializzaScorte(char scorteProdotti[][MAXSTRINGA])
{
	strcpy(scorteProdotti[0], "bevanda");
	strcpy(scorteProdotti[1], "cibo");
	strcpy(scorteProdotti[2], "dolce");
}

int main()
{
	printf("%d", 10 * 0);
	// Dichiarazione variabili
	int scontrinoLunghezza = 0,				 // Indica il numero di prodotti presenti nello scontrino
		uscita = 0,							 // Controlla l'uscita
		scontrinoQuantita[SCORTE],			 // Salva le quantita di ogni prodotto comprato
		scontrinoQuantitaTot = 0,			 // Quantita totale di ogni prodotto comprato
		scorteQuantita[3] = {200, 200, 200}, // Quantita disponibili in magazzino
		prodottoIndex;						 // Indice del prodotto scelto

	float scontrinoPrezzoTot,	 // Prezzo totale dello scontrino
		pagamento,				 // Soldi inseriti dall'utente
		resto,					 // Eventuale resto da dare all'utente
		scontrinoPrezzo[SCORTE], // Prezzo di ogni prodotto acquistato
		sconto = 0;				 // Percentuale di sconto

	char scontrinoProdotto[SCORTE][MAXSTRINGA], // Matrice contenente i nomi dei prodotti comprati
		risposta[MAXSTRINGA],					// Risposta dell'utente
		scorteProdotti[3][MAXSTRINGA];			// Risposta utente se bevanda, cibo o dolce

	inizializzaScorte(scorteProdotti);
	// Acquisizione dati e calcoli
	do
	{

		prodottoIndex = -1;
		do
		{
			// Stampa scelte possibili
			for (int i = 0; i < 3; i++)
			{
				if (scorteQuantita[i] > 0)
					printf("\t [ %s \t]\n", scorteProdotti[i]);
			}
			printf("\t [ e = ESCI \t]\n");

			// Acquisizione cosa vuole acquistare
			printf("\nCosa vuoi acquistare?\t");
			fgets(risposta, MAXSTRINGA, stdin);
			pulisciStringa(risposta);
			if (strcmp(risposta, "e") == 0)
			{
				uscita = 1;
				break;
			}
			else
			{
				strcpy(scontrinoProdotto[scontrinoLunghezza], risposta);
			}

			prodottoIndex = cercaProdotto(scontrinoProdotto[scontrinoLunghezza], scorteProdotti);

		} while (prodottoIndex < 0);

		// Controllo scontrinoProdotto[scontrinoLunghezza]
		if (uscita == 1)
			break;

		// Acquisizione quanti prodotti vuole comprare
		do
		{
			printf("\nQuanti ne vuoi comprare?[ES. 4] \t");
			if (
				scanf("%d", &scontrinoQuantita[scontrinoLunghezza]) != 1 || scontrinoQuantita[scontrinoLunghezza] < 1)
			{
				printf("\nErrore: valore non valido");

				pulisciBuffer();
				/*
				int c;
				while ((c = getchar()) != '\n' && c != EOF)
				{
				}
				*/
				scontrinoQuantita[scontrinoLunghezza] = -1; // Per ripetere il ciclo
			}
			else
			{
				scorteQuantita[prodottoIndex] -= scontrinoQuantita[scontrinoLunghezza];

				// Se non ci sono abbastanza prodotti
				if (scorteQuantita[prodottoIndex] < 0)
				{
					printf(
						"\nHai chiesto %d ,"
						" noi abbiamo solo %d ,"
						" quindi possiamo darti solo %d ",
						scontrinoQuantita[scontrinoLunghezza], (scontrinoQuantita[scontrinoLunghezza] + scorteQuantita[prodottoIndex]), (scontrinoQuantita[scontrinoLunghezza] + scorteQuantita[prodottoIndex]));
					scontrinoQuantita[scontrinoLunghezza] = scontrinoQuantita[scontrinoLunghezza] + scorteQuantita[prodottoIndex];
				}
			}
		} while (scontrinoQuantita[scontrinoLunghezza] < 1);

		// Incremento dei prodotti tot acquistati
		scontrinoQuantitaTot += scontrinoQuantita[scontrinoLunghezza];

		// Acquisizione prezzo del prodotto
		do
		{
			printf("\nQuanto costa?[ES. 3.54] \t\t");

			if (
				scanf("%f", &scontrinoPrezzo[scontrinoLunghezza]) != 1 || scontrinoPrezzo[scontrinoLunghezza] < 0.01 || scontrinoPrezzo[scontrinoLunghezza] > MAXSCONTRINO)
			{
				if (scontrinoPrezzo[scontrinoLunghezza] > MAXSCONTRINO)
					printf("\nErrore: non puoi aver pagato piu di %d euro", MAXSCONTRINO);
				else
					printf("\nErrore: hai inserito un numero negativo o una lettera");

				pulisciBuffer();
				scontrinoPrezzo[scontrinoLunghezza] = -1; // Per ripetere il ciclo
			}
			else
			{
				// Pulire il buffer di input
				pulisciBuffer();
				continue;
			}

		} while (scontrinoPrezzo[scontrinoLunghezza] < 0.01); // Se l'utente da un valore minore di 1 centesimo

		// Assegnazione del prezzo totale
		if (scontrinoLunghezza == 0)
		{
			scontrinoPrezzoTot = scontrinoPrezzo[scontrinoLunghezza] * scontrinoQuantita[scontrinoLunghezza];
		}
		else
		{
			scontrinoPrezzoTot += scontrinoPrezzo[scontrinoLunghezza] * scontrinoQuantita[scontrinoLunghezza];
		}

		printf("\nCARRELLO ATTUALE: \t\t\t%.2f EUR\n\n", scontrinoPrezzoTot);

		// Incremento variabile
		scontrinoLunghezza++;

	} while (uscita != 1);

	// Possibilita sconto dopo 5 prodotti comprati
	if (scontrinoQuantitaTot >= 5)
	{
		if (scontrinoQuantitaTot >= 10)
		{
			sconto = 0.10; // Sconto del 10%
		}
		else
		{
			sconto = 0.05; // Sconto del 5%
		}
		printf("\nHai ricevuto uno sconto del %.2f %% grazie al numero dei tuoi acquisti[%d]!", sconto * 100, scontrinoQuantitaTot);
	}

	// Visualizzazione dati
	if (scontrinoLunghezza > 0)
	{

		// Acquisizione come vuole pagare
		do
		{
			printf("\nTotale scontrino: %.2f ", scontrinoPrezzoTot);
			if (sconto > 0)
			{
				printf("\nSconto: -%.2f", sconto * scontrinoPrezzoTot);
				printf("\nTotale scontato: %.2f ", scontrinoPrezzoTot * (1 - sconto));
			}
			printf("\nCome vuoi pagare il tutto?[ES. 3.54]\t");
			if (scanf("%f", &pagamento) != 1 || pagamento < (scontrinoPrezzoTot * (1 - sconto)))
			{
				if (pagamento < (scontrinoPrezzoTot * (1 - sconto)))
					printf("\nErrore: valore non valido");

				// Pulire il buffer di input
				pulisciBuffer();
				pagamento = -1; // Per ripetere il ciclo
			}
			else
			{
				if (pagamento > (scontrinoPrezzoTot * (1 - sconto)))
				{
					resto = pagamento - (scontrinoPrezzoTot * (1 - sconto));
				}
			}
		} while (pagamento < (scontrinoPrezzoTot * (1 - sconto)));

		scontrinoSorting(
			scontrinoLunghezza,
			scontrinoPrezzo,
			scontrinoQuantita,
			scontrinoProdotto);

		inizializzaScontrino(
			scontrinoLunghezza,
			scontrinoProdotto,
			scontrinoQuantita,
			scontrinoQuantitaTot,
			scontrinoPrezzo,
			scontrinoPrezzoTot,
			sconto,
			pagamento,
			resto);
	}

	return 0;
}
