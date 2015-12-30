class CircularBuffer {
  int* buffer;
  unsigned int capacity = 0;
  unsigned int start = 0;
  unsigned int end = 0;
  unsigned int length = 0;

  public:
  CircularBuffer(unsigned int capacity) {
    assert(capacity > 0);
  SetCapacity(capacity);
  }

  ~CircularBuffer() {
    ReleaseBuffer();
  }

  void ReleaseBuffer() {
    if (buffer != 0) {
      delete [] buffer;
    }
  }

  void Reset() {
    start  = 0;
    end    = 0;
    length = 0;
  }

  void SetCapacity(unsigned int capacity) {
    this->capacity = capacity;

    ReleaseBuffer();
    buffer = new int [capacity];

    Reset();
  }

  void Add(int value) {
    if (end >= capacity) {
      end = 0;
    }
    buffer[end] = value;


    if (length == 0) {
      start = 0;
    } else if (start == end) {
      start++;
      if (start >= capacity) {
        start = 0;
      }
    }

    end++;

    if (length != capacity) {
      length++;
    }
  }

  int Get(int index) {
    unsigned int offset = start + index;
    if (offset >= capacity) {
      offset -= capacity;
    }

    return buffer[offset];
  }

  int Length() {
    return length;
  }

  void Print() {
    Serial.println("--");
    Serial.print("Capacity: ");
    Serial.print(this->capacity);

    Serial.print(", Start: ");
    Serial.print(this->start);

    Serial.print(", End: ");
    Serial.print(this->end);

    Serial.print(", Length: ");
    Serial.print(this->length);

    Serial.print("\nContents: ");

    unsigned int index = start;
    for (unsigned int i = 0; i < length; i++, index++) {
      if (index >= capacity) {
        index = 0;
      }

      Serial.print(buffer[index]);
      Serial.print(", ");
    }
    Serial.print("\n");
  }
};
