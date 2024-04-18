#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Jogo de advinhar numeros secretos.O programa deve gerar um numero secreto e o usuario deve adivinhar qual foi o numero.
//Em seguida,o usuario ira pensar em um numero secreto e o computador ira adivinhar.
//Toda vez que o jogo iniciar, o usuario devera informar a quantidade de rodadas desejadas.
//Cada rodada consiste de 2 jogadas,na primeira jogada o usuario advinha o numero e, na segunda jogada, o programa advinha o numero.
//Ao termino das rodadas, o placar geral deve ser informado.Fim do progama.

int main()
{
    int nuns;
    srand(time(0)); //A partir desse ira ser gerado os numeros aleatorio(segundos decorridos desde 1970)
    int tentativasH = 0, tentativasM = 0, rodadas = 0, rodadasH = 0, rodadasM = 0, i = 0, max = 21, mini = 0; //tentavasH=humanos,tentativasM=maquinas
    int numero, menor, maior, hisM = 0, hisH = 0;
    char resposta;

    printf("_________________________________________________________________________\n\n");

    printf("Digite a quantidade de rodadas desejada:"); //Primeira parte,o usuario deve escolher quantas rodadas ele quer.
    scanf("%d", &rodadas);

    for (i = 1; i <= rodadas; i++) //entao i comeca em 0 e enquanto i for menor que o numero de rodadas o loop vai rodar
    {
        max = 21;
        mini = 0;
        tentativasH = tentativasM = 0;
        nuns = rand() % 21; //Para gerar numeros aleatorios,%21 e resto da divisao por 21,sempre sera um valor entre 0 e 20.
        printf("\nRodada %d\n", i); //Rodada inicial,imprimir essa mensagem assim que come ar o jogo.
        printf("Qual o numero secreto gerado pelo computador?\n"); //Imprimir essa mensagem.
        printf("Digitae um numero entre 0 e 20: "); //O usuario deve digitar um numero entre 0 e 20,e ver se acerta o numero secreto.
        tentativasH++;
        do
        {
            scanf("%d", &numero);
            if (numero < nuns)
            {
                printf("Errou,o numero secreto e maior.Tente novamente: "); //Se o numero digitado for menor deve imprimir essa mensagem,e o usuario deve tentar de novo.
                tentativasH++;
            }
            else if (numero > nuns)
            {
                printf("Errou,o numero secreto e menor.Tente novamente: "); //Se o numero digitado for maior deve imprimir essa mensagem,e o usuario deve tentar de novo.
                tentativasH++;
            }
        } while (numero != nuns);
        printf("Parabens,voce acertou em %d tentativas.\n\n", tentativasH); //Quando o usuario acerta deve imprimir essa mensangem,e mostra em quantas tentativas foi.
        //rodadasH++;

        do
        {
            printf("Pense em um numero secreto entre 0 e 20. Pensou (s/n)? ");
            scanf(" %c", &resposta);
            getchar();
        } while (resposta != 'S' && resposta != 's'); //Enquanto o usuario nao digitar s ou S ele nao vai proseguir.

        do
        {
           nuns = rand() % max;
           if(mini == max){
            nuns = mini;
           }
            else if (mini > 0)
            {
                while (nuns <= mini || nuns >= max)
                {
                    nuns = rand() % 21;
                }
            }

            printf("O numero secreto e %d (s/n)? ", nuns);
            scanf("%c", &resposta);
            getchar();
            tentativasM++; //Vai gerar o numero aleatorio e vai pergunta se e o numero certo.

            if (resposta == 'N' || resposta == 'n')
            {
                printf("O numero secreto e maior do que %d ? ", nuns);
                scanf("%c", &resposta);
                getchar();
                if (resposta == 'S' || resposta == 's')
                {
                    mini = nuns;
                    //mini = nuns + 1;
                    //max = 21 - mini;
                }
            else
           {
              //mini = 0;
              max = nuns;
            }
            }
            else
            {
               //rodadasM++;
                break;
            }

        } while (1);//Quando o computador acerta o numero.
        printf("\nComputador acertou em %d tentativas e o usuario em %d.\n\n", tentativasM, tentativasH);

        if (tentativasM < tentativasH)
        {
            rodadasM++;
            printf("Computador venceu a rodada numero %d de um total de %d.\n", rodadasM, rodadas); //se as tentativas da maquinas for menor do que a do usuario.
        }
        else if (tentativasM > tentativasH)
        {
            rodadasH++;
            printf("Usuario venceu a rodada numero %d de um total de %d.\n", rodadasH, rodadas); //se nao.
        }

        else
        {
            printf("Empate de rodada numero %d de um total de %d.\n", rodadasH, rodadasM);
        }
        printf("\nPlacar de rodadas:\n");
        printf("Computador:%d  Usuario:%d \n\n", rodadasM, rodadasH);

    } //Final do for

    if (rodadasH > rodadasM)
    {
        printf("Usuario venceu.\n");
    }
    else if (rodadasH < rodadasM)
    {
        printf("Computador venceu.\n");
    }
    else
        printf("Empate");

    printf("Placar final:\n");
    printf("Computador:%d  Usuario:%d\n", rodadasM, rodadasH);

    FILE *fp;

    fp = fopen("arquivo.txt", "r");
    if (!fp) //Nao achou o arquivo.
    {
        fp = fopen("arquivo.txt", "w");
    }
    else
    {
        fscanf(fp, " %d %d", &hisM, &hisH); //primeiro numero maquina e segundo usuario.
        fclose(fp);
        fopen("arquivo.txt", "w");
    }
    hisM += rodadasM; //his= historico
    hisH += rodadasH;
    fprintf(fp, "%d %d", hisM, hisH);
    printf("Historicamente o computador ja venceu %d rodadas e o usuario %d rodadas.\n", hisM, hisH);
    fclose(fp);

    printf("_________________________________________________________________________\n");
}
