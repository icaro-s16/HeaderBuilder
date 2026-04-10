# HeaderBuilder

## Utilização
Essa biblioteca é utilizada para criar um *header* personalizado para o seu código usando metaprogramação, adicionando um serializador e um desserializador de forma automática!

## Exemplo

- **Definição da tabela de campos:** Você precisa criar uma tabela com os campos do seu *header*, colocando o nome do campo e o seu tipo. Observe que essa tabela precisa ser declarada com o nome do seu *header* + `_TABLE_`!

```C++
#define header_TABLE_(X)                 \
    X(size_t, fileSize)                  \
    X(std::string, fileName)             \
    X(int, fileID)                       \
    X(std::string, fileUser)             \
    X(std::string, fileServer)
```

- **Criação das estruturas:** Com essa tabela em mãos, podemos chamar os dois macros principais, o `ObjectBuilder` e o `HeaderBuilder`. Eles receberão como parâmetro o nome do seu header, criando, assim, o objeto do seu header com os campos definidos e o builder do header para fazer a serialização do seu objeto!

```C++
ObjectBuilder(header)
HeaderBuilder(header)


int main(){
    headerObject object;
    headerBuilder builder;

    object.fileID = 1;
    object.fileName = "Arquivo.txt";
    object.fileServer = "ServerIkr";
    object.fileSize = 1024;
    object.fileUser = "Icaro";

    std::vector<char> c = object.serializer_bytes();

    headerObject obj = builder.deserializer(c);

    std::cout << obj.serializer() << std::endl;
    
    return 0;
}
```

- **OBS:** Dentro do diretório `src/` há um exemplo de uso!


## Implementações 

- **Classe Object:** A classe object armazena todos os campos do seu header, contendo as funções de serialização, tanto para string quanto para vetor de char.

- **Classe Builder:** A classe builder faz o processo de desserialização de um header, retornando uma classe object.

- **Funções Default:** A lib apresenta um parser para a maioria dos tipos padrão. Caso você deseje adicionar um parser de uma string para um tipo específico, basta adicionar o seguinte bloco de código, no qual haverá a lógica do parser:

```C++
template<>
void parser(std::string, <new type>& t){
    \*
        todo!()    
    *\
}
```


## Instalação 

- **Git Clone:**
```shell
git clone https://github.com/icaro-s16/HeaderBuilder.git
```

- **Adicionando no seu projeto:**
Para adicionar ao seu projeto, basta mover o arquivo `src/HeaderBuilder.hpp` para onde você achar mais conveniente!
