# Hill-Climbing-Algorithm-Implementation
Simple Implementation of Hill Climbing Algorithm

What is Hill-Climbing technique?
In Hill-Climbing technique, starting at the base of a hill, we walk upwards until we reach the top of the hill. In other words, we start with initial state and we keep improving the solution until its optimal.
It is a variation of a generate-and-test algorithm which discards all states which do not look promising or seem unlikely to lead us to the goal state. To take such decisions, it uses heuristics (an evaluation function) which indicates how close the current state is to the goal state.
My Thought About This Algorithm:
The hill climb algorithm can be stuck on local minima and according to results. For me, this problem reduction method should be set so that the perturb function change is already reduced. This way reduces the chances of being stuck at the local minimum. I think this algorithm does not give the optimal results.