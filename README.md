# My_Printf

Custom implementation of the stdlib function `printf`, built from in C.

---

## Collaboration & Transparency

This project was originally built as a **duo project**. Out of respect for my teammate, this repository **only contains the code and modules that I personally developed**. 

We split the responsibilities as follows:
* **Teammate:** Developed the **Parser** (parsing format strings, extracting flags, and handling format specifiers).
* **Myself:** Developed the **Format Specifiers implementation**, and formatting/conversion logic.

---

## Technical Architecture

The architecture is designed to handle one big buffer and one print:

1. **The Core Engine:** Receives the format string, relies on the parser to identify specifiers, and triggers the appropriate formatting routines.
2. **Pullers & Global Buffer:** Instead of direct, unbuffered writing, data is routed through **pullers** that assemble and write formatted output into a global buffer before flushing it via system calls (`write`).
3. **ASCII Conversion Utilities (`my_[formatID]toa.c`):** Suite of helper functions responsible for converting raw data types (integers, floats, doubles, hexadecimal values) into ASCII representations to be injected into the buffer.

---

## Implemented Flags & Specifiers

As my core contribution to this project, I engineered the logic and formatting for the following specifiers:

* **Integers & Numbers:**
  * `%i / %d` — Signed decimal integers
  * `%u` — Unsigned decimal integers
  * `%x / %X` — Unsigned hexadecimal integers (lowercase / uppercase)
* **Floating-Point Numbers:**
  * `%f / %F` — Standard floating-point representation
  * `%e / %E` — Scientific notation (exponential format)
  * `%g / %G` — General format (automatically selects between `%f` and `%e` based on magnitude)
* **Characters & Strings:**
  * `%c` — Single characters
  * `%s` — Null-terminated character strings

---

### Compilation

This part of the project compile using cland and a Makefile. It then generates a C library.
