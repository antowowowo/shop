#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lib.h"
#define IVA 0.04
#define DEBUG 1
#define printDebug(fmt, ...)                                \
	do                                                      \
	{                                                       \
		if (DEBUG == 1)                                     \
		{                                                   \
			printf("\n[[DEBUG]] " fmt "\n", ##__VA_ARGS__); \
		}                                                   \
	} while (0)

/*
- Ordina un array float -
- array è da ordinare -
- size sta per la dimensione -
*/
float *bubbleSortingFloat(float array[], int size)
{
	printDebug("Ordinando l'array");
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] < array[j + 1])
			{
				float temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	return array;
}

/*
- Ordina un array int -
- array è da ordinare -
- size sta per la dimensione -
*/
int *bubbleSortingInt(int array[], int size)
{
	printDebug("Ordinando l'array");
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	return array;
}

/*
- Ordina una matrice -
- matrix è la matrice da ordinare -
- size sta per la dimensione -
*/
char (*bubbleSortingMatrixChar(char matrix[][MAXSTRINGA], int size)) [MAXSTRINGA]
{
	printDebug("Ordinando la matrice");
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			char temp[MAXSTRINGA];
			printDebug("temp %s matrix[j] %s matrix [j + 1]", temp, matrix[j], matrix[j + 1]);
		}
	}

	return matrix;
}

/*
- Stampa l'array float -
- array è da ordinare -
- size sta per la dimensione -
*/
void printArrayFloat(float array[], int size)
{
	printDebug("Stampando l'array float");
	for (int i = 0; i < size; i++)
	{
		printf("%.2f", array[i]);
	}
}

/*
- Stampa l'array int -
- array è da ordinare -
- size sta per la dimensione -
*/
void printArrayInt(int array[], int size)
{
	printDebug("Stampando l'array int");
	for (int i = 0; i < size; i++)
	{
		printf("%d", array[i]);
	}
}

/*
- Stampa la stringa -
- matrix è la matrice da ordinare -
- size sta per la dimensione -
*/
void printArrayMatrixChar(char matrix[][MAXSTRINGA], int size)
{
	printDebug("Stampando la matrice");
	for (int i = 0; i < size; i++)
	{
		printf("%s ", matrix[i]);
	}
}

/*
- Calcola la percentuale di iva nel prezzo -
*/
float calcolaIva(float n)
{
	return n * IVA;
}

/*
- Calcola la media tra prezzo e quantita -
*/
float calcolaMedia(float x, int y)
{
	return ((float)x / y);
}

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
void scontrinoSorting(
	int size,
	float scontrinoPrezzo[],
	int scontrinoQuantita[],
	char scontrinoProdotto[][MAXSTRINGA])
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
- pagamento e' il numero con cui l'utente paga -
- prezzoProdottiScontrino e' il prodotto di prezzo e quantita' -
- fraseSconto e' l'eventuale frase dello sconto -
- mediaScontrino e' la media tra prezzo e quantita' -
- fraseResto e' l'eventuale frase del resto -
- subtotale e' il prezzo totale senza iva e sconto -
- iva e' la percentuale di soldi che fa parte dell'IVA -
- totale e' il prezzo totale con iva e sconto -
*/
void stampaScontrino(
	int size,
	char prodotto[][MAXSTRINGA],
	int quantita[],
	int quantitaTot,
	float prezzo[],
	float pagamento,
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
	printf("\nSubtotale: \t\t %.2f EUR", subtotale);
	printf("\nIVA: \t\t\t %.2f EUR", iva);
	printf("\n%s EUR", fraseSconto);
	printf("\nTotale: \t\t %.2f EUR", totale);
	printf("\nPagamento: \t\t %.2f EUR", pagamento);

	printf("\n%s", fraseResto);
	printf("\n========================================================");
}

/*
- Inizializza i calcoli dello scontrino -
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

float inizializzaScontrino(
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
	/* ---- Calcolo prezzoProdottiScontrino ---- */
	float prezzoProdottiScontrino[100];
	for (int i = 0; i < size; i++)
	{
		prezzoProdottiScontrino[i] = prezzo[i] * quantita[i];
	}

	/* ---- Calcolo valoreSconto ---- */
	float valoreSconto = prezzoTot * sconto;

	/* ---- Calcolo fraseSconto ---- */
	char fraseSconto[100];
	if (valoreSconto == 0)
	{
		strcpy(fraseSconto, "\0"); // Stringa vuota
	}
	else
	{
		snprintf(fraseSconto, sizeof(fraseSconto), "\nSconto:\t\t\t -%.2f", valoreSconto);
	}

	/* ---- Calcolo subtotale, iva e totale ---- */
	float subtotale = prezzoTot;
	float iva = calcolaIva(prezzoTot);
	float totale = prezzoTot + iva - valoreSconto;

	/* ---- Calcolo mediaScontrino ---- */
	float mediaScontrino = calcolaMedia(totale, quantitaTot);

	/* ---- Calcolo fraseResto ---- */
	char fraseResto[100];
	if (resto == 0)
	{
		strcpy(fraseResto, "\0");
	}
	else
	{
		snprintf(fraseResto, sizeof(fraseResto), "\nResto: \t\t\t %.2f EUR", resto);
	}

	/* ---- Chiamata finale della funzione stampaScontrino ---- */
	stampaScontrino(
		size,
		prodotto,
		quantita,
		quantitaTot,
		prezzo,
		pagamento,
		prezzoProdottiScontrino,
		fraseSconto,
		mediaScontrino,
		fraseResto,
		subtotale,
		iva,
		totale);

	return totale;
}

void gestionePagamento(float totale)
{
	float pagamento,
		resto;
	do
	{
		printf("\nTotale scontrino: %.2f ", totale);
		printf("\nCome vuoi pagare il tutto?[ES. 3.54] ");
		if (scanf("%f", &pagamento) != 1 || pagamento < totale)
		{
			if (pagamento < totale)
			{
				printf("\nErrore: valore non valido");

				// Pulire il buffer di input
				pulisciBuffer();
				pagamento = -1; // Per ripetere il ciclo
			}
		}
		else
		{
			if (pagamento > totale)
			{
				resto = pagamento - totale;
			}
		}
	} while (pagamento != 1 || pagamento < totale);
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

char *acquisisciStringa(char domanda[], int min, int max)
{
	char stringa[max];
	do
	{
		printf("%s", domanda);
		fgets(stringa, max, stdin);
		pulisciStringa(stringa);
		if (strlen(stringa) < min || strlen(stringa) > max)
			printf("\nErrore: la lunghezza della stringa deve essere tra %d e %d.", min, max);
	} while (strlen(stringa) < min || strlen(stringa) > max);
	return stringa;
}

int acquisisciInt(char domanda[], int min, int max)
{
	int num;
	do {
		printf("%s", domanda);
		scanf("%d",&num);
		pulisciBuffer();
		if ( num < min || num > max ) printf("\nErrore: deve essere tra %d e %d.", min, max);
	} while ( num < min || num > max );
	return num;
}