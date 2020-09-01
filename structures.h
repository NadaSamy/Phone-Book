typedef struct
{
    char day[5];
    char month[5];
    char year[5];
} Date;
typedef struct
{
    char firstname[128];
    char lastname[128];
    Date DOB;
    char address[128];
    char email[128];
    char phonenumber[14];
} Contacts;
