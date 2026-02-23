#include "player.h"
#include "raylib.h"
#include "raymath.h"
#include <stdlib.h>

Player *Player_Init() 
{
  Player *player = malloc(sizeof(Player));

  player->size = (Vector2){32, 32};
  player->speed = 2.0f;
  player->currentFrame = 0;
  player->frameCount = 4;
  player->frameTime = 0.15f;
  player->frameTimer = 0.0f;
  
  player->tex = LoadTexture("./src/assets/game.png");
  player->frameRec = (Rectangle){0, 0, player->size.x, player->size.y};
  player->position.x = GAME_WIDTH / 2.0 - player->size.x / 2;
  player->position.y = GAME_HEIGHT / 2.0 - player->size.y / 2;
  player->direction = DIR_UP;

  return player;
}

void Player_Update(Player *player) {

  Vector2 direction = {0};

  if (IsKeyDown(KEY_RIGHT) && player->position.x < GAME_WIDTH - player->size.x)
  {
    direction.x += 1; 
    player->direction = DIR_RIGHT;
  }

  if (IsKeyDown(KEY_LEFT) && player->position.x > 0)
  {
    direction.x -= 1; 
    player->direction = DIR_LEFT;
  }

  if (IsKeyDown(KEY_DOWN) && player->position.y < GAME_HEIGHT - player->size.y)
  {  
    direction.y += 1; 
    player->direction = DIR_DOWN;
  }

  if (IsKeyDown(KEY_UP) && player->position.y > 0)
  {  
    direction.y -= 1; 
    player->direction = DIR_UP;
  }

  if (direction.x != 0 || direction.y != 0) 
  {
    player->frameTimer += GetFrameTime();

    if (player->frameTimer > player->frameTime) 
    {
      player->frameTimer = 0.0f;
      player->currentFrame++;

      if (player->currentFrame >= player->frameCount) 
      {
        player->currentFrame = 0;
      }
    }

    direction = Vector2Normalize(direction);
    player->position.x += direction.x * player->speed;
    player->position.y += direction.y * player->speed;
  }
  else player->currentFrame = 0;

  player->frameRec.x = player->currentFrame * player->size.x;
  player->frameRec.y = player->direction * player->size.y;
}

void Player_Draw(Player *player) 
{
  DrawTextureRec(player->tex, player->frameRec, player->position, WHITE);
}
