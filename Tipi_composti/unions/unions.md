### Memory Layout
Unions store their value in the same memory location, no matter which field or type is actively being used. That means that accessing any field apart from the one you set is generally a bad idea.


### Union Size
A downside of unions is that the size of the union is the size of the largest field in the union. Take this example:

typedef union IntOrErrMessage {
  int data;
  char err[256];
} int_or_err_message_t;

This IntOrErrMessage union is designed to hold an int 99% of the time. However, when the program encounters an error, instead of storing an integer here, it will store an error message. The trouble is that it's incredibly inefficient because it allocates 256 bytes for every int that it stores!


#### Helper Fields
One interesting (albeit not commonly used) trick is to use unions to create "helpers" for accessing different parts of a piece of memory. Consider the following:

```C
typedef union Color {
  struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
  } components;
  uint32_t rgba;
} color_t;
```

Only 4 bytes are used. And, (unlike in 99% of scenarios) it makes sense to both set and get values from this union through both the components and rgba fields! Both fields in the union are exactly 32 bits in size, which means that we can "safely" access the entire set of colors through the .rgba field, or get a single color component through the .components field.
- Possiamo accedere a un colore alla volta oppure all'intero dato tutto insieme!