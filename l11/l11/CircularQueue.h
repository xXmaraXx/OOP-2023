#include <iostream>
#include <vector>

template <typename T>
class CircularQueue {
  public:
    explicit CircularQueue(size_t capacity) : capacity(capacity), count(0), begin(0), end(0) {
        buffer.resize(capacity);
    }

    void push(const T& value) {
        if (isFull()) {
            buffer[end] = value;
            begin = (begin + 1) % capacity;
            end = (end + 1) % capacity;
        } else {
            buffer[end] = value;
            end = (end + 1) % capacity;
            count++;
        }
    }

    void pop() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty. Cannot perform pop operation.");
        }
        begin = (begin + 1) % capacity;
        count--;
    }

    T& front() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty. Cannot access front element.");
        }
        return buffer[begin];
    }

    T& back() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty. Cannot access back element.");
        }
        return buffer[(end + capacity - 1) % capacity];
    }

    size_t size() const {
        return count;
    }

    bool empty() const {
        return count == 0;
    }

  private:
    size_t capacity;
    size_t count;
    size_t begin;
    size_t end;
    std::vector<T> buffer;

    bool isFull() const {
        return count == capacity;
    }

    bool isEmpty() const {
        return count == 0;
    }
};
