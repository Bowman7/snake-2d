#include"raylib.h"

#define  WIDTH 805
#define HEIGHT 805

#include"grid.cpp"
#include"game.hpp"

int main(){
  InitWindow(WIDTH,HEIGHT,"snakewindow");
  SetTargetFPS(60);

  Grid grid;
  grid.InitGrid();

  Game game;
  
  while(!WindowShouldClose()){

    //handle input
    game.InitInput();
    //update
    game.Update();
    //draw
    BeginDrawing();
    ClearBackground(DARKGREEN);

    //draw grid
    grid.DrawGrid();
    game.Draw();
    
    EndDrawing();
  }

  return 0;  
}
