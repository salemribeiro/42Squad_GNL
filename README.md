# 42_GNL
Repositório de desenvolvimento do projeto Get Next Line da 42SP


FUNCAO PRINCIPAL ( get_next_line )
 Responsavel por executar a leitura das linhas de um arquivo, realizando
  isto atraves de um loop, carregando os dados em pates discretas cujo o
   tamanho é definido em tempo de compilacao atraves da flag "BUFFER_SIZE".
        (gcc -Wall -Wextra -Wextra -D BUFFER_SIZE=70 -g *.c)
 As partes sao unidas formando uma linha e sua completude e definida após a
   obtencao do caracter '\ n'.
 O termino funcao é feito após o encontro de um '\ n', '\ 0', erro ou fim de
   arquivo "EOF".
 O objetivo principal do exercicio e o entendimento do modificador "static"
   utilizado na persistencia de dados em memória, treino com a biblioteca
   de "IO" e o uso responsavel de alocacao de memória.
 Este projeto mostra a dificuldade em lidar com as funcoes Malloc e Free.
