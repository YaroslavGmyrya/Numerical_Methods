import sys
import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd
import re
import math

def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        return False

def main():

    input_file = sys.argv[1]

    method_template = "START (.+?) ====="
    func_template = "(f\d+)"
    delta_result_template = "DELTA RESULT:\s*(-?\d+\.?\d+|nan)"

    for input_file in sys.argv[1:]:
        method = ""
        funcs = []
        delta_result = []
        with open(input_file, "r") as file:
            for line in file:
                match = re.search(rf"{method_template}", line)
                if match:
                    method = match.group(1)

                match = re.search(rf"{func_template}", line)
                if match:
                    funcs.append(match.group(1))

                match = re.search(rf"{delta_result_template}", line)
                if match:
                    delta_result.append(float(match.group(1) if is_number(match.group(1)) else 1))
                    
        data = pd.DataFrame({
        'funcs': funcs,
        'delta_result': delta_result,
        })

        plt.figure(figsize=(16, 6))

        plt.yscale("log")
        
        sns.barplot(data=data, x='funcs', y='delta_result', color="red")

        plt.title(method)
        plt.xlabel('funcs')
        plt.ylabel("error")
        
        plt.savefig(f'graphs/{method.lower()}.png', dpi=300, bbox_inches='tight')

if __name__ == '__main__':
    main()
