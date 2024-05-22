#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Função para ler o input do teclado
char lerTecla() {
    char tecla;
    tecla = getch(); // Ler a tecla pressionada
    return tecla;
}

int inter(){
	system("cls");
	int menu;
	
	printf("--------------------\n");
	printf("||                ||\n");
	printf("||                ||\n");
	printf("||   [1] - JOGAR  ||\n");
	printf("|| [2] - TUTORIAL ||\n");
	printf("||   [3] - SAIR   ||\n");
	printf("||                ||\n");
	printf("||                ||\n");
	printf("--------------------\n");

	
	scanf("%d", &menu);
	return menu;
}


int tutorial(){
	int tut;
	system("cls");
	printf("PREPARANDO TUTORIAL\n");
	sleep(2);
	system("cls");
	printf("Bem-vindo ao Tutorial de Aventura!\n\n");
	printf("Neste jogo de aventura e puzzle, seu objetivo eh superar tres desafiantes fases. Aqui esta o que voce precisa saber:\n\n");
	printf("1- Movimentacao: Use as teclas W, A, S e D para mover seu personagem pelo cenario e caso queira sair do jogo use a tecla 'Q'\n");
	printf("2- Interatividade: Ao chegar em um objeto que possa ser interagido, pressione a tecla I. Isso inclui pegar chaves (@), pressionar botoes (O) e utilizar teletransportes (>).\n");
	printf("3- Objetivos: Em cada fase, seu objetivo eh encontrar a chave (@) para abrir a porta (D) e avançar para a proxima fase. A porta se transforma em (=) quando voce interage com a chave.\n");
	printf("4- Perigos: Esteja atento aos espinhos (#) e aos monstros (X e V). Se tocar em um espinho, a fase sera reiniciada. Se um monstro te alcançar, o mesmo acontecera.\n");
	printf("5- Teletransportes: Use os teletransportes (>) para se movimentar rapidamente pelo cenario. Eles sempre aparecem em pares.\n");
	printf("6- Reinicio: Se falhar tres vezes em uma fase, o jogo retornara ao menu principal.\n");
	printf("Agora que voce conhece as regras basicas, prepare-se para uma emocionante jornada! Boa sorte!\n\n");
	printf("Deseja voltar ao menu inicial?\n1-SIM\n2-NAO\n");
	scanf("%d", &tut);
	if (tut==1){
		inter();
	}else if(tut==2){
		printf("voce saiu");
		return 0;
	}else{
		printf("digite algo valido");
	}
	return tut;
}

char gameover(){
	char gm;
printf("GAME OVER\n");
sleep(2);
inter();
 return gm;
}


int fim(){
	system("cls");
	printf("PREPARANDO MENSAGEM DE DESPEDIDA\n");
	sleep(2);
	system("cls");
	    printf("  *****      *****    ******    **      *****       *****    ******      *****\n");
	    printf("  *****     ******    *******   **      *****       *****    ******      *****\n");
		printf("**     **  **     **  **    **        **          **     **  **    **  **     **\n");
		printf("**     **  **    ***  **    **  **    **          **     **  **    **  **     **\n");
		printf("**     **  *******    *******   **    **    ****  *********  **    **  **     **\n" );
		printf("**     **  **    ***  ******    **    **      **  *********  **    **  **     **\n");
		printf("**     **  **     **  **   **   **    **     **   **     **  **    **  **     **\n");
		printf("  *****     ******    **    **  **      *****     **     **  ******      *****\n");
		printf("  *****      *****    **    **  **      *****     **     **  ******      *****\n");
		printf("\n");
		printf("  \t\t\t  *****      *****    ******      \n");
		printf("  \t\t\t********     *****    *******      \n");
		printf("  \t\t\t**     **  **     **  **    **   \n");
		printf("  \t\t\t**     **  **     **  **    **  \n");
		printf("  \t\t\t********   **     **  *******      \n");
		printf("  \t\t\t*******    **     **  ******     \n");
		printf("  \t\t\t**         **     **  **   **  \n");
		printf("  \t\t\t**           *****    **    **  \n");
		printf("  \t\t\t**           *****    **    **  \n");
		printf("\n");
		printf("\t            **    *****      *****       *****    ******    **\n");
		printf("\t            **    *****      *****       *****    ******    ** \n");
		printf("\t            **  **     **  **          **     **  **    **  **\n");
		printf("\t            **  **     **  **          **     **  **    **  **\n");
		printf("\t            **  **     **  **    ****  *********  *******   ** \n");
		printf("\t    **      **  **     **  **      **  *********  ******    **\n");
		printf("\t    **     ***  **     **  **     **   **     **  **   **     \n");
		printf("\t     ********     *****      *****     **     **  **    **  **\n");
		printf("\t      ******      *****      *****     **     **  **    **  **\n");
		
	sleep(2);
}

char fase3(){
	int monstro;
	int posX = 1; // Posição inicial do jogador
	int vida = 3;
	int k;
	// Inicializando a semente para gerar números aleatórios
    srand(time(NULL));
    // Posição inicial do monstro
    int mpx = 38;
    int mpy = 2;
	int posY = 1;
	int i, j;
	char teclaPressionada;
	char mapa3[40][41] = {
        "****************************************",
		"*  *                   *               *",
		"*   *           ###    *               *",
		"*   *           #      *               *",
		"*                      *               *",
		"* # *#*#               *               *",
		"*# #          #####    *               *",
		"*       *     #O       *               *",
		"*      *         #     *               *",
		"*  *                   * * **#   ######*",
		"*   *                                  *",
		"*  *                    #              *",
		"*   *    #                   #         *",
		"*   *         #                        *",
		"*                        #             *",
		"*  >           #        #              *",
		"*             #             #          *",
		"*      #       #      #    #           *",
		"*   *         ####           ***********",
		"*******************  ########          *",
		"*  *                                   *",
		"*   *           ###                    *",
		"*   *           #                      *",
		"*                                      *",
		"* # *#*#                               *",
		"*# #          #####         ***        *",
		"*       *     #            **      ### *",
		"*      *         #         *     #     *",
		"*  *                       *     #     *",
		"*   *                    **      #     *",
		"*  *  ***              **        #     *",
		"* ##*    #            *                *",
		"*#  * #       #                  ###   *",
		"*@      *            #                 *",
		"*   #   *      #     #    ********     *",
		"*   #   *     #      #    *     #      *",
		"*  #    #      #    #     *   # ##    #*",
		"*   *   # >               *          # *",
		"*                         *  ## #D  #  *",
		"****************************************",
    };
    printf("cuidado os '#' sao espinhos, se tocar neles voce reinicia a fase, apos 3 perdas voce reinicia o jogo\n");
	sleep(2);// mostrar o texto de cima por 2 segundos
	for (i = 0; i < 40; i++) {
        for (j = 0; j < 40; j++) {
        	printf("%c", mapa3[i][j]);
            }
		printf("\n");
        }
        
    while (1) {
	// Limpar a tela e exibir a nova posicao do jogador
	system("cls"); // Para Windows
		// Movimento do monstro em direção ao jogador
		if (posX < mpx && mapa3[mpy][mpx - 1] != '*') {
    		mpx--;
		} else if (posX > mpx && mapa3[mpy][mpx + 1] != '*') {
    		mpx++;
		}

		if (posY < mpy && mapa3[mpy - 1][mpx] != '*') {
    		mpy--;
		} else if (posY > mpy && mapa3[mpy + 1][mpx] != '*') {
    		mpy++;
		}

        for (i = 0; i < 40; i++) {
            for (j = 0; j < 40; j++) {
                if (i == posY && j == posX) {
                    printf("&");
                } else if (i == mpy && j == mpx) {
                    printf("V");
                } else {
                    printf("%c", mapa3[i][j]);
                }
            }
            printf("\n");
        }
        
        // Verificar colisão com o monstro ou espinhos
        if (mapa3[posY][posX] == 'V' || mapa3[posY][posX] == '#') {
    		vida--;
   			if (vida == 0) {
        		system("cls");
        		gameover();
        		return 0;
    		}
   			mpx = 38;
    		mpy = 2;
    		posX = 1; // Reiniciar posição do jogador
    		posY = 1;
    		printf("Você perdeu uma vida! Vidas restantes: %d\n", vida);
    		sleep(2);
		}
        
        // Ler o input do teclado
	teclaPressionada = lerTecla();
	
	// Atualizar a posicao do jogador de acordo com a tecla pressionada
	    switch (teclaPressionada) {
	        case 'w':
	            if (mapa3[posY - 1][posX] != '*') {
	                posY--;
	            }
	            break;
	        case 'a':
	            if (mapa3[posY][posX - 1] != '*') {
	                posX--;
	            }
	            break;
	        case 's':
	            if (mapa3[posY + 1][posX] != '*') {
	                posY++;
	            }
	            break;
	        case 'd':
	            if (mapa3[posY][posX + 1] != '*') {
	                posX++;
	            }
	            break;
	        case 'q': // Sair do loop quando 'q' for pressionado
	            printf("Saindo do jogo...\n");
	            return 0;
	        case 'i': // Verificar se o jogador está sobre "@" e "D"
	            if (mapa3[posY][posX] == '@') {
	                mapa3[posY][posX] = ' ';
	                mapa3[18][18] = '=';//Alteracao do sprite da porta
			fim();
					
					}
				if (mapa3[posY][posX] == 'O') {
						mapa3[posY][posX] = ' ';
						mapa3[15][15] = ' ';
						vida++;
						printf("%d", vida);
						sleep(1);
						}	
				// Verificar teletransporte
	        	if (mapa3[posY][posX] == '>') {
                    // Procurar a próxima posição de ">"
                    int novaPosX = posX;
                    int novaPosY = posY;
                    for (i = 0; i < 40; i++) {
                        for (j = 0; j < 40; j++) {
                            if (mapa3[i][j] == '>' && (i != posY || j != posX)) {
                                // Teletransportar o jogador para a próxima posição de ">"
                                novaPosX = j;
                                novaPosY = i;
                                break;
                            }
                        }
                    }
                    posX = novaPosX;
                    posY = novaPosY;
                }
                break;
	        
	        default:
	            printf("Tecla invalida!\n");
	            sleep(1);
	            break;
	    }
	    
	    
   }
   return fase3;
}

char fase2(){
	int monstro;
	int posX = 1; // Posição inicial do jogador
	int vida = 3;
	int k;
	// Inicializando a semente para gerar números aleatórios
    srand(time(NULL));
    // Posição inicial do monstro
    int mpx = 5;
    int mpy = 5;
	int posY = 1;
	int i, j;
	char teclaPressionada;
	char mapa2[20][21] = {
        "********************",
		"*  *               *",
		"*   *           ###*",
		"*   *           #  *",
		"*                  *",
		"* # *#*#           *",
		"*# #          #####*",
		"*       *     #O   *",
		"*      *         #*",
		"*  *               *",
		"*   *              *",
		"*  *               *",
		"*   *    #         *",
		"*   *         #    *",
		"*                  *",
		"*              #   *",
		"*             #    *",
		"*      #       #   *",
		"*@  *         ####D*",
		"********************",
    };
    printf("cuidado os '#' sao espinhos, se tocar neles voce reinicia a fase, apos 3 perdas voce reinicia o jogo\n");
	sleep(2);// mostrar o texto de cima por 2 segundos
	for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
        	printf("%c", mapa2[i][j]);
            }
		printf("\n");
        }
    // Colocando o sprite do monstro na posição inicial
    	mapa2[mpy][mpx] = 'X';

    while (1) {
	// Limpar a tela e exibir a nova posicao do jogador
	system("cls"); // Para Windows
	//posiçao atualizada do monstro
		monstro = rand()%4;
        if(monstro == 0){
        	mpy--;
		}else if(monstro == 1){
			mpx--;
		}else if(monstro == 2){
			mpy++;
		}else if(monstro == 3){
			mpx++;
		}
		// Exibir o mapa com a posicaoa atualizada do jogador
		for (i = 0; i < 20; i++) {
            for (j = 0; j < 20; j++) {
                if (i == posY && j == posX) {
                    printf("&");
                } else if (i == mpy && j == mpx) {
                	if(mpy!='*' && mpx != '*'){
                		printf("X");
					}
                } else {
                    printf("%c", mapa2[i][j]);
                }
            }
            printf("\n");
        }
        
	// Ler o input do teclado
	teclaPressionada = lerTecla();
	
	// Atualizar a posicao do jogador de acordo com a tecla pressionada
	    switch (teclaPressionada) {
	        case 'w':
	            if (mapa2[posY - 1][posX] != '*') {
	                posY--;
	            }
	            break;
	        case 'a':
	            if (mapa2[posY][posX - 1] != '*') {
	                posX--;
	            }
	            break;
	        case 's':
	            if (mapa2[posY + 1][posX] != '*') {
	                posY++;
	            }
	            break;
	        case 'd':
	            if (mapa2[posY][posX + 1] != '*') {
	                posX++;
	            }
	            break;
	        case 'q': // Sair do loop quando 'q' for pressionado
	            printf("Saindo do jogo...\n");
	            return 0;
	        case 'i': // Verificar se o jogador está sobre "@" e "D"
	            if (mapa2[posY][posX] == '@') {
	                mapa2[posY][posX] = ' ';
	                mapa2[18][18] = '=';//Alteracao do sprite da porta
	                fase3();
					}
				if (mapa2[posY][posX] == 'O') {
						mapa2[posY][posX] = ' ';
						mapa2[15][15] = ' ';
						vida++;
						printf("%d", vida);
						sleep(1);
						}	
	            break;
	        
	        default:
	            printf("Tecla invalida!\n");
	            sleep(1);
	            break;
	    }
	    // Verificar colisão com o monstro ou espinhos
        if (mapa2[posY][posX] == 'X' || mapa2[posY][posX] == '#') {
            vida--;
            if (vida == 0) {
                system("cls");
                gameover();
                return 0;
            }
            posX = 1; // Reiniciar posição do jogador
            posY = 1;
            printf("Voce perdeu uma vida! Vidas restantes: %d\n", vida);
            sleep(2);
        }
		
	}
    return mapa2;
}



int main(int argc, char *argv[]) {
	while(1){
		int menu = inter();
		int posX = 1; // Posição inicial do jogador
	    int posY = 1;
		int i;
		int j;
		int tut;
		char mapa[10][11] = {
		"**********",
		"*D *     *",
		"*   *    *",
		"*   *    *",
		"*        *",
		"*   *    *",
		"*        *",
		"*     *  *",
		"*    *  @*",
		"**********",
		};
		char teclaPressionada;
		if(menu==1){
			printf("INICIANDO JOGO\n");
			sleep(2); //Sleep: o proximo comando so vai ser executado (x) segundos depois
			printf("Use as teclas W, A, S e D para mover seu personagem pelo cenário. Use a tecla 'q' quando quiser sair do jogo");
			sleep(2);
			
	    while (1) {
	        // Limpar a tela e exibir a nova posicao do jogador
	        system("cls"); // Para Windows
	
	        // Exibir o mapa com a posicaoa atualizada do jogador
	        for (i = 0; i < 10; i++) {
	            for (j = 0; j < 10; j++) {
	                if (i == posY && j == posX) {
	                    printf("&");
	                } else {
	                    printf("%c", mapa[i][j]);
	                }
	            }
	            printf("\n");
	        }
	
	        // Ler o input do teclado
	        teclaPressionada = lerTecla();
	
	        // Atualizar a posicao do jogador de acordo com a tecla pressionada
	        switch (teclaPressionada) {
	            case 'w':
	                if (mapa[posY - 1][posX] != '*') {
	                    posY--;
	                }
	                break;
	            case 'a':
	                if (mapa[posY][posX - 1] != '*') {
	                    posX--;
	                }
	                break;
	            case 's':
	                if (mapa[posY + 1][posX] != '*') {
	                    posY++;
	                }
	                break;
	            case 'd':
	                if (mapa[posY][posX + 1] != '*') {
	                    posX++;
	                }
	                break;
	            case 'q': // Sair do loop quando 'q' for pressionado
	                printf("Saindo do jogo...\n");
	                return 0;
	            case 'i': // Verificar se o jogador está sobre "@" e "O"
	                if (mapa[posY][posX] == '@') {
	                    mapa[posY][posX] = ' ';
	                    mapa[1][1] = '=';//Alteracao do sprite da porta
	                    fase2();//mudar de fase
	                }
	                break;
	            default:
	                printf("Tecla invalida!\n");
	                sleep(1);
	                break;
	        }
	    }
		}else if(menu==2){
			tutorial();
			
		}else if(menu==3){
			fim();
			return 0;
		}else{
			printf("DIGITE UMA OPCAO VALIDA");
		}
	
	}
}
