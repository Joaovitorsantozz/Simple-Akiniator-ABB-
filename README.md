# Árvore de Decisão e Aprendizado em C

Este projeto consiste na implementação de uma estrutura de dados de Árvore Binária de Decisão em C capaz de expandir seus nós dinamicamente em tempo de execução. O sistema utiliza uma lógica interativa onde o programa tenta adivinhar um conceito (ex: animais) por meio de perguntas e respostas, aprendendo novas diferenciações e reestruturando a árvore dinamicamente sempre que comete um erro.

### Diferenciais e Destaques Técnicos

- **Manipulação de Memória e Ponteiros:** Uso de alocação dinâmica (`malloc`/`free`) e ponteiros em C para a criação, navegação e liberação completa da árvore, evitando vazamentos de memória.
- **Mutabilidade Dinâmica de Nós:** Diferenciação entre nós de decisão (perguntas) e nós folha (respostas) via `structs` e `enums`. Quando a aplicação falha ao adivinhar, o nó folha é transformado dinamicamente em um nó de decisão, alocando a nova pergunta e encadeando a resposta antiga e a nova nas subárvores correspondentes.
- **Algoritmos e Travessia Recursiva:** Implementação de navegação recursiva para percorrer os ramos da árvore, além do algoritmo de travessia em Pré-Ordem (*Pre-Order Traversal*) para exibição do estado da estrutura após cada aprendizado.
- **Persistência em Tempo de Execução:** A estrutura evolui de forma contínua durante a execução sem perder o histórico do fluxo de perguntas já estruturado.
