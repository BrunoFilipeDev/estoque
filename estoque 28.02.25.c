#include <stdio.h>
#include <ctype.h>

float calcular_custo_estoque(float preco, char refrigeracao, char categoria) {
    refrigeracao = toupper(refrigeracao);
    categoria = toupper(categoria);

    if (preco <= 20) {
        switch (categoria) {
            case 'A': return 5.0;
            case 'L': return 10.0;
            case 'V': return 15.0;
            default: return 0.0;
        }
    } else if (preco > 20 && preco <= 50) {
        return (refrigeracao == 'S') ? 6.0 : 12.0;
    } else {
        if (refrigeracao == 'S') {
            switch (categoria) {
                case 'A': return 5.0;
                case 'L': return 2.0;
                case 'V': return 4.0;
                default: return 0.0;
            }
        } else {
            switch (categoria) {
                case 'A': return 0.0;
                case 'V': return 0.0;
                case 'L': return 1.0;
                default: return 0.0;
            }
        }
    }
}

float calcular_imposto(float preco, char refrigeracao, char categoria) {
    refrigeracao = toupper(refrigeracao);
    categoria = toupper(categoria);

    if (preco >= 50 || refrigeracao == 'S' || categoria == 'A') {
        return preco * 0.04;
    }
    return preco * 0.02;
}

int main() {
    float preco, custo_estoque, imposto, preco_total;
    char refrigeracao, categoria;

    printf("Digite o pre�o unit�rio: ");
    scanf("%f", &preco);

    printf("O produto necessita de refrigera��o? (S/N): ");
    scanf(" %c", &refrigeracao);

    printf("Digite a categoria do produto (A - Alimento, L - Limpeza, V - Vestu�rio): ");
    scanf(" %c", &categoria);

    custo_estoque = calcular_custo_estoque(preco, refrigeracao, categoria);
    imposto = calcular_imposto(preco, refrigeracao, categoria);
    preco_total = preco + custo_estoque + imposto;

    printf("\nResultados:\n");
    printf("Pre�o do Produto: R$ %.2f\n", preco);
    printf("Custo de Estocagem: R$ %.2f\n", custo_estoque);
    printf("Imposto: R$ %.2f\n", imposto);
    printf("Pre�o Total: R$ %.2f\n", preco_total);

    return 0;
}
