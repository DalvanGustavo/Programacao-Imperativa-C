#include <stdio.h>

int main(){
    int diaNascimento, mesNascimento, anoNascimento;
    int diaAtual, mesAtual, anoAtual;
    int amor, sorte, trabalho, cor;

    char cores[11][20] = {"Cinza.", "Vermelho.", "Laranja.", "Amarelo.", "Verde.", "Azul.", "Roxo.", "Marrom.", "Rosa.", "Preto.", "Branco."};
    
    scanf("%d/%d/%d %d/%d/%d", &diaNascimento, &mesNascimento, &anoNascimento, &diaAtual, &mesAtual, &anoAtual);

    amor = ((diaNascimento + mesNascimento + anoNascimento + diaAtual + mesAtual + anoAtual) * 7) % 101;
    sorte = ((diaNascimento + mesNascimento + diaAtual + mesAtual) * 9 + (anoAtual - anoNascimento)) % 101;
    trabalho = ((anoNascimento + anoAtual) - (diaNascimento + diaAtual + mesNascimento + mesAtual) * 8) % 101;
    cor = (diaNascimento * diaNascimento + diaAtual * diaAtual + mesNascimento * mesNascimento + mesAtual * mesAtual + anoNascimento * anoNascimento + anoAtual * anoAtual) % 11;

    //Bloco de decisões para o Amor
    printf("Amor: %d%% ", amor);
    if (amor < 20){
        printf("Pessimo dia para se apaixonar.");
    }else if (amor <= 40){
        printf("Melhor manter o coracao <3 longe de perigo.");
    }else if (amor < 70){
        printf("Se o papo e as ideias baterem, esta liberado pensar em algo.");
    }else if (amor <= 80){
        printf("Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.");
    }else{
        printf("Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.");
    }

    // Bloco de decisões para a Sorte
    printf("\nSorte: %d%% ", sorte);
    if (sorte < 30){
        printf("Nem jogue moedas pra cima hoje.");
    }else if (sorte <= 50){
        printf("Melhor nao arriscar.");
    }else if (sorte < 80){
        printf("Por sua conta em risco.");
    }else if (sorte <= 90){
        printf("Hoje vale a pena arriscar.");
    }else{
        printf("Nao tenha medo de virar cartas hoje.");
    }
    printf(" Sem tigrinho nem jogos de azar, por favor!");
    
    // Bloco de decisões para o Trabalho
    printf("\nTrabalho: %d%% ", trabalho);
    if(trabalho < 40){
        printf("Hoje nao sera um dia tao proveitoso, keep calm e faca o basico.");
    }else if (trabalho <= 50){
        printf("Segura a emocao, nao xinga ninguem, nao esquece de beber agua.");
    }else if (trabalho < 70){
        printf("Um dia proveitoso com certeza, leve sua simpatia consigo.");
    }else if (trabalho < 85){
        printf("Boas vibracoes hoje, chances podem estar ao seu redor.");
    }else{
        printf("Use do maximo de networking possível hoje, dia bom para negocios.");
    }

    printf("\nCor: %s", cores[cor]);

    return 0;
}