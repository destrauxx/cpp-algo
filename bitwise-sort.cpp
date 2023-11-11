#include <iostream>
#include <vector>

int countDigits(unsigned long long num)
{
    int digitsCount = 0;

    while (num != 0)
    {
        digitsCount++;
        num /= 10;
    }

    return digitsCount;
}

int getDigit(unsigned long long num, int posFromRight)
{
    for (int i = 0; i < posFromRight; i++)
    {
        num /= 10;
    }

    return num % 10;
}

std::vector<unsigned long long> bitwise(std::vector<unsigned long long> src)
{
    std::vector<int> positions;
    std::vector<std::vector<unsigned long long>> bucket;

    int digitsCount = countDigits(src[0]);
    int consideredDigit;
    for (int digitPosition = 0; digitPosition < digitsCount; digitPosition++)
    {
        bucket.resize(10);
        positions.resize(10);
        std::cout << "Phase " << digitPosition + 1 << std::endl;

        // Counting positions
        for (int elementIndex = 0; elementIndex < src.size(); elementIndex++)
        {
            consideredDigit = getDigit(src.at(elementIndex), digitPosition);

            for (int positionsIndex = consideredDigit + 1; positionsIndex < 10; positionsIndex++)
            {
                positions[positionsIndex]++;
            }
        }

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
                    for (int iter = countDigits(bucket.at(bucketSlot).at(elemInd)); iter < digitsCount; iter++)
                    {
                        if (bucket.at(bucketSlot).at(elemInd) != 0)
                        {
                            std::cout << "0";
                        }
                    }
                    std::cout << bucket.at(bucketSlot).at(elemInd) << ", ";
                }
                for (int iter = countDigits(bucket.at(bucketSlot).at(bucket.at(bucketSlot).size() - 1)); iter < digitsCount; iter++)
                {
                    if (bucket.at(bucketSlot).at(bucket.at(bucketSlot).size() - 1) != 0)
                    {
                        std::cout << "0";
                    }
                }
                std::cout << bucket.at(bucketSlot).at(bucket.at(bucketSlot).size() - 1);
                src.at(changedPosition++) = bucket.at(bucketSlot).at(bucket.at(bucketSlot).size() - 1);
            }
            std::cout << std::endl;
        }

        bucket.clear();
        positions.clear();
        std::cout << "**********" << std::endl;
    }

    return src;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<unsigned long long> nums;
    nums.resize(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
    int digitsCount = countDigits(nums[0]);

    std::cout << "Initial array:\n";
    for (int i = 0; i < n - 1; i++)
    {
        for (int iter = countDigits(nums.at(i)); iter < digitsCount; iter++)
        {
            if (nums.at(i) != 0)
            {
                std::cout << "0";
            }
        }
        std::cout << nums[i] << ", ";
    }
    for (int iter = countDigits(nums.at(n - 1)); iter < digitsCount; iter++)
    {
        if (nums.at(n - 1) != 0)
        {
            std::cout << "0";
        }
    }
    std::cout << nums[n - 1];
    std::cout << "\n**********" << std::endl;




    std::vector<unsigned long long> sorted = bitwise(nums);

    std::cout << "Sorted array:" << std::endl;

    for (int i = 0; i < sorted.size() - 1; i++)
    {
        for (int iter = countDigits(sorted.at(i)); iter < digitsCount; iter++)
        {
            if (sorted.at(i) != 0)
            {
                std::cout << "0";
            }
        }
        std::cout << sorted.at(i) << ", ";
    }
    for (int iter = countDigits(sorted.at(sorted.size() - 1)); iter < digitsCount; iter++)
    {
        if (sorted.at(sorted.size() - 1) != 0)
        {
            std::cout << "0";
        }
    }
    std::cout << sorted.at(sorted.size() - 1);
}
