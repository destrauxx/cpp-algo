#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> first, std::vector<int> second)
{
    std::vector<int> result;
    result.resize(first.size() + second.size());

    int first_elem = 0, second_elem = 0;
    for (int i = 0; i < first.size() + second.size(); i++)
    {
        if (first_elem < first.size() && (second_elem >= second.size() || first.at(first_elem) <= second.at(second_elem)))
        {
            result[i] = first[first_elem++];
        }
        else if (second_elem < second.size() && (first_elem >= first.size() || first.at(first_elem) > second.at(second_elem)))
        {
            result[i] = second[second_elem++];
        }
    }

    return result;
}

std::vector<int> insertion_sort(std::vector<int> sourceArray)
{
    if (sourceArray.size() <= 1)
    {
        return sourceArray;
    }

    std::vector<int> first(sourceArray.begin(), sourceArray.begin() + (sourceArray.size() / 2));
    std::vector<int> second(sourceArray.begin() + (sourceArray.size() / 2), sourceArray.begin() + sourceArray.size());
    first = insertion_sort(first);
    second = insertion_sort(second);
    return merge(first, second);
}

int main()
{
    int n = 5;
    std::cin >> n;

    std::vector<int> nums;
    nums.resize(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    std::vector<int> sorted = insertion_sort(nums);
    
    for (int elem : sorted)
    {
        std::cout << elem << " ";
    }
}
