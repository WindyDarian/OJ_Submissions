#include <queue>
#include <utility> // for std::pair

class Solution {
public:
    int splitArray(vector<int>& nums, int m)
    {
        auto min_heap_cmp = [](int v1, int v2)
        {
            return v1 < v2;
        };
        using min_heap_t = std::priority_queue<int, std::vector<int>, decltype(min_heap_cmp)>;
        using min_heap_sum_pair = std::pair<min_heap_t, int>;
        auto sort_by_sum = [](const min_heap_sum_pair& v1, const min_heap_sum_pair& v2)
        {
            return v1.second < v2.second;
        };

        std::vector<min_heap_sum_pair> heaps_and_current_sums(m);
        std::vector<int> popped_values;

        auto add_value = [&popped_values, &heaps_and_current_sums, sort_by_sum] (int value)
        {
            // try adding the value to the heap with minimum sum
            auto& heap_with_minimal_sum = heaps_and_current_sums.front().first;
            auto& minimal_sum = heaps_and_current_sums.front().second;
            heap_with_minimal_sum.push(value);
            minimal_sum.add_value();

            std::sort(heaps_and_current_sums.begin(), heaps_and_current_sums.end(), sort_by_sum);

            // auto& heap_with_maximal_sum = heaps_and_current_sums.back();
            // heap_with_minimal_sum.first.push(value);
            // heap_with_minimal_sum.stacks_and_current_sums[0]
        };

        for (auto value: nums)
        {

        }

        return 0;
    }
};
