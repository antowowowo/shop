/*
nome : Shop
versione : 3.0.0
descrizione : Simulazione di un negozio
*/

#include <stdio.h>
#include <string.h>
#include "lib.h"

int main()
{
	struct Scontrino
	{
		int lunghezza;
		int quantita[SCORTE];
		int quantitaTot;
		float prezzoTot;
		float prezzo[SCORTE];
		char prodotto[3][MAXSTRINGA];
	};

	// Dichiarazione variabili
	int uscita = 0,							 // Controlla l'uscita
		scorteQuantita[3] = {200, 200, 200}, // Quantita disponibili in magazzino
		prodottoIndex;						 // Indice del prodotto scelto

	float pagamento, // Soldi inseriti dall'utente
		resto,		 // Eventuale resto da dare all'utente
		sconto = 0;	 // Percentuale di sconto

	char risposta[MAXSTRINGA],		   // Risposta dell'utente
		scorteProdotti[3][MAXSTRINGA]; // Risposta utente se bevanda, cibo o dolce

	struct Scontrino scontrino;
	scontrino.lunghezza = 0;
	scontrino.quantitaTot = 0;

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
			strcpy(
				risposta,
				acquisisciStringa("\nCosa vuoi acquistare?\t", 1, 8));

			if (strcmp(risposta, "e") == 0)
			{
				uscita = 1;
				break;
			}

			prodottoIndex = cercaProdotto(risposta, scorteProdotti);

		} while (prodottoIndex < 0);

		strcpy(scontrino.prodotto[scontrino.lunghezza], risposta);

		// Controllo scontrinoProdotto[scontrinoLunghezza]
		if (uscita == 1)
			break;

		// Acquisizione quanti prodotti vuole comprare

		scontrino.quantita[scontrino.lunghezza] =
			acquisisciInt("\nQuanti ne vuoi comprare?[ES. 4] \t", 0, scorteQuantita[prodottoIndex]);
		printf("\nQuanti ne vuoi comprare?[ES. 4] \t");

		/* TODO:
			invertire la logica
		*/ 
		scorteQuantita[prodottoIndex] -= scontrino.quantita[scontrino.lunghezza];

		// Se non ci sono abbastanza prodotti
		if (scorteQuantita[prodottoIndex] < 0)
		{
			printf(
				"\nHai chiesto %d ,"
				" noi abbiamo solo %d ,"
				" quindi possiamo darti solo %d ",
				scontrino.quantita[scontrino.lunghezza],
				(scontrino.quantita[scontrino.lunghezza] + scorteQuantita[prodottoIndex]), 
				(scontrino.quantita[scontrino.lunghezza] + scorteQuantita[prodottoIndex])
			);

			scontrino.quantita[scontrino.lunghezza] = scontrino.quantita[scontrino.lunghezza] + scorteQuantita[prodottoIndex];
		}

		// Incremento dei prodotti tot acquistati
		scontrino.quantitaTot += scontrino.quantita[scontrino.lunghezza];

		// Acquisizione prezzo del prodotto
		do
		{
			printf("\nQuanto costa?[ES. 3.54] \t\t");

			if (
				scanf("%f", &scontrino.prezzo[scontrino.lunghezza]) != 1 || scontrino.prezzo[scontrino.lunghezza] < 0.01 || scontrino.prezzo[scontrino.lunghezza] > MAXSCONTRINO)
			{
				if (scontrino.prezzo[scontrino.lunghezza] > MAXSCONTRINO)
					printf("\nErrore: non puoi aver pagato piu di %d euro", MAXSCONTRINO);
				else
					printf("\nErrore: hai inserito un numero negativo o una lettera");

				pulisciBuffer();
				scontrino.prezzo[scontrino.lunghezza] = -1; // Per ripetere il ciclo
			}
			else
			{
				// Pulire il buffer di input
				pulisciBuffer();
				continue;
			}

		} while (scontrino.prezzo[scontrino.lunghezza] < 0.01); // Se l'utente da un valore minore di 1 centesimo

		// Assegnazione del prezzo totale
		if (scontrino.lunghezza == 0)
		{
			scontrino.prezzoTot = (float)scontrino.prezzo[scontrino.lunghezza] * scontrino.quantita[scontrino.lunghezza];
		}
		else
		{
			scontrino.prezzoTot += (float)scontrino.prezzo[scontrino.lunghezza] * scontrino.quantita[scontrino.lunghezza];
		}

		printf("\nCARRELLO ATTUALE: \t\t\t%.2f EUR\n\n", scontrino.prezzoTot);

		// Incremento variabile
		scontrino.lunghezza++;

	} while (uscita != 1);

	// Possibilita sconto dopo 5 prodotti comprati
	if (scontrino.quantitaTot >= 5)
	{
		if (scontrino.quantitaTot >= 10)
		{
			sconto = 0.10; // Sconto del 10%
		}
		else
		{
			sconto = 0.05; // Sconto del 5%
		}
		printf("\nHai ricevuto uno sconto del %.2f %% grazie al numero dei tuoi acquisti[%d]!", sconto * 100, scontrino.quantitaTot);
	}

	// Visualizzazione dati
	if (scontrino.lunghezza > 0)
	{

		// Acquisizione come vuole pagare
		/*
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
		*/
		scontrinoSorting(
			scontrino.lunghezza,
			scontrino.prezzo,
			scontrino.quantita,
			scontrino.prodotto);

		float totale = inizializzaScontrino(
			scontrino.lunghezza,
			scontrino.prodotto,
			scontrino.quantita,
			scontrino.quantitaTot,
			scontrino.prezzo,
			scontrino.prezzoTot,
			sconto,
			pagamento,
			resto);

		gestionePagamento(totale);
	}

	return 0;
}
