//
// Created by panda on 10.12.2019.
//

#ifndef LAB_01_PARSER_CHECKS_H
#define LAB_01_PARSER_CHECKS_H


bool is_digit(const char ch) {
    return ch >= '0' && ch <= '9';
}

size_t size_of_element(const std::string &s, const size_t current, const char start, const char end) {
    size_t st = 1, en = 0, i = current + 1;
    while (st != en && i <= s.size()) {
        if (s[i] == start)
            st++;
        if (s[i] == end)
            en++;
        i++;
    }
    return i - current;
}

std::string correct_string(const std::string &s) {
    std::string str = s;
    size_t i = 0;
    while (i < str.size()) {
        if (str[i] == '\n' || str[i] == '\r' || str[i] == '\t' || str[i] == ' ')
            str.erase(str.begin() + i);
        else
            i++;
    }
    return str;
}

std::string create_string(const std::string &s, const size_t current) {
    size_t end = current;
    while (s[end] != '\"' && end <= s.size())
        end++;
    return s.substr(current, end - current);
}

std::string create_num(const std::string &s, const size_t current) {
    size_t i = current;
    std::string num = "";
    while (i <= s.length() && is_digit(s[i])) {
        num += s[i];
        i++;
    }
    return num;
}

#endif //LAB_01_PARSER_CHECKS_H
