#pragma once

#include <map>

#include "common/common.h"


class UUIDsMapper
{
public:
    UUIDsMapper() = default;
    ~UUIDsMapper() = default;
    UUIDsMapper(const UUIDsMapper& other) = delete;
    UUIDsMapper& operator=(const UUIDsMapper& other) = delete;

    void AddUUID(std::string key, uuid_t uuid);
    // partial_match_min_size of 0 implies exact match is required
    void AddUUIDsWithGivenKeyToExternalCont(const std::string& key,
                                            ordered_uuids_t& ext_uuids_cont,
                                            int partial_match_min_size = 0);
    void DeleteUUID(std::string key, uuid_t uuid);

private:
    std::map<std::string, ordered_uuids_t> m_keys_and_uids;

    void add_uuids_with_exact_key_match_to_external_cont(const std::string& key,
                                                         ordered_uuids_t& ext_uuids_cont);
    void add_uuids_with_partial_key_match_to_external_cont(const std::string& key,
                                                           ordered_uuids_t& ext_uuids_cont);
}; //UUIDsMapper