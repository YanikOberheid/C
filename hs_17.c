#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct Geo {
    double dLatitude;
    double dLongitude;
    float fAltitude;
};

struct Messwert {
    int iMessungNummer;
    double dLuftdruck;
    float fTemperatur[3];
    struct Geo Position;
    struct Messwert *pNext;
};

// Funktion zur Ausgabe eines Messwerts (Call by Reference)
void ausgabe_p(struct Messwert *messung) {
    printf("Messung Nummer: %d\n", messung->iMessungNummer);
    printf("Luftdruck: %.2lf\n", messung->dLuftdruck);
    printf("Temperatur[0]: %.2f\n", messung->fTemperatur[0]);
    printf("Temperatur[1]: %.2f\n", messung->fTemperatur[1]);
    printf("Temperatur[2]: %.2f\n", messung->fTemperatur[2]);
    printf("Position: Latitude: %.5lf, Longitude: %.5lf, Altitude: %.2f\n",
           messung->Position.dLatitude,
           messung->Position.dLongitude,
           messung->Position.fAltitude);
    printf("Größe des Arrays fTemperatur: %lu Bytes\n", sizeof(messung->fTemperatur));
}

// Funktion zum Hinzufügen eines Elements zur Liste
int addToList(struct Messwert **pStart, struct Messwert newElement) {
    struct Messwert *pNew = (struct Messwert *)malloc(sizeof(struct Messwert));
    if (pNew == NULL) {
        return -1; // Speicher konnte nicht reserviert werden
    }
    *pNew = newElement;
    pNew->pNext = *pStart;
    *pStart = pNew;
    return 0; // Erfolg
}

// Funktion zur Ausgabe der Liste
void printList(struct Messwert *pStart) {
    struct Messwert *current = pStart;
    int count = 0;
    while (current != NULL) {
        ausgabe_p(current);
        printf("\n");
        current = current->pNext;
        count++;
    }
    printf("\nAnzahl der Elemente in der Liste: %d\n", count);
}

// Funktion zum Löschen der Liste
void emptyList(struct Messwert **pStart) {
    struct Messwert *current = *pStart;
    struct Messwert *next;
    while (current != NULL) {
        next = current->pNext;
        free(current);
        current = next;
    }
    *pStart = NULL;
}

// Funktion zur Erstellung eines Messwerts
struct Messwert set_mw(int nummer) {
    struct Messwert mess;
    mess.iMessungNummer = nummer;
    mess.dLuftdruck = 1050.25;
    mess.fTemperatur[0] = 25.0f;
    mess.fTemperatur[1] = 16.5f;
    mess.fTemperatur[2] = 18.0f;
    mess.Position.dLatitude = 51.44786;
    mess.Position.dLongitude = 7.27069;
    mess.Position.fAltitude = 128.0f;
    mess.pNext = NULL;
    return mess;
}

int main() {
    struct Messwert *pStart = NULL;
    struct Messwert mess1 = set_mw(1);
    struct Messwert mess2 = set_mw(2);
    
    printf("--- Ausgabe der addToList ---\n");
    addToList(&pStart, mess1);
    printf("-mess1 hinzugefuegt-\n");
    ausgabe_p(pStart);
    addToList(&pStart, mess2);
    printf("\n-mess2 hinzugefuegt-\n");
    ausgabe_p(pStart);

    printf("\n--- Ausgabe der Liste ---\n");
    printList(pStart);

    printf("\n--- Löschen der Liste ---");
    emptyList(&pStart);
    printList(pStart);

    return 0;
}
