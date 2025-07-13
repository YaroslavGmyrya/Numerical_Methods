#include "includes/header.hpp"

double iterations;

int main(int argc, char* argv[]){

    double eps;

    std::vector<std::function<double(std::function<double(double)>, double, double, double)>> func_collection = 
    {dichotomy_method, chord_method, newton_method};

    std::vector<std::string> func_names = {"Dichotomy method", "Chords method", "Newton method"};

    switch(argc){

        case 1: 
            std::cout << "\nEnter the  accuracy:";
            std::cin >> eps;
            break;

        case 2:
            eps = std::stod(argv[1]);
            break;
    }

    double result;
    int num_func;
    int i = 0;

    for(const auto& function : func_collection){
        num_func = 0;
        std::cout << "\n===== " << func_names[i] << " start =====\n\n";
        for (const auto& [test_function, range] : func_and_range){
            result = function(test_function, range.first, range.second, eps);
            num_func++;
            if(!std::isnan(result))
                std::cout << "f" << num_func << " Result: " << result << " iterations: "<< iterations << std::endl;
        }

         std::cout << "\n===== " << func_names[i++] << " end =====\n";
    }


    return 0;
}