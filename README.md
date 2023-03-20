# Finanza
Progetto realizzato per il corso "Laboratorio di Programmazione"
## Obbiettivo
Realizzare delle classi che rappresentano transazioni finanziarie su un conto corrente (ingresso e uscita). Le classi devono essere in gradi leggere e salvare i dati su file. <\br >
Oltre a ciò è necessario implementare metodologie ti testing.

## Come è stato realizzato
Il progetto si articola in 3 classi principlai:
- BankAccount che nel dominio della applicazione rappresenta il conto corrente dell'utente, dal quale partano transazioni, vengono effettuati prelievi e versamenti
- Transaction che rappresenta la transazione stessa
- IOFile che è una classa che si occupa unicamente di interagire con i file .txt che si occupano di memorizzare le informazioni dei vari BankAccount
oltre a ciò è stato inserito un main che simula l'interazione attraverso transazioni tra i vari utenti

## Testing 
Per effettuare il testing è stato utilizzato il framework di Google [<b > Google Test </b >](https://github.com/google/googletest.git). <\br >
Nello specifico è stata cerata una directory test con all'interno:
- runAllTest che si occupa di lanciare tutti i test del progetto 
- BanckAccountTest che contiene tutti i test della classe BanckAccount
la scelta di creare un file cpp che si occupa di lanciare tutti i test nella directory permette una evoluzione futura del testing in maniera agile. 
Infatti, qualora si aggiungano nuovi file cpp contenenti test essi verrano automaticamente eseguiti da runAllTest.

### Gestione degli indici degli utenti 
Ogni BanckAccount è caratterizzato da un indice.
Gli indici <0 sono riservati al testing, quindi, in caso di modifica al codice, si consiglia di evitare di assegnare indici <0.

