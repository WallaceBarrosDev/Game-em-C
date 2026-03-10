#include <raylib.h>
#include "player.h"

static Camera2D camera = {0};

Camera2D Camera2D_Get() 
{
  return camera;
}

void Camera2D_Init(Player *player) 
{
  camera.target = player->position;
  camera.offset = (Vector2){GAME_WIDTH / 2.0 - player->size.x / 2, GAME_HEIGHT / 2.0 - player->size.y / 2};
  camera.rotation = 0.0f;
  camera.zoom = 3.0f;
}

typedef struct {
  int x;
  int y;
} Border;

Border border = {150, 75};
void Camera2D_Update(Player *player) 
{
  if(player->position.y > camera.target.y + border.y)
    camera.target.y += player->position.y - border.y;

  if(player->position.y < camera.target.y - border.y)
    camera.target.y -= player->position.y + border.y;

  if(player->position.x > camera.target.x + border.x)
    camera.target.x += player->position.x - border.x;

  if(player->position.x < camera.target.x - border.x)
    camera.target.x -= player->position.x + border.x;

  float wheel = GetMouseWheelMove();
  
  if (wheel > 0) {
    camera.zoom += 0.1f * camera.zoom;
  } else if (wheel < 0) {
    camera.zoom -= 0.1f * camera.zoom;
  }
}
