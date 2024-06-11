#pragma once

#include"raylib.h"
#include<vector>

#include<iostream>
#include<random>

#include"snake.hpp"
#include"fruit.hpp"

class Game{
public:
  Game();
  ~Game();
  void InitInput();
  void HandleInput();
  void Update();
  void Draw();
  bool EventTriggered(double);
  void  CheckCollision();
  void AddBody();
  void NewFruitPos();
  void GetRandPos();
  int GetRandomNum();
private:
  int f_ValX;
  int f_ValY;
  Fruit fruit;
  Snake v_snake[100];
  double lastUpdatedTime = 0.0;
  int BodyCount=0;
};
