#include <iostream>

int* merge(int* first, int* second, int left_first, int right_first, int left_second, int right_second)
{
    int *result = new int[right_first + right_second + 2];
    
    for (int i = 0; i < right_first + right_second + 2; i++)
    {
        if ((first[left_first] <= second[left_second] || left_second > right_second) && left_first <= right_first)
        {
            result[i] = first[left_first++];
        } else if ((first[left_first] > second[left_second] || left_first > right_first) && left_second <= right_second)
        {
            result[i] = second[left_second++];
        }
    }
    
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    
    int *first = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> first[i];
    }
    
    int m;
    std::cin >> m;
    
    int *second = new int[m];
    for (int i = 0; i < m; i++)
    {
        std::cin >> second[i];
    }
    
    int *result = merge(first, second, 0, n-1, 0, m-1);
    
    for (int i = 0; i < n + m; i++)
    {
        std::cout << result[i] << " ";
    }
}
