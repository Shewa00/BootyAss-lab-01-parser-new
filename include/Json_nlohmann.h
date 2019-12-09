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

    stringstream strS;

    strS << "[";
    for (size_t i = 0; i < 4; ++i) {
        strS << "{";
        strS << R"("ticker":")" << any_cast<string>(any_cast<Json>(data[0])[i]) << "\",";
        strS << "\"id\":" << any_cast<double>(any_cast<Json>(data[1])[i]) << ",";
        strS << R"("description":")" << any_cast<string>(any_cast<Json>(data[2])[i]) << "\"";
        strS << "}";

        if (i != 4 - 1)
            strS << ",";
    }

    strS << "]";

    string str;
    getline(strS, str);

    return Json(str);
}

#endif //LAB_01_PARSER_JSON_NLOHMANN_H
