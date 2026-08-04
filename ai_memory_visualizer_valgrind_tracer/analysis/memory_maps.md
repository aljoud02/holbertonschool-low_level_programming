# Memory Analysis & Visualization Report

## 1. Stack Memory Analysis (`stack_example.c`)

### Execution Points & Memory Maps
Here is the step-by-step memory lifecycle during the execution of the stack-based functions:

#### Point A: Entry into Recursive/Stack Function (Function Frame Setup)
* **Stack Frame:** A new stack frame for the function is allocated on top of the stack.
* **Local Variables:** Variables like `int n` or local arrays are allocated within this frame.
* **Lifetime:** These variables are bound to the execution of this specific function instance.

#### Point B: Peak Recursion / Deepest Stack Frame
* **Stack Architecture:** Multiple stack frames exist simultaneously, each corresponding to an active function call.
* **Visual Representation:**
    ```text
    +----------------------------------+ <--- High Memory Address

    | main() Frame                     |
    | - local variables / arguments    |
    +----------------------------------+

    | stack_func(n=3) Frame            |
    +----------------------------------+

    | stack_func(n=2) Frame            |
    +----------------------------------+

    | stack_func(n=1) Frame            | <--- Current Stack Pointer (ESP/RSP)
    +----------------------------------+ <--- Low Memory Address
    ```

#### Point C: Function Exit (Frame Deallocation)
* **Mechanism:** The stack pointer moves back up, releasing the frame. 
* **Lifetime End:** Local variables become invalid immediately. Referencing their addresses after this point results in Undefined Behavior (UB).

---

## 2. Pointer Aliasing Analysis (`aliasing_example.c`)

### Memory Mapping & Ownership Tracking
This section tracks how multiple pointers interact with the same memory location.

* **Initial State:** A buffer or variable is allocated (either on the Stack or Heap).
* **Aliasing Event:** `ptr1` points to the allocated memory. `ptr2 = ptr1;` is executed.
* **State Map:**
    ```text
    [ ptr1 ] ------------> +------------------------+

                           | Dynamic/Static Buffer  |
    [ ptr2 ] ------------> +------------------------+
    ```
* **Ownership & Responsibility:** Both pointers reference the exact same memory address. However, only one pointer holds structural ownership. If `ptr1` is used to `free()` the memory, `ptr2` instantly becomes a Dangling Pointer. Any subsequent read/write via `ptr2` is an invalid memory access.

---

## 3. Heap Memory Analysis (`heap_example.c`)

### Lifetimes & Management
* **Allocation:** Memory requested via `malloc()` or `calloc()` bypasses the stack and is carved out of the Heap.
* **Lifetime:** Independent of function scopes. It persists until an explicit call to `free()` is executed.
* **State Visual:**
    ```text
    Stack Frame (main)          Heap Memory Segment
    +--------------------+      +--------------------+

    | ptr (Local Pointer)| ---> | Allocated Block    |
    +--------------------+      +--------------------+

---

## 4. AI Critique & Error Correction (Mandatory Audit)

### Documented Instance of AI Inaccuracy

* **Initial AI Output Prompted:** "Explain the state of a pointer after `free(ptr);` is called inside `heap_example.c`."
* **Incorrect AI Assertion:** The AI claimed that "Calling `free(ptr)` automatically sets the pointer to `NULL`, making it safe from causing bugs or segmentation faults."
* **Technical Critique & Correction:**
    * **Why it was wrong:** The AI confused ideal defensive programming with actual C runtime mechanics. The function `free(ptr)` only tells the memory allocator that the block at that address is no longer needed. It does not modify the value stored inside the actual pointer variable `ptr` itself.
    * **The Corrected Reality:** The pointer `ptr` still contains the exact same memory address as before (it becomes a Dangling Pointer). Attempting to dereference it without reassigning it causes Use-After-Free bugs or crashes, because that memory chunk might be reallocated elsewhere. To make it safe, a developer must explicitly write `ptr = NULL;` after freeing.

