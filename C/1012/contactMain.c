#include"contact.h"
#include"SequenceTable.h"
int main() {
    contact con;
    InitContact(&con);

    AddContact(&con);
    AddContact(&con);
    ShowContact(&con);

    DelContact(&con);
    DelContact(&con);
    ShowContact(&con);

    FindContact(&con);
    FindContact(&con);

    ModifyContact(&con);
    ModifyContact(&con);
    ShowContact(&con);

    DestroyContact(&con);
    ShowContact(&con);
    return 0;
}