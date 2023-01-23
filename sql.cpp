#include <sqlite3.h>

int main() {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("test.db", &db);

    if (rc != SQLITE_OK) {
        std::cout << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    std::string sql = "CREATE TABLE IF NOT EXISTS Customers (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL);";

    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &err_msg);

    if (rc != SQLITE_OK ) {
        std::cout << "SQL Error: " << err_msg << std::endl;
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    sql = "INSERT INTO Customers (ID, NAME) VALUES(1, 'John Doe');";

    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &err_msg);

    if (rc != SQLITE_OK ) {
        std::cout << "SQL Error: " << err_msg << std::endl;
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
    std::cout<<"Record added successfully\n";
    sqlite3_close(db);
    return 0;
}
