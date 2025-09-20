// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <catch_main.hpp>
#include "disk_schedule_base.hpp"
#include <array>
#include <memory>
#include <utility>

namespace disk_schedule::no {

class fcfs_disk final : public disk_base {
public:
    fcfs_disk(size_t S, size_t M, size_t N, vector<size_t> requests) : disk_base(S, M, N, std::move(requests)) {
        size_t last_head{this->S};
        this->steps.push_back(last_head);
        for (const auto &item: this->requests) {
            this->distance += std::max(item, last_head) - std::min(item, last_head);
            last_head = item;
            this->steps.push_back(last_head);
        }
    };

    [[nodiscard]] const char *name() const override {
        return "First Come First Served"; // same as First In First Out
    }
};

static constexpr const std::array<const std::array<const char *const, 3>, 4> pairs{
        {
                {"01.data.in", "fcfs/01.data.out", "fcfs/01.test.out"},
                {"02.data.in", "fcfs/02.data.out", "fcfs/02.test.out"},
                {"03.data.in", "fcfs/03.data.out", "fcfs/03.test.out"},
                {"04.data.in", "fcfs/04.data.out", "fcfs/04.test.out"},
        }};

TEST_CASE("fcfs test sample") {
    for (const auto &[stdInput, stdOutput, testOutput]: pairs) {
        {
            const CS203_redirect cr{stdInput, testOutput};
            const auto input = inputs::read_input();
            const std::unique_ptr<disk_base> disk = std::make_unique<fcfs_disk>(input.S, input.M, input.N,
                                                                                input.requests);
            disk->output();
        }
        CHECK(compareFiles(stdOutput, testOutput));
    }
}


}
#endif
