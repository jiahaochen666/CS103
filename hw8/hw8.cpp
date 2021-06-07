#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int solve_problem_1(const int *input_arr, const int size_of_input_arr) {
    // Note: size_of_input_arr is the size_of_cake here
    // Write your code for problem 1 here
    int dp[size_of_input_arr + 1];
    dp[0] = 0;
    for (int i = 1; i <= size_of_input_arr; i++){
        int max_val = 0;
        for (int j = 0; j < i; j++)
            max_val = max(max_val, input_arr[j] + dp[i - j - 1]);
        dp[i] = max_val;
    }
    return dp[size_of_input_arr];
}

int solve_problem_2(int capacity_of_firdging_box, const int *weights, const int *profit_scores,
                    const int num_available_cakes) {
    // Write your code for problem 2 here
    int dp[num_available_cakes + 1][capacity_of_firdging_box + 1];
    for (int i = 0; i <= num_available_cakes; i++){
        for (int j = 0; j <= capacity_of_firdging_box; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i - 1] <= j)
                dp[i][j] = max(profit_scores[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[num_available_cakes][capacity_of_firdging_box];
}

int solve_problem_3(const int *input_arr, const int size_of_input_arr, int size_of_cake) {
    // Write your code for problem 3 here
    int dp[size_of_cake + 1];
    for (int i = 1; i < size_of_cake + 1; i++)
        dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < size_of_input_arr; i++){
        for (int j = input_arr[i]; j <= size_of_cake; j++){
            dp[j] += dp[j - input_arr[i]];
        }
    }
    return dp[size_of_cake];
}

void convert_str_to_arr(string str, int **out_arr, int *size_of_out_arr) {
    int str_length = str.length();

    int arr[str_length];

    for (int i = 0; i < str_length; i++)
        arr[i] = 0;

    int j = 0, i;

    for (i = 0; str[i] != '\0'; i++) {

        if (str[i] == ',')
            continue;
        if (str[i] == ' ') {
            j++;
        } else {
            arr[j] = arr[j] * 10 + (str[i] - 48);
        }
    }

    *size_of_out_arr = j + 1;
    *out_arr = new int[*size_of_out_arr];

    for (i = 0; i <= j; i++) {
        (*out_arr)[i] = arr[i];
    }
}

void print_int_arr(const int *arr, const int size_of_arr) {
    cout << "arr[] = ";
    for (int i = 0; i < size_of_arr; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    // This main function is way too long, so please don't follow this style of programming!
    if (argc < 2) {
        cout << "Usage: ./hw8 <input_test_file>" << endl;
        return 1;
    }

    string line_of_test;
    ifstream input_file(argv[1]);

    while (getline(input_file, line_of_test)) {
        int loc_of_s = line_of_test.find(" ");
        int index_of_prob = atoi(line_of_test.substr(0, loc_of_s).c_str());

        switch (index_of_prob) {
            case 0: {
                // Cake Smuggling
                int loc_of_start = line_of_test.find("\"");
                int loc_of_end = line_of_test.find("\"", loc_of_start + 1);
                int *arr1;
                int size_of_arr1 = -1;
                convert_str_to_arr(line_of_test.substr(loc_of_start + 1, loc_of_end - loc_of_start - 1), &arr1,
                                   &size_of_arr1);
                // cout << "size_of_arr1: " << size_of_arr1 << endl;
                // print_int_arr(arr1, size_of_arr1);

                cout << solve_problem_1(arr1, size_of_arr1) << endl;

                delete[] arr1;
                break;
            }
            case 1: {
                // Cake Carrying
                int loc_of_sec_s = line_of_test.find(" ", loc_of_s + 1);
                int capacity_of_firdging_box = atoi(
                        line_of_test.substr(loc_of_s + 1, loc_of_sec_s - loc_of_s - 1).c_str());
                // cout << "capacity_of_firdging_box: " << capacity_of_firdging_box << endl;

                int loc_of_start = line_of_test.find("\"");
                int loc_of_end = line_of_test.find("\"", loc_of_start + 1);
                int *weights;
                int size_of_arr1 = -1;
                convert_str_to_arr(line_of_test.substr(loc_of_start + 1, loc_of_end - loc_of_start - 1), &weights,
                                   &size_of_arr1);
                // cout << "size_of_arr1: " << size_of_arr1 << endl;
                // print_int_arr(weights, size_of_arr1);

                int loc_of_sec_start = line_of_test.find("\"", loc_of_end + 1);
                int loc_of_sec_end = line_of_test.find("\"", loc_of_sec_start + 1);
                int *profit_scores;
                int num_available_cakes = -1;
                convert_str_to_arr(line_of_test.substr(loc_of_sec_start + 1, loc_of_sec_end - loc_of_sec_start - 1),
                                   &profit_scores, &num_available_cakes);
                // cout << "num_available_cakes: " << num_available_cakes << endl;
                // print_int_arr(profit_scores, num_available_cakes);

                cout << solve_problem_2(capacity_of_firdging_box, weights, profit_scores, num_available_cakes) << endl;

                delete[] weights;
                delete[] profit_scores;
                break;
            }
            case 2: {
                // Cake Offering
                int loc_of_sec_s = line_of_test.find(" ", loc_of_s + 1);
                int size_of_cake = atoi(line_of_test.substr(loc_of_s + 1, loc_of_sec_s - loc_of_s - 1).c_str());
                // cout << "size_of_cake: " << size_of_cake << endl;

                int loc_of_start = line_of_test.find("\"");
                int loc_of_end = line_of_test.find("\"", loc_of_start + 1);
                int *arr1;
                int size_of_arr1 = -1;
                convert_str_to_arr(line_of_test.substr(loc_of_start + 1, loc_of_end - loc_of_start - 1), &arr1,
                                   &size_of_arr1);
                // cout << "size_of_arr1: " << size_of_arr1 << endl;
                // print_int_arr(arr1, size_of_arr1);

                cout << solve_problem_3(arr1, size_of_arr1, size_of_cake) << endl;

                delete[] arr1;
                break;
            }
            default:
                cout << "Unable to recognize index_of_prob: " << index_of_prob << endl;
                break;
        }
    }

    return 0;
}