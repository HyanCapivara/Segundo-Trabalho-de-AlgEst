# Segundo-Trabalho-de-Alg.Est.

Grupo: Hyan M J G

Complexidades e principais decisões:

Como comentários gerais: tentei manter todos os métodos que não produzem alteração na classe como const - isso me impede de usa-los para alterar qualquer coisa dentro de ditos métodos. Bem adequado se eu só estiver tentando pegar alguma informação -, com exceção das estruturas ordenadas e dos grafos, permiti a repetição de ID's ao longo dos códigos, muitas das funções int deveriam ser booleanas, mas eu esqueci dessa possibilidade e agora já é meio tarde.

### main

só faz chamadas para os menus contidos em "Geral"

### Geral

contém menus para auxiliar os teste. 

### Elemento

| método | complexidade |
| :--- | :---: |
| construtores | O(1) |
| destrutores | O(1) |
| impressões | O(1) |
| get's | O(1) |

Essa parte do código é a mais básico do trabalho todo. Contém as definições de Elemento e suas classes derivadas (humano e professor - sim, eu estava sem criatividade). A complexidade de todos os construtores, destrutores, gets e da impressão é a mesma para todas as classes desse arquivo (quando aplicáveis). As únicas decisões que eu tomei nessa parte, que não estavam no enunciado, no caso, foram: criar as classes derivadas com relação de herança entre si - professor herda de humano que herda de elemento - e só fiz isso para experimentar mesmo - e não colocar setters nesse código, só dá para mexer nos atributos das instâncias na criação delas, fiz isso porque a lista não precisa mexer nos atributos da classe para operar devidamente.  

### Lista não ordenada (sequencial)

| método | complexidade |
| :--- | :---: |
| construtor | O(1) |
| destrutor | O(n) |
| inserir no inicio | O(1) |
| inserir no inicio com deslocamento | O(n) |
| inserir no final | O(1) |
| remover primeiro | O(1) |
| remover primeiro com deslocamento | O(n) |
| remover ultimo | O(1) |
| remover pelo ID | O(n) |
| buscar pelo id | O(n) |
| alterar pelo id | O(n) |
| imprimir lista | O(n) |
| get's | O(1) |
| set's | O(1) |

Aqui as coisas mudam um pouco. 
Quis permitir que o usuário escolhesse o tamanho da lista, então comecei a trabalhar com ponteiro de ponteiro. Isso fez com que todo esse código trabalhasse alocando memória e isso me obriga a liberar essa memória depois de usa-la dai a complexidade do destrutor começou a engordar. 
Fiz sobrecarga de operadores para inserção - tenho dois métodos, um para a classe humana e um para a classe professor. Deixou o código meio feinho, mas padronizou as funções de entrada.
Existem duas versões de inserção no inicio, a com O(1) é que está sendo usada, deixei a com O(n) por motivos que a minha razão desconhece - é só outra possibilidade para a mesma coisa.
Existem duas versões de remoção no inicio, a com O(1) é que está sendo usada nessa lista, mas a com O(n) é usada na primeira implementação da fila
Também tem duas funções de alteração, a que está ativa deleta um elemento e cria outro com os dados passados. A inativa deletava um elemento e criava, com o mesmo ID, um novo elemento com os parâmetros passados. Fiz duas porque estava em duvida quanto ao que essa função deveria fazer
Permite que se repetissem ID's. Não tem motivo digno, só esqueci que seria legal impedir o usuário de repetir ID's nas estruturas desordenadas e não queria ficar pagando O(n) toda inserção para fazer uma busca pelo ID que estou tentando inserir

### Lista Ordenada (sequencial)

| método | complexidade |
| :--- | :---: |
| construtor | O(1) |
| destrutor | O(n) |
| inserir | O(n) |
| remover primeiro | O(n) |
| remover ultimo | O(1) |
| remover pelo ID | O(n) |
| buscas | O(logn) |
| alterar pelo id | O(n) |
| imprimir lista | O(n) |
| gets | O(1) |

Aqui não tem nada de muito novo. Também usei a estrategia do vetor de ponteiro, a função de inserção está sobrecarregada e é isso. 
Esse tipo de lista não tolera "insira no inicio/fim", os elementos serão inseridos onde devem ser inseridos.
Eu dividi a função de busca em duas: a BuscarPeloID e a BuscaBinaria. A primeira chama a segunda e informa o seu resultado. A segunda faz a busca, propriamente dita. Fiz essa divisão para poder reutilizar o código de busca - sem mensagem adicional - para ajudar com as inserções e remoções

### Pilha

| método | complexidade |
| :--- | :---: |
| construtor | O(1) |
| destrutor | O(n) |
| empilhar / inserir no final | O(1) |
| desempilhar / remover ultimo | O(1) |
| ver topo | O(1) |
| pilha cheia | O(1) |
| pilha vazia | O(1) |

Aqui eu basicamente me aproveitei da estrutura da lista não ordenada e pronto: pilha com O(1). 
Os métodos de inserção e remoção são os mesmos da lista não ordenada, os métodos para olhar o topo e checar se a pilha está cheia/vazia fazem uso dos gets presentes na classe da lista não ordenada. 
Nos arquivos da pilha, existem duas funções comentadas com o mesmo nome que os métodos pilha cheia/vazia. Essas funções enchem e esvaziam a pilha. Ambas tem custo O(n). Tinha imaginado que era esse o objetivo desses métodos, mas descobri mais tarde que não era o caso

### Fila

| método | complexidade |
| :--- | :---: |
| construtor | O(1) |
| destrutor | O(n) |
| enfileirar / inserir no final | O(1) |
| remover primeiro com deslocamento | O(n) |
| desenfileirar | O(1) |
| ver frente | O(1) |
| fila vazia | O(1) |
| fila cheia | O(1) |

Aqui eu estava usando o código da lista não ordenada de novo, mas a complexidade do método de remoção - remover primeiro com deslocamento - é maior que o necessário, para esse caso. 
A primeira implementação solicitada segue o modelo da lista, a segunda segue uma lista circular mais apropriada para as filas
Seguindo a lista, temos remoção em O(n) - remover primeiro com deslocamento - e inserção em O(1). Implementei, com funções a parte, presentes na classe fila, um modelo de lista circular que faz remoções - desenfileirar - e inserções em O(1)

### Lista simplesmente encadeada

| método | complexidade |
| :--- | :---: |
| construtor | O(1) |
| destrutor | O(n) |
| inserir no inicio | O(1) | 
| inserir no final | O(n) |
| remover primeiro | O(1) |
| remover ultimo | O(n) |
| remover pelo ID | O(n) |
| buscar pelo id | O(n) |
| alterar pelo id | O(n) |
| imprimir lista | O(n) |
| get's | O(1) |
| set's | O(1) |

Para as estruturas encadeadas eu fui ainda menos criativo. O nó, além dos ponteiros necessários ao encadeamento, tem um único atributo: seu ID.
Não tem muito o que dizer, é a mesma estrutura/lógica que vimos em sala, só modificamos o jeito de mexer com as variáveis, muito do que era raiz->prox agora é raiz->getProx()
A única decisão importante tomada aqui, foi dizer que a classe grafo é amiga dessa classe. Essa escolha será justificada na parte de grafos.

### Lista duplamente encadeada

| método | complexidade |
| :--- | :---: |
| construtor | O(1) |
| destrutor | O(n) |
| inserir no inicio | O(1) | 
| inserir no final | O(n) |
| remover primeiro | O(1) |
| remover ultimo | O(n) |
| remover pelo ID | O(n) |
| buscar pelo id | O(n) |
| alterar pelo id | O(n) |
| imprimir lista | O(n) |
| get's | O(1) |
| set's | O(1) |

Nada de especial, mesma lógica e estrutura vista em sala

### Lista duplamente encadeada

| método | complexidade |
| :--- | :---: |
| construtor | O(1) |
| destrutor | O(n) |
| inserir no inicio | O(1) | 
| inserir no final | O(1) |
| remover primeiro | O(1) |
| remover ultimo | O(1) |
| remover pelo ID | O(n) |
| buscar pelo id | O(n) |
| alterar pelo id | O(n) |
| imprimir lista (sentido ->) | O(n) |
| imprimir lista (sentido <-) | O(n) |
| get's | O(1) |
| set's | O(1) |

A única escolha que eu fiz aqui foi colocar dois percursos para a impressão da lista

### Pilha encadeada

| método | complexidade |
| :--- | :---: |
| construtor | O(1) |
| destrutor | O(n) |
| empilhar / inserir no inicio | O(1) | 
| desempilhar / remover primeiro | O(1) |
| ver topo | O(1) |
| pilha vazia | O(1) |
| get's | O(1) |

Optei por fazer a pilha sobre uma lista simplesmente encadeada, reutilizando muito do código já feito. O código dessa lista permite inserção e remoção em O(1), sendo bem conveniente só reutiliza-lo aqui.
Para os métodos de "ver topo" e "pilha vazia", bastou pegar as informações fornecidas pelos gets deixados na lista simplesmente encadeada.

### Fila encadeada

| método | complexidade |
| :--- | :---: |
| construtor | O(1) |
| destrutor | O(n) |
| enfileirar / inserir no final | O(1) | 
| desenfileirar / remover primeiro | O(1) |
| ver frente | O(1) |
| fila vazia | O(1) |
| get's | O(1) |

Aqui eu reutilizei o código da lista duplamente encadeada circular. Essa estrutura permite inserir no final e remover do inicio em O(1), sendo a escolha natural para esse caso.
As funções para "ver frente" e "fila vazia" foram obtidas simplesmente avaliando o retorno dos get's presentes na definição da classe da lista duplamente encadeada circular.

### Deque

| método | complexidade |
| :--- | :---: |
| construtor | O(1) |
| destrutor | O(n) |
| inserir na cabeça | O(1) | 
| remover da cabeça | O(1) |
| olhar frente (cabeça) | O(1) |
| fila vazia (cabeça) | O(1) |
| inserir na calda | O(1) | 
| remover da calda | O(1) |
| olhar frente (calda) | O(1) |
| fila vazia (calda) | O(1) |
| get's | O(1) |
| set's | O(1) |

O deque basicamente é formado por duas filas. Como as filas encadeadas, com as quais acabei de trabalhar, são basicamente chamadas para a classe lista duplamente encadeada circular, optei por colocar duas instâncias dessas listas na definição da classe deque. Assim, eu posso reaproveitar todo o código, tendo apenas que chamar o método certo para a lista correta quando eu quiser inserir(remover) na(da) "cabeça" ou na(da) "calda". Poderia ter reaproveitado ainda mais código, e facilitado correções, se eu fizesse duas instâncias para filas - num pensei nisso antes (;-;)

### Árvore binária de busca

| método | complexidade |
| :--- | :---: |
| construtor | O(1) |
| destrutor | O(n) |
| desmatamento | O(n) |
| inserção | O(h ou n) |
| remoção | O(h ou n) |
| busca | O(n) |
| pré-ordem | O(n) |
| pós-ordem | O(n) |
| em ordem | O(n) |
| get's | O(1) |
| set's | O(1) |

O método de "desmatamento" é usado junto com o destrutor para desalocar os nós usados durante a execução.
A inserção e a remoção dependem da altura h. logn <= h <= n, onde n é número de nós. No pior caso, h = n
Até o presente momento, não fiz nenhum método de correção para impedir a degeneração da árvore.

### Grafos

| método | complexidade |
| :--- | :---: |
| construtor | O(n²) |
| destrutor | O(n²) |
| copiar matriz de adjacência | O(n²) |
| inicializar linha | O(n) |
| inicializar coluna | O(n) |
| copiar lista de adjacência | O(n²) |
| adicionar vértice | O(n²) |
| adicionar aresta | O(1) |
| verificar vizinho | O(1) |
| grau | O(n) |
| busca em largura | O(n²) |
| busca em profundidade | O(n²) |

Decidi copiar a ideia dos "vector" e fazer uma estrutura que, caso tenha seu tamanho excedido, cria outra com o dobro do tamanho. 
É perceptivel que essa escolha encareceu bastante o código, vide a complexidade do "adicionar vértice". Isso ocorre porque eu preciso criar uma estrutura nova, copiar para ela os dados da antiga, inicializar a nova linha/coluna - no caso da matriz - e depois deletar a estrutura velha. 
Essa classe usa um vetor de listas simplesmente encadeadas como lista de adjacência e uma matriz de inteiros como matriz de adjacência.
Além disso, concedi amizade entre a lista usada e essa classe para que eu pudesse usar o nó definido na lista. Isso foi especialmente útil para fazer os percursos em largura e profundidade
Pressupõe-se que os vértices estão numerados em termos de naturais não-nulos, com inicio em 1 e crescimento unitário, por inserção
