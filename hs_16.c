#include <stdio.h>
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
};

// Funktion zur Ausgabe eines Messwerts (Call by Value)
void ausgabe(struct Messwert messung) {
    printf("Messung Nummer: %d\n", messung.iMessungNummer);
    printf("Luftdruck: %.2lf\n", messung.dLuftdruck);
    printf("Temperatur[0]: %.2f\n", messung.fTemperatur[0]);
    printf("Temperatur[1]: %.2f\n", messung.fTemperatur[1]);
    printf("Temperatur[2]: %.2f\n", messung.fTemperatur[2]);
    printf("Position: Latitude: %.5lf, Longitude: %.5lf, Altitude: %.2f\n",
           messung.Position.dLatitude,
           messung.Position.dLongitude,
           messung.Position.fAltitude);
    printf("Größe des Arrays fTemperatur: %lu Bytes\n", sizeof(messung.fTemperatur));
    
    // Änderung eines Array-Elements
    messung.fTemperatur[1] = 99.9f;
}

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
    
    // Änderung eines Array-Elements
    messung->fTemperatur[1] = 99.9f;
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
    return mess;
}

int main() {
    struct Messwert mess;
    mess.iMessungNummer = 1;
    mess.dLuftdruck = 1013.25;
    mess.fTemperatur[0] = 20.0f;
    mess.fTemperatur[1] = 21.5f;
    mess.fTemperatur[2] = 22.0f;
    mess.Position.dLatitude = 51.44786;
    mess.Position.dLongitude = 7.27069;
    mess.Position.fAltitude = 128.0f;
    
    printf("--- Platzbedarf  ---\n");
    printf("Speicherbedarf von messung: %lu Bytes\n", sizeof(mess));
    printf("Speicherbedarf von messung.Position: %lu Bytes\n", sizeof(mess.Position));

    printf("\n--- Ausgabe mit Call by Value ---\n");
    ausgabe(mess);
    printf("\nTemperatur[1] nach Call by Value: %.2f\n", mess.fTemperatur[1]);
    
    printf("\n--- Ausgabe mit Call by Reference ---\n");
    ausgabe_p(&mess);
    printf("\nTemperatur[1] nach Call by Reference: %.2f\n", mess.fTemperatur[1]);
    
    
    printf("\n--- Ausgabe mit set_mw ---\n");
    struct Messwert messung = set_mw(1);
    ausgabe(messung);

    return 0;
}
