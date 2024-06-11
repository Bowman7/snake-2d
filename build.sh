#!/bin/bash

g++ main.cpp game.cpp fruit.cpp grid.cpp snake.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -g
