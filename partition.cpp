#include <iostream>

int main()
{
    int n, pivot;
    std::cin >> n;
    int nums[n];
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
    
    std::cin >> pivot;
    
    unsigned int equal = 0, greater = 0, next = 0;
    
    int temp;
    while (next != n)
    {
        if (nums[next] < pivot)
        {
            temp = nums[next];
            nums[next++] = nums[greater];
            nums[greater++] = nums[equal];
            nums[equal++] = temp;
        }
        else if (nums[next] == pivot)
        {
            temp = nums[next];
            nums[next++] = nums[greater];
            nums[greater++] = temp;
        }
        else if (nums[next] > pivot)
        {
            next++;
        }
    }
    
    std::cout << equal << " " << n-equal;
    return 0;
}
