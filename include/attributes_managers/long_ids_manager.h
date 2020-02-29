#pragma once

#include <map>

#include "common/common.h"


class LongIDsManager
{
public:
    LongIDsManager() = default;
    ~LongIDsManager() = default;
    LongIDsManager(const LongIDsManager& other) = delete;
	LongIDsManager& operator=(const LongIDsManager& other) = delete;

    void AddUser(long_id_t long_id, user_uid_t uuid);
    user_uid_t GetUsersByLongID(long_id_t long_id);

private:
    std::map<long_id_t, user_uid_t> m_long_ids_and_uuids;
}; //LongIDsManager


