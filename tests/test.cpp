// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <Json.hpp>

TEST(test, smthing) {
    std::string str = R"(lastname" : "Ivanov","firstname" : "Ivan","age" : 25,"islegal" : false,"marks" : [4,5,5,5,2,3],"address" : {"city" : "Moscow","street" : "Vozdvijenka"})";
    EXPECT_TRUE(true);
}