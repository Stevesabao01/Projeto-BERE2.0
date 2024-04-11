#include <stdio.h>
#include <stdbool.h>

void exibirMenuPrincipal();
void exibirMenuPagamento();
void exibirTotais(float, float, float);
void adicionarItem(int, float);
float calcularDesconto(float, int);

float totalLimpeza = 0.0;
float totalAlimentos = 0.0;
float totalPadaria = 0.0;

int main() {
    int opcao, submenu;
    bool caixaAberto = false; // Variável para controlar se o caixa está aberto ou fechado

    while (1) {
        if (!caixaAberto) {
            printf("==== SEJA BEM-VINDA BERE ^_^ ====\n");
            printf("1. Abertura de Caixa\n");
            printf("2. Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    // Implemente a lógica de abertura de caixa aqui
                    printf("Caixa aberto com sucesso!\n");
                    caixaAberto = true;
                    break;
                case 2:
                    return 0;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
            }
        } else {
            exibirMenuPrincipal();
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    exibirSubmenuLimpeza();
                    break;
                case 2:
                    exibirSubmenuAlimentos();
                    break;
                case 3:
                    exibirSubmenuPadaria();
                    break;
                case 4:
                    exibirTotais(totalLimpeza, totalAlimentos, totalPadaria);
                    exibirMenuPagamento();
                    break;
                case 5:
                    printf("Caixa fechado com sucesso!\n");
                    caixaAberto = false;
                    break;
                case 6:
                    return 0;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
            }
        }
    }
}

void exibirMenuPrincipal() {
    printf("\n==== SEJA BEM-VINDA BERE ^_^ ====\n");
    printf("\n-------------------------------------\n");
    printf("1. Abertura de Caixa\n"); //inseri a abertura de caixa seguindo a logica
    printf("2. Material de Limpeza\n");
    printf("3. Venda de Alimentos\n");
    printf("4. Padaria\n");
    printf("5. Pagamento\n");
    printf("6. Fechamento de Caixa\n"); //inseri o fechamento de caixa
    printf("7. Sair\n");
}

void exibirTotais(float totalLimpeza, float totalAlimentos,float totalPadaria) {
    printf("\n\nTotais:\n");
    printf("Total de Material de Limpeza: R$%.2f\n", totalLimpeza);
    printf("Total de Venda de Alimentos: R$%.2f\n", totalAlimentos);
    printf("Total de Padaria: R$%.2f\n", totalPadaria);
    printf("Total da Compra: R$%.2f\n", totalLimpeza + totalAlimentos + totalPadaria);
}

void adicionarItem(int categoria, float valor) {
    switch (categoria) {
        case 1:
            totalLimpeza += valor;
            break;
        case 2:
            totalAlimentos += valor;
            break;
        case 3:
            totalPadaria += valor;
            break;
    }
}

float calcularDesconto(float total, int opcao) {
    float desconto;

    if (opcao == 1 && total <= 50.0) {
        desconto = total * 0.05; // 5% de desconto
    } else if (opcao == 1 && total > 50.0 && total < 100.0) {
        desconto = total * 0.10; // 10% de desconto
    } else if (opcao == 1) {
        desconto = total * 0.18; // 18% de desconto
    } else {
        desconto = 0;
    }

    return total - desconto;
}

void exibirSubmenuLimpeza() {
    int submenuLimpeza, qtd;
    float valor;

    while (1) {
        printf("\n\n==== Material de Limpeza ^-^ ====\n\n");
        printf("1. Detergente un  -  R$1,99\n");
        printf("2. Sabao em po -1kg R$8,99\n");
        printf("3. Esponja -  R$1,50\n"); //sem estoque
        printf("4. Amaciante - 1Lt  R$15,00\n");
        printf("5. Bucha de Pia - kit com 3 R$4,99\n"); //mais um item adicionado
        printf("6. Desinfetante - 1Lt R$7,99\n");
        printf("7. Sabao em barra(un) R$1,00\n"); // item adicionado
        printf("8. Voltar ao menu principal\n");
        printf("Carrinho: R$%.2f     ", totalLimpeza);
        printf("Escolha uma opcao: ");
        scanf("%d", &submenuLimpeza);

        switch (submenuLimpeza) {
            case 1:
                printf("Informe a quantidade de Detergente: ");
                scanf("%d", &qtd);
                valor = qtd * 1.99;
                adicionarItem(1, valor);
                break;
            case 2:
                printf("Informe a quantidade de Sabao em po: ");
                scanf("%d", &qtd);
                valor = qtd * 8.99;
                adicionarItem(1, valor);
                break;
            case 3: //fazer com que o item fique sem estoque
                printf("Informe a quantidade de Esponja: ");
                scanf("%d", &qtd);
                valor = qtd * 1.50;
                adicionarItem(1, valor);
                break;
            case 4:
                printf("Informe a quantidade de Amaciante: ");
                scanf("%d", &qtd);
                valor = qtd * 15.00;
                adicionarItem(1, valor);
                break;
            case 5:
                printf("Informe a quantidade de Bucha de Pia: ");
                scanf("%d", &qtd);
                valor = qtd * 4.99;
                adicionarItem(1, valor);
                break;
            case 6:
                printf("Informe a quantidade de Desinfetante: ");
                scanf("%d", &qtd);
                valor = qtd * 7.99;
                adicionarItem(1, valor);
                break;
            case 7:
                printf("Informe a quantidade de Sabao em barra: ");
                scanf("%d", &qtd);
                valor = qtd * 1.00;
                adicionarItem(1, valor);
                break;
            case 8:
                return;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }
}

void exibirSubmenuAlimentos() {
    int submenuAlimentos, qtd;
    float valor;

    while(1) {
        printf("\n\n==== Alimentos ^-^ ====\n\n");
        printf("1. Cafe           R$19,99\n");
        printf("2. Leite          R$5,90\n");
        printf("3. Arroz - 1kg      R$4,50\n");
        printf("4. Feijao Preto - 1kg  R$8,00\n");
        printf("5. Acucar - 1kg     R$5,00\n");
        printf("6. Sal - 1kg      R$2,00\n"); //adicionei item
        printf("7. Farinha de Trigo - 1kg  R$5,00\n"); //adicionei item
        printf("8. Voltar ao menu principal\n");
        printf("Carrinho: R$%.2f     ", totalAlimentos);
        printf("Escolha uma opcao: ");
        scanf("%d", &submenuAlimentos);

        switch (submenuAlimentos) {
            case 1:
                printf("Informe a quantidade de Cafe: ");
                scanf("%d", &qtd);
                valor = qtd * 19.99;
                adicionarItem(2, valor);
                break;
            case 2:
                printf("Informe a quantidade de Leite: ");
                scanf("%d", &qtd);
                valor = qtd * 5.90;
                adicionarItem(2, valor);
                break;
            case 3:
                printf("Informe a quantidade de Arroz: ");
                scanf("%d", &qtd);
                valor = qtd * 4.50;
                adicionarItem(2, valor);
                break;
            case 4:
                printf("Informe a quantidade de Feijao Preto: ");
                scanf("%d", &qtd);
                valor = qtd * 8.00;
                adicionarItem(2, valor);
                break;
            case 5:
                printf("Informe a quantidade de Acucar: ");
                scanf("%d", &qtd);
                valor = qtd *5.00;
                adicionarItem(2, valor);
                break;
            case 6:
                printf("Informe a quantidade de Sal: ");
                scanf("%d", &qtd);
                valor = qtd * 2.00;
                adicionarItem(1, valor);
                break;
            case 7:
                printf("Informe a quantidade de Farinha de Trigo: ");
                scanf("%d", &qtd);
                valor = qtd * 5.00;
                adicionarItem(1, valor);
                break;
            case 8:
                return;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }
}

void exibirSubmenuPadaria() {
    int submenuPadaria, qtd;
    float valor;

    while(1) {
        printf("\n\n===== Padaria ^-^ =====\n\n");
        printf("1. Pao de Forma     R$9,50\n");
        printf("2. Pao Integral     R$12,50\n");
        printf("3. Pao Frances - Unid R$1,90\n");
        printf("4. Sonho           R$8,50\n");
        printf("5. Biscoito - kg   R$12,50\n"); //adicionado
        printf("6. Pao doce(un)    R$2,50\n"); //adicionado
        printf("7. Salgado(un)     R$17,50\n"); // adicionado
        printf("8. Voltar ao menu principal\n");
        printf("Carrinho: R$%.2f     ", totalPadaria);
        printf("Escolha uma opcao: ");
        scanf("%d", &submenuPadaria);

        switch (submenuPadaria) {
            case 1:
                printf("Informe a quantidade de Pao de Forma: ");
                scanf("%d", &qtd);
                valor = qtd * 9.50;
                adicionarItem(3, valor);
                break;
            case 2:
                printf("Informe a quantidade de Pao Integral: ");
                scanf("%d", &qtd);
                valor = qtd * 12.50;
                adicionarItem(3, valor);
                break;
            case 3:
                printf("Informe a quantidade de Pao Frances: ");
                scanf("%d", &qtd);
                valor = qtd * 1.90;
                adicionarItem(3, valor);
                break;
            case 4:
                printf("Informe a quantidade de Sonho: ");
                scanf("%d", &qtd);
              valor = qtd * 8.50;
                adicionarItem(3, valor);
                break;
            case 5: //adicionei de acordo com enunciado
                printf("Informe a quantidade de Biscoito: ");
                scanf("%d", &qtd);
                valor = qtd * 12.50;
                adicionarItem(1, valor);
                break;
            case 6: //tambem adicionado
                printf("Informe a quantidade de Pao Doce: ");
                scanf("%d", &qtd);
                valor = qtd * 2.50;
                adicionarItem(1, valor);
                break;
            case 7: //tambem adicionado
                printf("Informe a quantidade de Salgado: ");
                scanf("%d", &qtd);
                valor = qtd * 17.50;
                adicionarItem(1, valor);
                break;
            case 8:
                return;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }
}

void exibirMenuPagamento() {
    int opcao;
    float valorrecebido, change, total = calcularDesconto(totalLimpeza + totalAlimentos + totalPadaria, 1);

    printf("\n\nTotal com desconto,a vista no dinheiro: R$%.2f\n", total);
    printf("Escolha uma opcao de pagamento:\n");
    printf("1. Dinheiro\n");
    printf("2. Cartao\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Informe o valor recebido em dinheiro: ");
            scanf("%f", &valorrecebido);
            if (valorrecebido >= total) {
                change = valorrecebido - total;
                printf("Troco: R$%.2f\n", change);
            } else {
                printf("Valor insuficiente. Por favor, insira um valor maior.\n");
            }
            break;
        case 2:
            printf("Pagamento aprovado com cartao.\n");
            break;
    }
}
