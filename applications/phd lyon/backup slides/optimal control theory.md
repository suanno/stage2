To explain what is optimal control theory, we have to consider a dynamical system, whose evolution can be influenced by action that **you** can make on the system.
The theory studies what is the best way to act on the system to drive it in a target state. Where the concept of "best way" can be defined as you want, like "in the shortest time".

# Markovian process
In the simplest case, the way the agent decides what action he's going to make, depends only on the current state of the system, so it is a markovian process.
And the best strategy (of acting on the system) to reach the target state is found throught a system of rewards.
The system gives a reward to the agent if he likes the action and the algorithm maximizes the total reward of the process.