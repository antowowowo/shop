#ifndef LIB_H
#define LIB_H
#define MAXSTRINGA 10       // Indica la lunghezza massima di una stringa
#define SCORTE 500		    // Indica la dimensione massima dell'array
#define MAXSCONTRINO 2000   // Indica il prezzo massimo di un prodotto

float* bubbleSortingFloat( float array[], int size );

int* bubbleSortingInt( int array[], int size ); 

char (*bubbleSortingMatrixChar(char matrix[][MAXSTRINGA], int size))[MAXSTRINGA];

void printArrayFloat( float array[], int size);
	
void printArrayInt( int array[], int size );
	
void printArrayMatrixChar( char matrix[][MAXSTRINGA], int size );

float calcolaIva(float n);

float calcolaMedia(float x, int y);

int pulisciBuffer();

int cercaProdotto(char risposta[], char scorta[][MAXSTRINGA]);

void scontrinoSorting(int size, float scontrinoPrezzo[], int scontrinoQuantita[], char scontrinoProdotto[][MAXSTRINGA]);

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
	float totale);

float inizializzaScontrino(
	int size,
	char prodotto[][MAXSTRINGA],
	int quantita[],
	int quantitaTot,
	float prezzo[],
	float prezzoTot,
	float sconto,
	float pagamento,
	float resto);

void gestionePagamento(float totale);

char *pulisciStringa(char stringa[]);

void inizializzaScorte(char scorteProdotti[][MAXSTRINGA]);

char *acquisisciStringa(char domanda[], int min, int max);

int acquisisciInt(char domanda[], int min, int max);
#endif