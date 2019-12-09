//
// Created by panda on 10.12.2019.
//

#ifndef LAB_01_PARSER_JSON_NLOHMANN_H
#define LAB_01_PARSER_JSON_NLOHMANN_H

#include <iostream>
#include <sstream>
#include "Json.h"

using namespace std;

Json Transform(const std::string &s) {
    Json data(s);

    stringstream ss;

    ss << "[";
    for (size_t i = 0; i < 4; ++i) {
        ss << "{";
        ss << "\"ticker\":\"" << any_cast<string>(any_cast<Json>(data[0])[i]) << "\",";
        ss << "\"id\":" << any_cast<double>(any_cast<Json>(data[1])[i]) << ",";
        ss << "\"description\":\"" << any_cast<string>(any_cast<Json>(data[2])[i]) << "\"";
        ss << "}";

        if (i != 4 - 1)
            ss << ",";
    }

    ss << "]";

    string str;
    getline(ss, str);

    return Json(str);
}

#endif //LAB_01_PARSER_JSON_NLOHMANN_H
