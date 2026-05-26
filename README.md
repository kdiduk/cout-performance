# cout-performance
A rough benchmarking of std::cout with different settings


Print Sheakspear sonnets 1000 times to `/dev/null`

CLang 21 arm64-apple-darwin25.5

Time in microseconds

default: [2447149, 2424436, 2410315, 2686783, 2419577, 2423601, 2431216, 2425815, 2429051, 2448260]

no-sync [2431388, 2431463, 2475041, 2428963, 2436221, 2431060, 2433978, 2442381, 2424418, 2433070]

no-flush: [437274, 432456, 436400, 438486, 438761, 434446, 433248, 437799, 440202, 437079, 436849]

puts: [206680, 207813, 203624, 206264, 207542, 206263, 207782, 205182, 207931, 209172, 210095, 207811]

Conclusion: 
— disable sync with stdio didn't give any noticeable improvement
— use '\n' instead of std::endl improved performance by ~5-6 times
— using `puts()` from <stdio.h> showed ~12 times better performance