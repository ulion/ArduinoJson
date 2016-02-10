// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <gtest/gtest.h>

TEST(Issue221, ReadFirst) {
  char json[] =
      "{\"device\":\"temp\", "
      "\"value\":\"22\"},{\"device\":\"lux\",\"value\":\"888\"}";
  DynamicJsonBuffer jsonBuffer;
  JsonObject& obj1 = jsonBuffer.parseObject(json);
  ASSERT_TRUE(obj1.success());
  ASSERT_STREQ(obj1["device"], "temp");
  ASSERT_EQ(obj1["value"], 22);
}
