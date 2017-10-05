# Queue-Reconstruction-by-Height

## Question:

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

## Solution:

First we need to sort the vector by smallest k value so that the people who have no one taller then them are in the front and people who have many people taller then them are in the back.

Afterwards we count the number of people who are taller then the current person and move that person forward to his correct position. 
Since we ordered the people by k values, the person actual position is either the current position or before.

