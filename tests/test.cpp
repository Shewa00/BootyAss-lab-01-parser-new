Copyright 2020 panda
#include <gtest/gtest.h>
#include "Json.h"
#include <nlohmann/json.hpp>


const char *const json_data = R"(
{
    "lastname" : "Ivanov",
    "firstname" : "Ivan",
    "age" : 25,
    "islegal" : false,
    "marks" : [
    	4,5,5,5,2,3
    ],
    "address" : {
    	"city" : "Moscow",
        "street" : "Vozdvijenka"
    }
})";

TEST(Json, SimpleTest) {
    Json object = Json::parse(json_data);
    EXPECT_EQ(std::any_cast<std::string>(object["lastname"]), "Ivanov");
    EXPECT_EQ(std::any_cast<std::string>(object["firstname"]), "Ivan");
    EXPECT_EQ(std::any_cast<double>(object["age"]), 25);
    EXPECT_EQ(std::any_cast<bool>(object["islegal"]), false);

    auto marks = std::any_cast<Json>(object["marks"]);
    EXPECT_EQ(std::any_cast<double>(marks[0]), 4);
    EXPECT_EQ(std::any_cast<double>(marks[1]), 5);
    EXPECT_EQ(std::any_cast<double>(marks[2]), 5);
    EXPECT_EQ(std::any_cast<double>(marks[3]), 5);
    EXPECT_EQ(std::any_cast<double>(marks[4]), 2);
    EXPECT_EQ(std::any_cast<double>(marks[5]), 3);

    auto address = std::any_cast<Json>(object["address"]);
    EXPECT_EQ(std::any_cast<std::string>(address["city"]), "Moscow");
    EXPECT_EQ(std::any_cast<std::string>(address["street"]), "Vozdvijenka");
}

using json = nlohmann::json;

TEST(Json, SimpleTestNlohmann) {
    json JsonArrEmpty = json::array();
    json JsonArr = json::array({
                                       {"Si-9.15", "RTS-9.15", "GAZP-9.15"},
                                       {100024, 100027, 100050},
                                       {"Futures contract for USD/RUB",
                                        "Futures contract for index RTS",
                                        "Futures contract for Gazprom shares"}
                               });
    size_t count = 0;
    for (size_t j = 0; j < JsonArr.begin()->size(); ++j) {
        count = 0;
        json temp = json::object();
        for (size_t i = 0; i < JsonArr.size(); ++i, ++count) {
            switch (count) {
                case 0:
                    temp["ticker"] = JsonArr[i][j];
                    break;
                case 1:
                    temp["id"] = JsonArr[i][j];
                    break;
                case 2:
                    temp["description"] = JsonArr[i][j];
                    break;
                default:
                    break;
            }
        }
        JsonArrEmpty.push_back(temp);
    }

    JsonArr = JsonArrEmpty;
    EXPECT_EQ(JsonArr[0]["ticker"], "Si-9.15");
    EXPECT_EQ(JsonArr[1]["ticker"], "RTS-9.15");
    EXPECT_EQ(JsonArr[2]["ticker"], "GAZP-9.15");
    EXPECT_EQ(JsonArr[0]["id"], 100024);
    EXPECT_EQ(JsonArr[1]["id"], 100027);
    EXPECT_EQ(JsonArr[2]["id"], 100050);
    EXPECT_EQ(JsonArr[0]["description"], "Futures contract for USD/RUB");
    EXPECT_EQ(JsonArr[1]["description"], "Futures contract for index RTS");
    EXPECT_EQ(JsonArr[2]["description"], "Futures contract for Gazprom shares");
}
