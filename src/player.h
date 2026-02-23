#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

#define GAME_WIDTH 1200
#define GAME_HEIGHT 600

typedef enum 
{
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT,
    DIR_UP
} Direction;

typedef struct Player {
  Vector2 position;
  Vector2 size;
  Texture2D tex;
  Direction direction;
  Rectangle frameRec;
  int currentFrame;
  int frameCount;
  float frameTime;
  float frameTimer;
  float speed;  
} Player;

Player *Player_Init(void);
void Player_Update(Player *player);
void Player_Draw(Player *player);

Camera2D Camera2D_Get(void);
void Camera2D_Init(Player *player); 
void Camera2D_Update(Player *player);

#endif
