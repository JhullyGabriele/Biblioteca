#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
   char nome[100];
   char autor[100];
   int ano;
} estante;

void addLivro(estante livro[], int *nLivros);
void pesquisaLivro(estante livro[], int nLivros, const char *nome);
void salvarLivros(estante livro[], int nLivros, const char *nomeArquivo);
void carregarLivros(estante livro[], int *nLivros, const char *nomeArquivo);

int main(){
   const char *nomeArquivo = "Livros.dat";
   int opcao, maxLivros = 100;
   estante livro[maxLivros];
   int nLivros = 0;
   char termoPesquisa[100];
   
   carregarLivros(livro, &nLivros, nomeArquivo);
   
   do{
   printf("Escolha um número para continuar:\nDigite 0 para sair.\n");
   printf("1. Registrar um livro\n");
   printf("2. Listar todos os livros\n");
   printf("3. Pesquisar por um livro");
   scanf("%d", &opcao);
   getchar();
   
   if(opcao == 1){
      addLivro(livro, &nLivros);
   } else if(opcao == 2){
      printf("Lista de livros:");
      for(int i = 0; i < nLivros; i++){
      printf("\n%s", livro[i].nome);
      printf("\n%s", livro[i].autor);
      printf("\n%d\n", livro[i].ano);
      }
   } else if(opcao == 3){
      printf("Informe o nome do livro ou do autor: ");
      fgets(termoPesquisa, sizeof(termoPesquisa), stdin);
      termoPesquisa[strcspn(termoPesquisa, "\n")] = 0;
      pesquisaLivro(livro, nLivros, termoPesquisa);
   }
   
   } while (opcao != 0);

   salvarLivros(livro, nLivros, nomeArquivo);

return 0;
}

void addLivro(estante livro[], int *nLivros){
   printf("Informe o nome do livro: ");
   fgets(livro[*nLivros].nome, 100, stdin);
   
   livro[*nLivros].nome[strcspn(livro[*nLivros].nome, "\n")] = 0;
   
   printf("Informe o autor: ");
   fgets(livro[*nLivros].autor, 100, stdin);
   
   livro[*nLivros].autor[strcspn(livro[*nLivros].autor, "\n")] = 0;
   
   printf("Informe o ano de publicação: ");
   scanf("%d", &livro[*nLivros].ano);
   getchar();
   (*nLivros)++;
}

void pesquisaLivro(estante livro[], int nLivros, const char *nome){
   printf("Livros encontrados para a busca '%s':", nome);
   int found = 0;
   for(int i = 0; i < nLivros; i++){
      if(strstr(livro[i].nome, nome) != NULL || strstr(livro[i].autor, nome) != NULL){
         printf("\n%s", livro[i].nome);
         printf("\n%s", livro[i].autor);
         printf("\n%d\n", livro[i].ano);
         found = 1;
      }
   }
   if(!found){
      printf("Nenhum livro encontrado para essa busca: '%s'\n", nome);
   }
}

void salvarLivros(estante livro[], int nLivros, const char *nomeArquivo){
   FILE *file = fopen(nomeArquivo, "wb");
   if(file == NULL){
      perror("Não foi possível abrir o arquivo de salvamento.");
      return;
   }
   fwrite(livro, sizeof(estante), nLivros, file);
   fclose(file);
}

void carregarLivros(estante livro[], int *nLivros, const char *nomeArquivo){
   FILE *file = fopen(nomeArquivo, "rb");
   if(file == NULL){
      *nLivros = 0;
      return;
   }
   *nLivros = fread(livro, sizeof(estante), 100, file);
   fclose(file);
}