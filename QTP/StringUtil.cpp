#include "stringutil.h"

namespace StringUtil
{
    QString capitalize(QString s)
    {
        if(s.size() > 0)
            s[0] = s[0].toUpper();

        return s;
    }
}

