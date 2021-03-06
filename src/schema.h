#ifndef LDP_SCHEMA_H
#define LDP_SCHEMA_H

#include <string>
#include <vector>

using namespace std;

enum class ColumnType {
    bigint,
    boolean,
    numeric,
    timestamptz,
    varchar
};

class Counts {
public:
    unsigned int string = 0;
    unsigned int dateTime = 0;
    unsigned int number = 0;
    unsigned int integer = 0;
    unsigned int floating = 0;
    unsigned int boolean = 0;
    unsigned int null = 0;
};

class ColumnSchema {
public:
    string columnName;
    ColumnType columnType;
    string sourceColumnName;
    static void columnTypeToString(ColumnType type, string* str);
    static ColumnType selectColumnType(const Counts& counts);
};

class TableSchema {
public:
    bool skip = false;
    string tableName;
    string sourcePath;
    int sourceType;
    vector<ColumnSchema> columns;
    string moduleName;
    string directSourceTable;
};

class Schema {
public:
    vector<TableSchema> tables;
    static void MakeDefaultSchema(Schema* schema);
};

#endif
