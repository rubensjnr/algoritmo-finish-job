#include <iostream> ////////////////////////////////////////////////
#include <conio.h>  // Aluno: Rubens da Cunha Junior
#include <stdlib.h> // R.A: 2211550375
#include <locale.h> // Curso: Analise e Desenvolvimento de Sistemas
#include <string.h> // Ano: 2º - Turma 2 - Sala 13
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
void consultarEvento(struct evento ev[], int qtdEvento, struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp);
void mostrarTodosEventos(struct evento ev[], int qtdEvento, struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp);
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
		case 7: { system("clear||cls"); consultarEvento(eventos, qtdEventos, cidades, qtdCidades, apresentadores, qtdApresentadores); break; }
		case 8: { system("clear||cls"); mostrarTodosEventos(eventos, qtdEventos, cidades, qtdCidades, apresentadores, qtdApresentadores); break; }
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
    int i = 0, f = qtdEv, x=0, y=0;
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
    		cout << "\n=====================================\n";
    		cout << "\nIncrição de participante concluida!!!\n";
    		cout << "\n=====================================\n";
    		cout << " - Segue detalhes do evento abaixo: ";
    		cout << "\n - Descrição: " << ev[m].descricao;
    		cout << "\n - Cidade: " << cid[x].nome;
    		cout << "\n - Apresentador: " << ap[y].nome;
    		cout << "\n - Precço do convite: " << ev[m].preco;
    		cout << "\n=====================================\n";
    		return true ;
		}
    	else {
    		cout << "\nO número de vagas para esse evento foi esgotada";
    		return false ;
		}
    }
    else {
		cout << "\n Evento não Encontrado!\n";
		return false ;	
	}
}

//
void leituraCidade(struct cidade x[], int &qtdCidades){
	int i = 0, t = 0;
	char verificador[1];
	for(; t == 0; i++){
		system("clear||cls");
		cout << "\t==========================\n";
		cout << "\t -- Cadastro de Cidade --\n";
		cout << "\t==========================\n";
		cout << "\nDigite o codigo da cidade: "; cin >> x[i].codigo; cin.ignore();
		cout << "\nDigite o nome da cidade: "; gets(x[i].nome);
		cout << "\nDigite a UF do municipio: "; gets(x[i].uf);
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
		cout << "\t================================\n";
		cout << "\t -- Cadastro de Apresentador --\n";
		cout << "\t================================\n";
		cout << "\nDigite o codigo do apresentador: "; cin >> x[i].codigo; cin.ignore();
		cout << "\nDigite o nome do apresentador: "; gets(x[i].nome);
		cout << "\nDeseja informar mais um apresentador? S/N: "; cin >> verificador; cin.ignore();
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
		cout << "\t==========================\n";
		cout << "\t -- Cadastro de Evento --\n";
		cout << "\t==========================\n";
		cout << "\n - Digite um número de código para o evento: "; cin >> ev[i].codigo; cin.ignore();
		cout << "\n - Digite uma descrição do evento: "; gets(ev[i].descricao);
		bool z = false ;
		for(int j = 0 ; z == false ; j++){
			if (j == 5 ) system("clear||cls");
			cout << "\n - Informe o código da cidade aonde ocorrerá o evento: "; cin >> ev[i].codCidade; cin.ignore();
			z = encontraCidade(cd, ev[i].codCidade, qtdCidades, x);
			if(z){
				cout << "\n==============================\n";
				cout << "> Cidade: " << cd[x].nome;
				cout << "\n> UF: " << cd[x].uf;
				cout << "\n==============================";
			} else cout << "\nCidade não encontrata!\n ";
		}
		z = false;
		for(int j = 0 ; z == false ; j++){
			if (j == 5) system("clear||cls");
			cout << "\n\nInforme o código do apresentador do evento: "; cin >> ev[i].codApresentador; cin.ignore();
	    	z = encontraApresentador(ap, ev[i].codApresentador, qtdAp, y);
	    	if (z) {
	    		cout << "\n==============================\n";
	    		cout << "> Apresentador: " << ap[y].nome;
	    		cout << "\n==============================";
			}
			else cout << "\n Apresentador não Encontrado!\n";
		}
		cout << "\n\n - Informe o limite de participantes do evento: "; cin >> ev[i].limiteParticipantes; cin.ignore();
		cout << "\n - Informe o preço do convite unitário do evento: "; cin >> ev[i].preco; cin.ignore();
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
		cout << "\t================================\n";
		cout << "\t -- Cadastro de Participante --\n";
		cout << "\t================================\n";
		cout << "\nDigite o código do participante: "; cin >> part[i].codigo; cin.ignore();
		cout << "\nDigite o nome do participante: "; gets(part[i].nome);
		cout << "\nO participante ja optou por um evento? S/N: "; gets(verificador);
		if (strcmp(verificador, "S") == 0 || strcmp(verificador, "s") == 0){
        	cout << "Informe o código do evento de escolha do participante: "; cin >> part[i].codEvento; cin.ignore();
			acrescentaParticipanteEvento(ev, qtdEv, part[i].codEvento, cd, qtdCidades, ap, qtdAp);
        }
		cout << "\nDeseja informar mais um participante? S/N: "; gets(verificador);
			if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            t++;
        }
	}
	qtdParticipante = i;
}


void consultarEvento(struct evento ev[], int qtdEvento, struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp){
	char verificador[1];
	int codigoConsulta, t = 0;
	for(;t == 0;){
		system("clear||cls");
		cout << "\t==========================\n";
		cout << "\t -- Consulta de Evento --\n";
		cout << "\t==========================\n";
		cout << "\n\n - Digite o código do evento para consulta: "; cin >> codigoConsulta; cin.ignore();
	    int i = 0, f = qtdEvento, x = 0, y = 0;
	    int m = (i + f) / 2;
	    for (; f >= i && codigoConsulta != ev[m].codigo; m = (i + f) / 2){
	        if (codigoConsulta > ev[m].codigo)
	            i = m + 1;
	        else
	            f = m - 1;
	    }
	    if (codigoConsulta == ev[m].codigo){
	    	cout << "==========================\n";
			cout << " -- Evento encontrado! --\n";
			cout << "==========================\n";
			cout << "\n- Código do evento: " << ev[m].codigo;
			cout << "\n\n- Descrição: " << ev[m].descricao;
			encontraCidade(cd, ev[m].codCidade, qtdCidades, x);
			cout << "\n\n- Cidade:" << cd[x].nome;
			encontraApresentador(ap, ev[m].codApresentador, qtdAp, y);
			cout << "\n\n- Apresentador: " << ap[y].nome;
			cout << "\n\n- Total de participantes: " << ev[m].qtdParticipantes;
			cout << "\n\n- Preço unitario do convite: R$ " << ev[m].preco;
			cout << "\n\n- Arrecadação: R$ " << (ev[m].qtdParticipantes*ev[m].preco);
	    }
	    else cout << "\nCódigo não encontrado!!!\n";
	    cout << "\nDeseja consultar mais um evento? S/N: "; gets(verificador);
	    if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            t++;
        }
    }
}

void mostrarTodosEventos(struct evento ev[], int qtdEvento, struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp){
	int codigoConsulta, t = 0;
	for(;t==0;){
		cout << "\t====================================\n";
		cout << "\t -- Todos os Eventos Cadastrados! -- \n";
		cout << "\t====================================\n";
		for (int i = 0 ; i < qtdEvento ; i++){
			int x,y;	
			cout << "\n- Código do evento: " << ev[i].codigo;
			cout << "\n\n- Descrição: " << ev[i].descricao;
			encontraCidade(cd, ev[i].codCidade, qtdCidades, x);
			cout << "\n\n- Cidade:" << cd[x].nome;
			encontraApresentador(ap, ev[i].codApresentador, qtdAp, y);
			cout << "\n\n- Apresentador: " << ap[y].nome;
			cout << "\n\n- Total de participantes: " << ev[i].qtdParticipantes;
			cout << "\n\n- Preço unitario do convite: R$ " << ev[i].preco;
			cout << "\n\n- Arrecadação: R$ " << (ev[i].qtdParticipantes*ev[i].preco);
			cout << "\n====================================";
		}
	    cout << "\n\n\nPara voltar ao menu Inicial, pressione [V]\n";
		char verificador = getch();
	    if (verificador == 'v' || verificador == 'V'){
            t++;
        }
    }
}








