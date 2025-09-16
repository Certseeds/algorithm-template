// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2024 nanoseeds

*/


namespace rbqueue {
class ringbuffer_queue {
private:
    std::vector<int32_t> vec;
    size_t read{0}, write{0};
    size_t csize{};
public:
    explicit ringbuffer_queue(size_t size) : vec(vector<int32_t>(size, 0)) {
        csize = size;
    }

    bool isFull() const {
        if (write - read == csize) {
            return true;
        } else if (read - write == csize) {
            return true;
        }
        return false;
    }

    bool isEmpty() const {
        return read == write; // if read == write, it must be empty
    }

    void push(int32_t value) {
        if (isFull()) {
            return;
        }
        vec[write % csize] = value;
        write = (write + 1) % (csize << 1);
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        read = (read + 1) % (csize << 1);
    }

    int32_t front() {
        return vec[read % csize];
    }
};

}
