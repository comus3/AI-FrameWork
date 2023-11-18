#ifndef LAYER_H
#define LAYER_H

#include "neuron.h"

typedef struct layer_t {
    int num_neu;
    neuron *neu;
} layer;

// Function prototypes
layer* create_layer(int num_neurons, int num_weights_per_neuron);
void initialize_layer(layer *l, int num_neurons, int num_weights_per_neuron);
void destroy_layer(layer *l);

#endif // LAYER_H
