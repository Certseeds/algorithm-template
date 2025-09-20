// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <catch_main.hpp>
#include "disk_schedule_base.hpp"
#include <array>
#include <algorithm>
#include <memory>
#include <unordered_set>

namespace disk_schedule::no {
using std::unordered_set;

class cscan_disk final : public disk_base {
public:
    cscan_disk(size_t S, size_t M, size_t N, vector<size_t> requests) : disk_base(S, M, N, std::move(requests)) {
        vector<size_t> sorts{this->requests};
        for (const auto i: std::array<size_t, 3>{S, 1, M}) {
            sorts.push_back(i);
        }
        std::sort(std::begin(sorts), std::end(sorts), std::less<>());
        const auto range = std::equal_range(std::begin(sorts), std::end(sorts), S);
        for (auto left{range.first}; left != std::begin(sorts); --left) {
            this->steps.push_back(*left);
        }
        this->steps.push_back(*std::begin(sorts));
        for (auto left{std::end(sorts) - 1}; left != (range.second - 1); --left) {
            this->steps.push_back(*left);
        }
        for (size_t i{1}, size{this->steps.size()}; i < size; ++i) {
            this->distance += std::max(this->steps[i], this->steps[i - 1]) -
                              std::min(this->steps[i], this->steps[i - 1]);
        }
    };

    [[nodiscard]] const char *name() const override {
        return "cscan"; // 这个没缩写
    }
};

static constexpr const std::array<const std::array<const char *const, 3>, 4> pairs{
        {
                {"01.data.in", "cscan/01.data.out", "cscan/01.test.out"},
                {"02.data.in", "cscan/02.data.out", "cscan/02.test.out"},
                {"03.data.in", "cscan/03.data.out", "cscan/03.test.out"},
                {"04.data.in", "cscan/04.data.out", "cscan/04.test.out"},
        }};

TEST_CASE("cscan test sample") {
    for (const auto &[stdInput, stdOutput, testOutput]: pairs) {
        {
            const CS203_redirect cr{stdInput, testOutput};
            const auto input = inputs::read_input();
            const std::unique_ptr<disk_base> disk = std::make_unique<cscan_disk>(input.S, input.M, input.N,
                                                                                 input.requests);
            disk->output();
        }
        CHECK(compareFiles(stdOutput, testOutput));
    }
}


}
#endif
