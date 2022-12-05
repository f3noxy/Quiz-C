# Quiz C

Integrantes: Wilton Nicolas de Lima Lopes - 29460468

# Introdução

O jogo consiste em perguntas e respostas, a medida em que o jogador vai acertando perguntas a premiação vai subindo, mas a dificuldades das perguntas também é elevada. Tendo um total de 300 perguntas no acervo, 16 perguntas selecionadas aleatoriamente serão feitas em sequência ao jogador, caso acerte todas as perguntas recebera a premiação de 1 milhão de reais e terá seu nome registrado no pódio dos Vencedores, caso perca ainda receberá uma menor quantia, exceto na pergunta de 1 milhão, onde se errar ira perder tudo. Além disso o jogador pode pedir para parar ao decorrer do jogo, se escolher parar, recebera uma menor quantia, mas não menor que a quantia da resposta errada.

[Demonstração em vídeo](https://www.youtube.com/watch?v=fEu3uoGXORo&ab_channel=WiltonNicolas)

# Resultados

Ao inciar o jogo, você poderá escolher entre 5 opções.

![image](https://user-images.githubusercontent.com/78822853/204970290-1e5beb4a-626e-40da-b485-817699c28ec0.png)

## Primeira opção - Jogar

Escolhendo a primeira opção, você precisará digitar um nome antes de inciar o jogo. Após a escolha do nome, será feito um total de 16 perguntas, caso você não erre ou não escolha a opção de parar. Para a seleção das perguntas é gerado um número aleátorio, entre determinados intervalos de acordo com o número de perguntas acertadas. Para gerar o número aleátorio foi criada a função gerarNumeroAleatorio, que usa da função srand para garantir a não repetição até certo nível, e a rand para gerar o número em si.

![image](https://user-images.githubusercontent.com/78822853/205534596-37233826-b013-45d0-9bff-4a470fcfc02c.png)


Dificuldade: Não ter um número aleátorio repetido nas perguntas.

Apesar de sempre ser gerado um número aleátorio, ainda havia a chance do número se repetir eventualmente, então foi necessário fazer um sistema para que se guarde os números já gerados dentro de um array, e então cada vez que um novo número for gerado ele seja comparado com todos os números salvos dentro da array, caso seja igual, um novo número será gerado e o processo de comparação será repetido, até que o novo número seja diferente de todos os anteriores.

![image](https://user-images.githubusercontent.com/78822853/205145610-7f5860e2-bd13-42e4-9c25-1f6c10def779.png)

Dificuldade: Manipular o arquivo de texto das pergutas para imprimir as perguntas na tela.

As perguntas do jogo estão armazenadas dentro de um arquivo txt, separadas em bloco de 6, onde a primeira linha é a pergunta, as quatro próximas são as alternativas e a sexta é um espaço em branco, portanto é necessário determinar as linhas da pergunta que será exibida. Além disso após as 1800 linhas compostas pelas 300 perguntas, se tem as linhas das respostas das perguntas, totalizando assim um arquivo de 2100 linhas.
Portanto após gerar o número da pergunta, é calculado a linha onde está a pergunta, depois a linha onde está a primeira alternativa da pergunta e por fim a linha onde está a resposta da pergunta, tudo isso só será realizado caso o número aleátorio for maior que 1, pois caso seja igual a 1, será a pergunta padrão, então os procedimentos não são necessários. Após se ter todas as linhas da pergunta, a função exibirPergunta entra em ação, abrindo o arquivo questions.txt no modo "r" e busca a pergunta através de um estrutura de repetição, que se repete até a linha da pergunta fornecida, o mesmo acontece para as funções exibirRespostas e obterAlternativaCorreta, que por sua vez só mudam o objetivo.

![image](https://user-images.githubusercontent.com/78822853/205535406-beaa7d8a-5c22-42c3-ae62-6b8361ed06af.png)

![image](https://user-images.githubusercontent.com/78822853/204968478-8bda887b-d322-4482-bd5f-8ec4d34e450a.png)

Após a exibição da pergunta e suas alternativas, o jogador poderá escolher entre responder a pergunta ou parar. Após digitar uma das opções, o jogo checa se a resposta está correta, caso esteja e não seja a décima sexta pergunta, o jogo continua, e o procedimento de gerar um número aleátorio para a pergunta e calcular suas linhas é realizado novamente. Caso esteja correta e ser a décima sexta pergunta, o jogo se encerra e parabeniza o jogador. Caso erre a pergunta, o jogador é informado que errou e o jogo se encerra. Caso escolha parar, o jogador é confirmado da sua decisão e o jogo se encerra.

![image](https://user-images.githubusercontent.com/78822853/204968533-b71d8268-0695-4002-893f-77a741d9b2d4.png)

Após a finalização do jogo, independente da forma, o seu nome e resultado será salvo no histórico, que pode ser acessado através do menu. Com a exceção de que, se você conseguir acertas as 16 perguntas, seu nome também será salvo nos vencedores, que também pode ser acessado através do menu. O Histórico e Pódio dos Vencedores é criado em um arquivo de texto através das funções criadas salvarHistorico e salvarVencedores, onde elas checam se já existe arquivo, caso haja ele abre o arquivo no modo "a", caso não exista ele criar o arquivo com o modo "w".

![image](https://user-images.githubusercontent.com/78822853/205534113-74cdc9bb-d1e4-4aaa-94e1-54f64dc2646d.png)

### Funcionamento -  Jogar

![image](https://user-images.githubusercontent.com/78822853/204969211-92e1e7a0-6dc2-4e94-9818-7abf827ca3e3.png)

![image](https://user-images.githubusercontent.com/78822853/204969351-0e0ff0b0-88e8-4fe4-9772-51388d6bb534.png)


## Segunda opção - Vencedores

Caso escolha a segunda opção, será exibido os vencedores do jogo, além de possibilidade de apagar os vencedores salvos. Caso a opção seja acessada antes de não se ter nenhum vencedor, será retornado a mensagem de que ninguém foi capaz de ganhar o 1 milhão.

![image](https://user-images.githubusercontent.com/78822853/204968997-319e753d-875b-4336-9f58-33dabc62f1a6.png)

Para fazer a exibição dos vencedores, é usada a função exibirVencedores, que abre o arquivo vencedores.txt (caso exista) no modo "r" e imprime todas as linhas contidas no arquivo, caso não exista o arquivo vencedores.txt a função retorna "1".

![image](https://user-images.githubusercontent.com/78822853/205535939-61d9c0b0-77a2-484c-9ce5-806cd61be0c5.png)


### Funcionamento - Vencedores

![image](https://user-images.githubusercontent.com/78822853/204969919-bac373d8-d062-4f9d-b9be-82e770acab16.png)

## Terceira opção - Histórico

Caso escolha a terceira opção, será exibido o histórico de jogos, com nome e resultado, além da possibilidade de apagar o histórico salvo. Caso a opção seja acessada antes de nenhum jogo ser realizado, será retornado a mensagem de que nenhum jogo foi realizado, portanto não há histórico.

![image](https://user-images.githubusercontent.com/78822853/204969860-0cb94631-b357-43bf-8ab2-f818dedff1e8.png)

Para realizar a exibição do histórico, é utilizado a função exibirHistorico, que abre o arquivo historico.txt (caso exista) no modo "r" e imprime todas as linhas contidas no arquivo, caso não exista o arquivo historico.txt a função retorna "1".

![image](https://user-images.githubusercontent.com/78822853/205536160-129b5881-771c-4e13-b4b2-a117d077216a.png)

### Funcionamento -  Histórico

![image](https://user-images.githubusercontent.com/78822853/204970009-4f885785-76b8-438f-9bfe-9fd24ed44f44.png)

## Quarta opção - Créditos

Caso escolha a quarta opção, será exibido os creditos de realização do jogo.

![image](https://user-images.githubusercontent.com/78822853/204970206-72a87eb8-f542-4986-a638-5e95e7d8364c.png)


### Funcionamento - Créditos

![image](https://user-images.githubusercontent.com/78822853/204970082-37a3b066-a910-4973-b550-173afa44de3a.png)


## Quinta opção - Sair

Caso escolha a quinta opção, o jogo sera fechado.
