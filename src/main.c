#include "raylib.h"
#include "player.h"
#include <stdlib.h>

int main() {

  InitWindow(GAME_WIDTH, GAME_HEIGHT, "Game em C com raylib");
  SetTargetFPS(60);
  
  Player *player = Player_Init();
  Camera2D_Init(player);

  while (!WindowShouldClose()) {

    Player_Update(player);
    Camera2D_Update(player);

    BeginDrawing();
      ClearBackground(RAYWHITE);
      BeginMode2D(Camera2D_Get());
       Player_Draw(player);
      EndMode2D();
    EndDrawing();
  }

  free(player);
  CloseWindow();
  return 0;
}
