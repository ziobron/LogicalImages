#include <gtest/gtest.h>
#include <json.hpp>
#include "LogicalImages.hpp"

struct LogicalImagesTests : public ::testing::Test
{
};

TEST_F(LogicalImagesTests, assertThatJSONParsingLibraryWorks)
{
    using json = nlohmann::json;

    json j;
    j["pi"] = 3.14;

    ASSERT_TRUE(j["pi"] == 3.14);
}
