RandomWriter
============

- Statistical program that generates random stories (of relevant style according to input training data)
- Underlying algorithm uses Markov Models of varying order.

* Execution Instructions
  - Type ./randomTextOutput to execute the program
  - For generating random output from new files, you can include those files in working directory of code 
    & and specify them in the program
  - Note : Currently generates 2000 characters of text

* Underlying Mechanism 
  - Works on the Markov Model Mechanisum of State transition
  - The order of the model, which is basically the state dependence of the Model, is specifiable
  - Higher order Markov Models yield better performance but reduce the variability from training text
  - The state transition parameters are obtained by observing state transitions in the training text
