#include "../include/neuron.h"
#include <stdlib.h>

neuron* create_neuron(int num_weights) {
    neuron *n = (neuron*)malloc(sizeof(neuron));

    if (n != NULL) {
        initialize_neuron(n, num_weights);
    }

    return n;
}

void initialize_neuron(neuron *n, int num_weights) {
    n->actv = 0.0;
    n->out_weights = (float*)malloc(num_weights * sizeof(float));
    n->bias = 0.0;
    n->z = 0.0;

    n->dactv = 0.0;
    n->dw = (float*)malloc(num_weights * sizeof(float));
    n->dbias = 0.0;
    n->dz = 0.0;
}

void destroy_neuron(neuron *n) {
    if (n != NULL) {
        free(n->out_weights);
        free(n->dw);
        free(n);
    }
}
