//Calculadora de 5 opera�oes:soma(+),subtra��o(-),multiplica�ao (* ou x),divisao(\)
//e potencia�ao(^).obs:(na multiplica�ao tem que aceitar * e x.)
//Sempre que o usuario digitar uma opera�ao diferente das disponiblizadas
//imprimir a mensagem "opera�ao invalida",pergunta se deseja continuar ou finalizar o programa.
//Fazer uma estrutura de repeti�ao,com 2 regras
//o programa deve continuar sempre que o usuario digitar S ou s.
//e finalizar com N e n.
//E no final do programa mostrar a quantidade de opera�ao validas.
//Os while dentro do while e para aceitar somente s e n como resposta se deve eu nao continuar programa
//e caso seja diferente de s ou n,ira pergunta novamente.
//Switch foi usado para realizar a conta quando indentificar o operador.
//E o while principal foi para o programa continuar rodando enquanto o usuario desejar.
#include<stdio.h>
#include<math.h>
int main(){
float n1,n2,resultado;//n1 e n2=numeros e resultado das opera�oes
 char op;//opera�oes
 int contador = 0;//contador de opera�oes
 char resposta = 's';//Continuar sempre que manter esse valor(trocar para S e s)
 printf ("\n____________________________________________\n");
 while(resposta != 'n')
 {
 printf("\nDigite a expressao: ");//Digite o numero que deseja realizar a opera�ao
 scanf("%f %c %f", &n1,&op,&n2);//scan float para jogar em n1 e n2 para realizar a opera�ao selecionada
 getchar();
 if (op != '+' && op != '-' && op != '*' && op != 'x' && op != '\\' && op != '^')
 { //If para caso o operador seja invalido
 printf("Operador invalido!\n");//Opera�ao invalida
 printf("Voce deseja digitar outra expressao (s/n)?");
 scanf(" %c", &resposta);
 while ((resposta !='S' && resposta != 's') && (resposta !='N' && resposta != 'n'))
 { //While para ver qual foi a resposta.
 printf("\nResposta invalida!\n");//Opera�ao invalida
 printf("Voce deseja digitar outra expressao (s/n)?");
 scanf(" %c", &resposta);
 }
 if(resposta == 'S' || resposta =='s')//Continuar rodando o programa.
 {
 continue;
 }
 else if (resposta == 'N' || resposta == 'n')//finaliza o while e continua na linha 60.
 {
 break;
 }
 }
//Estrutura para realizar a opera�ao selecionada em switch.
//Com while para continuar executando.
 switch (op)
 {
 case '+':
 printf("resultado = %0.2f\n",n1 + n2);//soma
 break;
 case '-':
 printf("resultado = %0.2f\n",n1 - n2);//subtra�ao
 break;
 case '*' :
 printf("resultado = %0.2f\n",n1 * n2);//multiplica�ao
 break;
 case 'x' :
 printf("resultado = %0.2f\n",n1 * n2);//multiplica�ao aceitando a letra x.
 break;
 case '\\':
 printf("resultado = %0.2f\n",n1 / n2);//Divisao.(Utilizei 2 barra para o linguagem reconhecer.
 break;
 case '^':
 printf("resultado = %0.2f\n", pow(n1, n2));//para pontencia�ao usei pow.
 break;
 }
 printf("Voce deseja digitar outra expressao (s/n)?");
 scanf("%c", &resposta);
 getchar();
 contador += 1;//contador de opera�ao,logo depois do switch para pegar as opera�oes validas.
 while ((resposta !='S' && resposta != 's') && (resposta !='N' && resposta != 'n'))
 {
 printf("\nResposta invalida!\n");//Opera�ao invalida
 printf("Voce deseja digitar outra expressao (s/n)?");
 scanf(" %c", &resposta);
 }
 if(resposta == 'S' || resposta =='s')//para continuar o programa.
 {
 continue;
 }
 else if (resposta == 'N' || resposta == 'n')//finaliza a estrutura do while e continua na linha 60.
 {
 break;
 }
 }
 printf ("\nForam calculadas %i expressoes validas.\n", contador);
 //Quantidade de operacoes validas usando o contador.
 printf("Tchau!\n");//Fim do programa.
 printf ("____________________________________________\n");}
