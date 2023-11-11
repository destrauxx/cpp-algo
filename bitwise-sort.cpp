#include <iostream>
#include <vector>
#include <string>

int getDigit(std::string num, int posFromRight)
{
    return num[num.length() - posFromRight - 1]-48;
}

std::vector<std::string> bitwise(std::vector<std::string> src)
{
    std::vector<std::vector<std::string>> bucket;

    int digitsCount = src[0].length();
    int consideredDigit;
    for (int digitPosition = 0; digitPosition < digitsCount; digitPosition++)
    {
        bucket.resize(10);
        std::cout << "Phase " << digitPosition + 1 << std::endl;

        // Bucket filling
        for (int elementIndex = 0; elementIndex < src.size(); elementIndex++)
        {
            consideredDigit = getDigit(src.at(elementIndex), digitPosition);

            bucket.at(consideredDigit).push_back(src.at(elementIndex));
        }

        // Bucket printing and source vector refilling
        int changedPosition = 0;
        for (int bucketSlot = 0; bucketSlot < bucket.size(); bucketSlot++)
        {
            std::cout << "Bucket " << bucketSlot << ": ";
            if (bucket.at(bucketSlot).size() == 0)
            {
                std::cout << "empty";
            }
            else
            {
                for (int elemInd = 0; elemInd < bucket.at(bucketSlot).size() - 1; elemInd++)
                {
                    src.at(changedPosition++) = bucket.at(bucketSlot).at(elemInd);
                    std::cout << bucket.at(bucketSlot).at(elemInd) << ", ";
                }
                std::cout << bucket.at(bucketSlot).at(bucket.at(bucketSlot).size() - 1);
                src.at(changedPosition++) = bucket.at(bucketSlot).at(bucket.at(bucketSlot).size() - 1);
            }
            std::cout << std::endl;
        }

        bucket.clear();
        std::cout << "**********" << std::endl;
    }

    return src;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> nums;
    nums.resize(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
    int digitsCount = nums[0].length();

    std::cout << "Initial array:\n";
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << nums[i] << ", ";
    }
    std::cout << nums[n - 1];
    std::cout << "\n**********" << std::endl;

    std::vector<std::string> sorted = bitwise(nums);

    std::cout << "Sorted array:" << std::endl;

    for (int i = 0; i < sorted.size() - 1; i++)
    {
        std::cout << sorted.at(i) << ", ";
    }
    std::cout << sorted.at(sorted.size() - 1);
}
