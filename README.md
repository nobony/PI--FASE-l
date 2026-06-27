# 📊 Análise Comparativa de Desempenho: Busca Sequencial vs. Tabela Hash

> Projeto Integrador 2A – Estrutura de Dados · **Grupo 5** · Linguagem **C**
> Estudo experimental do impacto da estrutura de dados no tempo de busca, sobre um dataset real de **400.009 registros**.

---

## 🧭 Índice

- [Sobre o Projeto](#-sobre-o-projeto)
- [Destaques](#-destaques)
- [Objetivos](#-objetivos)
- [Conceitos Utilizados](#-conceitos-utilizados)
- [Estrutura do Projeto](#-estrutura-do-projeto)
- [Como Compilar e Executar](#️-como-compilar-e-executar)
- [Função Hash do Grupo](#-função-hash-grupo-5--meio-do-quadrado)
- [Protocolo Experimental](#-protocolo-experimental)
- [Resultados](#-resultados-obtidos)
- [Análise](#-análise)
- [Limitações e Melhorias](#️-limitações)
- [Autores](#-autores)

---

## 📌 Sobre o Projeto

Aplicação em **C** que lê um dataset real de produtos em CSV, carrega os dados em memória dinâmica e compara experimentalmente dois algoritmos de busca:

| Fase | Estrutura | Complexidade média |
| ---- | --------- | ------------------ |
| **Fase I** | Busca Sequencial sobre vetor dinâmico | O(n) |
| **Fase II** | Tabela Hash com encadeamento | O(1) |

O programa constrói a Tabela Hash, contabiliza colisões e mede o tempo médio de busca em diferentes cenários, permitindo quantificar na prática a diferença entre as complexidades teóricas.

---

## ⭐ Destaques

- 🗂️ **400.009 registros** carregados a partir de `dataset4.csv`.
- 🧮 **Tabela Hash** com tamanho igual ao volume de dados (fator de carga α ≈ 1).
- 🔗 **Tratamento de colisões por encadeamento** (listas ligadas).
- 📈 **143.107 colisões** contabilizadas (taxa ≈ 35,8%).
- ♻️ **Gestão de memória completa** — toda a memória alocada é liberada ao final.

---

## 🎯 Objetivos

- Implementar a **Tabela Hash com encadeamento** (chaining).
- Utilizar a **função hash designada ao Grupo 5** (Meio do Quadrado / Mid-Square).
- Definir o tamanho da tabela igual ao volume de dados do dataset.
- Contabilizar o **número total de colisões**.
- Medir o **tempo médio de busca** sob protocolo experimental padronizado.
- Comparar formalmente **Busca Sequencial × Tabela Hash**.

---

## 🧠 Conceitos Utilizados

- Tabela Hash e tratamento de colisões por **encadeamento**
- Função hash **Meio do Quadrado**: `h(k) = (k² / 100) mod m`
- Busca Sequencial — complexidade O(n)
- Tipos Abstratos de Dados (TAD) e modularização `.h` / `.c`
- Alocação e **liberação** de memória dinâmica
- Leitura de arquivos CSV e medição de tempo

---

## 📂 Estrutura do Projeto

```
📁 src
 ┣ 📁 Fase-I
 ┃ ┗ (implementação da Busca Sequencial — Fase I)
 ┃
 ┗ 📁 Fase-II
   ┣ 📁 include
   ┃ ┣ busca.h
   ┃ ┣ hash.h        ← estrutura da Tabela Hash e protótipos
   ┃ ┣ leitura.h
   ┃ ┣ produto.h
   ┃ ┣ tempo.h
   ┃ ┗ testes.h
   ┣ 📁 src
   ┃ ┣ busca.c
   ┃ ┣ hash.c        ← Tabela Hash com encadeamento
   ┃ ┣ leitura.c
   ┃ ┣ main.c
   ┃ ┣ produto.c
   ┃ ┣ tempo.c
   ┃ ┗ testes.c      ← protocolo experimental
   ┗ dataset4.csv
```

---

## ⚙️ Como Compilar e Executar

A partir da pasta da Fase II:

```bash
cd src/Fase-II
gcc src/*.c -Iinclude -o programa
```

> O `dataset4.csv` deve estar na **mesma pasta do executável** (o programa o carrega pelo nome `dataset4.csv`).

```bash
./programa
```

---

## 🔑 Função Hash (Grupo 5 — Meio do Quadrado)

A chave de busca é o **ID do produto** (`long int`). A função designada ao grupo eleva a chave ao quadrado, descarta dígitos das extremidades e aplica o módulo pelo tamanho da tabela:

```c
h(k) = (k² / 100) mod m
```

onde `m` é o tamanho da tabela, definido como **igual ao número de registros** (400.009), mantendo o fator de carga **α = n/m ≈ 1**.

---

## 🧪 Protocolo Experimental

1. A Tabela Hash é **totalmente carregada** antes de qualquer medição.
2. Para cada cenário são executadas **1.000 buscas consecutivas**:
   - Elemento no **início**, no **meio** e no **final** do dataset
   - Elemento **inexistente**
3. Mede-se o **tempo total** e calcula-se o **tempo médio** por busca.
4. Contabiliza-se o **número total de colisões** durante a inserção.

---

## 📊 Resultados Obtidos

**Carga**

| Métrica | Valor |
| ------- | ----- |
| Registros carregados | 400.009 |
| Total de colisões | 143.107 |
| Taxa de colisão | ≈ 35,8% |

**Tempo médio por busca (ms)**

| Cenário      | Busca Sequencial (Fase I) | Tabela Hash (Fase II) |
| ------------ | ------------------------- | --------------------- |
| Início       | 0.000545                  | ~0 (sub-resolução)    |
| Meio         | 0.834203                  | ~0 (sub-resolução)    |
| Final        | 1.971888                  | ~0 (sub-resolução)    |
| Inexistente  | 2.066933                  | ~0 (sub-resolução)    |
| Complexidade | O(n)                      | O(1) médio            |

> ⚠️ **Nota de medição:** com 1.000 buscas O(1), o tempo da Tabela Hash fica abaixo da resolução de `clock()`. Para obter valores numéricos confiáveis, recomenda-se um cronômetro de alta resolução (`clock_gettime` / `QueryPerformanceCounter`) ou aumentar para ~1.000.000 de buscas.

---

## 🔍 Análise

A busca sequencial confirma o comportamento **linear O(n)**: o pior caso (inexistente) foi ≈ **3.800× mais lento** que o melhor caso. A Tabela Hash mantém desempenho **praticamente constante** em todos os cenários, validando a complexidade média **O(1)** mesmo com 35,8% de colisões tratadas por encadeamento.

---

## ⚠️ Limitações

- Maior consumo de memória (ponteiros + listas ligadas).
- No pior caso (todas as chaves no mesmo índice), degrada para O(n).
- Não mantém os dados ordenados (inviabiliza busca por intervalo).

## 🚀 Possíveis Melhorias

- Cronômetro de alta resolução para medir o tempo real da hash.
- Funções hash alternativas (multiplicação, hashing universal) para reduzir colisões.
- Comparação com árvores balanceadas (AVL, Red-Black) — O(log n).

---

## 👨‍💻 Autores

| Integrante | Matrícula |
| ---------- | --------- |
| Pedro de Faria Mello | 2512130037 |
| Sofia de Carvalho Brito | 2512130063 |
| Victor Sousa Pereira | 2512130015 |

---

## 📚 Referências

- CORMEN, T. H. et al. *Algoritmos: Teoria e Prática*. 3. ed. Elsevier.
- KNUTH, D. E. *The Art of Computer Programming, Vol. 3: Sorting and Searching*.
- ZIVIANI, N. *Projeto de Algoritmos com Implementações em Pascal e C*.
- Documentação da linguagem C (ISO/IEC 9899).

---

## 📌 Observação

Projeto de fins acadêmicos, desenvolvido para a disciplina de Estruturas de Dados (análise de algoritmos).
