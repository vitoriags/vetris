#include <SDL.h>
#include <stdio.h>

// dimen��es da janela
const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

SDL_Window* window = NULL; // declarando a janela sdl
SDL_Surface* screenSurface = NULL; // declarando uma superficie de janela sdl (2D)

void init();
void close();


void init() {
	// criando a janela || window = SDL_CreateWindow = ("nome da jenela", posi��o x, posi��o y, largura, altura, aviso de cria��o: mostra quando uma janela � criada)
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARGURA_TELA, ALTURA_TELA, SDL_WINDOW_SHOWN);
	screenSurface = SDL_GetWindowSurface(window); // obtendo a superficie da janela
}

void close() {
	SDL_DestroyWindow(window); // destr�i a janela para liberar a mem�ria
	SDL_Quit(); // fechando o sdl
}


int main(int argc, char* args[]) {

	init();

	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0xFF)); // pintando a superficie de azul claro
	SDL_UpdateWindowSurface(window); // atualizando a janela (renderiza��o)
	SDL_Delay(5000); // fechar depois de 5 segundos
	close();

	return 0;
}