// src/weight_update.c

#include "../include/weight_update.h"

void update_weights() {
    int i, j, k;

    for (i = 0; i < num_layers - 1; i++) {
        for (j = 0; j < num_neurons[i]; j++) {
            for (k = 0; k < num_neurons[i + 1]; k++) {
                // Update Weights
                lay[i].neu[j].out_weights[k] -= (alpha * lay[i].neu[j].dw[k]);
            }

            // Update Bias
            lay[i].neu[j].bias -= (alpha * lay[i].neu[j].dbias);
        }
    }
}
