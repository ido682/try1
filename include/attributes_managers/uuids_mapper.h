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

    void AddUser(std::string key, user_uid_t user);
    // partial_match_min_size of 0 implies exact match
    void AddUsersWithGivenKeyToExternalCont(const std::string& key,
                                            users_ordered_cont_t& ext_users_cont,
                                            int partial_match_min_size = 0);

private:
    std::map<std::string, users_ordered_cont_t> m_keys_and_uids;

    void add_users_with_exact_key_match_to_external_cont(const std::string& key,
                                                         users_ordered_cont_t& ext_users_cont);
    void add_users_with_partial_key_match_to_external_cont(const std::string& key,
                                                           users_ordered_cont_t& ext_users_cont);
}; //UUIDsMapper