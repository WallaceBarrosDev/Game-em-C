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

void Camera2D_Update(Player *player) 
{
  camera.target = (Vector2){
    player->position.x + player->size.x / 2.0f, 
    player->position.y + player->size.y / 2.0f
  };

  float wheel = GetMouseWheelMove();
  
  if (wheel > 0) {
    camera.zoom += 0.1f * camera.zoom;
  } else if (wheel < 0) {
    camera.zoom -= 0.1f * camera.zoom;
  }
}
