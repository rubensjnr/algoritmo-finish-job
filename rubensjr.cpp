#include <iostream> // Aluno: Rubens da Cunha Junior
#include <conio.h>  // R.A: 2211550375
#include <stdlib.h> // Curso: Analise e Desenvolvimento de Sistemas
#include <locale.h> // Ano: 2º - Turma 2 - Sala 13
#include <string.h>
#include <math.h>
#include <cstring>
#include <stdio.h>
using namespace std;

struct cidade{
	int codigo;
	char nome[20], uf[2];
};

struct apresentador{
	int codigo;
	char nome[30];
};

struct evento{
	int codigo, codCidade, codApresentador,
	qtdParticipantes, limiteParticipantes;
	float preco;
	char descricao[30];
};

struct participante{
	int codigo, codEvento = 0;
	char nome[30];
};
//
void encontraCidade(struct cidade cd[], int codCidade, int &cod);
void encontraApresentador(struct apresentador ap[], int codAp, int &cod);
bool acrescentaParticipanteEvento(struct evento ev[], int codEv, struct cidade cid[], struct apresentador ap[]);
void leituraCidade(struct cidade x[], int &qtdCidades);
void leituraApresentador(struct apresentador x[], int &qtdApresentador);
void leituraEvento(struct evento ev[], struct cidade cd[], struct apresentador ap[], int &qtdEv);
void leituraParticipante(struct participante part[], struct evento ev[], int &qtdParticipante, struct cidade cd[], struct apresentador ap[]);
void menuPrincipal();


//bool encontraCidade(struct cidade cd, int codCidade, int &cod);


//
int main(){
	system("Color E0");
	setlocale(LC_ALL,"Portuguese");
	int qtdCidades, qtdApresentadores, qtdEventos, qtdParticipantes;
	cidade cidades[2];
	apresentador apresentadores[2];
	evento eventos[2];
	participante participantes[2];
	
	char op;
	for(int i = 0 ; i < op != -1 ; i++){
	menuPrincipal();
	op = getch();
	int opcao = op - '0';
	switch(opcao){
		case 1: { system("clear||cls"); leituraCidade(cidades, qtdCidades); break; }
		case 2: { system("clear||cls"); leituraApresentador(apresentadores, qtdApresentadores); break; }
		case 3: { system("clear||cls"); leituraEvento(eventos, cidades, apresentadores, qtdEventos); break; }
		case 4: { system("clear||cls");
		leituraParticipante(participantes, eventos, qtdParticipantes, cidades, apresentadores);
		break; }
		case 5: { system("clear||cls"); break; }
		case 6: { system("clear||cls"); break; }	
  		case 9: { op = -1; return 0;  break; }
		default : { cout << "\n\nOpcao invalida. Tecle algo para continuar..."; getch(); }
		}
	}
}
void menuPrincipal(){
	system("clear||cls");
	cout << "\n\t\tControle de Eventos FEMA - Trabalho de Algoritmo! \n\n";
	cout << "\n\t1 - Informar uma cidade.\n";
	cout << "\n\t2 - Informar um(a) apresentador(a).\n";
	cout << "\n\t3 - Informar um evento.\n";
	cout << "\n\t4 - Informar um participante.\n";
	cout << "\n\t5 - Informar um(a) novo(a) apresentador(a).\n";
	cout << "\n\t6 - Informar um novo evento.\n";
	cout << "\n\t7 - Consultar evento.\n";
	cout << "\n\t8 - Ver todos os eventos.\n";
	cout << "\n\n\t9- Sai/Exit.\n\n";
}
void encontraCidade(struct cidade cd[], int codCidade, int &cod){
    int i = 0, f = 10;
    int m = (i + f) / 2;
    for (; f >= i && codCidade != cd[m].codigo; m = (i + f) / 2){
        if (codCidade > cd[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codCidade == cd[m].codigo){
    		cod = m;
    }
    else {
    	cout << "\n Cidade não Encontrado!";
	}
    getch();
}


void encontraApresentador(struct apresentador ap[], int codAp, int &cod){
    int i = 0, f = 10;
    int m = (i + f) / 2;
    for (; f >= i && codAp != ap[m].codigo; m = (i + f) / 2){
        if (codAp > ap[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codAp == ap[m].codigo){
			cod = m;
    }
    else {
    	cout << "\n Apresentador não Encontrado!";
	}
    getch();
}
bool acrescentaParticipanteEvento(struct evento ev[], int codEv, struct cidade cid[], struct apresentador ap[]){
    int i = 0, f = 10, x, y;
    int m = (i + f) / 2;
    
    for (; f >= i && codEv != ev[m].codigo; m = (i + f) / 2){
        if (codEv > ev[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codEv == ev[m].codigo){
    	encontraCidade(cid, ev[m].codCidade, x);
    	encontraApresentador(ap, ev[m].codApresentador, y);
    	if (ev[m].qtdParticipantes < ev[m].limiteParticipantes){
    		ev[m].qtdParticipantes++;
    		cout << "\nIncrição de participante concluida!!!\n";
    		cout << "Segue detalhes do evento abaixo: ";
    		cout << "Descrição: " << ev[m].descricao;
    		cout << "Cidade: " << cid[x].nome;
    		cout << "Apresentador: " << ap[y].nome;
    		
    		return true ;
		}
    	else {
    		cout << "O número de vagas para esse evento foi esgotada";
    		return false ;
		}
    }
    else {
		cout << "\n Evento não Encontrado!";
		return false ;	
	}
    getch();
}


//
void leituraCidade(struct cidade x[], int &qtdCidades){
	int i = 0, t = 0;
	char verificador[1];
	for(; t == 0; i++){
		cout << "Digite o codigo da cidade: "; cin >> x[i].codigo; cin.ignore();
		cout << "Digite o nome da cidade: "; gets(x[i].nome);
		cout << "Digite a UF do municipio: "; gets(x[i].uf);
		cout << "\nDeseja informar mais uma cidade? S/N: "; cin >> verificador; cin.ignore();
		cout << "\n";
        if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            t++;
        }
	
	}
	qtdCidades = i;
}
void leituraApresentador(struct apresentador x[], int &qtdApresentador){
	int i = 0, t = 0;
	char verificador[1];
	for(; t == 0 ; i++){
		cout << "Digite o codigo do apresentador: "; cin >> x[i].codigo; cin.ignore();
		cout << "Digite o nome do apresentador: "; gets(x[i].nome);
		cout << "\nDeseja informar mais um participante? S/N: "; cin >> verificador; cin.ignore();
		if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            t++;
        }
	}
	qtdApresentador = i;
}
void leituraEvento(struct evento ev[], struct cidade cd[], struct apresentador ap[], int &qtdEv){
	int i = 0, t = 0, x, y;
	char verificador[1];
	for(; t == 0 ; i++){
		cout << "Digite um número de código para o evento: "; cin >> ev[i].codigo; cin.ignore();
		cout << "Digite uma descrição do evento: "; gets(ev[i].descricao);
		cout << "Informe o código da cidade aonde ocorrerá o evento: "; cin >> ev[i].codCidade; cin.ignore();
		
		encontraCidade(cd, ev[i].codCidade, x); //falta fazer um loop para pedir novamente a instrução
	
		cout << "Informe o código do apresentador do evento: "; cin >> ev[i].codApresentador; cin.ignore();
		
	    encontraApresentador(ap, ev[i].codApresentador, y); //falta fazer um loop para pedir novamente a instrução
		
		cout << "Informe o limite de participantes do evento: "; cin >> ev[i].limiteParticipantes; cin.ignore();
		cout << "Informe o preço do convite unitário do evento: "; cin >> ev[i].preco; cin.ignore();
		cout << "\nDeseja informar mais um evento? S/N: "; cin >> verificador; cin.ignore();
		
		if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            t++;
        }
	}
	qtdEv = i;
}

void leituraParticipante(struct participante part[], struct evento ev[], int &qtdParticipante, struct cidade cd[], struct apresentador ap[]){
	int i = 0, t = 0;
	char verificador[1];
	for(; t==0 ; i++){
		cout << "Digite o código do participante: "; cin >> part[i].codigo; cin.ignore();
		cout << "Digite o nome do participante: "; gets(part[i].nome);
		cout << "O participante ja optou por um evento? S/N: "; gets(verificador);
		if (strcmp(verificador, "S") == 0 || strcmp(verificador, "s") == 0){
        	cout << "Informe o código do evento de escolha do participante: "; cin >> part[i].codEvento; cin.ignore();
			acrescentaParticipanteEvento(ev, part[i].codEvento, cd, ap);
        }
		cout << "\nDeseja informar mais um participante? S/N: "; gets(verificador);
			if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            t++;
        }
	}
	qtdParticipante = i;
}














