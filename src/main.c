#include "../include/layer.h"
#include <stdio.h>

layer* lay;  // Global variable for layers

// Function prototype for create_architecture
int create_architecture();

int main() {
    // ... (existing code)

    int result = create_architecture();

    if (result == SUCCESS_CREATE_ARCHITECTURE) {
        // Your code for using the architecture
        // ...

        // Free memory when done
        for (int i = 0; i < num_layers; ++i) {
            destroy_layer(&lay[i]);
        }
        free(lay);
    } else {
        printf("Error creating architecture\n");
    }

    return 0;
}
