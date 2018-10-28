#include <relation.hpp>
#include <histhash.hpp>
#include <index.hpp>
#include <cstdint>
#include <iostream>

#define RADIX (3)

void RHJ::Relation::Tuple::print() const {
    std::cout << "key: " << this->key << ", value: " << this->payload << std::endl;
}


RHJ::List *RHJ::Relation::RadixHashJoin(RHJ::Relation *relR, RHJ::Relation *relS) {

    PsumTable hashTableR(*relR, RADIX);

    PsumTable hashTableS(*relS, RADIX);

    // PsumTable::Bucket bucket = hashTableR[3];

    // for (uint32_t i = 0U; i < bucket.size; i++) {
    //     bucket.tuples[i].print();
    // }

    List * const results = new List;
    for (std::size_t hash = 0UL; hash < RADIX; hash++)
    {
        PsumTable::Bucket r = hashTableR[hash];
        PsumTable::Bucket s = hashTableS[hash];

        if (r.size < s.size)
        {
            Index index(r); index.join(s, *results);
        }
        else
        {
            Index index(s); index.join(s, *results);
        }
    }

    return results;
}

