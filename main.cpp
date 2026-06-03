#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;

int main () {

    // ENTRADA 
    string nomes[20];
    int qtdAlunos, qtdDisciplinas;
    float notas[20][5];
    float medias[20];
    int opcaoInicial;



    cout << "====== SISTEMA DE NOTAS v4.0 ======" << endl;
    cout << "1 - Novo Relatório"<< endl;
    cout << "2 - Ver relatório salvo" << endl;
    cout << "Escolha uma opção: " << endl;
    cin >> opcaoInicial;
       


    // LEITURA DE ARQUIVO (commit 5)
    if (opcaoInicial == 2) {
     ifstream leitura ("relatorio.txt");
     if (leitura.is_open()){
        string linha;
        cout << "\n";
        while (getline(leitura, linha)) {
            cout << linha << endl;
        }
        leitura.close();
         } else {
            cout << "Nenhum relatório encontrado. " << endl;
       }
    }


      if (opcaoInicial == 3){
      cout <<"\n === SOBRE === " << endl;
      cout <<"Sistemas de notas v4.0" << endl;
      cout << "Desenvolvido por: " << endl;
      cout << "Turma: LOPAL 2026 - SENAI-SP" << endl;
      }

     if (opcaoInicial == 4){
      ifstream leituraRep ("reprovados.txt");
      if(leituraRep.is_open()){
        string linha;
        cout <<"\n";
        while (getline(leituraRep, linha)){
            cout << linha << endl;
        }
        leituraRep.close();
      } else {
        cout << "Nenhum relatório de reprovados encontrado ou crie um Novo Relatório";
      }

     }

    do {
        cout << "Quantidade de alunos (1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore(); 

    for (int i = 0; i < qtdAlunos; i++) {
        
        
        do{
        cout << "Nome do aluno " << i + 1 << ": ";
        getline(cin, nomes[i]);
    if (nomes[i] == " "){
        cout << "[ERRO] o nome nao pode ser vazio! Digite Novamente. " << endl;
      }
     } while (nomes[i] == " ");
   }

    do {
        cout << "\nQuantidade de disciplinas (1 a 5): ";
        cin >> qtdDisciplinas;
    } while (qtdDisciplinas < 1 || qtdDisciplinas > 5);

    // PROCESSAMENTO

    //LEITURA DE ALUNOS (Commit 1)
    for (int i = 0; i < qtdAlunos; i++) {
        float somaAluno = 0; 
        
        cout << "\nDigitando notas de: " << nomes[i] << endl;

        
        // NOTAS E MEDIAS
        for (int j = 0; j < qtdDisciplinas; j++) {
            do {
                cout << "  Nota da Disciplina " << j + 1 << " (0 a 10): ";
                cin >> notas[i][j];
                
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    cout << "  [ERRO] Nota invalida! Digite entre 0 e 10." << endl;
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
            
            somaAluno += notas[i][j];
        }
        
        medias[i] = somaAluno / qtdDisciplinas;
    }

    // SAÍDA

    // CLASSIFICAÇÃO E RELATÓRIO
    cout << "\n==========================================" << endl;
    cout << "            RELATORIO DE NOTAS            " << endl;
    cout << "==========================================" << endl;
    int aprovados = 0, recuperacao = 0, reprovados = 0;
   
    float maiorNota = -1.0;
    float menorNota = 11.0;
    string alunoMaior = " ";
    string alunoMenor = " ";
    

    for (int i = 0; i < qtdAlunos; i++) {
        cout << i + 1 << ". " << nomes[i] << "\t | Media: " << medias[i];

        
        if (medias[i] >= 7.0) {
            cout << " | Status: APROVADO" << endl;
            aprovados ++;
        } else if (medias[i] >= 5.0) {
            cout << " | Status: RECUPERACAO" << endl;
            recuperacao ++;
        } else {
            cout << " | Status: REPROVADO" << endl;
            reprovados ++;
        }
    
      
    if (medias[i] > maiorNota){
        maiorNota = medias[i];
        alunoMaior = nomes[i];
     }
    if (medias[i] < menorNota){
        menorNota = medias[i];
        alunoMaior = nomes[i];
      }
    }

     cout << "\nMaior media: " << alunoMaior << "(" << maiorNota << ")" << endl;
     cout << "Menor media: " << alunoMenor << " (" << menorNota << ")" << endl;

    // SALVAR EM ARQUIVO (Commit 4)

  ofstream arquivo("relatorio.txt");

  if(arquivo.is_open()) {
  time_t agora = time (0);
  char* dataHora = ctime (&agora);

  arquivo << " Data do relatorio: " << dataHora;
  arquivo << "===== RELATORIO =====" << endl;



    arquivo <<"=== RELATÓRIO ===" << endl;
    for (int i = 0; i < qtdAlunos; i ++) {
        arquivo << nomes[i] << "- Média: " << medias[i] << "-";
        if (medias[i] >= 7.0){
            arquivo <<"Aprovado" << endl;
        } else if (medias[i] >= 5){
            arquivo <<"Recuperação" << endl;
        } else {
            arquivo <<"Reprovado" << endl;
        }
    }
    arquivo << "\nResumo: " << aprovados << "aprovados," << recuperacao << "em recuperação," << reprovados <<"reprovados." << endl;

    arquivo.close ();
    cout << "\nRelatório salvo em relatorio.txt" << endl;
  }
  else
  {
    cout << "Erro ao criar arquivo." << endl;
  }


  ofstream arqReprovados("reprovados.txt");

  if (arqReprovados.is_open()){
    arqReprovados << "==== RELATORIO DE REPROVADOS ====" << endl;
    for (int i = 0; i < qtdAlunos; i++){
    
       if (medias[i] < 5.0){
        arqReprovados << nomes[i] << " - Media: " << medias[i] << " - Reprovado" << endl;
       }
    }
    arqReprovados.close();
    cout <<"Relatorio de reprovados salvo em reprovados.txt" << endl;
  } else {
    cout << "Erro ao criar arquivo de reprovados." << endl;
  }


    return 0;
}