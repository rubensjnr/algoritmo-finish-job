#include <iostream> ////////////////////////////////////////////////
#include <conio.h>  // Aluno: Rubens da Cunha Junior
#include <stdlib.h> // R.A: 2211550375
#include <locale.h> // Curso: Analise e Desenvolvimento de Sistemas
#include <string.h> // Ano: 2º - Turma 2 - Sala 13
#include <math.h>	////////////////////////////////////////////////
#include <cstring>
#include <stdio.h>
using namespace std;
//structs
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
//prototipação
bool encontraCidade(struct cidade cd[], int codCidade, int qtdCidades, int &cod);
bool encontraApresentador(struct apresentador ap[], int codAp, int qtdAp, int &cod);
bool acrescentaParticipanteEvento(struct evento ev[],int qtdEv, int codEv, struct cidade cid[], int qtdCidades, struct apresentador ap[], int qtdAp);
void leituraCidade(struct cidade cd[], int &qtdCidades);
void leituraApresentador(struct apresentador ap[], int &qtdApresentador);
void leituraEvento(struct evento ev[], struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp, int &qtdEv);
void leituraParticipante(struct participante part[], struct evento ev[],int qtdEv, int &qtdParticipante, struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp);
void consultarEvento(struct evento ev[], int qtdEvento, struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp);
void mostrarTodosEventos(struct evento ev[], int qtdEvento, struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp);
void inserirNovoEvento(struct evento ev[], int qtdEventos, struct evento tr[], int qtdTransacao, struct evento at[],
					   struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp, int &att);
void inserirNovoApresentador(struct apresentador ap[], int qtdAp, struct apresentador tr[], int qtdTr, struct apresentador att[], int &qtdAt);
void atualizarTabelaInicialApresentador(struct apresentador ap[], int &qtdApresentador, struct apresentador att[], int qtdAtualizada);
void atualizarTabelaEvento(struct evento ev[], int &qtdEventos, struct evento att[], int qtdAtualizada);
void menuPrincipal();
//main
int main(){
	system("Color E0");
	setlocale(LC_ALL,"Portuguese");
	int qtdCidades, qtdApresentadores, qtdEventos, qtdParticipantes, qtdEvTransacao, qtdEvAtualizada, qtdApTransacao, qtdApAtualizada;
	cidade cidades[100];
	apresentador apresentadores[100], tabelaApresentadoresTransacao[100], tabelaApresentadoresAtualizada[100];
	evento eventos[100], tabelaEventoTransacao[100], tabelaEventoAtualizada[100];
	participante participantes[100];
	//menu
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
		case 5: {system("clear||cls");
				inserirNovoApresentador(apresentadores, qtdApresentadores, tabelaApresentadoresTransacao, qtdApTransacao,
										tabelaApresentadoresAtualizada, qtdApAtualizada);
				atualizarTabelaInicialApresentador(apresentadores, qtdApresentadores, tabelaApresentadoresAtualizada, qtdApAtualizada);
				break;}
		case 6: { system("clear||cls"); inserirNovoEvento(eventos, qtdEventos, tabelaEventoTransacao, qtdEvTransacao, tabelaEventoAtualizada,
														  cidades, qtdCidades, apresentadores, qtdApresentadores, qtdEvAtualizada);
										atualizarTabelaEvento(eventos, qtdEventos, tabelaEventoAtualizada, qtdEvAtualizada); break; }
		case 7: { system("clear||cls"); consultarEvento(eventos, qtdEventos, cidades, qtdCidades, apresentadores, qtdApresentadores); break; }
		case 8: { system("clear||cls"); mostrarTodosEventos(eventos, qtdEventos, cidades, qtdCidades, apresentadores, qtdApresentadores); break; }
  		case 9: { op = -1; return 0;  break; }
		default : { cout << "\n\nOpcao invalida. Tecle algo para continuar..."; getch(); }
		}
	}
}
//funções
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
    int i = 0, f = qtdEv, indiceCidade=0, indiceApresentador=0;
    int m = (i + f) / 2;
    
    for (; f >= i && codEv != ev[m].codigo; m = (i + f) / 2){
        if (codEv > ev[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codEv == ev[m].codigo){
    	encontraCidade(cid, ev[m].codCidade,qtdCidades, indiceCidade);
    	encontraApresentador(ap, ev[m].codApresentador, qtdAp, indiceApresentador);
    	if (ev[m].qtdParticipantes < ev[m].limiteParticipantes){
    		ev[m].qtdParticipantes++;
    		cout << "\n=====================================\n";
    		cout << "\nIncrição de participante concluida!!!\n";
    		cout << "\n=====================================\n";
    		cout << " - Segue detalhes do evento abaixo: ";
    		cout << "\n - Descrição: " << ev[m].descricao;
    		cout << "\n - Cidade: " << cid[indiceCidade].nome;
    		cout << "\n - Apresentador: " << ap[indiceApresentador].nome;
    		cout << "\n - Preço do convite: " << ev[m].preco;
    		cout << "\n=====================================\n";
    		return true ;
		}
    	else {
    		cout << "\nO número de vagas para esse evento foi esgotada\n";
    		return false ;
		}
    }
    else {
		cout << "\n Evento não Encontrado!\n";
		return false ;	
	}
}
void leituraCidade(struct cidade cd[], int &qtdCidades){
	int i = 0, condicaoLoopInsercao = 0;
	char verificador[1];
	for(; condicaoLoopInsercao == 0; i++){
		bool verificadorDeCodigoCidade = false;
    	while (!verificadorDeCodigoCidade) {
    		system("clear||cls");
			cout << "\t==========================\n";
			cout << "\t -- Cadastro de Cidade --\n";
			cout << "\t==========================\n";
        	cout << "\nDigite o codigo da cidade: "; cin >> cd[i].codigo; cin.ignore();
			verificadorDeCodigoCidade = true;
        	for (int j = 0; j < i ; j++) 
           		if (cd[i].codigo == cd[j].codigo) {
               		verificadorDeCodigoCidade = false;
               		cout << "\nCodigo de cidade invalido ou já informado!!!\n";
					cout << "\nPressione uma tecla para inserir outro codigo...\n"; cin.get();
               		break; 
       	    	}
   			}
		cout << "\nDigite o nome da cidade: "; gets(cd[i].nome);
		cout << "\nDigite a UF do municipio: "; gets(cd[i].uf);
		cout << "\nDeseja informar mais uma cidade? S/N: "; cin >> verificador; cin.ignore();
		cout << "\n";
        if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            condicaoLoopInsercao++;
        }
	}
	qtdCidades = i;
}
void leituraApresentador(struct apresentador ap[], int &qtdApresentador){
	int i = 0, condicaoLoopInsercao = 0;
	char verificador[1];
	for(; condicaoLoopInsercao == 0 ; i++){
		bool verificadorDeCodigoApresentador = false;
    	while (!verificadorDeCodigoApresentador) {
		system("clear||cls");
		cout << "\t================================\n";
		cout << "\t -- Cadastro de Apresentador --\n";
		cout << "\t================================\n";
		cout << "\n- Digite o codigo do apresentador: "; cin >> ap[i].codigo; cin.ignore();
		verificadorDeCodigoApresentador = true;
		for (int j = 0; j < i; j++) 
            if (ap[i].codigo == ap[j].codigo) {
                verificadorDeCodigoApresentador = false;
                cout << "\nCodigo de apresentador já informado!!!\n";
				cout << "\nPressione uma tecla para inserir outro codigo...\n"; getch();
                break; 
        	}
    	}
		cout << "\n- Digite o nome do apresentador: "; gets(ap[i].nome);
		cout << "\n- Deseja informar mais um apresentador? S/N: "; cin >> verificador; cin.ignore();
		if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            condicaoLoopInsercao++;
        }
	}
	qtdApresentador = i;
}
void leituraEvento(struct evento ev[], struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp, int &qtdEv){
	int i = 0, condicaoLoopInsercao = 0, numIndexCidade = 0, numIndexApresentador = 0;
	char verificador[1];
	for(; condicaoLoopInsercao == 0 ; i++){
		bool verificadorDeCodigoEvento = false;
    	while (!verificadorDeCodigoEvento) {
		system("clear||cls");
		cout << "\t==========================\n";
		cout << "\t -- Cadastro de Evento --\n";
		cout << "\t==========================\n";
		cout << "\n - Digite um número de código para o evento: "; cin >> ev[i].codigo; cin.ignore();
		verificadorDeCodigoEvento = true;
		for (int j = 0; j < i; j++) 
            if (ev[i].codigo == ev[j].codigo) {
                verificadorDeCodigoEvento = false;
                cout << "\nCodigo de evento já informado!!!\n";
				cout << "\nPressione uma tecla para inserir outro codigo...\n"; getch();
                break; 
        	}
    	}
		cout << "\n - Digite uma descrição do evento: "; gets(ev[i].descricao);
		bool verificadorDeBusca = false ;
		for(int j = 0 ; verificadorDeBusca == false ; j++){
			if (j == 5 ) system("clear||cls");
			cout << "\n - Informe o código da cidade aonde ocorrerá o evento: "; cin >> ev[i].codCidade; cin.ignore();
			verificadorDeBusca = encontraCidade(cd, ev[i].codCidade, qtdCidades, numIndexCidade);
			if(verificadorDeBusca){
				cout << "\n==============================\n";
				cout << "- Cidade: " << cd[numIndexCidade].nome;
				cout << "\n- UF: " << cd[numIndexCidade].uf;
				cout << "\n==============================";
			} else cout << "\nCidade não encontrata!\n ";
		}
		verificadorDeBusca = false;
		for(int j = 0 ; verificadorDeBusca == false ; j++){
			if (j == 5) system("clear||cls");
			cout << "\n\n - Informe o código do apresentador do evento: "; cin >> ev[i].codApresentador; cin.ignore();
	    	verificadorDeBusca = encontraApresentador(ap, ev[i].codApresentador, qtdAp, numIndexApresentador);
	    	if (verificadorDeBusca) {
	    		cout << "\n==============================\n";
	    		cout << "- Apresentador: " << ap[numIndexApresentador].nome;
	    		cout << "\n==============================";
			}
			else cout << "\n Apresentador não Encontrado!\n";
		}
		cout << "\n\n - Informe o limite de participantes do evento: "; cin >> ev[i].limiteParticipantes; cin.ignore();
		cout << "\n - Informe o preço do convite unitário do evento: "; cin >> ev[i].preco; cin.ignore();
		cout << "\n - Deseja informar mais um evento? S/N: "; cin >> verificador; cin.ignore();
		
		if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            condicaoLoopInsercao++;
        }
	}
	qtdEv = i;
}
void leituraParticipante(struct participante part[], struct evento ev[],int qtdEv, int &qtdParticipante, struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp){
	int i = 0, condicaoLoopInsercao = 0;
	char verificador[1];
	for(; condicaoLoopInsercao==0 ; i++){
		bool verificaExistenciaEvento = false;
		bool verificadorDeCodigoParticipante = false;
    	while (!verificadorDeCodigoParticipante) {
		system("clear||cls");
		cout << "\t================================\n";
		cout << "\t -- Cadastro de Participante --\n";
		cout << "\t================================\n";
		cout << "\nDigite o código do participante: "; cin >> part[i].codigo; cin.ignore();
		verificadorDeCodigoParticipante = true;
		for (int j = 0; j < i; j++) 
            if (part[i].codigo == part[j].codigo) {
                verificadorDeCodigoParticipante = false;
                cout << "\nCodigo de participante já informado!!!\n";
				cout << "\nPressione uma tecla para inserir outro codigo...\n"; getch();
                break; 
        	}
    	}
		cout << "\nDigite o nome do participante: "; gets(part[i].nome);
        for(;verificaExistenciaEvento == false;){
        	cout << "\nInforme o código do evento de escolha do participante: "; cin >> part[i].codEvento; cin.ignore();
			verificaExistenciaEvento = acrescentaParticipanteEvento(ev, qtdEv, part[i].codEvento, cd, qtdCidades, ap, qtdAp);
			if(!verificaExistenciaEvento){
				cout << "\nDeseja escolher outro evento? S/N: "; gets(verificador);
				if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
	            verificaExistenciaEvento = true;
	            system("clear||cls");
        }
		}
	}	
		cout << "\nDeseja informar mais um participante? S/N: "; gets(verificador);
			if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            condicaoLoopInsercao++;
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
		cout << "\n - Digite o código do evento para consulta: "; cin >> codigoConsulta; cin.ignore();
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
	    else cout << "\n\nCódigo não encontrado!!!\n";
	    cout << "\n\nDeseja consultar mais um evento? S/N: "; gets(verificador);
	    if (strcmp(verificador, "n") == 0 || strcmp(verificador, "N") == 0){
            t++;
        }
    }
}
void mostrarTodosEventos(struct evento ev[], int qtdEvento, struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp){
	int codigoConsulta, t = 0;
	for(; t==0 ;){
		float valorTotalEventos = 0;
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
			valorTotalEventos += (ev[i].qtdParticipantes*ev[i].preco);
			cout << "\n=================================================================";
		}
		cout << "\n\t- O valor total arrecadado de todos os eventos é: R$ " << valorTotalEventos;
		cout << "\n=================================================================";
	    cout << "\n\n\tPara voltar ao menu Inicial, pressione [V]\n";
		char verificador = getch();
	    if (verificador == 'v' || verificador == 'V'){
            t++;
        }
    }
}
void inserirNovoEvento(struct evento ev[], int qtdEventos, struct evento tr[], int qtdTransacao, struct evento at[],
struct cidade cd[], int qtdCidades, struct apresentador ap[], int qtdAp, int &att){
	leituraEvento(tr, cd, qtdCidades, ap, qtdAp, qtdTransacao);
    int i = 0, j = 0, k = 0;
    for (;i < qtdEventos && j < qtdTransacao;k++){
        if (ev[i].codigo < tr[j].codigo){
            at[k].codigo = ev[i].codigo;
            at[k].codCidade = ev[i].codCidade;
            at[k].codApresentador = ev[i].codApresentador;
            at[k].qtdParticipantes = ev[i].qtdParticipantes;
            at[k].limiteParticipantes = ev[i].limiteParticipantes;
            at[k].preco = ev[i].preco;
            strcpy(at[k].descricao,ev[i].descricao);
            i++;
            }
        else {
            at[k].codigo = tr[j].codigo;
            at[k].codCidade = tr[j].codCidade;
            at[k].codApresentador = tr[j].codApresentador;
            at[k].qtdParticipantes = tr[j].qtdParticipantes;
            at[k].limiteParticipantes = tr[j].limiteParticipantes;
            at[k].preco = tr[j].preco;
            strcpy(at[k].descricao,tr[j].descricao);
            j++;
        }
    }
    while (i < qtdEventos){
		at[k].codigo = ev[i].codigo;
        at[k].codCidade = ev[i].codCidade;
        at[k].codApresentador = ev[i].codApresentador;
        at[k].qtdParticipantes = ev[i].qtdParticipantes;
    	at[k].limiteParticipantes = ev[i].limiteParticipantes;
        at[k].preco = ev[i].preco;
        strcpy(at[k].descricao,ev[i].descricao);		
        i++;
        k++;
    }
    while (j < qtdTransacao){
		at[k].codigo = tr[j].codigo;
        at[k].codCidade = tr[j].codCidade;
        at[k].codApresentador = tr[j].codApresentador;
        at[k].qtdParticipantes = tr[j].qtdParticipantes;
        at[k].limiteParticipantes = tr[j].limiteParticipantes;
        at[k].preco = tr[j].preco;
        strcpy(at[k].descricao,tr[j].descricao);
        j++;
        k++;
    }
    att = k;
}
void inserirNovoApresentador(struct apresentador ap[], int qtdAp, struct apresentador tr[], int qtdTr, struct apresentador att[], int &qtdAt){
	leituraApresentador(tr, qtdTr);
	int i = 0, j = 0, k = 0;
    for (;i < qtdAp && j < qtdTr;k++){
        if (ap[i].codigo < tr[j].codigo){
            att[k].codigo = ap[i].codigo;
            strcpy(att[k].nome,ap[i].nome);
            i++;
            }
        else {
            att[k].codigo = tr[j].codigo;
            strcpy (att[k].nome,tr[j].nome);
            j++;
        }
    }
    while (i < qtdAp){
        att[k].codigo = ap[i].codigo;
        strcpy(att[k].nome,ap[i].nome);
        i++;
        k++;
    }
    while (j < qtdTr){
        att[k].codigo = tr[j].codigo;
        strcpy(att[k].nome,tr[j].nome);
        j++;
        k++;
    }
    qtdAt = k;
}
void atualizarTabelaInicialApresentador(struct apresentador ap[], int &qtdApresentador, struct apresentador att[], int qtdAtualizada){
	qtdApresentador = qtdAtualizada;
	for(int i = 0 ; i < qtdApresentador ; i++ ){
		ap[i].codigo = att[i].codigo;
		strcpy(ap[i].nome,att[i].nome);
	}
}
void atualizarTabelaEvento(struct evento ev[], int &qtdEventos, struct evento att[], int qtdAtualizada){
	qtdEventos = qtdAtualizada;
	for(int i = 0 ; i < qtdEventos ; i++){
		ev[i].codigo = att[i].codigo;
		ev[i].codCidade = att[i].codCidade;
		ev[i].codApresentador = att[i].codApresentador;
		ev[i].qtdParticipantes = att[i].qtdParticipantes;
		ev[i].limiteParticipantes = att[i].limiteParticipantes;
		ev[i].preco = att[i].preco;
		strcpy(ev[i].descricao,att[i].descricao);
	}
}
