#include <iostream>
#include <stdlib.h>	
#include <string.h>
#include <locale.h>

using namespace std;

#define line "-------------------------------------------\n"

// variaveis globais
bool acerto = false;
char letter[1], key[7];
string secret, letters, word, tema;
int chances = 5, acertos, tam, tamkey, i, contk, num;

// String de caracteres

char fruta[][10] = {"banana", "limao", "abacate", "morango", "ma�a"};
char roupa[][10] = {"camisa", "sapato", "bermuda", "regata", "gravata"};
char comida[][20] = {"pizza", "hamburguer", "churrasco", "sushi", "salada"};
char esporte[][10] = {"basquete", "futebol", "natacao", "volei", "corrida"};



void mostraralunos(){ // Menu para mostrar os dados dos alunos
	printf("%s[] Aluno: Gabriel George\tRA: 7002260\n[] Aluno: Gabriel Pascon\tRA: 6617818\n%s", line, line);
}

int main(){
	setlocale(LC_ALL, "Portuguese");  // Setando o tipo portuguese no sistema	
	system("COLOR 09");				  // Seta a cor do sistema para azul e preto 
	
	while(word == ""){
		
		mostraralunos();
		
		cout << "\n\n" << line << "\t\tESCOLHA UM TEMA\n" << line << "[1] Fruta\n[2] Roupa\n[3] Comida\n[4] Esporte\nDigite sua escolha: ";
		cin >> num;
		if(num == 1){
			word = fruta[rand()% 5];
			tema = "Fruta";
		}
		else if(num == 2){
			word = roupa[rand()% 5];
			tema = "Roupa";
		}
		else if(num == 3){
			word = comida[rand()% 5];
			tema = "Comida";
		}
		else if(num == 4){
			word = esporte[rand()% 5];
			tema = "Esporte";
		}
		system("cls");
	}
	
	
	
	while(word[i] != '\0' ){ // esse la�o vai esconder a palavra secreta e pegar o tamanho da string
		secret += "-";
		tam++;
		i++;
	}
	
	i = 0; // volta o indentador para 0
	
	system("pause"); // Voce vai precisar apertar uma tecla 
	
	while (true){
		system("cls"); 			// vai limpar o terminal
		system("COLOR 0E");		// Seta a cor do sistema para amarelo e preto 
		cout << line << "[] Tema:\t\t" << tema << "\n[] Chances restantes:\t" << chances << "\n[] Palavra Secreta:\t" << secret << "\n[] Tamanho: " << tam <<"\n[] Acertos: " << acertos << "\n[] Letras digitadas:" << letters  << "\n" << line ;
		
		letra:
		cout << "Digite uma letra: ";	
		cin >> letter[1];
		
		tamkey = strlen(key);
		
		i = contk = 0;
		
		while(letters[i] != '\0'){
//			cout << letters[i] << " < > " << letter[1] << endl;
			if(letters[i] == letter[1]){
				contk++;
			}
			if( contk == 1 ){
				printf("\n%s[*] Letra j� digitada, Digite Novamente\n%s\n\n",line,line);
				goto letra;
			}
			i++;
		}
		key[tamkey] += letter[1]; // Adiciona a letra na string
		letters += letter[1];
		
		
		for(int j = 0; j <= tam ; j++){ // esse la�o vai confererir se a letra digitada est� na palavra secreta
			if(word[j] == letter[1]){
				secret[j] = letter[1];
				acertos++; // aumenta o acertos
				acerto = true;
			}
		}
		
		if(!acerto) { // ele vai conferir se � falso
			chances--; // se for tira uma chance
		}
		acerto = false;
		
		if (chances == 0){  // se as chances acabarem quebra o programa
			printf("Voc� Perdeu :(\n");
			mostraralunos();
			break;
		}
		if (acertos == tam){  // se os acertos forem do tamanho do texto quebra o la�o
			printf("Voc� Ganhou :D\n");
			mostraralunos();
			break;
		}
		
	}
	return 0;
}
