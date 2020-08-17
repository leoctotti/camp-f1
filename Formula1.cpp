#include <stdio.h>
#include <windows.h>
#include <locale.h>

// Declara��o das fun��es.
void Topo();
int Menu();
bool CadastraResultados(int pontPilotos[], bool hasData, int vitoriasPilotos[]);
void AtualizaEquipes(int pontPilotos[], int pontEquipes[], int vitoriasPilotos[], int vitoriasEquipes[]);
void ListaPilotos(int pontPilotos[], int vitoriasPilotos[]);
void ListaEquipes(int pontEquipes[], int vitoriasEquipes[]);
void ListaCampeoes(int pontPilotos[], int pontEquipes[], int vitoriasPilotos[], int vitoriasEquipes[]);

// Fun��o s� para simplificar o uso da parte superior do programa que se repete v�rias vezes.
void Topo() {
	printf("-----------------------------------------\n");
    printf("-        CAMPEONATO DE FORMULA 1        -\n");
    printf("-----------------------------------------\n");
}

// Fun��o para gerenciar o menu do programa, sempre que o usu�rio entra em alguma op��o retorna ao menu inicial.
int Menu() {
	int opc = 0, erro;

	do {
		erro = 0;
		printf("\n(1) - Cadastrar Resultado. \n");
		printf("(2) - Listar pontua��o acumulada do campeonato de pilotos. \n");
		printf("(3) - Listar pontua��o acumulada do campeonato de construtores. \n");
		printf("(4) - Listar quem foi o campe�o de pilotos e qual equipe campe�o de construtores. \n");
		printf("(5) - Sair. \n");
		printf("Informe a op��o desejada: ");
		scanf("%d", &opc);
		
		if(opc == 1 || opc == 2 || opc == 3 || opc == 4 || opc == 5) {
			erro = 0;
		} else {
			system("cls");
			Topo();
			printf("\nOp��o invalida, por favor selecione novamente!\n");
			erro = 1;
			fflush(stdin);
		}
	} while(erro == 1);
	
	return opc;
}

// Fun��o para efetuar o cadastro dos resultados das corridas
bool CadastraResultados(int pontPilotos[], bool hasData, int vitoriasPilotos[]) {
	// A fun��o recebe como par�metros o vetor de pontos dos pilotos, a variavel hasData e o vetor de vit�rias de pilotos.
	
	int i, piloto, erro = 0; // Vari�veis locais, i para o for, piloto para ler do usu�rio e erro para controlar a entrada de dados.
	
	static int corrida = 0; // Var�avel do tipo static pra fazer a contagem de quantas corridas j� foram cadastradas.
	  
	corrida += 1; // A cada execu��o da fun��o corrida++
	system("cls");
	Topo();
	printf("\nCadastro das informacoes do campeonato.\n");
	printf("Corrida numero %d de 21\n", corrida);

	for(i = 1; i < 6; i++) { // Executa 5 vezes para ler do usu�rio quais pilotos ficaram em quais posi��es da corrida
		do {
			erro = 0;
			printf("\n===== %d posicao no campeonato =====", i);
			printf("\nInforme o n�mero do piloto que ocupou essa posi��o: ");
			scanf("%d", &piloto);
			
			if(piloto > 20 || piloto <= 0) { // Condi��o para verificar se o n�mero do piloto informado est� entre 1 a 20.
				erro = 1;
				printf("\nO piloto informado n�o existe! Informe um numero de 1 a 20!\n");
				fflush(stdin);
			} else if(i == 1) {
				pontPilotos[piloto] = pontPilotos[piloto] + 25;
				vitoriasPilotos[piloto] = vitoriasPilotos[piloto] + 1; // Piloto em primeiro lugar, recebe uma vit�ria
			} else if(i == 2) {
				pontPilotos[piloto] = pontPilotos[piloto] + 18;
			} else if(i == 3) {
				pontPilotos[piloto] = pontPilotos[piloto] + 15;
			} else if(i == 4) {
				pontPilotos[piloto] = pontPilotos[piloto] + 12;
			} else if(i == 5) {
				pontPilotos[piloto] = pontPilotos[piloto] + 10;
			}
		} while(erro == 1);
	}
	
	hasData = 1; // Se saiu do la�o while, o registro da pontua��o funcionou, e hasData agora � 1, liberando o acesso as op��es que precisam desses dados
	
	system("cls");

	return hasData;
	
}

void AtualizaEquipes(int pontPilotos[], int pontEquipes[], int vitoriasPilotos[], int vitoriasEquipes[]) {
	// Fun��o utilizada para atualizar as informa��es, juntando os pontos de cada piloto e colocando na equipe, assim como
	// as vit�rias. (� executada logo ap�s o registro de uma corrida, deixando os dados nos vetores sempre atualizados)
	
	int i; // Var�avel local i para usar no for
	
	for(i = 1; i < 21; i++) { // Executa 
		if(i % 2 == 0) { // Verifica se o n�mero � par ou �mpar, j� que as equipes s�o definidas em n�meros �mpares
		} else {
			pontEquipes[i] = pontPilotos[i] + pontPilotos[i + 1];
			vitoriasEquipes[i] = vitoriasPilotos[i] + vitoriasPilotos[i + 1];
		}
	}
	
}

void ListaPilotos(int pontPilotos[], int vitoriasPilotos[]) {
	// Fun��o para listar pontua��o e vit�rias dos pilotos, recebe como par�metros o vetor de pontua��o dos pilotos e o vetor de vit�rias dos pilotos.
	
	int i; // Var�avel local i para usar no for
	
	system("cls");
	Topo();
	printf("Pontua��es individuais de cada piloto: \n");
	
	for(i = 0; i < 20; i++) { // Executa 20 vezes para escrever na tela cada piloto com sua respectiva pontua��o e vit�rias.
		printf("\nPiloto (%d)\n", i+1);
		printf("Pontua��o atual: %d pontos.\n", pontPilotos[i+1]);
		printf("Vit�rias individuais: %d\n", vitoriasPilotos[i+1]);
	}
	
}

void ListaEquipes(int pontEquipes[], int vitoriasEquipes[]) {
	// Fun��o para listar pontua��o e vit�rias da equipe, recebe como par�metros o vetor de pontua��o e de vit�rias das equipes.
	
	int i; // Var�avel local i para usar no for
	
	system("cls");
	Topo();
	printf("Pontua��es de construtores: \n");
	
	for(i = 1; i < 21; i++) { // Executa 20 vezes para escrever na tela cada equipe com suas respectivas pontua��es e vit�rias.
		if(i % 2 == 0) {
		} else {
			printf("\nEquipe (%d)\n", i);
			printf("Pontua��o atual: %d pontos.\n", pontEquipes[i]);
			printf("Vit�rias da equipe: %d\n", vitoriasEquipes[i]);
		}
	}
	
}

void ListaCampeoes(int pontPilotos[], int pontEquipes[], int vitoriasPilotos[], int vitoriasEquipes[]) {
	// Fun��o para listar o piloto campe�o e a equipe campe�, recebe como par�metro todos os vetores,
	// pontua��o de pilotos e equipes, e vit�rias de pilotos e equipes.
	
	int i, maior = 0, pmaior = 0, posicaoPMaior = 0, posicaoMaior = 0; 
	// Var�aveis locais, i para o for, maior para salvar a maior pontua��o atual, pmaior para salvar a pen�ltima pontua��o
	// maior, posicaoMaior para salvar a posi��o no vetor onde a maior pontua��o est�, e posicaoPMaior, para salvar a posi��o
	// no vetor onde a pen�ltima maior pontua��o est�.
	
	system("cls");
	Topo();
	
	for(i = 1; i < 21; i++) { // Executa 20 vezes para passar por todos os valores do vetor de pontos dos pilotos e ver qual o maior valor.
		if(pontPilotos[i] >= maior && pontPilotos[i] != 0) { // Condi��o para ver se os pontos do piloto que o for est� executando � maior do que o valor maior j� registrado, tendo que ser diferente de zero pontos.
			// Todas essas vari�veis come�am com zero, mas isso s� � executado caso os pontos de algum piloto
			// seja diferente de zero
			
			pmaior = maior; // Pen�ltimo maior, recebe o valor do valor maior atual antes que seja alterado.
            posicaoPMaior = posicaoMaior; // Posi��o do pen�ltimo maior, recebe a posi��o do maior valor antes que seja alterado.
            
			// A partir daqui os valores j� s�o atualizados pro novo valor maior
			maior = pontPilotos[i]; // O maior valor, armazena os pontos do piloto que possui mais pontos at� o momento. 
            posicaoMaior = i; // A posi��o desse maior valor, armazena em que �ndice do vetor est� esses pontos.
		}
		if(i == 20) { // Condi��o para verificar se o i � igual a 20, que � a ultima execu��o do la�o for
			printf("\n      Resultado campe�o de pilotos      \n");
			if(maior == pmaior){ // Verifica se o maior valor e o pen�ltimo maior valor s�o iguais, havendo empate de pontos.
				if(pmaior != 0) {
					if(vitoriasPilotos[posicaoMaior] > vitoriasPilotos[posicaoPMaior]) { // Verifica se o n�mero de vit�rias de um � maior que a do outro.
						printf("\nPiloto vencedor individual: \n");
						printf("Piloto (%d)\n", posicaoMaior);
						printf("Pontua��o: %d pontos.\n", pontPilotos[posicaoMaior]);
					} else if(vitoriasPilotos[posicaoMaior] < vitoriasPilotos[posicaoPMaior]) { // Verifica se o n�mero de vit�rias de um � menor que a do outro.
						printf("\nPiloto vencedor individual: \n");
						printf("Piloto (%d)\n", posicaoPMaior);
						printf("Pontua��o: %d pontos.\n", pontPilotos[posicaoPMaior]);
					} else if(vitoriasPilotos[posicaoMaior] == vitoriasPilotos[posicaoPMaior]) { // Verifica se o n�mero de vit�rias dos dois pilotos � igual, causando empate.
						printf("\nEmpate!");
						printf("\nDois pilotos obtiveram a mesma quantidade de pontos e de vit�rias.");
						
						printf("\n\nPilotos vencedores:");
						printf("\nPiloto (%d) e Piloto(%d)", posicaoPMaior, posicaoMaior);
						printf("\n\nPontua��o dos pilotos (%d e %d): %d pontos.", posicaoPMaior, posicaoMaior, pontPilotos[posicaoMaior]);
						if(vitoriasPilotos[posicaoMaior] == 1) { // Apenas muda pro singular caso seja s� uma vit�ria
							printf("\nVit�rias dos pilotos (%d e %d): %d vit�ria.", posicaoPMaior, posicaoMaior, vitoriasPilotos[posicaoMaior]);
						} else {
							printf("\nVit�rias dos pilotos (%d e %d): %d vit�rias.", posicaoPMaior, posicaoMaior, vitoriasPilotos[posicaoMaior]);
						}
					}
				} else {
					printf("\nPiloto vencedor individual: \n");
					printf("Piloto %d\n", posicaoMaior);
					printf("Pontua��o: %d pontos.\n", pontPilotos[posicaoMaior]);
				}
			} else { // Se as duas maiores pontua��es n�o forem iguais, apenas declara vencedor o piloto com mais pontos.
				printf("\nPiloto vencedor individual: \n");
				printf("Piloto %d\n", posicaoMaior);
				printf("Pontua��o: %d pontos.\n", pontPilotos[posicaoMaior]);
			}
		}
	}
	
	// Define todas as vari�veis para seus valores iniciais
	maior = 0;
    pmaior = 0;
    posicaoPMaior = 0;
    posicaoMaior = 0;
    i = 1;
    
    for(i = 1; i < 21; i++) { // Executa 20 vezes para passar por todos os valores do vetor de pontos das equipes e ver qual o maior valor.
        if(i % 2 == 0) { // Filtra para apenas �ndices �mpares serem considerados
        } else {
            if(pontEquipes[i] >= maior && pontEquipes[i] != 0) { // Condi��o para ver se os pontos da equipe que o for est� executando � maior do que o valor maior j� registrado, tendo que ser diferente de zero pontos.
                // Todas essas vari�veis come�am com zero, mas isso s� � executado caso os pontos de alguma equipe
				// seja diferente de zero
				
				pmaior = maior; // Pen�ltimo maior, recebe o valor do valor maior atual antes que seja alterado.
                posicaoPMaior = posicaoMaior; // Posi��o do pen�ltimo maior, recebe a posi��o do maior valor antes que seja alterado.
                
				// A partir daqui os valores j� s�o atualizados pro novo valor maior
				maior = pontEquipes[i]; // O maior valor, armazena os pontos da equipe que possui mais pontos at� o momento.
                posicaoMaior = i; // A posi��o desse maior valor, armazena em que �ndice do vetor est� esses pontos.
            } 
        if(i == 19) { // Condi��o para verificar se o i � igual a 19, que � a ultima equipe dentro do vetor
        	printf("\n\n      Resultado campe�o de construtores      \n");
                if(maior == pmaior){ // Verifica se o maior valor e o pen�ltimo maior valor s�o iguais, havendo empate de pontos.
                	if(pmaior != 0) {
						if(vitoriasEquipes[posicaoMaior] > vitoriasEquipes[posicaoPMaior]) { // Verifica se o n�mero de vit�rias de um � maior que a do outro.
	                        printf("\nEquipe vencedora: \n");
	                        printf("Equipe (%d) // Piloto %d e Piloto %d\n", posicaoMaior, posicaoMaior, posicaoMaior + 1);
	                        printf("Pontua��o da equipe: %d pontos.\n", pontEquipes[posicaoMaior]);
	                    } else if(vitoriasEquipes[posicaoMaior] < vitoriasEquipes[posicaoPMaior]) { // Verifica se o n�mero de vit�rias de um � menor que a do outro.
	                        printf("\nEquipe vencedora: \n");
	                        printf("Equipe (%d) // Piloto %d e Piloto %d\n", posicaoPMaior, posicaoPMaior, posicaoPMaior + 1);
	                        printf("Pontua��o da equipe: %d pontos.\n", pontEquipes[posicaoPMaior]);
	                    } else if(vitoriasEquipes[posicaoMaior] == vitoriasEquipes[posicaoPMaior]) { // Verifica se o n�mero de vit�rias das duas equipes � igual, causando empate.
	                        printf("\nEmpate!");
	                        printf("\nDuas equipes obtiveram a mesma quantidade de pontos e de vit�rias.");
	                        
	                        printf("\n\nEquipes vencedoras:");
	                        printf("\nEquipe (%d) e Equipe(%d)", posicaoPMaior, posicaoMaior);
	                        printf("\n\nPontua��o das equipes (%d e %d):: %d pontos.", posicaoPMaior, posicaoMaior, pontEquipes[posicaoMaior]);
	                        if (vitoriasEquipes[posicaoMaior] == 1) { // Apenas muda pro singular caso seja s� uma vit�ria
	                        	printf("\nVit�rias das equipes (%d e %d): %d vit�ria.\n", posicaoPMaior, posicaoMaior, vitoriasEquipes[posicaoMaior]);
							} else {
								printf("\nVit�rias das equipes (%d e %d): %d vit�rias.\n", posicaoPMaior, posicaoMaior, vitoriasEquipes[posicaoMaior]);
							}
	                    }
					} else {
						printf("\nEquipe vencedora: \n");
                        printf("Equipe (%d) // Piloto %d e Piloto %d\n", posicaoMaior, posicaoMaior, posicaoMaior + 1);
                        printf("Pontua��o da equipe: %d pontos.\n", pontEquipes[posicaoMaior]);
					}
                }  else { // Se as duas maiores pontua��es n�o forem iguais, apenas declara vencedor o piloto com mais pontos.
                    printf("\nEquipe vencedora: \n");
                    printf("Equipe (%d) // Piloto %d e Piloto %d\n", posicaoMaior, posicaoMaior, posicaoMaior + 1);
                    printf("Pontua��o da equipe: %d pontos.\n", pontEquipes[posicaoMaior]);
                }
            }
        }
    }
}

int main() {
	
	setlocale(LC_ALL,""); // Define a linguagem de execu��o do programa, arrumando os acentos. (Biblioteca locale.h)
	
	int opc, x, i; // Vari�veis locais, opc para receber a op��o do usu�rio pela fun��o menu, x e i para usar em la�os for
	static int corrida = 0; // Uma vari�vel static para armazenar quantas corridas j� foram registradas
	bool hasData = 0; // Vari�vel para verificar se alguma corrida j� foi registrada na op��o 1
	int pontPilotos[20], pontEquipes[20], vitoriasPilotos[20], vitoriasEquipes[20]; // Vetores
	
	for(i; i <= 20; i++){ // Executa 20 vezes para iniciar todos os vetores com 0 em todas as suas posi��es.
		pontPilotos[i] = 0;
		pontEquipes[i] = 0;
		vitoriasPilotos[i] = 0;
		vitoriasEquipes[i] = 0;
	}
	
	Topo();
	
	do{
		opc = Menu(); // Executa a fun��o do menu
		if(opc == 1) {
			if(corrida > 21) {
				system("cls");
				Topo();
				printf("\nErro, j� foram informadas o n�mero m�ximo de corridas! %d de 21 corridas!\n", corrida);
			} else {
				hasData = CadastraResultados(pontPilotos, hasData, vitoriasPilotos); // Executa a fun��o de cadastro dos resultados e armazena o retorno da var�avel hasData.
				corrida += 1;
				AtualizaEquipes(pontPilotos, pontEquipes, vitoriasPilotos, vitoriasEquipes); // Atualiza as informa��es das equipes, juntando os pontos e vit�rias de cada piloto a sua equipe.
				Topo();
				printf("\nResultado cadastrado com sucesso!\n"); // Informa ao usu�rio que o resultado foi cadastrado
			}
		} else if(opc == 2) {
			if(hasData == 0) { // Verifica se alguma corrida j� foi cadastrada na op��o 1.
				system("cls");
				Topo();
				printf("\nEssa op��o requer que ao menos um registro de dados seja informado na op��o 1.\n");	
			} else if(hasData == 1) {
				ListaPilotos(pontPilotos, vitoriasPilotos); // Executa a fun��o de listar os pilotos passando os vetores de pontua��o e vit�rias.
				printf("\nPressione qualquer tecla para voltar ao menu principal!\n.");
				system("pause > nul"); // Fun��o da biblioteca windows.h que pausa o programa e s� volta a executar quando o usu�rio aperta alguma tecla. (> nul faz com que a mensagem padr�o dessa fun��o n�o seja exibida)
				system("cls");
				Topo();
			}
		} else if(opc == 3) {
			if(hasData == 0) { // Verifica se alguma corrida j� foi cadastrada na op��o 1.
				system("cls");
				Topo();
				printf("\nEssa op��o requer que ao menos um registro de dados seja informado na op��o 1.\n");	
			} else if(hasData == 1) {
				ListaEquipes(pontEquipes, vitoriasEquipes); // Executa a fun��o de listar as equipes passando os vetores de pontua��o e vit�rias.
				printf("\nPressione qualquer tecla para voltar ao menu principal!\n.");
				system("pause > nul"); // Fun��o da biblioteca windows.h que pausa o programa e s� volta a executar quando o usu�rio aperta alguma tecla. (> nul faz com que a mensagem padr�o dessa fun��o n�o seja exibida)
				system("cls");
				Topo();
			}
		} else if(opc == 4) {
			if(hasData == 0) { // Verifica se alguma corrida j� foi cadastrada na op��o 1.
				system("cls");
				Topo();
				printf("\nEssa op��o requer que ao menos um registro de dados seja informado na op��o 1.\n");	
			} else if(hasData == 1) {
				ListaCampeoes(pontPilotos, pontEquipes, vitoriasPilotos, vitoriasEquipes);
				printf("\n\nPressione qualquer tecla para voltar ao menu principal!\n.");
				system("pause > nul"); // Fun��o da biblioteca windows.h que pausa o programa e s� volta a executar quando o usu�rio aperta alguma tecla. (> nul faz com que a mensagem padr�o dessa fun��o n�o seja exibida)
				system("cls");
				Topo();
			}
		} else if(opc == 5) {
			return 0;
		}	
	} while(opc != 5); // Faz com que todas as op��es retornem ao menu principal, pois ser� executado novamente, at� que que o usu�rio escolha 5 para sair.
	
}
