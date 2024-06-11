#pragma once

#include"raylib.h"

class Snake{
public:
  Snake();
  ~Snake();
  void Draw();
  void DrawHead();
  void Update();
  void Move(int);
  void MoveSouth();
  void MoveEast();
  void MoveNorth();
  void MoveWest();
  void MoveToDir();
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
  int GetDir(){
    return direction;
  }
  void SetDir(int dir){
    direction = dir;
  }

  int GetID(){
    return ID;
  }
  void SetID(int id){
    ID = id;
  }
  
private:
  int posx;
  int posy;
  int size;
  int direction;
  bool dir_switch;
  int ID;
};
