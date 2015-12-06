#include <cstdlib>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define BPP 32

int draw(SDL_Surface *image, SDL_Rect *rect1, SDL_Rect *rect2);

////////////////////////////!
//! \file
//! \brief mainクラス
//!
//! mainクラスです。
//!
//! \author hiroto
//! \date 2015/08/25
///////////////////////////
int main(int argc, char *argv[]){

  SDL_Surface *gScreenSurface;
  SDL_Rect rect,scr_rect,rect_tmp;
  SDL_Event ev;

  // 初期化
  if(SDL_Init(SDL_INIT_VIDEO)){
    printf("初期化失敗\n");
    return 1;
  }

  // ウィンドウのタイトルとアイコン(→キャプション)を設定
  SDL_WM_SetCaption("HELLO SDL!", NULL);

  // ウィンドウの初期化
  gScreenSurface = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE);
  
  // 画像読み込み
  gScreenSurface = IMG_Load("../img/character.png");
  
  // 白い色を透過色にする
    SDL_SetColorKey(gScreenSurface, SDL_SRCCOLORKEY, SDL_MapRGB(gScreenSurface->format, 255, 255, 255));
    gScreenSurface = SDL_DisplayFormat(gScreenSurface);  
  // 画像の矩形情報設定 
    rect.x = 0;
    rect.y = 0;
    rect.w = 38;
    rect.h = 40;

    /* 画像配置位置情報の設定 */
    scr_rect.x = 0;
    scr_rect.y = 0;

    /* サーフェスの複写 */
    SDL_BlitSurface(gScreenSurface, &rect, SDL_GetVideoSurface(), &scr_rect);

    /* サーフェスフリップ */
    SDL_Flip(SDL_GetVideoSurface());
    
   int exit_prg = 0;
   /* イベントループ */
    while(exit_prg == 0){   
        if(SDL_PollEvent(&ev)){
            switch(ev.type){
            case SDL_KEYDOWN:
                switch(ev.key.keysym.sym){
                case SDLK_UP:
                    rect_tmp.y -= rect.h;
                    break;
                case SDLK_DOWN:
                    rect_tmp.y += rect.h;
                    break;
                case SDLK_RIGHT:
                    rect_tmp.x += rect.w;
                    break;
                case SDLK_LEFT:
                    rect_tmp.x -= rect.w;
                    break;
                case SDLK_ESCAPE:
                    exit_prg = 1;
                    break;
                default:
                    break;
                }

                /* 移動可能範囲の判定 */
                if(rect_tmp.x >= 0 && rect_tmp.x + rect.w <= WINDOW_WIDTH && rect_tmp.y >= 0 && rect_tmp.y + rect.h <= WINDOW_HEIGHT){
                    scr_rect = rect_tmp;
                    /* 描画 */
                    draw(gScreenSurface, &rect, &scr_rect);
                }
                else {
                    rect_tmp = scr_rect;
                }
                break;
            default:
                break;
            }
        }
        SDL_Delay(1);
    }
  SDL_FreeSurface(gScreenSurface); 
  SDL_Quit();

  return 0;
}

int draw(SDL_Surface *image, SDL_Rect *rect1, SDL_Rect *rect2){
    SDL_Rect window_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_Surface *video_surface;
    
    video_surface = SDL_GetVideoSurface();

    /* 背景色塗りつぶし */
    SDL_FillRect(video_surface, &window_rect, SDL_MapRGB(video_surface->format, 0, 0, 0));

    /* サーフェスの複写 */
    SDL_BlitSurface(image, rect1, video_surface, rect2);

    /* サーフェスフリップ */
    SDL_Flip(video_surface);

    return 0;
}
