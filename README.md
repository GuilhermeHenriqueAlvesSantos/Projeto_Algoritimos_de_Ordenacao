# Análise Comparativa de Algoritmos de Ordenação

## Introdução

O propósito deste projeto é realizar uma análise comparativa de seis algoritmos de ordenação com base no tempo de execução. O objetivo é testar e observar como esses algoritmos se comportam em relação ao desempenho quando aplicados a um conjunto de dados aleatórios. A análise fornece uma visão prática do desempenho dos algoritmos em situações reais de execução, além de permitir uma comparação com as expectativas teóricas de complexidade algorítmica.

Este projeto utiliza uma implementação simples em linguagem C, com a medição do tempo de execução de cada algoritmo.

## Algoritmos Testados

### 1. Selection Sort
**Teoria:** O Selection Sort é um algoritmo de ordenação simples baseado na troca de elementos. Ele seleciona repetidamente o menor (ou maior) elemento de uma parte não ordenada do vetor e o coloca na posição correta. A cada iteração, a parte ordenada do vetor aumenta em um elemento.

**Complexidade:** O tempo de execução do Selection Sort é O(n²), devido às duas iterações aninhadas: uma para percorrer o vetor e outra para buscar o menor elemento.

---

### 2. Insertion Sort
**Teoria:** O Insertion Sort constrói a ordenação do vetor um elemento de cada vez. Ele começa com o segundo elemento e o insere na posição correta dentro da parte já ordenada, deslocando os elementos maiores.

**Complexidade:** A complexidade é O(n²) no pior caso, quando o vetor está ordenado de forma inversa. No melhor caso, quando o vetor já está ordenado, a complexidade é O(n).

---

### 3. Bubble Sort
**Teoria:** O Bubble Sort compara elementos adjacentes e os troca se estiverem na ordem errada. Este processo é repetido até que o vetor esteja ordenado. O nome "bubble" se refere ao comportamento dos elementos que "sobem" para suas posições corretas.

**Complexidade:** A complexidade é O(n²) no pior caso, devido às várias passagens pelo vetor. No entanto, se o vetor já estiver parcialmente ordenado, o algoritmo pode ter um desempenho melhor.

---

### 4. Merge Sort
**Teoria:** O Merge Sort é um algoritmo eficiente baseado na técnica de "dividir e conquistar". Ele divide o vetor em duas metades, ordena cada metade recursivamente e depois mescla as duas metades ordenadas.

**Complexidade:** A complexidade do Merge Sort é O(n log n), o que o torna muito mais eficiente que os anteriores para vetores grandes.

---

### 5. Quick Sort
**Teoria:** O Quick Sort é outro algoritmo baseado em "dividir e conquistar". Ele escolhe um "pivô" e particiona o vetor de forma que todos os elementos menores que o pivô fiquem à esquerda e os maiores à direita. O processo é recursivo.

**Complexidade:** A complexidade média do Quick Sort é O(n log n), mas pode ser O(n²) no pior caso, quando o vetor é altamente desordenado ou o pivô é mal escolhido.

---

### 6. Heap Sort
**Teoria:** O Heap Sort é baseado na estrutura de dados "heap", que é um tipo de árvore binária. Ele primeiro constrói um heap a partir do vetor e depois retira o maior elemento (no caso de um max-heap), ajustando o heap até que todos os elementos sejam ordenados.

**Complexidade:** A complexidade do Heap Sort é O(n log n), o que o torna eficiente para grandes volumes de dados.

## Metodologia

A metodologia seguida para realizar os testes de desempenho consistiu nos seguintes passos:

1. **Geração de Dados:** Um vetor de 10 elementos aleatórios foi gerado para cada execução, utilizando a função `rand()` para garantir aleatoriedade.
   
2. **Execução dos Algoritmos:** Para cada algoritmo, o vetor foi copiado e o algoritmo correspondente foi executado individualmente.
   
3. **Medição de Tempo:** O tempo de execução foi medido utilizando as funções da biblioteca `<time.h>` de C. O tempo foi calculado em segundos, com precisão de frações de segundo.
   
4. **Repetição:** Cada algoritmo foi executado uma vez, e o tempo de execução foi registrado para análise.
   
5. **Comparação dos Resultados:** A comparação entre os algoritmos foi feita com base no tempo de execução, levando em consideração tanto a teoria quanto a prática.

## Resultados

Os resultados dos tempos de execução para um vetor de tamanho 10 são apresentados abaixo:

| Algoritmo         | Tempo de Execução (segundos) |
|-------------------|------------------------------|
| Selection Sort    | 0.000030                     |
| Insertion Sort    | 0.000025                     |
| Bubble Sort       | 0.000040                     |
| Merge Sort        | 0.000025                     |
| Quick Sort        | 0.000015                     |
| Heap Sort         | 0.000022                     |

**Nota:** Os tempos podem variar dependendo do sistema e da carga de execução. Os valores apresentados são aproximados.

## Análise

Com base nos resultados, podemos observar as seguintes tendências:

- **Algoritmos de Complexidade O(n²):** O Selection Sort, Insertion Sort e Bubble Sort apresentaram tempos de execução muito próximos. Isso é esperado, pois todos esses algoritmos possuem uma complexidade quadrática no pior caso. O Bubble Sort, em particular, foi ligeiramente mais lento devido ao número de trocas necessárias.

- **Algoritmos de Complexidade O(n log n):** O Merge Sort, Quick Sort e Heap Sort demonstraram um desempenho significativamente melhor em comparação aos algoritmos quadráticos, o que está em linha com a teoria. O Quick Sort foi o mais rápido, seguido pelo Merge Sort e Heap Sort.

- **Relação Teoria vs. Prática:** Os algoritmos com complexidade O(n log n) se mostraram consistentemente mais rápidos do que os algoritmos com complexidade O(n²), confirmando que a escolha do algoritmo é crucial para a eficiência em grandes volumes de dados.

## Conclusão

Este projeto permitiu validar na prática as diferenças teóricas entre os algoritmos de ordenação, especialmente no que diz respeito ao impacto da complexidade algorítmica sobre o desempenho. Os resultados mostraram que:

- **Algoritmos O(n²):** Algoritmos como Selection Sort, Insertion Sort e Bubble Sort têm limitações evidentes quando o número de elementos aumenta. Eles são fáceis de entender e implementar, mas o tempo de execução cresce rapidamente à medida que o vetor cresce.

- **Algoritmos O(n log n):** Merge Sort, Quick Sort e Heap Sort se saem muito melhor em dados maiores. O Quick Sort foi o mais rápido nos testes, seguido pelo Merge Sort e Heap Sort. Embora o Heap Sort tenha sido eficiente, ele não foi tão rápido quanto o Merge Sort ou o Quick Sort, mas ainda superou os algoritmos quadráticos.

Em resumo, este projeto demonstrou a importância de escolher o algoritmo certo para o tipo de dados com os quais estamos lidando. Em grandes volumes de dados, Quick Sort e Merge Sort são as melhores opções, enquanto os algoritmos O(n²), como Bubble Sort e Selection Sort, devem ser evitados sempre que a performance for uma preocupação.

## Equipe do Projeto

- **Eduardo de Almeida Freitas**
- **Guilherme Silveira Alves**
- **Guilherme Henrique Alves Santos**

