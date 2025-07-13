import sys
import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd

NOF_TEST_FUNCS = 46

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

    funcs = []
    iterations = []
    results = []
    complete_funcs = []
    methods = []
    colors = ["red", "green", "blue", "yellow"]


    with open(input_file, "r") as file:

        for line in file:

            words = line.strip().replace(":", "").split(" ")

            if("Result" and "iterations" in words):

                funcs.append(words[0])
                iterations_index = words.index("iterations")
                result_index = words.index("Result")

                iterations.append(float(words[iterations_index + 1]))
                results.append(float(words[result_index + 1]))

            if "end" in line:

                words = line.split(" ")

                index_end = words.index("end")

                methods.append(words[index_end - 2] + "_" + words[index_end - 1])

                complete_funcs.append(len(funcs) / NOF_TEST_FUNCS * 100)

                data = pd.DataFrame({
                    'functions': funcs,
                    'results': results,
                    'iterations': iterations
                })

                plt.figure(figsize=(16, 6))
                
                sns.barplot(data=data, x='functions', y='iterations', color=colors.pop())
                
                plt.title(methods[-1])
                plt.xlabel('functions')
                plt.ylabel('iterations')
                
                plt.savefig(f'{methods[-1]}.png', dpi=300, bbox_inches='tight')
                plt.show()

                funcs = []
                iterations = []
                results = []


    data = pd.DataFrame({
        'methods': methods,
        "complete_funcs": complete_funcs,
    })

    plt.figure(figsize=(16, 6))
    
    sns.barplot(data=data, x='methods', y='complete_funcs', color=colors.pop())
    
    plt.title("resolved equations")
    plt.xlabel('methods')
    plt.ylabel('resolved equations')
    
    plt.savefig('complete.png', dpi=300, bbox_inches='tight')
    plt.show()

            

    

if __name__ == '__main__':
    main()
