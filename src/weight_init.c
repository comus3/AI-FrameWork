#include "../include/weight_init.h"
#include <stdlib.h>

int initialize_weights() {
    // You can implement your own logic for weight initialization here
    // For example, initialize weights to random values, or use a specific strategy

    // Iterate through layers and neurons to initialize weights
    for (int i = 0; i < num_layers - 1; ++i) {
        for (int j = 0; j < lay[i].num_neu; ++j) {
            // Assuming a simple random initialization for demonstration purposes
            for (int k = 0; k < lay[i + 1].num_neu; ++k) {
                lay[i].neu[j].out_weights[k] = ((float)rand() / RAND_MAX) * 2.0 - 1.0;
            }
        }
    }

    // You can add more sophisticated weight initialization logic as needed

    return SUCCESS_INIT_WEIGHTS;
}
