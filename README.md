
# Shop - Il Negozio di Antonio

Un software gestionale scritto in C per la gestione degli acquisti in un negozio, completo di scontrino, calcolo del resto, sconti e gestione delle scorte.

---

## Compilazione ed Esecuzione del Codice

Per avviare il programma, posizionati nella cartella del progetto ed esegui i seguenti comandi nel terminale:

```bash
cd shop
cd src
gcc main.c -o main
./main

```

---

## Funzionalità Attuali

* **Gestione Quantità:** Scelta di quanti prodotti comprare.
* **Categorie Prodotti:** Scelta di comprare una bevanda, un cibo o un dolce.
* **Contatori Dedicati:** Counter specifici per bevanda, cibo e dolce.
* **Statistiche di Spesa:**
* Costo totale e media del costo finale.
* Costo totale di bevanda, cibo e dolce.
* Media costo di bevanda, cibo e dolce.


* **Gestione Pagamento:** Possibilità di ricevere il resto se si paga una cifra superiore al costo totale.
* **Scontrino:**
* Memorizzazione in un array dello scontrino.
* Stampa finale dello scontrino.


* **Interfaccia:** Implementazione grafica da terminale.
* **Algoritmi e Strutture Dati:**
* Ordinamento (sorting) dell'array dei prezzi.
* Implementazione e uso delle matrici.


* **Promozioni:** Possibilità di ricevere uno sconto dopo aver acquistato $X$ prodotti.

---

## Funzionalità Future

* [ ] Controllo e validazione delle cifre decimali.
* [ ] Gestione dei buoni spesa.

---

## Changelog

### V 2.5.3

* **Aggiustamenti:**
* Risolto il bug del sorting: l'errore risiedeva nell'algoritmo di ordinamento e non nella stampa (`print`). Allineati i metodi di ordinamento.



### V 2.5.2

* **Errori Conosciuti:**
* L'errore sta nel sorting non nel print, allineare i metodi di allineamento.



### V 2.5.1

* **Aggiustamenti:**
* Risolto il bug per cui la risposta "e" veniva erroneamente inserita nella lista dei prodotti.


* **Errori Conosciuti:**
* Problemi con le funzioni `printArray`.



### V 2.5.0

* **Modifiche:**
* Introduzione e aggiunta delle funzioni per modularizzare il codice.


* **Errori Conosciuti:**
* Problemi con le funzioni `printArray`.
* La risposta "e" viene inserita nella lista dei prodotti.



### V 2.4.0

* **Modifiche:**
* Sostituzione degli array monodimensionali con matrici di stringhe.



### V 2.3.0

* **Implementazioni:**
* Aggiunta della logica per ricevere uno sconto dopo l'acquisto di $X$ prodotti.



### V 2.2.0

* **Implementazioni:**
* Implementato l'ordinamento dell'array dei prezzi.



### V 2.1.0

* **Aggiunte:**
* Aggiunta dell'array per la gestione delle **SCORTE** e delle quantità disponibili.



### V 2.0.0

* **Implementazioni:**
* Migliorata la componente grafica del programma.
* Implementata la stampa dello scontrino.


* **Rimozioni:**
* Rimosse le vecchie variabili singole riguardanti bevande, cibo e dolci.



### V 1.5.1

* **Modifiche:**
* *Bug fix:* Il programma ora non va più in errore se viene inserita una lettera al posto di un numero nei seguenti contesti:
* Domanda di pagamento.
* Domanda dei pezzi comprati.
* Domanda del prezzo.




* **Rimozioni:**
* Rimosso il codice ridondante relativo a:
* `mediaBevande`, `scontrinoBevande`, `totBevande`
* `mediaCibo`, `scontrinoCibo`, `totCibo`
* `mediaDolce`, `scontrinoDolce`, `totDolce`





### V 1.5.0

* **Aggiunte:**
* Implementazione dell'array scontrino.


* **Modifiche:**
* Refactoring generale delle variabili.



### V 1.4.1

* **Miglioramenti:**
* Implementazione di suggerimenti testuali per guidare l'utente.



### V 1.4.0

* **Aggiunte:**
* Gestione del pagamento e calcolo del resto.



### V 1.3.0

* **Aggiunte:**
* Aggiunta gestione delle **SCORTE max** e limite massimo dello scontrino.


* **Modifiche:**
* *Bug fix:* Il programma gestisce l'errore se si inserisce una lettera al posto di un numero.


* **Miglioramenti:**
* Messaggi di errore più descrittivi e parlanti.



### V 1.2.1

* **Modifiche:**
* Miglioramento generale del codice.
* *Bug fix:* Il programma gestisce l'errore se si inserisce una lettera al posto di un numero.



### V 1.2.0

* **Aggiunte:**
* Calcolo della media costo di bevanda, cibo e dolce.
* Calcolo del costo totale diviso per bevanda, cibo e dolce.


