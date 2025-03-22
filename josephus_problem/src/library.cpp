
#include "library.hpp"

namespace template_library {
    int josephus_problem([[maybe_unused]] const std::vector<int>& nums,
                         [[maybe_unused]] int k) {
        std::deque<int> dq; 
        int a=nums.size();
        for (int i=0; i<a; ++i){
            dq.push_back(nums[i]);
        }
        while (dq.size() > 1) {
            int temp = (k - 1) % dq.size();
            for (int i = 0; i < temp; ++i) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            dq.pop_front();
        }
    return dq.front();
        return 0;
    };
}
