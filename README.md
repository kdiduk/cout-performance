# cout-performance

A rough benchmark of `std::cout` with different settings.

## Benchmark

Print Shakespeare's sonnets 1000 times to `/dev/null`.

Environment:

* Apple M3
* Clang 21
* arm64-apple-darwin25.5

Time in microseconds.

| Run   | Default | no sync with stdio | no std::endl | puts() |
|-------|---------|--------------------|--------------|--------|
| 1.    | 2447149 | 2431388            | 437274       | 206680 |
| 2.    | 2424436 | 2431463            | 432456       | 207813 |
| 3.    | 2410315 | 2475041            | 436400       | 203624 |
| 4.    | 2686783 | 2428963            | 438486       | 206264 |
| 5.    | 2419577 | 2436221            | 438761       | 207542 |
| 6.    | 2423601 | 2431060            | 434446       | 206263 |
| 7.    | 2431216 | 2433978            | 433248       | 207782 |
| 8.    | 2425815 | 2442381            | 437799       | 205182 |
| 9.    | 2429051 | 2424418            | 440202       | 207931 |
| 10.   | 2448260 | 2433070            | 437079       | 209172 |
| Avg.  | 2454620 | 2436798            | 436636       | 206825 |
| 50p   | 2427433 | 2432266            | 437079       | 207111 |
| 90p   | 2472112 | 2445647            | 438761       | 208055 |


## Conclusions

* Disabling stdio synchronization had no measurable effect in this benchmark.
* Using `'\n'` instead of `std::endl` improved performance by approximately 5–6×.
* `puts()` from `<stdio.h>` was more than 2× faster than `std::cout` using `'\n'` instead of `std::endl`.
