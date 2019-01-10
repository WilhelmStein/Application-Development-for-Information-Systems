#pragma once
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <deque>
#include <string>
#include <types.hpp>
#include <executioner.hpp>
#include <statistics.hpp>
#include <pair.hpp>


namespace RHJ {
    class JoinEnumerator {

        std::unordered_map<std::string, std::deque<std::size_t> > bestTree;
        std::unordered_map< std::string, std::deque<RHJ::Query::Predicate> > connections;

        std::set<std::size_t> startSet;

        public:
        
        JoinEnumerator(const RHJ::Query& query);
        ~JoinEnumerator();

        std::deque<std::size_t> generateBestCombination();
        std::deque<RHJ::Query::Predicate> relToPred(std::deque<std::size_t>);

        float cost(std::deque<std::size_t> rel);
        bool connected(std::size_t relA, const std::deque<std::size_t>& permutation);

        static std::vector< std::deque<std::size_t>> generateSubCombinations(const std::vector<std::size_t>& set);
        
    };
}