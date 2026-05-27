#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

int main () {

    // ENTRADA 
    string nomes[20];
    int qtdAlunos, qtdDisciplinas;
    float notas[20][5];
    float media[20];
    

    cout << "====== SISTEMA DE NOTAS v5.0 ======" << endl;

    do {
        cout << "Quantidade de alunos (1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore(); 

    for (int i = 0; i < qtdAlunos; i++) {
        cout << "Nome do aluno " << i + 1 << ": ";
        getline(cin, nomes[i]);
    }
      // NOTAS E MÉDIAS

    do {
        cout << "\nQuantidade de disciplinas (1 a 5): ";
        cin >> qtdDisciplinas;
    } while (qtdDisciplinas < 1 || qtdDisciplinas > 5);

    // PROCESSAMENTO

    //LEITURA DE ALUNOS (Commit 1)
    for (int i = 0; i < qtdAlunos; i++) {
        float somaAluno = 0; 
        
        cout << "\nDigitando notas de: " << nomes[i] << endl;
        
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
        
        media[i] = somaAluno / qtdDisciplinas;
    }

    // SAÍDA

    // CLASSIFICAÇÃO E RELATÓRIO
    cout << "\n==========================================" << endl;
    cout << "            RELATORIO DE NOTAS            " << endl;
    cout << "==========================================" << endl;
    int aprovados = 0, recuperacao = 0, reprovados = 0;


    for (int i = 0; i < qtdAlunos; i++) {
        cout << i + 1 << ". " << nomes[i] << "\t | Media: " << media[i];

        
        if (media[i] >= 7.0) {
            cout << " | Status: APROVADO" << endl;
        } else if (media[i] >= 5.0) {
            cout << " | Status: RECUPERACAO" << endl;
        } else {
            cout << " | Status: REPROVADO" << endl;
        }
    }
      

    // SALVAR EM ARQUIVO (Commit 4)
  ofstream arquivo("relatorio.txt");

  if(arquivo.is_open()) {
    arquivo <<"=== RELATÓRIO ===" << endl;
    for (int i = 0; i < qtdAlunos; i ++) {
        arquivo << nomes[i] << "- Média: " << media[i] << "-";
        if (media[i] >= 7){
            arquivo <<"Aprovado" << endl;
        } else if (media[i] >= 5){
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



    return 0;
}