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
    if len(sys.argv) != 2:
        print("Добавьте файл с результатами теста")
        sys.exit(1)

    input_file = sys.argv[1]

    colors = ["blue", "red"]
    x = []
    original_value = []
    interpolation_value = []
    current_test = []
    funcs = []
    delta_y_uniform = []
    delta_y_chebyshev = []


    with open(input_file, "r") as file:

        for line in file:

            words = line.strip().replace(":", "").split(" ")

            if("Arguments" in words):
                x = [float(x) for x in words[1:] if is_number(x)]

            if("Original" in words):
                original_value = [float(x) for x in words[2:] if is_number(x)]

            if("Interpolation" in words):
                interpolation_value =[float(x) for x in words[2:] if is_number(x)]

            if("START" in words):
                current_test = words[2:5]

            if("Function" in words):

                if("f1" in words):
                    funcs.append(words[2])
                else:

                    tmp = 0

                    funcs.append(words[2])

                    for i in range(len(original_value)):
                        tmp += abs(original_value[i] - interpolation_value[i])

                    if "UNIFORM" in current_test:
                        if not (tmp >= 10000):
                            delta_y_uniform.append(round(tmp, 1))
                        else:
                            delta_y_uniform.append(math.nan)

                    elif "CHEBYSHEV" in current_test:
                        if not (tmp >= 10000):
                            delta_y_chebyshev.append(round(tmp, 1))
                        else:
                            delta_y_chebyshev.append(math.nan)
                    
                    data = pd.DataFrame({
                    'x': x,
                    'original_value': original_value,
                    'interpolation_value': interpolation_value
                })

                    plt.figure(figsize=(16, 6))
                    
                    sns.lineplot(data=data, x='x', y='original_value', color=colors[0], label="Original")
                    sns.lineplot(data=data, x='x', y='interpolation_value', color=colors[1], label="Interpolation")
                    
                    plt.title("_".join(current_test) + " " + funcs[-2])
                    plt.xlabel('x')
                    plt.ylabel(funcs[-2] + "(x)")
                    
                    plt.savefig(f'graphs/{"_".join(current_test) + " " + funcs[-2]}.png', dpi=300, bbox_inches='tight')

                    x.clear()
                    original_value.clear()
                    interpolation_value.clear()

    data = pd.DataFrame({
        'delta_y_uniform': delta_y_uniform,
        "delta_y_chebyshev": delta_y_chebyshev,
        "funcs" : funcs[:29]
    })

    plt.figure(figsize=(16, 6))
    plt.yscale('log')
    sns.barplot(data=data, x='funcs', y='delta_y_uniform', color="green")
    
    plt.title("Errors in uniform")
    plt.xlabel('funcs')
    plt.ylabel('errors')
    
    plt.savefig('graphs/Errors_uniform.png', dpi=300, bbox_inches='tight')


    plt.figure(figsize=(16, 6))
    plt.yscale('log')
    sns.barplot(data=data, x='funcs', y='delta_y_chebyshev', color="yellow")
    
    plt.title("Errors in chebyshev")
    plt.xlabel('funcs')
    plt.ylabel('errors')
    
    plt.savefig('graphs/Errors_chebyshev.png', dpi=300, bbox_inches='tight')
    

if __name__ == '__main__':
    main()
