class DynamicArray {
private:
    int* data = nullptr;
    size_t size;
    size_t cap;

    void realloc(size_t new_cap) {
        int* new_data = new int[new_cap];

        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        cap = new_cap;
    }
public:
    DynamicArray(int capacity) {
        cap = capacity;
        data = new int[capacity];
        size = 0;
    }

    int get(int i) {
        return data[i];
    }

    void set(int i, int n) {
        data[i] = n;
    }

    void pushback(int n) {
        if (size >= cap)
            realloc(2*cap);
        data[size] = n;
        ++size;
    }

    int popback() {
        --size;
        return data[size];
    }

    void resize() {
        realloc(2*cap);
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};
