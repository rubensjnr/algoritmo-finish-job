#include <iostream> ////////////////////////////////////////////////
#include <conio.h>  // Aluno: Rubens da Cunha Junior
#include <stdlib.h> // R.A: 2211550375
#include <locale.h> // Curso: Analise e Desenvolvimento de Sistemas
#include <string.h> // Ano: 2� - Turma 2 - Sala 13
#include <math.h>	////////////////////////////////////////////////
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
	int codigo, codEvento;
	char nome[30];
};
//
bool encontraCidade(struct cidade cd[], int codCidade, int qtdCidades, int &cod);
bool encontraApresentador(struct apresentador ap[], int codAp, int qtdAp, int &cod);
bool acrescentaParticipanteEvento(struct evento ev[],int qtdEv, int codEv, struct cidade cid[], int qtdCidades, struct apresentador ap[], int qtdAp);
void leituraCidade(struct cidade x[], int &qtdCidades);
void leituraApresentador(struct apresentador x[], int &qtdApresentador);
void leituraEvento(struct evento ev[], struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp, int &qtdEv);
void leituraParticipante(struct participante part[], struct evento ev[],int qtdEv, int &qtdParticipante, struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp);
void menuPrincipal();
//
int main(){
	system("Color E0");
	setlocale(LC_ALL,"Portuguese");
	int qtdCidades, qtdApresentadores, qtdEventos, qtdParticipantes;
	cidade cidades[3];
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
		case 3: { system("clear||cls"); leituraEvento(eventos, cidades, qtdCidades, apresentadores, qtdApresentadores, qtdEventos); break; }
		case 4: { system("clear||cls");
		leituraParticipante(participantes, eventos, qtdEventos, qtdParticipantes, cidades, qtdCidades, apresentadores, qtdApresentadores);
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
bool encontraCidade(struct cidade cd[], int codCidade, int qtdCidades, int &cod){
    int i = 0, f = qtdCidades;
    int m = (i + f) / 2;
    for (; f >= i && codCidade != cd[m].codigo; m = (i + f) / 2){
        if (codCidade > cd[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codCidade == cd[m].codigo){
    	cod = m;
    	return true;
    }
    else {
    	return false;
	}
}

bool encontraApresentador(struct apresentador ap[], int codAp, int qtdAp, int &cod){
    int i = 0, f = qtdAp;
    int m = (i + f) / 2;
    for (; f >= i && codAp != ap[m].codigo; m = (i + f) / 2){
        if (codAp > ap[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codAp == ap[m].codigo){
			cod = m;
			return true;
    }
    else {
    	return false;
	}
}
bool acrescentaParticipanteEvento(struct evento ev[],int qtdEv, int codEv, struct cidade cid[], int qtdCidades, struct apresentador ap[], int qtdAp){
    int i = 0, f = qtdEv, x, y;
    int m = (i + f) / 2;
    
    for (; f >= i && codEv != ev[m].codigo; m = (i + f) / 2){
        if (codEv > ev[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codEv == ev[m].codigo){
    	encontraCidade(cid, ev[m].codCidade,qtdCidades, x);
    	encontraApresentador(ap, ev[m].codApresentador, qtdAp, y);
    	if (ev[m].qtdParticipantes < ev[m].limiteParticipantes){
    		ev[m].qtdParticipantes++;
    		cout << "\nIncri��o de participante concluida!!!\n";
    		cout << "Segue detalhes do evento abaixo: ";
    		cout << "Descri��o: " << ev[m].descricao;
    		cout << "Cidade: " << cid[x].nome;
    		cout << "Apresentador: " << ap[y].nome;
    		
    		return true ;
		}
    	else {
    		cout << "O n�mero de vagas para esse evento foi esgotada";
    		return false ;
		}
    }
    else {
		cout << "\n Evento n�o Encontrado!\n";
		return false ;	
	}
}

//
void leituraCidade(struct cidade x[], int &qtdCidades){
	int i = 0, t = 0;
	char verificador[1];
	for(; t == 0; i++){
		system("clear||cls");
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
		system("clear||cls");
		cout << "Digite o codigo do apresentador: "; cin >> x[i].codigo; cin.ignore();
		cout << "Digite o nome do apresentador: "; gets(x[i].nome);
		cout << "\nDeseja informar mais um participante? S/N: "; cin >> verificador; cin.ignore();
		if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            t++;
        }
	}
	qtdApresentador = i;
}
void leituraEvento(struct evento ev[], struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp, int &qtdEv){
	int i = 0, t = 0, x, y;
	char verificador[1];
	bool z = false ;
	for(; t == 0 ; i++){
		system("clear||cls");
		cout << " - Digite um n�mero de c�digo para o evento: "; cin >> ev[i].codigo; cin.ignore();
		cout << "\n - Digite uma descri��o do evento: "; gets(ev[i].descricao);
	
		for(int j = 0 ; z == false ; j++){
			if (j == 5 ) system("clear||cls");
			cout << "\n - Informe o c�digo da cidade aonde ocorrer� o evento: "; cin >> ev[i].codCidade; cin.ignore();
			z = encontraCidade(cd, ev[i].codCidade, qtdCidades, x);
			if(z){
				cout << "\n==============================\n";
				cout << "> Cidade: " << cd[x].nome;
				cout << "\n> UF: " << cd[x].uf;
				cout << "\n==============================\n";
			} else cout << "\nCidade n�o encontrata!\n ";
		}
		z = false;
		for(int j = 0 ; z == false ; j++){
			if (j == 5) system("clear||cls");
			cout << "\n\nInforme o c�digo do apresentador do evento: "; cin >> ev[i].codApresentador; cin.ignore();
	    	z = encontraApresentador(ap, ev[i].codApresentador, qtdAp, y);
	    	if (z) {
	    		cout << "\n==============================\n";
	    		cout << "> Apresentador: " << ap[y].nome;
	    		cout << "\n==============================\n";
			}
			else cout << "\n Apresentador n�o Encontrado!\n";
		}
		cout << "\n\n - Informe o limite de participantes do evento: "; cin >> ev[i].limiteParticipantes; cin.ignore();
		cout << "\n - Informe o pre�o do convite unit�rio do evento: "; cin >> ev[i].preco; cin.ignore();
		cout << "\n - Deseja informar mais um evento? S/N: "; cin >> verificador; cin.ignore();
		
		if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            t++;
        }
	}
	qtdEv = i;
}

void leituraParticipante(struct participante part[], struct evento ev[],int qtdEv, int &qtdParticipante, struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp){
	int i = 0, t = 0;
	char verificador[1];
	for(; t==0 ; i++){
		system("clear||cls");
		cout << "Digite o c�digo do participante: "; cin >> part[i].codigo; cin.ignore();
		cout << "Digite o nome do participante: "; gets(part[i].nome);
		cout << "O participante ja optou por um evento? S/N: "; gets(verificador);
		if (strcmp(verificador, "S") == 0 || strcmp(verificador, "s") == 0){
        	cout << "Informe o c�digo do evento de escolha do participante: "; cin >> part[i].codEvento; cin.ignore();
			acrescentaParticipanteEvento(ev, qtdEv, part[i].codEvento, cd, qtdCidades, ap, qtdAp);
        }
		cout << "\nDeseja informar mais um participante? S/N: "; gets(verificador);
			if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            t++;
        }
	}
	qtdParticipante = i;
}














