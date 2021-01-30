# Estrutura-de-Dados-em-Linguagem-C

Com o gcc já instalado no seu sistema, é muito simples usá-lo para compilar programas em C. Se o programa consistir de um único arquivo, você pode simplesmente executar este comando no terminal:

$ gcc prog.c -o prog


onde prog.c é o nome do arquivo que contém o código. Os outros dois parâmetros, -o prog, indicam o arquivo de saída do compilador — o arquivo executável que conterá o programa. Você não verá nenhuma mensagem na tela se a compilação ocorrer sem problemas; o compilador só diz alguma coisa quando ocorrem erros.

Você precisa especificar o nome do arquivo executável de saída pois o padrão, por razões históricas, é usar o arquivo a.out. Em geral, usamos o mesmo nome do arquivo de código, tirando a extensão .c.

Para executar o programa, a maneira mais “universal” é digitar o seguinte comando no terminal:

$ ./prog
