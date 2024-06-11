#pragma once

#include"raylib.h"

class Fruit{
public:
  Fruit();
  ~Fruit();
  void Draw();
  void Update();
  int GetPosX(){
    return posx;
  }
  int GetPosY(){
    return posy;
  }
  int GetSize(){
    return size;
  }
  void SetPosX(int x){
    posx = x;
  }
  void SetPosY(int y){
    posy = y;
  }
  
private:
  int posx;
  int posy;
  int size;
};
