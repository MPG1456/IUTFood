#include "datastore.h"

static DataStore::DataStore& instance()
{
    static DataStore s;
    return s;
}
