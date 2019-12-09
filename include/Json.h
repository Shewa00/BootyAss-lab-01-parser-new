#ifndef LAB_01_PARSER_JSON_H
#define LAB_01_PARSER_JSON_H

#include <string>
#include <any>
#include <vector>
#include <map>


class Json {
    std::map<std::string, std::any> Object;
    std::vector<std::any> Array;
public:
    // Конструктор из строки, содержащей Json-данные.
    explicit Json(const std::string &s);

    // Метод возвращает true, если данный экземпляр содержит в себе JSON-массив. Иначе false.
    [[nodiscard]] bool is_Array() const;

    // Метод возвращает true, если данный экземпляр содержит в себе JSON-объект. Иначе false.
    [[nodiscard]] bool is_Object() const;

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


    static std::map<std::string, std::any> create_Obj(const std::string &s, size_t begin);

    static std::vector<std::any> create_Arr(const std::string &s, size_t begin);

    static std::pair<std::any, size_t> create_Value(const std::string &s, size_t current);
};

#endif //LAB_01_PARSER_JSON_H