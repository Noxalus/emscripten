#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <assert.h>
#include <emscripten.h>

void loop() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_MOUSEMOTION: {
        printf("motion => {x: %d, y: %d, xrel: %d, yrel: %d}\n",
          event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel);

        break;
      }
      case SDL_MOUSEBUTTONDOWN: {
        printf("button down => {button: %d, state: %d, x: %d, y: %d}\n", 
          event.button.button, event.button.state, event.button.x, event.button.y);

        break;
      }
      case SDL_MOUSEBUTTONUP: {
        printf("button up => {button: %d, state: %d, x: %d, y: %d}\n", 
          event.button.button, event.button.state, event.button.x, event.button.y);

        break;
      }
      case SDL_MOUSEWHEEL: {
        printf("wheel => {timestamp: %d, windowID: %d, which: %d, x: %d, y: %d}\n", 
          event.wheel.timestamp, event.wheel.windowID, event.wheel.which, event.wheel.x, event.wheel.y);

        break;
      }
    }
  }
}

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface *screen = SDL_SetVideoMode(600, 450, 32, SDL_HWSURFACE);

  printf("Please use the mouse over the canvas.\n");

  emscripten_set_main_loop(loop, 0, 0);

  return 0;
}
