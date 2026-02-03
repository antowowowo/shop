/*
nome : Shop Da Antonio
versione : 2.1.0
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
	-Array scorte e quantita IN CORSO
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
	V 2.1.0
		Aggiunte:
		-Array scorte e quantita

*/

#include <stdio.h>
#include <ctype.h>

/* Spesa.c: gestione carrello della spesa */

int main()
{
	// Dichiarazione variabili
	int maxScontrino = 2000,
		scorte = 500,
		scontrinoLunghezza = 0,
		uscita = 0,
		scontrinoQuantita[scorte],
		scontrinoQuantitaTot,
		scorteQuantita[3] = {200, 200, 200},
		prodottoIndex;

	float /*prezzo,*/
		scontrinoPrezzoTot,
		pagamento,
		resto,
		scontrinoMedia,
		scontrinoPrezzo[scorte];

	char /*risposta,*/
		scontrinoProdotto[scorte],
		scorteProdotti[3] = {'b', 'c', 'd'}; // Risposta utente se bevanda o cibo

	// Acquisizione dati e calcoli
	do
	{

		for (int i = 0; i < scontrinoLunghezza; i++)
		{
			printf("\n---%c", scontrinoProdotto[i]);
			printf("---%d", scontrinoQuantita[i]);
			printf("---%.2f", scontrinoPrezzo[i]);
		}

		do
		{
			// Stampa scelte possibili
			for (int i = 0; i < 3; i++)
			{
				if (scorteQuantita[i] > 0)
					printf("\t [ %c \t\t] \n", scorteProdotti[i]);
			}
			printf("\t [ e = ESCI \t]\n");

			// Acquisizione cosa vuole acquistare
			printf("\nCosa vuoi acquistare?\t");
			scanf(" %c", &scontrinoProdotto[scontrinoLunghezza]); // Risposta utente se bevanda, cibo o dolce
			scontrinoProdotto[scontrinoLunghezza] = (tolower(scontrinoProdotto[scontrinoLunghezza]));
			if (scontrinoProdotto[scontrinoLunghezza] != 'b' && scontrinoProdotto[scontrinoLunghezza] != 'c' && scontrinoProdotto[scontrinoLunghezza] != 'd' && scontrinoProdotto[scontrinoLunghezza] != 'e')
				printf("\nErrore\n");
		} while (scontrinoProdotto[scontrinoLunghezza] != 'b' && scontrinoProdotto[scontrinoLunghezza] != 'c' && scontrinoProdotto[scontrinoLunghezza] != 'd' && scontrinoProdotto[scontrinoLunghezza] != 'e');

		// Controllo scontrinoProdotto[scontrinoLunghezza]
		if (scontrinoProdotto[scontrinoLunghezza] == 'e')
		{
			uscita = 1;
			break;
		}

		// Assegnazione variabile prodottoIndex
		switch (scontrinoProdotto[scontrinoLunghezza])
		{
		case 'b':
			prodottoIndex = 0;
			break;

		case 'c':
			prodottoIndex = 1;
			break;

		case 'd':
			prodottoIndex = 2;
			break;
		};

		// Acquisizione quanti prodotti vuole comprare
		do
		{
			printf("\nQuanti ne vuoi comprare?[ES. 4] \t");
			if (
				scanf("%d", &scontrinoQuantita[scontrinoLunghezza]) != 1 || scontrinoQuantita[scontrinoLunghezza] < 0)
			{
				printf("\nErrore: valore non valido");
				if (scontrinoQuantita[scontrinoLunghezza] < 0)
					printf("\nErrore: numero minore di 0");

				// Pulire il buffer di input
				int c;
				while ((c = getchar()) != '\n' && c != EOF)
				{
				}
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
		} while (scontrinoQuantita[scontrinoLunghezza] < 0);

		// Incremento dei prodotti tot acquistati
		scontrinoQuantitaTot += scontrinoQuantita[scontrinoLunghezza];

		// Acquisizione prezzo del prodotto
		do
		{
			printf("\nQuanto costa?[ES. 3.54] \t\t");

			if (
				scanf("%f", &scontrinoPrezzo[scontrinoLunghezza]) != 1 || scontrinoPrezzo[scontrinoLunghezza] < 0 || scontrinoPrezzo[scontrinoLunghezza] > maxScontrino)
			{
				if (scontrinoPrezzo[scontrinoLunghezza] > maxScontrino)
					printf("\nErrore: non puoi aver pagato piu di %d euro", maxScontrino);
				else
					printf("\nErrore: hai inserito un numero negativo o una lettera");

				// Pulire il buffer di input
				int c;
				while ((c = getchar()) != '\n' && c != EOF)
				{
				}
				scontrinoPrezzo[scontrinoLunghezza] = -1; // Per ripetere il ciclo
			}
			else
			{
				continue;
			}

		} while (scontrinoPrezzo[scontrinoLunghezza] < 0); // Se l'utente da un valore minore di 0

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

	// Visualizzazione dati
	if (scontrinoLunghezza > 0)
	{

		// Acquisizione come vuole pagare
		do
		{
			printf("\nTotale scontrino: %.2f ", scontrinoPrezzoTot);
			printf("\nCome vuoi pagare il tutto?[ES. 3.54]\t");
			if (scanf("%f", &pagamento) != 1 || pagamento < scontrinoPrezzoTot)
			{
				if (pagamento < scontrinoPrezzoTot)
					printf("\nErrore: valore non valido");

				// Pulire il buffer di input
				int c;
				while ((c = getchar()) != '\n' && c != EOF)
				{
				}
				pagamento = -1; // Per ripetere il ciclo
			}
			else
			{
				if (pagamento > scontrinoPrezzoTot)
				{
					resto = pagamento - scontrinoPrezzoTot;
				}
			}
		} while (pagamento < scontrinoPrezzoTot);

		// Stampa scontrino
		printf("\n========================================================");
		printf("\n                       SHOP                             ");
		printf("\n========================================================");
		for (int i = 0; i < scontrinoLunghezza; i++)
		{
			printf("\n%c x%d  %.2f = %.2f", scontrinoProdotto[i], scontrinoQuantita[i], scontrinoPrezzo[i], scontrinoPrezzo[i] * scontrinoPrezzo[i]);
		}
		printf("\n--------------------------------------------------------");
		printf("\nProdotti comprati: \t %d", scontrinoQuantitaTot);
		printf("\nPrezzo totale: \t\t %.2f EUR", scontrinoPrezzoTot);
		if (scontrinoPrezzoTot > 0 && scontrinoQuantitaTot > 0)
			printf("\nMedia prezzo totale: \t %.2f EUR", ((float)scontrinoPrezzoTot / scontrinoQuantitaTot));
		printf("\nPagamento: \t\t %.2f EUR", pagamento);

		if (resto > 0)
			printf("\nResto: \t\t\t %.2f EUR", resto);
		printf("\n========================================================");
	}

	return 0;
}
// @TODO FIX STAMPA SCONTRINO