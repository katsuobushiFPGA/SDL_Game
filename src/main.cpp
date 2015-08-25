#include <cstdlib>
#include <SDL/SDL.h>

/*!
 * \file
 * \brief mainクラス
 *
 * mainクラスです。
 *
 * \author hiroto
 * \date 2015/08/25
 */ 
int main(int argc, char *argv[]){

  SDL_Surface *gScreenSurface;
  SDL_Event ev;

  // 初期化
  if(SDL_Init(SDL_INIT_VIDEO)){
    printf("初期化に失敗したっぽい\n");
    return 1;
  }

  // ウィンドウのタイトルとアイコン(→キャプション)を設定
  SDL_WM_SetCaption("HELLO SDL!", NULL);

  // ウィンドウの初期化
  gScreenSurface = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE);

  // 終了イベント待ち
  while(1){
    SDL_PollEvent(&ev);
    if(ev.type == SDL_QUIT) break;
  }

  SDL_Quit();

  return 0;
}
