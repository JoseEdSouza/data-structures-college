# README
# Classificador de Árvore de Decisão em Python

Este projeto implementa um classificador de árvore de decisão em Python para tarefas de classificação. Ele permite que você treine um modelo de árvore de decisão com base em um conjunto de dados de entrada e faça previsões com base nas respostas do usuário.

O código inclui funcionalidades para pré-processamento de dados, como separação em conjuntos de treinamento e teste, além de recursos para treinar o modelo e realizar previsões interativas. A árvore de decisão é construída usando o critério de ganho de informação ou índice de pureza de Gini, dependendo da escolha do usuário.

O projeto é composto por dois arquivos principais:

1. `diseaseDecisionTree.py`: Este arquivo contém a implementação da classe `DecisionTreeClassifier`, que representa o classificador de árvore de decisão. Ele também inclui a definição da classe auxiliar `Node`, que representa um nó da árvore.

2. `cdt.py`: Este arquivo é o ponto de entrada do programa. Ele contém o código que carrega os dados, divide-os em conjuntos de treinamento e teste e treina o modelo de árvore de decisão. Também permite que o usuário faça previsões interativas com base nos sintomas fornecidos.


## Requisitos

Certifique-se de ter os seguintes requisitos instalados no seu ambiente antes de executar o código:

- Python (versão 3.6 ou superior)
- Bibliotecas Python: numpy, pandas, scikit-learn

## Instalação

Siga as etapas abaixo para configurar o ambiente e instalar as dependências:

1. Clone este repositório para o seu ambiente local.
2. Navegue até o diretório do código-fonte.

    ```
    cd path/to/source/code
    ```

3. Crie um ambiente virtual (opcional, mas recomendado).

    ```
    python -m venv myenv
    source myenv/bin/activate  # (para Linux/Mac)
    myenv\Scripts\activate  # (para Windows)
    ```

4. Instale as dependências usando o pip e o arquivo "requirements.txt".
   
    **pip**:
    ```
    pip install -r requirements.txt
    ```
    **makefile**:
    ```shell
    make install
    ```
## Executando o código

Para executar o código, siga as instruções específicas fornecidas no código-fonte.
Ou rode ```make run``` depois de instalar para rodar usando argumentos e arquivo de dados predefinidps

