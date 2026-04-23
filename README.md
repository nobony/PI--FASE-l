PI - Fase I: IMPLEMENTAÇÃO E ANÁLISE DE BUSCA EM ESTRUTURAS DE DADOS

Este repositório contém o desenvolvimento da primeira fase do Projeto Integrador, focado na leitura, estruturação e análise de desempenho de busca em grandes conjuntos de dados.

🎯 Sobre o Projeto 🎯

O que este app faz?

Esta aplicação é um motor de busca e processamento de dados de alta performance para inventários. Ele realiza a leitura automatizada de arquivos estruturados (CSV) com mais de 400 mil registros, carrega essas informações na memória RAM do computador e permite buscas instantâneas por IDs específicos, reportando o tempo exato de processamento da CPU em milissegundos.

Por que foi construído?

O sistema foi criado como parte do Projeto Integrador de Estrutura de Dados. O propósito é acadêmico e científico: validar na prática a teoria da Complexidade Linear $O(n)$. Através deste app, estabelecemos um baseline (ponto de partida) para provar o quanto uma busca sequencial pode ser lenta em grandes datasets, justificando a evolução para estruturas mais complexas como as Tabelas Hash na próxima etapa.

📊 Resultados Obtidos (Baseline)

Com um dataset de 400.009 registros, obtivemos os seguintes tempos:

<img width="543" height="170" alt="image" src="https://github.com/user-attachments/assets/2a724d3e-f513-490b-8052-5c978b57d1ae" />









🚀 Como Executar

1. Clone o repositório: git clone https://github.com/seu-usuario/PI--FASE-I.git
2. Compile o projeto: gcc src/*.c -o programa
3. Execute: ./programa

👥 Integrantes

VICTOR SOUSA PEREIRA - 2512130015

PEDRO DE FARIA MELLO - 2512130037

SOFIA DE CARVALHO - 2512130063



