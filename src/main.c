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
	struct Scontrino{
		int lunghezza;
		int quantita[SCORTE];
		int quantitaTot;
		float prezzoTot;
		float prezzo[SCORTE];
		char prodotto[3][MAXSTRINGA];
	};
	
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
			scontrinoLunghezza,
			scontrinoPrezzo,
			scontrinoQuantita,
			scontrinoProdotto);

		float totale = inizializzaScontrino(
			scontrinoLunghezza,
			scontrinoProdotto,
			scontrinoQuantita,
			scontrinoQuantitaTot,
			scontrinoPrezzo,
			scontrinoPrezzoTot,
			sconto,
			pagamento,
			resto);
		
		gestionePagamento(totale);
	}

	return 0;
}
