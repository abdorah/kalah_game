#ifndef  FUNCTIONS_H_
#define  FUNCTIONS_H_
typedef enum{false, true} bool;
void swap(char *a, char *b);
void reverse(char *str, int length);
char* itoa(int num, char* str, int base);
typedef struct Partie{
	int joueur1[7];
	int joueur2[7];
}Partie; 
void renderTexture12(SDL_Texture* tex, SDL_Renderer* ren, int x, int y);
SDL_Texture* renderText(char* message, char* fontFile,SDL_Color color, int fontSize, SDL_Renderer* renderer);
void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y, int w, int h);
SDL_Texture* loadTexture(char* file, SDL_Renderer* ren);
void Score_DISPALYRED(char* message, int x, int y, SDL_Renderer* renderer);
void Score_DISPALYBLU(char* message, int x, int y, SDL_Renderer* renderer);
int Is_It_The_End(int joueur1[7], int joueur2[7],int ini);
void init(int a, int j1[7], int j2[7]);
void ChangeTurn(int* t);
void one_range(int joueur_actif[7], int joueur_passif[7], int case_num, int * turn);
void Loadcase(int a, int i, int j, SDL_Renderer* renderer);
void LoadAll(struct Partie P, SDL_Renderer* renderer,int turn);
void rewrite(struct Partie P);
void read(int joueur1[7], int joueur2[7]);
void tourjouer(int j, SDL_Renderer* renderer);
void congra(int t,int *n, struct Partie P, SDL_Renderer* Ren);
int isdeffirent(Partie p, Partie t);
#endif