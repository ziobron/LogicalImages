#include <gtest/gtest.h>
#include "json.hpp"
#include "LogicalImages.hpp"
#include "JSONFileReader.hpp"

class AlgorithmA : public Algorithm
{
public:
    AlgorithmA() {}

    bool solve(std::shared_ptr<Board> b)
    {
        return true;
    }
};

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

TEST_F(LogicalImagesTests, checkFirstConstructorNoexception)
{
    std::string path = "../test/ReadMeBoardTestFile.json";
    JSONFileReader jfr(path);
    auto b = std::make_shared<Board>(jfr.readRowSize(),
                                     jfr.readColSize(),
                                     jfr.readCluesRows(),
                                     jfr.readCluesCols());
    auto a = std::make_shared<AlgorithmA>();

    LogicalImages li(b, a);
}

TEST_F(LogicalImagesTests, checkSecondConstructorNoexception)
{
    std::string path = "../test/ReadMeBoardTestFile.json";
    auto a = std::make_shared<AlgorithmA>();

    LogicalImages li(path, a);
}

TEST_F(LogicalImagesTests, checkSecondConstructorExceptions)
{
    std::string path;
    auto a = std::make_shared<AlgorithmA>();

    path = "../test/JSONFileReaderWrongColSizeTestFile.json";
    ASSERT_THROW(LogicalImages li1(path, a), InvalidDimensions);

    path = "../test/JSONFileReaderWrongRowSizeTestFile.json";
    ASSERT_THROW(LogicalImages li2(path, a), InvalidDimensions);

    path = "../test/JSONFileReaderNumberOfLinesAndColsNoMatch.json";
    ASSERT_THROW(LogicalImages li3(path, a), InvalidDimensions);

    path = "../test/JSONFileReaderNumberOfLinesAndRowsNoMatch.json";
    ASSERT_THROW(LogicalImages li4(path, a), InvalidDimensions);
}

TEST_F(LogicalImagesTests, checkSolveAlgorithmA)
{
    std::string path = "../test/ReadMeBoardTestFile.json";
    std::string solution = "Puzzle solved!";
    auto a = std::make_shared<AlgorithmA>();
    testing::internal::CaptureStdout();

    LogicalImages li(path, a);
    li.solve();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find(solution), std::string::npos);
}
