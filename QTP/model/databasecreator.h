#ifndef DATABASE_CREATOR_H
#define DATABASE_CREATOR_H

#include <QtSql/QSqlDatabase>

class DatabaseCreator
{
    private:
		DatabaseCreator();

    public:
		/**
		 * @brief getInstance
		 * @return returns an instance of the database
		 */
		static QSqlDatabase getInstance();

		/**
		 * @brief createDB
		 * @return create the database (and erase any database already existing)
		 */
		static bool createDB(void);

        static int insertNumber;
};

#endif // DATABASE_CREATOR_H
