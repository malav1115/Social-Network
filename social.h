// Defining the MAX_SIZE and MAX_CONTENT_SIZE
#define MAX_SIZE 50
#define MAX_CONTENT_SIZE 200
typedef enum
{
    INDIVIDUAL,  // 0
    BUSINESS,    // 1
    GROUP,       // 2
    ORGANISATION // 3
} Nodetype;

struct Node
{
    int id;
    char *name;
    char *date;
    Nodetype type;
    char *content[MAX_CONTENT_SIZE];
    int numcontent;
    struct Node *links[MAX_SIZE];
    int numlinks;
};

struct individual
{
    struct Node *node;
    char *birthday;
    struct Business *blist[MAX_SIZE];
    int nblist;
    struct Group *Glist[MAX_SIZE];
    int nGlist;
    struct Organisation *Olist[MAX_SIZE];
    int nOlist;
};

struct Business
{
    struct Node *node;
    double x_cordinate;
    double y_cordinate;
    struct individual *owner[MAX_SIZE];
    int nowner;
    int nconstomer;
    struct individual *customer[MAX_SIZE];
    struct Group *Glist[MAX_SIZE];
    int nGlist;
};

struct Organisation
{
    struct Node *node;
    double x_cordinate;
    double y_cordinate;
    struct individual *members[MAX_SIZE];
    int nmembers;
};

struct Group
{
    struct Node *node;
    struct individual *members[MAX_SIZE];
    int nmember;
    struct Business *Blist[MAX_SIZE];
    int nBlist;
};

// function for todays date
char *today_date();

// Creation of All type of nodes
struct Node *CreateNode(Nodetype type);
struct individual *CreateIndividual();
struct Business *CreateBusiness();
struct Group *CreateGroup();
struct Organisation *CreateOrganisation();

// All Print Functions are here ---
void PrintNode(struct Node *node);
void PrintIndividual(struct individual *Individual);
void PrintAllNodes();
void PrintBusiness(struct Business *business);
void PrintGroup(struct Group *group);
void PrintOrganisation(struct Organisation *orgi);

// Search of Node by ID and Name --
struct Node *SearchbyId(int id);
struct Node *SearchbyName(char *name);
struct Node *SearchbyBirthday(char *birthday);

// Function which help to print 1-hop of different type of nodes
void PrintNodesbyNode(struct Node *node);
void PrintBusinessofIndividual(struct individual *Individual);
void PrintGroupsofIndividual(struct individual *Individual);
void PrintOrganisationofIndividual(struct individual *Individual);

void PrintOwnersofBusiness(struct Business *business);
void PrintCostumersofBusiness(struct Business *business);
void PrintGroupsofBusiness(struct Business *business);

void PrintMembersofGroup(struct Group *new_grp);
void PrintBusinessofGroup(struct Group *new_grp);

void PrintMembersofOrganisation(struct Organisation *new_Organisation);

// Printing 1-hop of Individual
void Print_1_hop_for_indiviual(struct individual *Individual);

// Printing 1-hop for Business
void Print_1_hop_for_Business(struct Business *business);

// Printing 1-hop for Group
void Print_1_hop_for_Group(struct Group *grp);

// Printing 1-hop for Organisation
void Print_1_hop_for_Organisation(struct Organisation *org);

// Deletion of all type of Nodes
void DeleteNode(struct Node *node);
void DeleteIndividual(struct individual *Individual);
void DeleteBusiness(struct Business *business);
void DeleteOrganisation(struct Organisation *new_org);
void DeleteGroup(struct Group *new_grp);

// Function for Contents
void Create_Post_Content(struct Node *node);
void PrintAllContentofaNode(struct Node *node);
struct Node *Search_for_content_helper();
void Search_for_content();

// Displaying the content of content posted by individuals linked to a given individual
void Dipslay_Content_ofconneted_Individaul(struct individual *Individual);

// LInking Fucntions
void Add_Owner_to_Business(struct Business *new_business, struct individual *new_indi);
void Add_Constumers_to_Business(struct Business *new_business, struct individual *new_indi);
void Add_Group_to_Business(struct Business *new_business, struct Group *new_grp);
void Add_Member_to_Group(struct Group *new_grp, struct individual *new_indi);
void Add_Member_to_Organisation(struct Organisation *new_org, struct individual *new_indi);

// Some Extra Functions
struct individual *SearchIndividual(int id);
struct Business *SearchBusiness(int id);
struct Organisation *SearchOrganisation(int id);
struct Group *SearchGroup(int id);
void DeleteAll();