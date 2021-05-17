#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_version.h>
#include <SDL2/begin_code.h>
#include <SDL2/close_code.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "functions.h"
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
Partie P ;
int turn = 1, oldturn[100];
int case_n=5;
Partie Stack[100];
int tournbr = 0;

int main( int argc, char* args[] ){
	int quit = 0;
	int t ;
	int k = 0;
	char* b = "4";
	SDL_Event e;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_Window* window = SDL_CreateWindow("Kalah",100,100,1024,600,SDL_WINDOW_SHOWN);
    SDL_Renderer *Ren=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_RenderClear(Ren);
	SDL_Texture* texture = loadTexture("OptionsMenu.bmp", Ren);
	renderTexture12(texture, Ren, 0, 0);
	SDL_RenderPresent(Ren);
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				if (k==0) {
					t = 257;
					if (e.button.y > t&& e.button.y < t + 60 && e.button.x < 625 && e.button.x > 397) {
						SDL_RenderClear(Ren);
						SDL_Texture* texture = loadTexture("InitialisationBoard.bmp", Ren);
						SDL_Color color = { 255,255,255,255 };
						renderTexture12(texture, Ren, 0, 0);
						renderTexture12(renderText(b, "Andrographis.ttf", color, 70, Ren), Ren, 630, 285);
						SDL_RenderPresent(Ren);
						k = 1;
					}
					if (e.button.y > t + 78 && e.button.y < t + 138 && e.button.x < 625 && e.button.x > 397) {	
						read(P.joueur1, P.joueur2);
						if (Is_It_The_End(P.joueur1, P.joueur2, atoi(b))) {
							quit = 1;
						}
					}
					if (e.button.y > t + 148 && e.button.y < t + 208 && e.button.x < 625 && e.button.x > 397) {
						SDL_DestroyRenderer(Ren);
						SDL_DestroyWindow(window);
						SDL_Quit();
						exit(0);
					}
				}
				else {
					if (e.button.y > 294 && e.button.y <361 && e.button.x < 475 && e.button.x > 213) {
						init(atoi(b), P.joueur1, P.joueur2);
						quit = 1;
					}
					if (e.button.y > 283 && e.button.y < 317 && e.button.x < 564 && e.button.x > 510) {
						if (atoi(b) < 10) {
							itoa(atoi(b) + 1, b, 10);
							SDL_RenderClear(Ren);
							SDL_Texture* texture = loadTexture("InitialisationBoard.bmp", Ren);
							SDL_Color color = { 255,255,255,255 };
							renderTexture12(texture, Ren, 0, 0);
							renderTexture12(renderText(b, "Andrographis.ttf", color, 70, Ren), Ren, 630, 285);
							SDL_RenderPresent(Ren);
						}
					}
					if (e.button.y > 335 && e.button.y < 369 && e.button.x < 564 && e.button.x > 510) {
						if (atoi(b) > 1) {
							itoa(atoi(b) - 1, b, 10);
							SDL_RenderClear(Ren);
							SDL_Texture* texture = loadTexture("InitialisationBoard.bmp", Ren);
							SDL_Color color = { 255,255,255,255 };
							renderTexture12(texture, Ren, 0, 0);
							renderTexture12(renderText(b, "Andrographis.ttf", color, 70, Ren), Ren, 630, 285);
							SDL_RenderPresent(Ren);
						}
					}
				}
			}
			if (e.type == SDL_QUIT) {
				SDL_DestroyRenderer(Ren);
				SDL_DestroyWindow(window);
				SDL_Quit();
				exit(0);
			}
	    }
	}
	Stack[tournbr] = P;
	oldturn[tournbr] = turn;
	if (quit == 1) {
		LoadAll(P, Ren, turn);
		t = 0;
		quit = 0;
	}
    while (!quit&&!t){
		congra(Is_It_The_End(P.joueur1, P.joueur2, atoi(b) ), &t, P, Ren);
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = 1;
            }          
            if (e.type == SDL_MOUSEBUTTONDOWN){

                        if (turn==1){
                            if (e.button.y>420 && e.button.y<535 && e.button.x >190 && e.button.x<270 && P.joueur1[0]!=0) {
                                one_range(P.joueur1,P.joueur2,0,&turn);
								tournbr++;
								if (isdeffirent(Stack[tournbr], P)) {
									Stack[tournbr] = P;
									oldturn[tournbr] = turn;
								}
                            }
                            if (e.button.y>420 && e.button.y<535 && e.button.x <385 && e.button.x>305 && P.joueur1[1] != 0) {
                                one_range(P.joueur1,P.joueur2,1,&turn);
								tournbr++;
								if (isdeffirent(Stack[tournbr], P)) {
									oldturn[tournbr] = turn;
									Stack[tournbr] = P;
									}
                                }
                            if (e.button.y>420 && e.button.y<535 && e.button.x <500 && e.button.x>420 && P.joueur1[2] != 0) {
                                one_range(P.joueur1,P.joueur2,2,&turn);
								tournbr++;
								if (isdeffirent(Stack[tournbr], P)) {
									Stack[tournbr] = P;
									oldturn[tournbr] = turn;
								}
                                }
                            if (e.button.y>420 && e.button.y<535 && e.button.x <615 && e.button.x>535 && P.joueur1[3] != 0) {
                                one_range(P.joueur1,P.joueur2,3,&turn);
								tournbr++;
								if (isdeffirent(Stack[tournbr], P)) {
									Stack[tournbr] = P;
									oldturn[tournbr] = turn;
								}
                                }
                            if (e.button.y>420 && e.button.y<535 && e.button.x <730 && e.button.x>650 && P.joueur1[4] != 0) {
                                one_range(P.joueur1,P.joueur2,4,&turn);
								tournbr++;
								if (isdeffirent(Stack[tournbr], P)) {
									Stack[tournbr] = P;
									oldturn[tournbr] = turn;
								}
								
                                }
                            if (e.button.y>420 && e.button.y<535 && e.button.x <845 && e.button.x>765 && P.joueur1[5] != 0) {
                                one_range(P.joueur1,P.joueur2,5,&turn);
								tournbr++;

								if (isdeffirent(Stack[tournbr], P)) {
									Stack[tournbr] = P;
									oldturn[tournbr] = turn;
								}
								}
                        }
                         else{

                            if (e.button.y>50 && e.button.y<165 && e.button.x >190 && e.button.x<270 && P.joueur2[5] != 0) {
                                one_range(P.joueur2,P.joueur1,5,&turn);
								tournbr++;

								if (isdeffirent(Stack[tournbr], P)) {
									Stack[tournbr] = P;
									oldturn[tournbr] = turn;
								}
								}
                            if (e.button.y>50 && e.button.y<165 && e.button.x <385 && e.button.x>305 && P.joueur2[4] != 0) {
                                one_range(P.joueur2,P.joueur1,4,&turn);
								tournbr++;

								if (isdeffirent(Stack[tournbr], P)) {
									Stack[tournbr] = P;
									oldturn[tournbr] = turn;
								}
								}
                            if (e.button.y>50 && e.button.y<165 && e.button.x <500 && e.button.x>420 && P.joueur2[3] != 0) {
                                one_range(P.joueur2,P.joueur1,3,&turn);
								tournbr++;

								if (isdeffirent(Stack[tournbr], P)) {
									Stack[tournbr] = P;
									oldturn[tournbr] = turn;
								}
								}
                            if (e.button.y>50 && e.button.y<165 && e.button.x <615 && e.button.x>535 && P.joueur2[2] != 0) {
                                one_range(P.joueur2,P.joueur1,2,&turn);
								tournbr++;
								if (isdeffirent(Stack[tournbr], P)) {
									Stack[tournbr] = P;
									oldturn[tournbr] = turn;
								}
								
								}
                            if (e.button.y>50 && e.button.y<165 && e.button.x <730 && e.button.x>650 && P.joueur2[1] != 0) {
                                one_range(P.joueur2,P.joueur1,1,&turn);
								tournbr++;
								if (isdeffirent(Stack[tournbr], P)) {
									Stack[tournbr] = P;
									oldturn[tournbr] = turn;
								}
								}
                            if (e.button.y>50 && e.button.y<165 && e.button.x <845 && e.button.x>765 && P.joueur2[0] != 0) {
                                one_range(P.joueur2,P.joueur1,0,&turn);
								tournbr++;
								if (isdeffirent(Stack[tournbr], P)) {
									Stack[tournbr] = P;
									oldturn[tournbr] = turn;
								}
								}
							
                         }

						if (e.button.y > 253 && e.button.y < 350 && e.button.x < 660  && e.button.x > 455 && (tournbr >=1 && tournbr < 100)) {
							tournbr--;
							turn = oldturn[tournbr];
							P = Stack[tournbr];
						}
						
						LoadAll(P, Ren, turn);

			}
			
        }
		rewrite(P);
    }
    SDL_DestroyRenderer(Ren);
    SDL_DestroyWindow(window);
    SDL_Quit();
	return 0;
}