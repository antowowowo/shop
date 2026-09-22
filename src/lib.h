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

#endif