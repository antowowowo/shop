#include <stdio.h>
#include "lib.h"
#define IVA 0.04

/*
- Ordina un array float -
- array è da ordinare -
- size sta per la dimensione -
*/
float* bubbleSortingFloat( float array[], int size ) {
	printDebug("Ordinando l'array");
	for ( int i = 0; i < size - 1; i++ ) {
		for ( int j = 0; j < size - i - 1; j++ ) {
			if ( array[j] < array[j + 1] ) {
				float temp = array[j];
				array[j] = array [j + 1];
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
int* bubbleSortingInt( int array[], int size ) {
	printDebug("Ordinando l'array");
	for (int i = 0; i < size - 1; i++) {
		for ( int j = 0; j < size - i - 1; j++ ) {
			if ( array[j] > array[j + 1] ) {
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
char (*bubbleSortingMatrixChar(char matrix[][MAXSTRINGA], int size))[MAXSTRINGA] {
	printDebug("Ordinando la matrice");	
	for ( int i = 0; i < size - 1; i++ ) {
		for ( int j = 0; j < size - i - 1; j++ ) {
			char temp[MAXSTRINGA];
			printDebug("temp %s matrix[j] %s matrix [j + 1]", temp, matrix[j], matrix[j + 1] );
		}
	}
	

	return matrix;
}

/*
- Stampa l'array float -
- array è da ordinare -
- size sta per la dimensione -
*/
void printArrayFloat( float array[], int size) {
	printDebug("Stampando l'array float");
	for ( int i = 0; i < size; i++ ) {
		printf("%.2f",array[i]);
	}

}

/*
- Stampa l'array int -
- array è da ordinare -
- size sta per la dimensione -
*/
void printArrayInt( int array[], int size ) {
	printDebug("Stampando l'array int");
	for ( int i = 0; i < size; i++ ) {
		printf("%d",array[i]);
	}

}

/* 
- Stampa la stringa -
- matrix è la matrice da ordinare -
- size sta per la dimensione -
*/
void printArrayMatrixChar( char matrix[][MAXSTRINGA], int size ) {
	printDebug("Stampando la matrice");
	for ( int i = 0; i < size; i++ ) {
		printf("%s ", matrix[i]);
	}

}

#define DEBUG 0
#define printDebug(fmt, ...) \
    do { \
        if (DEBUG == 1) { \
            printf("\n[[DEBUG]] " fmt "\n", ##__VA_ARGS__); \
        } \
    } while (0)

float calcolaIva(float n){
	return n * IVA;
}

float calcolaMedia(float x, int y){
	return ((float)x / y);
}