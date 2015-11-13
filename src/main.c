/*
#include "GL/gl.h"
#include "SDL/SDL.h"

void _start() {
  SDL_Event evnt;
  float theta = 0;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_SetVideoMode(640, 480, 0, SDL_OPENGL);
  SDL_ShowCursor(SDL_DISABLE);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1, 1, -1, 1, 1, 100);
  glMatrixMode(GL_MODELVIEW);

  glEnable(GL_DEPTH_TEST);


  do {
    SDL_PollEvent(&evnt);

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta += 1, 0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES); {
      glVertex3i(1, 1, -10);
      glVertex3i(1, -1, -10);
      glVertex3i(-1, 1, -10);
    } glEnd();
    SDL_GL_SwapBuffers();

  } while (evnt.type != SDL_QUIT);
  SDL_Quit();

  __asm__ ( \
    "movl $1,%eax\n"\
    "xorl %ebx,%ebx\n"\
    "int $128\n"\
  );
}
*/

#include <stdio.h>

void _start() {
  printf("hello, world\n");

  __asm__ ( \
    "movl $1,%eax\n"\
    "xorl %ebx,%ebx\n"\
    "int $128\n"\
  );
}
