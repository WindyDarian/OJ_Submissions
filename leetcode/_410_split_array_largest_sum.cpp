#include <algorithm>

class Solution {
public:
    int splitArray(vector<int>& nums, int m)
    {
        // The solution must be between [max_element, sum_all]
        auto max_element = 0L;
        auto sum_all = 0L;
        for (auto num : nums)
        {
            if (num > max_element) {max_element = num;}
            sum_all += num;
        }

        auto calculate_valid_as_max = [&nums, m](decltype(sum_all) desired_max)
        {
            auto current_subarray_sum = 0L;
            auto current_cuts = 0;
            for (auto num : nums)
            {
                current_subarray_sum += num;
                if (current_subarray_sum > desired_max)
                {
                    current_cuts++;
                    if (current_cuts >= m)
                    {
                        return false;
                    }
                    current_subarray_sum = num;
                }
            }
            return true;
        };
        
        for (auto current = max_element; current <= sum_all; current++)
        {
            if (calculate_valid_as_max(current))
            {
                return current;
            }
        }

        return 0;
    }
};
