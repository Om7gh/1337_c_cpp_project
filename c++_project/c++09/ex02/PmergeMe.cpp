
#include "PmergeMe.hpp"

std::vector<int> jacobSequence(int size)
{
        std::vector<int> sequence;
        if (size <= 0)
                return (sequence);
        sequence.push_back(0);
        if (size == 1)
                return (sequence);
        sequence.push_back(1);
        for (int i = 2; i < size; ++i)
                sequence.push_back(sequence[i - 1] + 2 * sequence[i - 2]);
        return (sequence);
}

std::deque<int> jacobSequenceDeque(int size)
{
        std::deque<int> sequence;
        if (size <= 0)
                return (sequence);
        sequence.push_back(0);
        if (size == 1)
                return (sequence);
        sequence.push_back(1);
        for (int i = 2; i < size; ++i)
                sequence.push_back(sequence[i - 1] + 2 * sequence[i - 2]);
        return (sequence);
}

bool flag(std::pair<int, int>& pair1, std::pair<int, int>& pair2)
{
        return pair1.first < pair2.first;
}

int binarySearchVect(const std::vector<int>& arr, int target, int left, int right)
{
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int binarySearchDeque(const std::deque<int>& arr, int target, int left, int right)
{
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

void mergeChains(std::vector<int>& main_chain, std::vector<int>& pend_chain, int odd)
{
    std::vector<int> jacob = jacobSequence(pend_chain.size());
    std::vector<bool> inserted(pend_chain.size(), false);

    for (size_t i = 0; i < jacob.size() && jacob[i] < static_cast<int>(pend_chain.size()); i++)
    {
        int idx = jacob[i];
        if (idx < static_cast<int>(pend_chain.size()) && !inserted[idx]) {
            int pos = binarySearchVect(main_chain, pend_chain[idx], 0, main_chain.size());
            main_chain.insert(main_chain.begin() + pos, pend_chain[idx]);
            inserted[idx] = true;

            int prev = (i == 0) ? 0 : jacob[i - 1];
            for (int j = idx - 1; j > prev; j--)
            {
                if (j >= 0 && !inserted[j])
                {
                    pos = binarySearchVect(main_chain, pend_chain[j], 0, main_chain.size());
                    main_chain.insert(main_chain.begin() + pos, pend_chain[j]);
                    inserted[j] = true;
                }
            }
        }
    }

    for (size_t i = 0; i < pend_chain.size(); i++)
    {
        if (!inserted[i])
        {
            int pos = binarySearchVect(main_chain, pend_chain[i], 0, main_chain.size());
            main_chain.insert(main_chain.begin() + pos, pend_chain[i]);
        }
    }
    if (odd != -1)
    {
        int pos = binarySearchVect(main_chain, odd, 0, main_chain.size());
        main_chain.insert(main_chain.begin() + pos, odd);
    }
}

void mergeChainsDeque(std::deque<int>& main_chain, std::deque<int>& pend_chain, int odd)
{
    std::deque<int> jacob = jacobSequenceDeque(pend_chain.size());
    std::deque<bool> inserted(pend_chain.size(), false);
    
    for (size_t i = 0; i < jacob.size() && jacob[i] < static_cast<int>(pend_chain.size()); i++)
    {
        int idx = jacob[i];
        if (idx < static_cast<int>(pend_chain.size()) && !inserted[idx]) {
            int pos = binarySearchDeque(main_chain, pend_chain[idx], 0, main_chain.size());
            main_chain.insert(main_chain.begin() + pos, pend_chain[idx]);
            inserted[idx] = true;
            
            int prev = (i == 0) ? 0 : jacob[i - 1];
            for (int j = idx - 1; j > prev; j--)
            {
                if (j >= 0 && !inserted[j])
                {
                    pos = binarySearchDeque(main_chain, pend_chain[j], 0, main_chain.size());
                    main_chain.insert(main_chain.begin() + pos, pend_chain[j]);
                    inserted[j] = true;
                }
            }
        }
    }
    for (size_t i = 0; i < pend_chain.size(); i++)
    {
        if (!inserted[i]) {
            int pos = binarySearchDeque(main_chain, pend_chain[i], 0, main_chain.size());
            main_chain.insert(main_chain.begin() + pos, pend_chain[i]);
        }
    }
    if (odd != -1)
    {
        int pos = binarySearchDeque(main_chain, odd, 0, main_chain.size());
        main_chain.insert(main_chain.begin() + pos, odd);
    }
}

void pmergeInsertionVect(int ac, char* av[])
{
        std::clock_t start = clock();
        std::vector< std::pair<int, int> > vect;
        int odd = -1;
        for (int i = 1; i < ac; i += 2)
        {
                int data1, data2;

                std::stringstream ss1(av[i]);
                if (!(ss1 >> data1) || data1 < 0)
                    throw std::invalid_argument("Error: Invalid input");
                if (i + 1 < ac)
                {
                        std::stringstream ss2(av[i + 1]);
                        if (!(ss2 >> data2) || data2 < 0)
                                throw std::invalid_argument("Error: Invalid input");
                        vect.push_back(std::make_pair(data1, data2));
                }
                else
                {
                    odd = data1;
                    break;
                }
        }

        for (std::vector< std::pair<int, int> >::iterator it = vect.begin(); it != vect.end(); it++)
                if (it->first > it->second)
                        std::swap(it->first, it->second);

        std::sort(vect.begin(), vect.end(), flag);

        std::vector< int > main_chain;
        std::vector< int > pend_chain;

        if (!vect.empty())
        {
                main_chain.push_back(vect[0].first);
                pend_chain.push_back(vect[0].second);
        }

        for (int i = 1; i < (int)vect.size(); i++)
        {
                main_chain.push_back(vect[i].first);
                pend_chain.push_back(vect[i].second);
        }
        mergeChains(main_chain, pend_chain, odd);
        std::clock_t end = clock();

        std::cout << "Before : ";
        for (int i = 1; i < ac; i++)
        {
                std::string input = av[i];
                std::cout << av[i] << " ";
        }
        std::cout << "\nAFter : ";
        for (size_t i = 0; i < main_chain.size(); i++)
                std::cout << main_chain.at(i) << " ";
        std::cout << "\n";
        double time = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
        std::cout << "Time to process a range of " << main_chain.size() << " elements with std::vector " << std::fixed << time << "us" << std::endl;
}

void pmergeInsertionDeque(int ac, char* av[])
{
        std::clock_t start = clock();
        std::deque< std::pair<int, int> > deque;
        int odd = -1;

        for (int i = 1; i < ac; i += 2)
        {
                int data1, data2;

                std::stringstream ss1(av[i]);
                if (!(ss1 >> data1) || data1 < 0)
                    throw std::invalid_argument("Error: Invalid input");
                if (i + 1 < ac)
                {
                        std::stringstream ss2(av[i + 1]);
                        if (!(ss2 >> data2) || data2 < 0)
                                throw std::invalid_argument("Error: Invalid input");
                        deque.push_back(std::make_pair(data1, data2));
                }
                else
                {
                    odd = data1;
                    break;
                }
        }

        for (std::deque< std::pair<int, int> >::iterator it = deque.begin(); it != deque.end(); it++)
                if (it->first > it->second)
                        std::swap(it->first, it->second);

        std::sort(deque.begin(), deque.end(), flag);

        std::deque< int > main_chain;
        std::deque< int > pend_chain;

        if (!deque.empty())
        {
                main_chain.push_back(deque[0].first);
                pend_chain.push_back(deque[0].second);
        }

        for (int i = 1; i < (int)deque.size(); i++)
        {
                main_chain.push_back(deque[i].first);
                pend_chain.push_back(deque[i].second);
        }
        mergeChainsDeque(main_chain, pend_chain, odd);
        std::clock_t end = clock();

        double time = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
        std::cout << "Time to process a range of " << main_chain.size() << " elements with std::deque " << std::fixed << time << "us" << std::endl;
}
