#include <stdio.h>

// Definizione della funzione esterna
void funzione_esterna() {
    // Tentativo di definizione di una funzione interna (Non consentito, in teoria)
    void funzione_interna() {
        printf("Chiamata alla funzione interna\n");
    }

    // Chiamata alla funzione interna
    funzione_interna();
}

int main() {
    // Chiamata alla funzione esterna
    funzione_esterna();

    return 0;
}