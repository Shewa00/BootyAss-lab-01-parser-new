// Copyright 2018 panda_canniball@mail.ru

#ifndef INCLUDE_JSON_HPP_
#define INCLUDE_JSON_HPP_

#include <iostream>
#include <string>
#include <map>
#include <any>

class Json {
    std::map<std::string, std::any> ObjectType;
    std::vector<std::any> ArrayType;
public:
    explicit Json(const std::string& str) {

    }



    // Метод возвращает true, если данный экземпляр содержит в себе JSON-массив. Иначе false.
    [[nodiscard]] bool is_array() const {}
    // Метод возвращает true, если данный экземпляр содержит в себе JSON-объект. Иначе false.
    [[nodiscard]] bool is_object() const {}

    // Метод возвращает значение по ключу key, если экземпляр является JSON-объектом.
    // Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
    // Если экземпляр является JSON-массивом, генерируется исключение.
    std::any& operator[](const std::string& key) {}

    // Метод возвращает значение по индексу index, если экземпляр является JSON-массивом.
    // Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
    // Если экземпляр является JSON-объектом, генерируется исключение.
    std::any& operator[](int index) {}

    // Метод возвращает объект класса Json из строки, содержащей Json-данные.
    static Json parse(const std::string& s) {}

    // Метод возвращает объекта класса Json из файла, содержащего Json-данные в текстовом формате.
    static Json parseFile(const std::string& path_to_file) {}
};

void parser(std::string &str) {
    size_t length = str.length();
    length++;




}


#endif // INCLUDE_JSON_HPP_
