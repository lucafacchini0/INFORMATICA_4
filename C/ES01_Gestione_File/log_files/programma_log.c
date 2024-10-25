#include <stdio.h>
#include <time.h>
#include <stdlib.h>

FILE *fileDiLog;

void apriFileDiLog();
void scriviLog(const char *messaggio);
void chiudiFileDiLog();

int main() {
    apriFileDiLog();

    scriviLog("Applicazione avviata.");
    scriviLog("Connessione al database BilardoSQL effettuata.");
    scriviLog("Errore:: impossibile connettersi al server di FBLabs.");

    chiudiFileDiLog();

    return 0;
}
void apriFileDiLog() {
    fileDiLog = fopen("log.txt", "a");
    if (fileDiLog == NULL) {
        perror("Errore nell'apertura del file di log");
        exit(1);
    }
}

void scriviLog(const char *messaggio) {
    time_t tempoCorrente;
    struct tm *tempoLocale;
    time(&tempoCorrente);
    tempoLocale = localtime(&tempoCorrente);

    fprintf(fileDiLog, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n",
            tempoLocale->tm_year + 1900, tempoLocale->tm_mon + 1, tempoLocale->tm_mday,
            tempoLocale->tm_hour, tempoLocale->tm_min, tempoLocale->tm_sec, messaggio);
}

void chiudiFileDiLog() {
    fclose(fileDiLog);
}


