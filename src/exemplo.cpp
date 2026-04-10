#include "HeaderBuilder.hpp"
#include <iostream>

#define header_TABLE_(X)                 \
    X(size_t, fileSize)                  \
    X(std::string, fileName)             \
    X(int, fileID)                       \
    X(std::string, fileUser)             \
    X(std::string, fileServer)           

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