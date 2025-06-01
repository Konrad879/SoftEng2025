#include <gtest/gtest.h>
#include "Sorter.h"
#include "SortData.h"
#include <algorithm>
#include <cstdlib>

TEST(test_merge, SortsCorrectly)
{
    Sorter* sorter = new Sorter();
    SortData<float, std::vector> data;

    int dsize = 128 + rand() % 100;
    for (unsigned i = 0; i < dsize; i++)
        data.add(float(rand() % 1024) / 4096.0f);
    
    SortError error = sorter->sort<float, std::vector, STT_MERGE>(data);

    ASSERT_EQ(error, SE_SUCCESS);
    ASSERT_TRUE(std::is_sorted(data.data().begin(), data.data().end()));

    delete sorter;
}
