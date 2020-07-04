#! /bin/python3

import subprocess
import math

results = []
trials = int(math.log(1024, 2));

for i in range(trials + 1):
    print("Calculating for {} pages".format(2 ** i))
    result = subprocess.run(["./tlb", "{}".format(2 ** i), "10000000"])
    results.append(result.returncode)

print(results)
