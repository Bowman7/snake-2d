#include"raylib.h"
#include"snake.hpp"

//directiojn,1-N,2-S,3-E,4-W
Snake::Snake(){
    posx = 4;
    posy = 1;
    size = 80;
    direction = 2;//south
    dir_switch = false;
    ID = 0;
};
Snake::~Snake(){
  
};
void Snake::DrawHead(){
   int x = posx*size;
   int y = posy*size;
   DrawRectangle(x,y,size,size,PINK);
}
void Snake::Draw(){
    int x = posx*size;
    int y = posy*size;
    DrawRectangle(x,y,size,size,BLUE);
}
//move accordint to own directio
void Snake::MoveToDir(){
  Move(direction);
}
//mvoe south
void Snake::MoveSouth(){
  posy+=1;
  if(posy>=10){
      posy-=1;
  }
};
//move east
void Snake::MoveEast(){
  posx +=1;
  if(posx>=10){
    posx-=1;
  }
}
//west
void Snake::MoveWest(){
  posx-=1;
  if(posx<0){
    posx+=1;
  }
}
//north
void Snake::MoveNorth(){
  posy-=1;
  if(posy<0){
    posy+=1;
  }
}
//move snake
void Snake::Move(int dir){
  if(dir != direction){
    dir_switch = true;
  }
  switch(dir){
  case 1:
    MoveNorth();break;
  case 2:
    MoveSouth();break;
  case 3:
    MoveEast();break;
  case 4:
    MoveWest();break;
  }
}
void Snake::Update(){

}

