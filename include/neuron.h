#ifndef NEURON_H
#define NEURON_H

typedef struct neuron_t {
    float actv;
    float *out_weights;
    float bias;
    float z;

    float dactv;
    float *dw;
    float dbias;
    float dz;
} neuron;

// Function prototypes
neuron* create_neuron(int num_weights);
void initialize_neuron(neuron *n, int num_weights);
void destroy_neuron(neuron *n);

#endif // NEURON_H
