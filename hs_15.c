#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANZAHL 10
void bubble(int *, int, int (*)(int, int));
void ausgabe(int *, int);
int compare_value(int, int);
int qs(int);
int compare_qs(int, int);

int main()
{
    printf("\nHS_15 - Sortieren mit Funktionszeigern\n\n");
    srand((unsigned int)time(NULL)); // Zufallszahlen initialisieren
    int *iDaten = (int *)malloc(ANZAHL * sizeof(int));

    // ANTWORT Seite 21: int (*pf_cv) (int, int);
    int (*pf)(int, int) = NULL; // Funktionszeiger passend zum Typ von compare_value

    if (iDaten != NULL) // Prüfen, ob Allokation erfolgreich war, also der Pointer auf eine gültige Adresse zeigt
    {
        for (int i = 0; i < ANZAHL; i++)
        {
            *(iDaten + i) = rand() % (ANZAHL * 100); // das int-Array mit Pseudo-Zufallszahlen zwischen 0 und ANZAHL*100 (hier 1000) füllen
        }
        printf("\n--- VOR dem Sortieren ---\n");
        ausgabe(iDaten, ANZAHL);

        printf("\nNach Wert(w) oder Quersumme (q) sortieren?\n");
        char option;
        scanf(" %c", &option); // char aus der Eingabe einlesen und in option speichern

        if (option == 'w')
        {
            pf = compare_value;
        }
        else if (option == 'q')
        {
            pf = compare_qs;
        }
        else
        {
            printf("\nUngueltige Eingabe, bitte erneut versuchen.");
        }

        if (pf != NULL)
        { // Prüfen, ob Eingabe vom Benutzer zuvor erfolgreich war

            bubble(iDaten, ANZAHL, pf); // die ersten ANZAHL-viele(hier 10) Elemente im int-Array iDaten sortieren
            printf("\n---NACH dem Sortrieren ---\n");
            ausgabe(iDaten, ANZAHL);
        }

        free(iDaten); // reservierten Speicher wieder freigeben
    }
    else

        printf("\nReservierung fehlgeschlagen - FEHLER!\n");
    return 0;
}

void ausgabe(int *iWerte, int iZahl) // Ausgabe eines int-Arrays
{
    for (int i = 0; i < iZahl; i++)
    {
        printf("%d\t%d\t%d\n", i, iWerte[i], qs(iWerte[i]));
    }
}

void bubble(int *iWerte, int iZahl, int (*fp)(int, int))
{
    // Sortieren eines int-Arrays
    int iFlag;
    do
    {
        iFlag = 0;
        for (int i = 0; i < iZahl - 1; i++)
        {
            if ((*fp)(iWerte[i], iWerte[i + 1])) // Vergleich der Elemente
            {
                // ggf. tauschen der Elemente
                int iHilf = iWerte[i];
                iWerte[i] = iWerte[i + 1];
                iWerte[i + 1] = iHilf;
                iFlag = 1; // Wert gefunden, also weiter versuchen
                break;
            }
        }
    } while (iFlag); // solange Werte gefunden werden
}

int compare_value(int a, int b)
{
    return a > b;
}

int qs(int z)
{
    if (z < 10)
    {
        return z;
    }
    else
    {
        return z % 10 + qs(z / 10);
    }
}

int compare_qs(int a, int b)
{
    return qs(a) > qs(b);
}