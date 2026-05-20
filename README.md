# shop
## il negozio di antonio
## compilazione ed esecuzione del codice
```
cd shop
cd src
gcc main.c -o main
./main
```  

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
	-Ordinamento array prezzo
	-Ricevere sconto dopo X prodotti
	-Implemento matrici
FUNZIONALITA FUTURE :
	-Controllo cifre decimali
	-Buoni spesa
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
		-Aggiunta SCORTE max e scontrino max
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
		-Array SCORTE e quantita
	V 2.2.0
		Implementazioni:
		-Ordinamento array prezzo
	V 2.3.0
		Implementazioni:
		-RIcevere sconto dopo X prodotti
	V 2.4.0
		Modifiche:
		-Sostituzione array monodimensionale con matrici di stringhe
	V 2.5.0
		Errori conosciuti:
		-Funzioni printArray
		-Risposta "e" viene messa nella lista dei prodotti
		Modifiche:
		-Aggiunta delle funzioni
	V 2.5.1
		Aggiustati:
		-Risposta "e" viene messa nella lista dei prodotti
		Errori conosciuti:
		-Funzioni printArray
	V 2.5.2
		Errori conosciuti:
		-L'errore sta nel sorting non nel print, allineare i metodi di allineamento
	V 2.5.3
		Aggiustati:
		-L'errore sta nel sorting non nel print, allineare i metodi di allineamento
