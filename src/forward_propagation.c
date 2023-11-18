#include "../include/forward_propagation.h"
#include <math.h>

void forward_prop() {
    int i, j, k;

    for (i = 1; i < num_layers; i++) {
        for (j = 0; j < num_neurons[i]; j++) {
            lay[i].neu[j].z = lay[i].neu[j].bias;

            for (k = 0; k < num_neurons[i - 1]; k++) {
                lay[i].neu[j].z += (lay[i - 1].neu[k].out_weights[j]) * (lay[i - 1].neu[k].actv);
            }

            // Relu Activation Function for Hidden Layers
            if (i < num_layers - 1) {
                lay[i].neu[j].actv = (lay[i].neu[j].z < 0) ? 0 : lay[i].neu[j].z;
            }
            // Sigmoid Activation function for Output Layer
            else {
                lay[i].neu[j].actv = 1 / (1 + exp(-lay[i].neu[j].z));
                printf("OUTPUT: %d\n", (int)round(lay[i].neu[j].actv));
                printf("\n");
            }
        }
    }
}
