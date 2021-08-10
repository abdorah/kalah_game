#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_version.h>
#include <SDL2/begin_code.h>
#include <SDL2/close_code.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "functions.h"

void swap(char *a, char *b)
{
	if (!a || !b)
		return;

	char temp = *(a);
	*(a) = *(b);
	*(b) = temp;
}

void reverse(char *str, int length)
{
	int start = 0;
	int end = length - 1;
	while (start < end)
	{
		swap((str + start), (str + end));
		start++;
		end--;
	}
}

char *itoa(int num, char *str, int base)
{
	int i = 0;
	bool isNegative = false;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	if (num < 0 && base == 10)
	{
		isNegative = true;
		num = -num;
	}

	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	if (isNegative == true)
		str[i++] = '-';

	str[i] = '\0';
	reverse(str, i);
	return str;
}

void renderTexture12(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
	int w, h;
	SDL_QueryTexture(tex, NULL, NULL, &w, &h);
	renderTexture(tex, ren, x, y, w, h);
}
SDL_Texture *renderText(char *message, char *fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer)
{
	TTF_Font *font = TTF_OpenFont(fontFile, fontSize);
	SDL_Surface *surf = TTF_RenderText_Blended(font, message, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}
SDL_Texture *loadTexture(char *file, SDL_Renderer *ren)
{
	SDL_Texture *texture = NULL;
	SDL_Surface *loadedImage = SDL_LoadBMP(file);
	texture = SDL_CreateTextureFromSurface(ren, loadedImage);
	SDL_FreeSurface(loadedImage);
	return texture;
}
void Score_DISPALYRED(char *message, int x, int y, SDL_Renderer *renderer)
{
	SDL_Color color = {255, 55, 0, 255};
	SDL_Texture *texture = renderText(message, "Andrographis.ttf", color, 100, renderer);
	renderTexture12(texture, renderer, x, y);
}
void Score_DISPALYBLU(char *message, int x, int y, SDL_Renderer *renderer)
{
	SDL_Color color = {0, 128, 255, 255};
	SDL_Texture *texture = renderText(message, "Andrographis.ttf", color, 100, renderer);
	renderTexture12(texture, renderer, x, y);
}
int Is_It_The_End(int joueur1[7], int joueur2[7], int ini)
{
	int TesT1 = 0, TesT2 = 0;
	int half = ini * 6;
	for (int j = 0; j < 6; j++)
	{
		if (joueur1[j] != 0)
		{
			TesT1 = 1;
		}
		if (joueur2[j] != 0)
		{
			TesT2 = 1;
		}
	}
	if (TesT1 == 0 || TesT2 == 0 || joueur1[6] > half || joueur2[6] > half)
	{
		return 0;
	}
	return 1;
}
void init(int a, int j1[7], int j2[7])
{
	for (int i = 0; i < 6; i++)
	{
		j1[i] = a;
		j2[i] = a;
	}
	j1[6] = 0;
	j2[6] = 0;
}
void ChangeTurn(int *t)
{
	if ((*t) == 0)
	{
		(*t) = 1;
	}
	else
	{
		(*t) = 0;
	}
}
void one_range(int joueur_actif[7], int joueur_passif[7], int case_num, int *turn)
{
	int i = case_num;
	int a, final_case = 0;
	int k = joueur_actif[i];
	char player[12] = "active";
	joueur_actif[i] = 0;
	for (int j = 1; j <= k; j++)
	{
		a = (j + i) % 13;
		if (a < 7)
		{
			final_case = a;
			strcpy(player, "active");
			joueur_actif[a] = joueur_actif[a] + 1;
		}
		else
		{
			final_case = a % 7;
			strcpy(player, "passive");
			joueur_passif[final_case]++;
		}
	}
	if (final_case != 6)
	{
		if (strcmp(player, "active") == 0)
		{
			if (((joueur_actif[final_case]) == 1) && joueur_passif[5 - final_case] != 0)
			{
				joueur_actif[6] += joueur_passif[5 - final_case] + 1;
				joueur_passif[5 - final_case] = 0;
				joueur_actif[final_case] = 0;
			}
			else
			{
				ChangeTurn(turn);
			}
		}
		else
		{

			ChangeTurn(turn);
		}
	}
}
void tourjouer(int j, SDL_Renderer *renderer)
{
	if (j == 1)
	{
		Score_DISPALYBLU("X", 780, 255, renderer);
	}
	else
	{
		Score_DISPALYRED("X", 190, 255, renderer);
	}
}
void Loadcase(int a, int i, int j, SDL_Renderer *renderer)
{

	char b[10];
	itoa(a, b, 10);
	switch (j)
	{
	case 2:
		Score_DISPALYRED(b, 190 + 115 * (5 - i), 50, renderer);

		break;
	case 1:
		Score_DISPALYBLU(b, 190 + 115 * i, 420, renderer);
		break;
	}
}
void LoadAll(struct Partie P, SDL_Renderer *renderer, int turn)
{

	SDL_RenderClear(renderer);
	SDL_Texture *texture = loadTexture("GameBoard.bmp", renderer);
	SDL_Texture *retour_icon = loadTexture("undoAction.bmp", renderer);
	renderTexture12(texture, renderer, 0, 0);
	renderTexture12(retour_icon, renderer, 425, 223);
	tourjouer(turn, renderer);
	for (int i = 0; i < 6; i++)
	{
		Loadcase(P.joueur1[i], i, 1, renderer);
		Loadcase(P.joueur2[i], i, 2, renderer);
	}

	char b[10];
	itoa(P.joueur2[6], b, 10);
	Score_DISPALYRED(b, 60, 260, renderer);

	itoa(P.joueur1[6], b, 10);
	Score_DISPALYBLU(b, 880, 260, renderer);
	SDL_RenderPresent(renderer);
}
void rewrite(struct Partie P)
{
	FILE *fptr;
	fptr = fopen("score_saving_file.txt", "w+");
	for (int j = 0; j < 7; j++)
	{
		fprintf(fptr, "%d ", P.joueur2[6 - j]);
	}
	for (int j = 0; j < 7; j++)
	{
		fprintf(fptr, "%d ", P.joueur1[j]);
	}
	fclose(fptr);
}
void read(Partie partie)
{
	FILE *file = fopen("score_saving_file.txt", "r");
	int num;
	int count = 0;
	while (fscanf(file, "%d ", &num) != EOF)
	{
		printf("%d ", num);
		if (count > 6)
		{
			partie.joueur1[13-count] = num;
		}
		else
		{
			partie.joueur2[count] = num;
		}
		++count;
		if (count==14)
		{
			break;
		}	
	}
	fclose(file);
}
void congra(int t, int *n, struct Partie P, SDL_Renderer *Ren)
{
	if (!t)
	{
		if (P.joueur1[6] < P.joueur2[6])
		{
			SDL_RenderClear(Ren);
			SDL_Texture *texture = loadTexture("Player2Win.bmp", Ren);
			renderTexture12(texture, Ren, 0, -30);
			SDL_RenderPresent(Ren);
			SDL_Delay(6000);
		}
		if (P.joueur1[6] > P.joueur2[6])
		{
			SDL_RenderClear(Ren);
			SDL_Texture *texture = loadTexture("Player1Win.bmp", Ren);
			renderTexture12(texture, Ren, 0, -30);
			SDL_RenderPresent(Ren);
			SDL_Delay(6000);
		}
		*n = 0;
	}
}
int isdeffirent(Partie p, Partie t)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		if (p.joueur1 != t.joueur1 || p.joueur2 != t.joueur2)
		{
			return 1;
		}
	}
	return 0;
}