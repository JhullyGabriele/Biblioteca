# Biblioteca
Gerenciador de livros em C.

Uma biblioteca que permite adicionar livros, listar todos os livros, pesquisar por um livro ou sair.
A variável que determina a quantidade de livros é iniciada em 0 e conforme livros novos são adicionados ela recebe um incremento, aumentando o número de livros que pode receber. O número de livros possíveis depende apenas da quantidade de memória que o usuário tem disponível em seu servidor.
A pesquisa pode ser feita informando o nome do livro ou do autor e mostrará resultados iguais ou o mais perto possível, caso não encontre o mesmo título informado.
O diferencial dessa biblioteca é que ela tem uma função que salva todos os livros em um arquivo que é lido toda a vez que o programa inicia, permitindo que o programa seja fechado e sua memória seja mantida.
