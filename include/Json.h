#ifndef LAB_01_PARSER_JSON_H
#define LAB_01_PARSER_JSON_H

#include <string>
#include <any>
#include <vector>
#include <map>


class Json {
public:
    // Конструктор из строки, содержащей Json-данные.
    Json(const std::string &s);

    // Метод возвращает true, если данный экземпляр содержит в себе JSON-массив. Иначе false.
    bool is_array() const;

    // Метод возвращает true, если данный экземпляр содержит в себе JSON-объект. Иначе false.
    bool is_object() const;

    // Метод возвращает значение по ключу key, если экземпляр является JSON-объектом.
    // Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
    // Если экземпляр является JSON-массивом, генерируется исключение.
    std::any &operator[](const std::string &key);

    // Метод возвращает значение по индексу index, если экземпляр является JSON-массивом.
    // Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
    // Если экземпляр является JSON-объектом, генерируется исключение.
    std::any &operator[](size_t index);

    // Метод возвращает объект класса Json из строки, содержащей Json-данные.
    static Json parse(const std::string &s);


    std::map<std::string, std::any> create_obj(const std::string &s, const size_t begin);

    std::vector<std::any> create_arr(const std::string &s, const size_t begin);

    std::pair<std::any, size_t> create_value(const std::string &s, const size_t current);

private:
    std::map<std::string, std::any> obj;
    std::vector<std::any> arr;
};

#endif //LAB_01_PARSER_JSON_H