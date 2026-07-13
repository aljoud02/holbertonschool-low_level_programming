# Controlled Instrumentation Experiment Report

## Experimental Results
The program was successfully instrumented using the `clock()` function from `<time.h>`. Below are the precise execution times recorded on the host machine:

```text
TOTAL seconds: 0.000773
BUILD_DATA seconds: 0.000289
PROCESS seconds: 0.000342
REDUCE seconds: 0.000136
```

## Measurement Boundaries Justification
To ensure the empirical validation is scientific and fair, the instrumentation boundaries were placed strictly around the logical phases of the execution flow:

* **Sub-measurements (`BUILD_DATA`, `PROCESS`, `REDUCE`)**: The `clock()` markers were placed immediately before and after each function call. This strictly isolates the algorithmic workload of each phase, removing any initialization or print overhead from the sub-metrics.
* **Total Measurement (`TOTAL`)**: The global clock started before the first phase (`build_dataset`) and stopped after the final assignment, capturing the continuous lifecycle of the processing engine.

## Result Analysis
The sum of the three sub-phases is **0.000767 seconds** (\(0.000289 + 0.000342 + 0.000136\)), which is slightly less than the reported **TOTAL** of **0.000773 seconds**. 

This delta of **0.000006 seconds** is fully expected in systems engineering. It represents the architectural overhead of function invocation, stack pushing/popping, and the minuscule processor time required to jump between execution blocks. The `PROCESS` phase consumed the highest runtime due to its localized mathematical modifications inside the loop.

