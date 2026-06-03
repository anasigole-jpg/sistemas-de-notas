# 📊 Sistema de Gestão de Notas v5.0

Este é um programa desenvolvido em **C++** projetado para gerenciar o desempenho acadêmico de alunos. O sistema permite a entrada de dados, cálculo automático de médias, classificação de status (Aprovado/Recuperação/Reprovado) e persistência de dados em arquivos de texto.

## 🚀 Funcionalidades

- **Cadastro Flexível**: Suporta até 20 alunos e até 5 disciplinas por relatório.
- **Validação de Dados**: Garante que as notas inseridas estejam sempre no intervalo entre 0 e 10.
- **Cálculo de Média**: Processamento automático da média aritmética de cada aluno.
- **Classificação de Status**:
    - **Aprovado**: Média ≥ 7.0
    - **Recuperação**: Média entre 5.0 e 6.9
    - **Reprovado**: Média < 5.0
- **Persistência de Dados**: Salva automaticamente o relatório final em um arquivo chamado `relatorio.txt`.
- **Módulo de Leitura**: Opção para visualizar o histórico de notas salvo anteriormente sem precisar reiniciar o cadastro.

## 🛠️ Tecnologias Utilizadas

- **Linguagem**: C++
- **Bibliotecas**:
    - `iostream`: Entrada e saída de dados via console.
    - `string`: Manipulação de textos/nomes.
    - `fstream`: Manipulação de arquivos (leitura e escrita).
    - `windows.h`: Suporte para funcionalidades do sistema operacional.

## 📋 Como usar

1.  **Compilação**: Utilize um compilador C++ (como o G++):
    ```bash
    g++ sistema_notas.cpp -o sistema_notas
    ```
2.  **Execução**:
    ```bash
    ./sistema_notas
    ```
3.  **Fluxo**:
    - Escolha entre criar um **Novo Relatório** ou **Ver relatório salvo**.
    - Informe a quantidade de alunos e seus respectivos nomes.
    - Insira as notas por disciplina.
    - O sistema exibirá o relatório na tela e salvará uma cópia no arquivo `relatorio.txt`.

## 📂 Estrutura do Arquivo de Saída

O arquivo gerado (`relatorio.txt`) segue este padrão:
```text
=== RELATÓRIO ===
João Silva - Média: 8.5 - Aprovado
Maria Souza - Média: 6.0 - Recuperação
...
Resumo: 1 aprovados, 2 em recuperação, 0 reprovados.