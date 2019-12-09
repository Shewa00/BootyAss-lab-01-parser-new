#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

TEST(Json, SimpleTestNlohmann) {
    json JsonArrEmpty = json::array();
    json JsonArr = json::array({
                                       {"Si-9.15", "RTS-9.15", "GAZP-9.15"},
                                       {100024, 100027, 100050},
                                       {"Futures contract for USD/RUB", "Futures contract for index RTS",
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