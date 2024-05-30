### Montecarlo methods
Are algorithm that recurr to the generation of random numbers to explore the phase space of the system.
Usually the do importance sampling, meaning that they explore only the states with lower Free energy, that are the ones where is most likely to find the system.

##### Metropolis
You select a spin and you calculate the energy change if you flip it.
Then you calculate the ratio between the (Boltzmann) probability of the state with the spin flipped and unflipped.
If it is > 1, you accept the flip, otherwise you accept it with a probability that is the ratio.
It is possible to prove that the algorithm converges to the Boltzmann distribution [meaning that the number of times a configuration reappears during the simulation, is proportional to its Boltzmann probability]

##### Cluster algoritms
You consider each domain and you flip all the spins of that domain with probability 1/2.