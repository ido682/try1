#include "long_ids/long_ids_manager.h"


void LongIDsManager::AddUser(long_id_t long_id, user_uid_t uuid)
{
    m_long_ids_and_uuids[long_id] = uuid;
}

user_uid_t LongIDsManager::GetUsersByLongID(long_id_t long_id)
{
    return m_long_ids_and_uuids[long_id];
}

