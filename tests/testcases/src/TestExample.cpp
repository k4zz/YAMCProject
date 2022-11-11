#include <gtest/gtest.h>

#include "ExampleModule/ExampleModule.h"

TEST(Unit_ExampleModule_Addition, TwoPlusTwo_ReturnFour)
{
    ASSERT_EQ(ExampleModule::addition(2, 2), 4);
}