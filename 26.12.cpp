// Задача 7

class Solution {
public:
    int findLucky(vector<int>& arr) {

        int arr_2[501];
        int dlina = 0;
        for (int i : arr) {
            dlina++;
        }

        for (int i = 0; i <= 500; i++) {
            arr_2[i] = 0;
        }

        for (int i = 0; i < dlina; i++) {
            arr_2[arr[i]]++;
        }

        for (int i = dlina; i > 0; i--) {
            if (arr_2[i] == i) {
                return i;
            }
        }


        return -1;

    }

};


// Задача 8

class Solution {

public:
    int majorityElement(vector<int>& nums) {

        int candidat = 0;
        int votes = 0;
        int check = -1;

        for (int i : nums) {

            if (check == -1) {
                check = 0;
                candidat = i;
            }

            if (candidat == i) {
                votes++;
            }
            else {
                votes--;
            }

            if (votes == 0) {
                check = -1;
            }
        }

        return candidat;

    }


};

// Задача 6
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        int n = 0;
        for (int i : nums) {
            n++;
        }

        int temp = 0;
        int dif = 100000;

        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    temp = nums[i + 1];
                    nums[i + 1] = nums[i];
                    nums[i] = temp;
                }
            }

        }

        for (int i = 0; i < n - k + 1; i++) {
            int a = nums[i + k - 1] - nums[i];
            if (a < dif) {
                dif = a;
            }
        }
        return dif;
    }


};

// Задача 5


#include <iostream>

int sum(int a, int b) {
    return a + b;
}


int mult(int a, int b) {
    return a * b;
}


int dif(int a, int b) {
    return a - b;
}


double divv(int a, int b) {
    return a / b;
}


int main()
{
    int a = 0;
    int b = 0;
    char operation = '.';
    int (*ptr_sum) (int, int) { sum };
    int (*ptr_dif) (int, int) { dif };
    double (*ptr_divv) (int, int) { divv };
    int (*ptr_mult) (int, int) { mult };


    /*std::cin >> operation;
    std::cout << (operation == '*');
    */
    while (true) {
        std::cout << "Enter parameter a: " << std::endl;
        std::cin >> a;

        std::cout << "Enter parameter b: " << std::endl;
        std::cin >> b;

        std::cout << "Enter operation for a and b or space if you want to end: " << std::endl;
        std::cin >> operation;

        if (operation == '+') {
            std::cout << ptr_sum(a, b);
        }
        if (operation == '-') {
            std::cout << ptr_dif(a, b);
        }
        if (operation == '/') {
            std::cout << ptr_divv(a, b);
        }
        if (operation == '*') {
            std::cout << ptr_mult(a, b);
        }
        if (operation == ' ') {
            break;
        }
        std::cout << std::endl;
    }

}


