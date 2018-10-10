#include <gtest/gtest.h>
#include "json.hpp"
#include "LogicalImages.hpp"

struct LogicalImagesTests : public ::testing::Test
{
};

TEST_F(LogicalImagesTests, assertThatJSONParsingLibraryWorks)
{
    using json = nlohmann::json;

    json j;
    j["pi"] = 3.14;

    ASSERT_EQ(j.dump(), "{\"pi\":3.14}");
}
