#include <stdio.h>

#pragma pack(1)

struct Geo
{
    double dLatitude;
    double dLongitude;
    float fAltitude;
};

struct Messwert
{
    int iMessungNummer;
    double dLuftdruck;
    float fTemperatur[3];
    struct Geo Position;
};

struct Messwert set_mw(int iNummer)
{
    struct Messwert tmp;
    tmp.iMessungNummer = iNummer;
    tmp.dLuftdruck = 1013.25;
    tmp.fTemperatur[0] = 15.0f;
    tmp.fTemperatur[1] = 16.5f;
    tmp.fTemperatur[2] = 18.2f;

    tmp.Position.dLatitude = 51.1234;
    tmp.Position.dLongitude = 7.5678;
    tmp.Position.fAltitude = 345.6f;

    return tmp;
}

void ausgabe(struct Messwert mw)
{
    printf("\n--- ausgabe() ---\n");
    printf("Messung Nummer:  %d\n", mw.iMessungNummer);
    printf("Luftdruck:       %.2f\n", mw.dLuftdruck);
    printf("Temperatur[0]:   %.2f\n", mw.fTemperatur[0]);
    printf("Temperatur[1]:   %.2f\n", mw.fTemperatur[1]);
    printf("Temperatur[2]:   %.2f\n", mw.fTemperatur[2]);
    printf("Position:        Lat=%.5f, Lon=%.5f, Alt=%.2f\n",
           mw.Position.dLatitude, mw.Position.dLongitude, mw.Position.fAltitude);

    printf("sizeof(mw.fTemperatur) = %zu\n", sizeof(mw.fTemperatur));

    mw.fTemperatur[1] = 99.99f;
    printf("=> ---FUNKTION ausgabe()--- Der aktuelle Wert von mw.fTemperatur[1] ist %.2f\n", mw.fTemperatur[1]);
}

// Diese Funktion macht das Gleiche wie ausgabe(), aber diesmal übergeben wir
// einen Zeiger auf einen Messwert.
void ausgabe_p(struct Messwert *pm)
{
    printf("\n--- ausgabe_p() ---\n");
    printf("Messung Nummer:  %d\n", pm->iMessungNummer);
    printf("Luftdruck:       %.2f\n", pm->dLuftdruck);
    printf("Temperatur[0]:   %.2f\n", pm->fTemperatur[0]);
    printf("Temperatur[1]:   %.2f\n", pm->fTemperatur[1]);
    printf("Temperatur[2]:   %.2f\n", pm->fTemperatur[2]);
    printf("Position:        Lat=%.5f, Lon=%.5f, Alt=%.2f\n",
           pm->Position.dLatitude, pm->Position.dLongitude, pm->Position.fAltitude);

    printf("sizeof(pm->fTemperatur) = %zu\n", sizeof(pm->fTemperatur));

    pm->fTemperatur[1] = 123.45f;
    printf("=> ---FUNKTION ausgabe_p() --- Der aktuelle Wert von pm->fTemperatur[1] ist %.2f\n", pm->fTemperatur[1]);
}

int main(void)
{

    struct Messwert messung = {
        42,
        998.12,
        {10.1f, 20.2f, 30.3f},
        {51.44786, 7.27069, 128.0f}};

    printf("sizeof(messung)         = %zu\n", sizeof(messung));
    printf("sizeof(messung.Position)= %zu\n", sizeof(messung.Position));

    ausgabe(messung);

    printf("\nZurück in main:\n");

    printf("Nach ausgabe(), messung.fTemperatur[1] = %.2f\n",
           messung.fTemperatur[1]);

    ausgabe_p(&messung);

    printf("\nZurück in main:\n");

    printf("Nach ausgabe_p(), messung.fTemperatur[1] = %.2f\n",
           messung.fTemperatur[1]);

    struct Messwert messNeu = set_mw(99);

    ausgabe(messNeu);

    return 0;
}
