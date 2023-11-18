// src/architecture.c

#include "../include/layer.h"
#include "your_weight_init_file.h"  // Include the file for weight initialization

int create_architecture() {
    int i = 0, j = 0;

    lay = (layer*)malloc(num_layers * sizeof(layer));

    if (lay == NULL) {
        printf("Error allocating memory for layers\n");
        return ERR_CREATE_ARCHITECTURE;
    }

    for (i = 0; i < num_layers; i++) {
        lay[i] = *create_layer(num_neurons[i]);  // Store the created layer

        lay[i].num_neu = num_neurons[i];
        printf("Created Layer: %d\n", i + 1);
        printf("Number of Neurons in Layer %d: %d\n", i + 1, lay[i].num_neu);

        for (j = 0; j < num_neurons[i]; j++) {
            if (i < (num_layers - 1)) {
                lay[i].neu[j] = *create_neuron(num_neurons[i + 1]);  // Store the created neuron
            }

            printf("Neuron %d in Layer %d created\n", j + 1, i + 1);
        }
        printf("\n");
    }

    printf("\n");

    // Initialize the weights
    if (initialize_weights() != SUCCESS_INIT_WEIGHTS) {
        printf("Error Initializing weights...\n");
        return ERR_CREATE_ARCHITECTURE;
    }

    return SUCCESS_CREATE_ARCHITECTURE;
}
