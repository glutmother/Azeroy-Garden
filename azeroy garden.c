#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main(int argc, char *argv[]) {
	
	srand(time(0));
	char mapa_vila[11][11];
	char mapa_masmorra1[11][11];
	char mapa_masmorra2[16][16];
	char mapa_masmorra3[26][26];
	int linhas;
	int colunas;
	int opcao = 0;
	int fase = 0;
	int menu = 1;
	int jogador_vidas = 3;
	char jogador = '^';
	char parede = '*';
	char espinho = '#';
	char caixa = 'k';
	char botao = 'O';
	char porta = 'D';
	char chave = '@';
	char escada = 'L';
	char monstro1 = 'X';
	char monstro2 = 'Y';
	char boss = 'Z';
	char npc = '<';
	int arma = 0;
	int x = 5;
	int y = 9;
	int tem_chave = 0;
	int x_monstro = 5;
	int y_monstro = 1;
	int x_chave = 0;
	int y_chave = 0;
	
	while(menu == 1){
		printf("<= Azeroy Garden =>\n");
		printf("***************************************\n");
		printf("1 - Jogar\n");
		printf("2 - Tutorial\n");
		printf("3 - Sair\n");
		printf("***************************************\n");
		scanf("%d", &opcao);
		if(opcao == 1){
			break;
		}
		if(opcao == 2){
			system("cls");
			printf("Bem-vindo(a)(e) ao Azeroy Garden! Este jogo se passa na vila de Azeroy, uma vila pacifica e bela, porem com poucos habitantes. Mas, um dia, monstros atacaram o jardim da vila, considerado o mais belo da regiao, e se esconderam dentro das masmorras que ha debaixo da vila. Sua missao sera derrota-los e vingar os habitantes da vila. Boa Sorte!\n\n");
			system("pause");
			system("cls");
			printf("Simbolos:\n\n");
			printf("< - Jogador olhando para a esquerda\n");
			printf("^ - Jogador olhando para cima\n");
			printf("> - Jogador olhando para a direita\n");
			printf("v - Jogador olhando para baixo\n");
			printf("* - Parede: O jogador nao pode passar\n");
			printf("# - Espinho: O jogador morre ao passar por cima\n");
			printf("k - Caixa: O jogador nao pode passar, mas pode ser destruida com ataque\n");
			printf("O - Botao: Executa uma acao a ser pressionado\n");
			printf("D - Porta fechada: O jogador nao pode passar\n");
			printf("@ - Chave: Abre uma porta fechada ao interagir\n");
			printf("= - Porta aberta: O jogador pode passar\n");
			printf("L - Escada: Leva o jogador a proxima fase\n");
			printf("X - Monstro tipo 1\n");
			printf("Y - Monstro tipo 2\n");
			printf("Z - Boss final\n\n");
			system("pause");
			system("cls");
			printf("Controles:\n\n");
			printf("w - Move o jogador para cima e altera o simbolo do jogador para ^\n");
			printf("a - Move o jogador para a esquerda e altera o simbolo do jogador para <\n");
			printf("s - Move o jogador para baixo e altera o simbolo do jogador para v\n");
			printf("d - Move o jogador para a direita e altera o simbolo do jogador para >\n");
			printf("i - Interage com o objeto que esta a frente do jogador\n");
			printf("o - O jogador realiza um ataque na celula a sua frente\n\n");
			system("pause");
			system("cls");
		}
		if(opcao < 1 || opcao > 3){
			while(opcao < 1 || opcao > 3){
			printf("Escolha uma opcao valida: ");
			scanf("%d", &opcao);
			}
		}
		if(opcao == 3){
			printf("Jogo feito por Isabella Barbosa\n\n");
			printf("Byeeee! :3");
			return 0;
		}
	}
	system("cls");
	while(opcao == 1 && fase == 0){
		printf("Vidas: &d", jogador_vidas);
		for(linhas = 0; linhas<11; linhas++){
			for(colunas = 0; colunas<11; colunas++){
				if(linhas == 0 || colunas == 0 || colunas == 10 || linhas == 10){
					mapa_vila[linhas][colunas] = '*';
				}else{
					mapa_vila[linhas][colunas] = ' ';
					mapa_vila[y][x] = jogador;
					mapa_vila[2][1] = parede;
					mapa_vila[2][2] = parede;
					mapa_vila[1][2] = porta;
					mapa_vila[1][1] = escada;
					mapa_vila[1][9] = npc;
					
				}
				if(x == 10 && jogador == '>'){
					jogador = '>';
					x = x-1;
					mapa_vila[y][x] == jogador;
				}else if(x == 0 && jogador == '<'){
					jogador = '<';
					x = x+1;
					mapa_vila[y][x] == jogador;
				}else if(y == 10 && jogador == 'v'){
					jogador = 'v';
					y = y-1;
					mapa_vila[y][x] == jogador;
				}else if(y == 0 && jogador == '^'){
					jogador = '^';
					y = y+1;
					mapa_vila[y][x] == jogador;
				}else if(x == 9 && y == 1 && jogador == '>'){
					jogador = '>';
					x = x-1;
					mapa_vila[y][x] == jogador;
				}else if(x == 9 && y == 1 && jogador == '^'){
					jogador = '^';
					y = y+1;
					mapa_vila[y][x] == jogador;
				}else if(x == 2 && y == 1 && mapa_vila[1][2] == 'D' && jogador == '<'){
					jogador = '<';
					x = x+1;
					mapa_vila[y][x] == jogador;
				}else if(x == 2 && y == 2 && jogador == '<'){
					jogador = '<';
					x = x+1;
					mapa_vila[y][x] == jogador;
				}else if(x == 1 && y == 2 && jogador == '^'){
					jogador = '^';
					y = y+1;
					mapa_vila[y][x] == jogador;
				}else if(x == 2 && y == 2 && jogador == '^'){
					jogador = '^';
					y = y+1;
					mapa_vila[y][x] == jogador;
				}else if(x == 1 && y == 1){
					fase = 1;
				}
		}
	}
		for(linhas = 0; linhas<11; linhas++){
			for(colunas = 0; colunas<11; colunas++){
				printf("%c", mapa_vila[linhas][colunas]);
			}
			printf("\n");
		}
		int mov_jogador = getch();
		switch(mov_jogador){
			case 'w':
				jogador = '^';
				y = y-1;
				mapa_vila[y][x] = jogador;
				break;
			case 'a':
				jogador = '<';
				x = x-1;
				mapa_vila[y][x] = jogador;
				break;
			case 's':
				jogador = 'v';
				y = y+1;
				mapa_vila[y][x] = jogador;
				break;
			case 'd':
				jogador = '>';
				x = x+1;
				mapa_vila[y][x] = jogador;
				break;
			case 'i':
				if(x+1 == 9 && y == 1 || x == 9 && y == 2){
					printf("Eh muito perigoso ir sem equipamento! Escolha uma arma:\n");
					printf("1 - Espada\n");
					printf("2 - Arco e Flecha\n");
					printf("3 - Cajado\n");
					scanf("%d", &arma);
					if(arma != 1 && arma != 2 && arma != 3){
						while(arma != 1 && arma != 2 && arma != 3){
						printf("Insira um valor valido: ");
						scanf("%d", &arma);
						}
					}
					if(arma == 1){
						printf("Otima escolha! A espada eh otima para combate corpo a corpo.\nAlias, tome esta chave, voce ira precisar para abrir a porta da masmorra.\n\n");
					}else if(arma == 2){
						printf("Otima escolha! O arco eh otimo para manter distancia dos seus inimigos.\nAlias, tome esta chave, voce ira precisar para abrir a porta da masmorra.\n\n");
					}else if(arma == 3){
						printf("Otima escolha! O cajado eh otimo para matar varios inimigos proximos de uma vez so.\nAlias, tome esta chave, voce ira precisar para abrir a porta da masmorra.\n\n");
					}
					system("pause");
					tem_chave = 1;
				}
				if(x-1 == 2 && y == 1 && jogador == '<' && tem_chave == 1){
					porta = '=';
				}
				break;
		}
		system("cls");
	}
	
	while(opcao == 1 && fase == 1){
		printf("Vidas: &d", jogador_vidas);
		for(linhas = 0; linhas<11; linhas++){
			for(colunas = 0; colunas<11; colunas++){
				if(linhas == 0 || colunas == 0 || colunas == 10 || linhas == 10){
					mapa_masmorra1[linhas][colunas] = '*';
				}else{
					mapa_masmorra1[linhas][colunas] = ' ';
					mapa_masmorra1[y][x] = jogador;
					mapa_masmorra1[1][9] = escada;
					mapa_masmorra1[2][9] = porta;
					mapa_masmorra1[2][8] = parede;
					mapa_masmorra1[1][8] = parede;
					mapa_masmorra1[1][5] = caixa;
				}if(x == 10 && jogador == '>'){
					jogador = '>';
					x = x-1;
					mapa_masmorra1[y][x] == jogador;
				}else if(x == 0 && jogador == '<'){
					jogador = '<';
					x = x+1;
					mapa_masmorra1[y][x] == jogador;
				}else if(y == 10 && jogador == 'v'){
					jogador = 'v';
					y = y-1;
					mapa_masmorra1[y][x] == jogador;
				}else if(y == 0 && jogador == '^'){
					jogador = '^';
					y = y+1;
					mapa_masmorra1[y][x] == jogador;
				}else if(y == 1 && x == 5 && jogador == '^' && caixa == 'k' || y == 1 && x == 5 && jogador == '^' && caixa == '@'){
					y = y+1;
					mapa_masmorra1[y][x] == jogador;
				}else if(y == 1 && x == 5 && jogador == '<' && caixa == 'k' || y == 1 && x == 5 && jogador == '<' && caixa == '@'){
					x = x+1;
					mapa_masmorra1[y][x] == jogador;
				}else if(y == 1 && x == 5 && jogador == '>' && caixa == 'k' || y == 1 && x == 5 && jogador == '>' && caixa == '@'){
					x = x-1;
					mapa_masmorra1[y][x] == jogador;
				}else if(y == 2 && x == 8 && jogador == '>'){
					x = x-1;
					mapa_masmorra1[y][x] == jogador;
				}else if(y == 2 && x == 8 && jogador == '^'){
					y = y+1;
					mapa_masmorra1[y][x] == jogador;
				}else if(y == 1 && x == 8 && jogador == '>'){
					x = x-1;
					mapa_masmorra1[y][x] == jogador;
				}else if(y == 2 && x == 9 && porta == 'D'){
					y = y+1;
					mapa_masmorra1[y][x] == jogador;
				}else if(y == 1 && x == 9){
					fase = 2;
				}
			}
		}
		for(linhas = 0; linhas<11; linhas++){
			for(colunas = 0; colunas<11; colunas++){
				printf("%c", mapa_masmorra1[linhas][colunas]);
			}
			printf("\n");
		}
		int mov_jogador = getch();
		switch(mov_jogador){
			case 'w':
				jogador = '^';
				y = y-1;
				mapa_masmorra1[y][x] = jogador;
				break;
			case 'a':
				jogador = '<';
				x = x-1;
				mapa_masmorra1[y][x] = jogador;
				break;
			case 's':
				jogador = 'v';
				y = y+1;
				mapa_masmorra1[y][x] = jogador;
				break;
			case 'd':
				jogador = '>';
				x = x+1;
				mapa_masmorra1[y][x] = jogador;
				break;
			case 'i':
				if(mapa_masmorra1[y-1][x] == caixa && caixa == '@' && jogador == '^'){
					tem_chave = 1;
					caixa = ' ';
				}else if(mapa_masmorra1[y][x+1] == caixa && caixa == '@' && jogador == '>'){
					tem_chave = 1;
					caixa = ' ';
				}else if(mapa_masmorra1[y][x-1] == caixa && caixa == '@' && jogador == '<'){
					tem_chave = 1;
					caixa = ' ';
				}else if(y-1 == 2 && x == 9 && porta == 'D' && jogador == '^' && tem_chave == 1){
					porta = '=';
				}
				break;
			case 'o':
				if(arma == 1){
					if(jogador == '>'){
						if(mapa_masmorra1[y][x+1] == caixa || mapa_masmorra1[y][x+2] == caixa || mapa_masmorra1[y+1][x+1] == caixa || mapa_masmorra1[y+1][x+2] == caixa || mapa_masmorra1[y-1][x+1] == caixa || mapa_masmorra1[y-1][x+2] == caixa){
							caixa = '@';
						}
					}else if(jogador == '^'){
						if(mapa_masmorra1[y-1][x] == caixa || mapa_masmorra1[y-2][x] == caixa || mapa_masmorra1[y-1][x+1] == caixa || mapa_masmorra1[y-2][x+1] == caixa || mapa_masmorra1[y-1][x-1] == caixa || mapa_masmorra1[y-2][x-1] == caixa){
							caixa = '@';
						}
					}else if(jogador == 'v'){
						if(mapa_masmorra1[y+1][x] == caixa || mapa_masmorra1[y+2][x] == caixa || mapa_masmorra1[y+1][x+1] == caixa || mapa_masmorra1[y+2][x+1] == caixa || mapa_masmorra1[y+1][x-1] == caixa || mapa_masmorra1[y+2][x-1] == caixa){
							caixa = '@';
						}
					}else if(jogador == '<'){
						if(mapa_masmorra1[y][x-1] == caixa || mapa_masmorra1[y][x-2] == caixa || mapa_masmorra1[y+1][x-1] == caixa || mapa_masmorra1[y+1][x-2] == caixa || mapa_masmorra1[y-1][x-1] == caixa || mapa_masmorra1[y-2][x-2] == caixa){
							caixa = '@';
						}
					}
				}else if(arma == 2){
					if(jogador == '^'){
						if(mapa_masmorra1[y-1][x] == caixa || mapa_masmorra1[y-2][x] == caixa || mapa_masmorra1[y-3][x] == caixa || mapa_masmorra1[y-4][x] == caixa){
							caixa = '@';
						}
					}else if(jogador == 'v'){
						if(mapa_masmorra1[y+1][x] == caixa || mapa_masmorra1[y+2][x] == caixa || mapa_masmorra1[y+3][x] == caixa || mapa_masmorra1[y+4][x] == caixa){
							caixa = '@';
						}
					}else if(jogador == '<'){
						if(mapa_masmorra1[y][x-1] == caixa || mapa_masmorra1[y][x-2] == caixa || mapa_masmorra1[y][x-3] == caixa || mapa_masmorra1[y][x-4] == caixa){
							caixa = '@';
						}
					}else if(jogador == '>'){
						if(mapa_masmorra1[y][x+1] == caixa || mapa_masmorra1[y][x+2] == caixa || mapa_masmorra1[y][x+3] == caixa || mapa_masmorra1[y][x+4] == caixa){
							caixa = '@';
						}
					}
				}else if(arma == 3){
					if(mapa_masmorra1[y-1][x] == caixa || mapa_masmorra1[y-1][x+1] == caixa || mapa_masmorra1[y][x+1] == caixa || mapa_masmorra1[y+1][x+1] == caixa || mapa_masmorra1[y+1][x] == caixa || mapa_masmorra1[y+1][x-1] == caixa || mapa_masmorra1[y][x-1] == caixa || mapa_masmorra1[y-1][x-1] == caixa){
						caixa = '@';
					}
				}
				break;
		}
		system("cls");
	}
}

	while(opcao == 1 && fase == 2){
		printf("Vidas: &d", jogador_vidas);
		for(linhas = 0; linhas<16; linhas++){
			for(colunas = 0; colunas<16; colunas++){
				if(linhas == 0 || colunas == 0 || colunas == 15 || linhas == 15){
					mapa_masmorra2[linhas][colunas] = '*';
				}else{
					mapa_masmorra2[linhas][colunas] = ' ';
				}
			}
		}
		for(linhas = 0; linhas<16; linhas++){
			for(colunas = 0; colunas<16; colunas++){
				printf("%c", mapa_masmorra2[linhas][colunas]);
			}
			printf("\n");
		}
		system("pause");
		fase = 3;
	}
	
	while(opcao == 1 && fase == 3){
		printf("Vidas: &d", jogador_vidas);
		for(linhas = 0; linhas<26; linhas++){
			for(colunas = 0; colunas<26; colunas++){
				if(linhas == 0 || colunas == 0 || colunas == 25 || linhas == 25){
					mapa_masmorra3[linhas][colunas] = '*';
				}else{
					mapa_masmorra3[linhas][colunas] = ' ';
				}
			}
		}
		for(linhas = 0; linhas<26; linhas++){
			for(colunas = 0; colunas<26; colunas++){
				printf("%c", mapa_masmorra3[linhas][colunas]);
			}
			printf("\n");
		}
		system("pause");
		fase = 4;
	}
	
	return 0;
}