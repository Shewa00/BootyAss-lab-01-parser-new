Copyright 2020 panda
#include "Json.h"
#include "Checks.h"

Json::Json(const std::string &s) {
    std::string str = correct_string(s);
    size_t i = 0;
    if (str[i] == '{')
        Object = create_Obj(str, ++i);
    else if (str[i] == '[')
        Array = create_Arr(str, ++i);
    else
        throw std::exception();
}

bool Json::is_Array() const {
    return !Array.empty();
}

bool Json::is_Object() const {
    return !Object.empty();
}

std::any &Json::operator[](const std::string &key) {
    if (is_Object())
        return Object[key];
    else
        throw std::exception();
}

std::any &Json::operator[](size_t index) {
    if (is_Array())
        return Array[index];
    else
        throw std::exception();
}


std::map<std::string, std::any> 
    Json::create_Obj(const std::string &s, const size_t begin) {
    size_t i = begin;
    std::map<std::string, std::any> result;
    std::pair<std::any, size_t> value;
    bool end = false;
    while (i <= s.size() && !end) {
        if (s[i] != '\"')
            throw std::exception();

        std::string key = create_string(s, ++i);
        i += key.size() + 1;

        if (s[i] != ':')
            throw std::exception();

        value = create_Value(s, ++i);
        result.emplace(key, value.first);

        if (s[i] == '\"')
            i++;
        i += value.second;

        if (s[i] == '}')
            end = true;
        else if (s[i] != ',')
            throw std::exception();

        i++;
    }
    return result;
}

std::vector<std::any> 
    Json::create_Arr(const std::string &s, const size_t begin) {
    std::string str;
    std::vector<std::any> result;
    std::pair<std::any, size_t> value;
    size_t i = begin;
    bool end = false;
    while (i <= s.size() && !end) {
        value = create_Value(s, i);
        result.push_back(value.first);
        i += value.second;
        if (s[i] == ']')
            end = true;
        else if (s[i] != ',')
            throw std::exception();
        i++;
    }
    return result;
}

std::pair<std::any, size_t>
    Json::create_Value(const std::string &s, const size_t current) {
    size_t i = current;
    std::any value;
    std::string str;
    if (s[i] == '\"') {
        str = create_string(s, current + 1);
        i += str.size() + 1;
        value = str;
    } else if (s[i] == '[') {
        size_t end = size_of_element(s, i, '[', ']');
        str = s.substr(i, end);
        value = Json(str);
        i += end;
    } else if (s[i] == '{') {
        size_t end = size_of_element(s, i, '{', '}');
        str = s.substr(i, end);
        value = Json(str);
        i += end;
    } else if (is_digit(s[i])) {
        str = create_num(s, current);
        i += str.size();
        value = atof(str.c_str());
    } else if (s.substr(i, 5) == "false") {
        i += 5;
        value = false;
    } else if (s.substr(i, 4) == "true") {
        i += 4;
        value = true;
    } else if (s.substr(i, 4) == "null") {
        i += 3;
        value = nullptr;
    } else {
        throw std::exception();
    }

    return std::pair<std::any, size_t>(value, i - current);
}

Json Json::parse(const std::string &s) {
    return Json(s);
}
