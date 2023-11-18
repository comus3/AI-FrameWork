#include "../include/back_propagation.h"
#include <math.h>

void back_prop(int p) {
    int i, j, k;

    // Output Layer
    for (j = 0; j < num_neurons[num_layers - 1]; j++) {
        lay[num_layers - 1].neu[j].dz = (lay[num_layers - 1].neu[j].actv - desired_outputs[p][j]) * (lay[num_layers - 1].neu[j].actv) * (1 - lay[num_layers - 1].neu[j].actv);

        for (k = 0; k < num_neurons[num_layers - 2]; k++) {
            lay[num_layers - 2].neu[k].dw[j] = lay[num_layers - 1].neu[j].dz * lay[num_layers - 2].neu[k].actv;
            lay[num_layers - 2].neu[k].dactv = lay[num_layers - 2].neu[k].out_weights[j] * lay[num_layers - 1].neu[j].dz;
        }

        lay[num_layers - 1].neu[j].dbias = lay[num_layers - 1].neu[j].dz;
    }

    // Hidden Layers
    for (i = num_layers - 2; i > 0; i--) {
        for (j = 0; j < num_neurons[i]; j++) {
            if (lay[i].neu[j].z >= 0) {
                lay[i].neu[j].dz = lay[i].neu[j].dactv;
            } else {
                lay[i].neu[j].dz = 0;
            }

            for (k = 0; k < num_neurons[i - 1]; k++) {
                lay[i - 1].neu[k].dw[j] = lay[i].neu[j].dz * lay[i - 1].neu[k].actv;

                if (i > 1) {
                    lay[i - 1].neu[k].dactv = lay[i - 1].neu[k].out_weights[j] * lay[i].neu[j].dz;
                }
            }

            lay[i].neu[j].dbias = lay[i].neu[j].dz;
        }
    }
}
