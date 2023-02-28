# Flight-Path-Calculator


# Description
A terminal-based path finding that calculates the paths and finds the cheapest path

# Features
* Stores the flights by mapping the available flights from the entered City
* Finds the shortest path using stacks and adjacent cities
* No memory leak checked using Valgrind

# Example Outputs of the CSV txt files

9 cities and 11 flights have been loaded
The list of the cities that HPAir serves is given below:
P, Q, R, S, T, W, X, Y, Z,

The cities adjacent to X are:
X ->

The cities adjacent to W are:
W -> S, Y,

The whole flight map is given below:

P -> R, W,

Q -> X,

R -> X, Z,

S -> T,

T -> W,

W -> S, Y,

X ->

Y -> R, Z,

Z ->

Request is to fly from W to X:

Flight #77 from W to Y, Cost: 400 TL

Flight #88 from Y to R, Cost: 450 TL

Flight #22 from R to X, Cost: 150 TL

Total Cost: 1000 TL

Request is to fly from S to X:

Flight #55 from S to T, Cost: 300 TL

Flight #66 from T to W, Cost: 350 TL

Flight #77 from W to Y, Cost: 400 TL

Flight #88 from Y to R, Cost: 450 TL

Flight #22 from R to X, Cost: 150 TL

Total Cost: 1650 TL


