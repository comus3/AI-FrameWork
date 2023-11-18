#include "../include/layer.h"
#include <stdlib.h>

layer* create_layer(int num_neurons, int num_weights_per_neuron) {
    layer *l = (layer*)malloc(sizeof(layer));

    if (l != NULL) {
        initialize_layer(l, num_neurons, num_weights_per_neuron);
    }

    return l;
}

void initialize_layer(layer *l, int num_neurons, int num_weights_per_neuron) {
    l->num_neu = num_neurons;
    l->neu = (neuron*)malloc(num_neurons * sizeof(neuron));

    for (int i = 0; i < num_neurons; ++i) {
        initialize_neuron(&(l->neu[i]), num_weights_per_neuron);
    }
}

void destroy_layer(layer *l) {
    if (l != NULL) {
        for (int i = 0; i < l->num_neu; ++i) {
            destroy_neuron(&(l->neu[i]));
        }
        free(l->neu);
        free(l);
    }
}
