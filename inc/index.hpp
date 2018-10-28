
#pragma once

#include <histhash.hpp>
#include <types.hpp>
#include <rdxl.hpp>
#include <functional>

namespace RHJ 
{
    class Index
    {
        const PsumTable::Bucket& _data;

        bucket_key_t * _bucket;
        std::size_t _bucketSize;

        chain_key_t * _chain;

        std::function<bucket_key_t(const Relation::Tuple&)> _hash;

    public:

        Index(const PsumTable::Bucket&);
        ~Index();

        void join(const PsumTable::Bucket&, RHJ::List&) const;
    };
}
