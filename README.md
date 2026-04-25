# 📊 Análise de Performance de Busca Sequencial em C

## 📌 Sobre o Projeto

Este projeto foi desenvolvido para a disciplina **Projeto Integrador 2A - Estrutura de Dados** com o objetivo de analisar o desempenho do algoritmo de **Busca Sequencial (Linear)** em diferentes cenários.

A aplicação foi implementada em linguagem C e realiza a leitura de um dataset em formato CSV, armazenando os dados em memória dinâmica para posteriormente executar buscas e medir o tempo de execução.

---

## 🎯 Objetivos

* Implementar a **busca sequencial** em um vetor dinâmico
* Medir o tempo de execução em diferentes casos:

  * Início
  * Meio
  * Final
  * Elemento inexistente
* Analisar empiricamente a complexidade do algoritmo
* Aplicar conceitos de:

  * Estruturas de Dados
  * Alocação dinâmica
  * Modularização em C
  * Manipulação de arquivos CSV

---

## 🧠 Conceitos Utilizados

* Busca Sequencial — complexidade O(n)
* Tipos Abstratos de Dados (TAD)
* Modularização com `.h` e `.c`
* Leitura de arquivos CSV
* Medição de tempo com `clock()`

---

## 📂 Estrutura do Projeto

```
📁 src
 ┣ 📁 include
 ┃ ┣ busca.h
 ┃ ┣ leitura.h
 ┃ ┣ produto.h
 ┃ ┣ tempo.h
 ┃ ┗ teste.h
 ┃
 ┣ 📁 src
 ┃ ┣ busca.c
 ┃ ┣ leitura.c
 ┃ ┣ main.c
 ┃ ┣ produto.c
 ┃ ┣ tempo.c
 ┃ ┗ teste.c
 ┃
 ┗ 📁 data
   ┗ dataset4.csv
```

---

## ⚙️ Como Compilar e Executar

### 🔧 Compilação

```bash
gcc src/*.c -Iinclude -o programa
```

### ▶️ Execução

```bash
./programa
```

---

## 🧪 Metodologia de Testes

O programa executa:

* Leitura completa do dataset
* 1000 buscas consecutivas para cada cenário:

  * Elemento no início
  * Elemento no meio
  * Elemento no final
  * Elemento inexistente
* Cálculo de:

  * Tempo total (ms)
  * Tempo médio por busca

---

## 📊 Resultados Obtidos

| Caso        | Tempo Total (ms) | Tempo Médio (ms) |
| ----------- | ---------------- | ---------------- |
| Início      | 0.545            | 0.000545         |
| Meio        | 834.203          | 0.834203         |
| Final       | 1971.888         | 1.971888         |
| Inexistente | 2066.933         | 2.066933         |

### 🔍 Análise

Os resultados demonstram claramente o comportamento linear da busca sequencial:

* Melhor caso → O(1)
* Pior caso → O(n)

O pior caso foi aproximadamente **3800 vezes mais lento** que o melhor caso, evidenciando o impacto da posição do elemento no vetor.

---

## ⚠️ Limitações

* Resultados podem variar devido a:

  * Cache da CPU
  * Processos do sistema operacional
  * Variações de hardware

* A busca sequencial não é eficiente para grandes volumes de dados

---

## 🚀 Possíveis Melhorias

* Implementar **Busca Binária** (com dados ordenados)
* Utilizar **Tabelas Hash**
* Comparar desempenho entre diferentes algoritmos
* Otimizar leitura do CSV

---

## 👨‍💻 Autores

* Pedro de Faria Mello - 2512130037
* Sofia de Carvalho Brito - 2512130063
* Victor Sousa Pereira - 2512130015

---

## 📚 Referências

* CORMEN, T. H. et al. *Algoritmos: Teoria e Prática*
* ZIVIANI, N. *Projeto de Algoritmos*
* Documentação da linguagem C (ISO/IEC 9899)

---

## 📌 Observação

Este projeto tem fins acadêmicos e foi desenvolvido como parte do estudo de análise de algoritmos e estruturas de dados.

---



