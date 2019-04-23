]000, 1000[; 1000
]000, 500[;1 500
]250, 500[;2 250
]250, 375[;3 125
]312, 375[;4 63
]343, 375[;5 32
]359, 375[;6 16
]359, 367[;7 8
]359, 363[;8 4
]359, 361[;9 2
360 10       1



[1 3 14 78 79 240 281 285 298 432 981 1002 1005 1023 1987 2039 2919 3029]

[inicio, fim]
int binary_search(int sorted_list[], int low, int high, int element)
{
    if (high < low)
        return -1;
    int middle = low + (high - low)/2;
    if (element < sorted_list[middle])
        return binary_search(sorted_list, low, middle-1, element);
    else if (element > sorted_list[middle])
        return binary_search(sorted_list, middle+1, high, element);
    else
        return middle;
}

